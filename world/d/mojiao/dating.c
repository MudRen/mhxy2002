#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIR"��ħ��"NOR);
     set("long",
   "                                   \n"
"                        "+BBLU+""+HIR+"��ħ��"+NOR+"                 \n"    
""+HIW+"���������ħ�Ҳ��ħ�̵��ܲ�����������������ʮ�ֵ�ɭ��\n"
""+HIW+"�˵�����һ��"+HIR+"����ħ���"+NOR+"\n"
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"gate",
          "enter": __DIR__"dating2",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tianmo" : 1,
  ]));
 setup();
      replace_program(ROOM);
}
