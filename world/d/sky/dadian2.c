// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "[33m��������[m");
  set ("long", @LONG
�������������ڵ�����������.���ϵ�����ϼ�����,����ǧ��.
�ɹ��ɽ�������һ��,���ϴ���������϶��ı���.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dianmen.c",
  "northup" : __DIR__"dian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

int valid_leave(object me, string dir)
{  object *inv, container;
    int sizeinv;
  if (dir !="northup")
   return ::valid_leave(me, dir);
   
     if (dir == "northup") 
     inv=all_inventory(me);
     sizeinv=sizeof(inv);
    while (sizeinv--)
   {
       if (userp(inv[sizeinv]))
       {
     container=inv[sizeinv];
     break;
       }
       if (inv[sizeinv]->is_container())
       {
     container=inv[sizeinv];
     break;
       }
       continue;
   }
   if (container)
   {
       message_vision(HIC"���д����������������������"+container->name()+
           HIC"��ȥ��ʲô�������ɻ���أ���\n"NOR,me);
        return notify_fail("");

    }
     return ::valid_leave(me, dir);
 
   }


