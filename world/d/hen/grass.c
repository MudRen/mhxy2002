// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "�ݵ�");
  set ("long", @LONG

        һƬ������Ĳݵؾ�����Լ�ᣨ[1;36mdate[m���ĺõط�Ŷ��

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"jw",
]));

        setup();
}

void init()
{
        add_action("do_date","date");
}

int do_date()
{
        object ob = this_player();
        int i = 100 + random(50);

        if( ob->query("hen/money") < i )
                return notify_fail("û��ǮҲȥԼ�᣿\n");

        ob->command_function("cls");
        ob->command_function("shape");
        ob->add("hen/money",-i);
        ob->add("hen/happy",12);
        ob->add("hen/life",-5);
        ob->add("hen/satisfy",12);
        ob->add("hen/dirty",8);
        ob->add("hen/affection",-1);
        cat(DATE);
        return 1;
}
