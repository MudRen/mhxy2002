#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIW"ħ�����"NOR);
     set("long",

"�������ħ�̵�����ˣ���������ҵ������ڣ�������ɢ����һ����ǵ�ζ��\n"
"������˵ħ�̵������û�һ��Ҳ���١�\n"
);
  set("exits", ([ /* sizeof() == 2 */
                "west":"/d/moon/kunlun",
                "east":"/d/mojiao/road1",
]));
 setup();
      replace_program(ROOM);
}
