#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIC"��ħ��"NOR);
     set("long",
   "                                   \n"
"                        "+BBLU+""+HIC+"��ħ��"+NOR+"                 \n"    
"���������ħ�Ҳ��ħ�̵����ã���������������ʮ�ֵ�ɭ��\n"
"�˵�����һ��"+HIG+"����ħ���\n"NOR
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"dating2",
          "enter": __DIR__"dating4",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/renmo" : 1,
  ]));
 setup();
      replace_program(ROOM);
}
