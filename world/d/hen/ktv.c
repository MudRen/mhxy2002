// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "KTV����");
  set ("long", @LONG

        һ���ܱ��µİ��ᣬ�����Ҳϲ������Ļ������루[1;33mchang_ge[m��

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"road6",
]));

        setup();
}

void init()
{
        add_action("do_changge","chang_ge");
}

int do_changge()
{
        object ob = this_player();
        int i = 400 + random(100);

        if( ob->query("hen/money") < i )
                return notify_fail("���Ǯ����������\n");

        ob->command_function("cls");
        ob->command_function("shape");
        ob->add("hen/money",-i);
        ob->add("hen/happy",12);
        ob->add("hen/satisfy",12);
        ob->add("hen/dirty",8);

        cat(KTV);
        return 1;
}
