// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "�˶���");
  set ("long", @LONG

        ���������˶��������벻Ҫ����������������ɡ�[1;33m��do_sport��
[m
LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"road5",
]));

        setup();
}

void init()
{
        add_action("do_sport","do_sport");
}

int do_sport()
{
        object ob = this_player();

        ob->add("hen/weight",-1);
        ob->add("hen/dirty",5);
        ob->command_function("cls");
        ob->command_function("shape");
        cat(SPORT);
        write("�˶��ô������...\n");
        return 1;
}
