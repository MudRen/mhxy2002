#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIY"��ħ��"NOR);
     set("long",
   "                                   \n"
"                        "+BBLU+""+HIY+"��ħ��"+NOR+"                 \n"    
"������ǵ�ħ�Ҳ��ħ�̵Ļ��ã���������������ʮ�ֵ�ɭ��\n"
"�˵�����һ��"+HIB+"����ħ���\n"NOR
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"dating",
          "enter": __DIR__"dating3",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dimo" : 1,
  ]));
 setup();
      replace_program(ROOM);
}
