// by fly 2000.12.6

#include <ansi.h>
#include <room.h>
string look_sign();
inherit ROOM;

void create()
{
    set ("short", "��������");
  set ("long", @LONG

����֮����һ������֮�ƣ����������ľ�������ǰ��һ�Ŵ���������
����֪�����ˡ�����һ�����ң�д�ţ������������ĸ��̽���֡�
           [1;35m��������������������������������������������
           [1;35m��������������������������������������������
          [1;35m ��������    [1;37m��    ��    ��    ��    [1;35m��������
          [1;35m ��������������������������������������������
           [1;35m��������������������������������������������[2;37;0m

��������һλ������������ȴ�ƺ����˸�ľ�Ƶ�����(Sign)��
LONG);
        set("item_desc", ([
                "sign" : (: look_sign :),
          ]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/huanggong/chaoyangmen",
]));
set("objects", ([
            "/d/city/npc/yayi1":1+random(2),
              "/d/city/obj/npc/change_couple":1,
              "/d/city/obj/npc/zhifu":1,
]));
        set("no_fight", 1);
        set("no_magic", 1);
  set("light_up", 1);
  setup();
}
string look_sign()
{
       return
       "\n\n"
       "    ��������������������������������������\n"
       "    ��"+HIG"��������(ask wei about ��������)"NOR+" ��\n"       
       "    ��"+HIG"�޸Ļ���(ask guan jia about ����)"NOR+"��\n"       
       "    ��������������������������������������\n\n";
}
void init()
{ 
          object me = this_player();
          call_out("wait", 2, me);         
}

void wait(object me)
{
        tell_room(environment(me),"\n "+me->name()+"�Ҵ�ææ���������˹�����\n");
          write(" "+me->name()+"����ɨ����һ�£��ƺ�ûҲ����ʲô����ĵط���\n",me);
          call_out("wait2", 5, me);         
                return;
}
void wait2(object me)
{
          write(WHT" ͻȻ�㷢����λ�����������ƺ����˸�ľ�Ƶ�����(sign)��\n"NOR);
                return;
}
