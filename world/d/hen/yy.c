// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "С��ҽԺ");
  set ("long", @LONG

        ������С�������ˣ����͵������ƣ�[1;35mzhi_liao[m����

[m
LONG);
  set("exits", ([ /* sizeof() == 4 */
        "west": __DIR__"road7",
]));

        setup();
}

void init()
{
        add_action("do_zhiliao","zhi_liao");
}

int do_zhiliao()
{
        object ob = this_player();

        if( ob->query("hen/money") < 1000 )
                return notify_fail("���Ǯ�����β��ˣ������ɡ�\n");
        ob->set("hen/ill",0);
        ob->command_function("cls");
        ob->command_function("shape");
        switch(random(2))
        {
                case 0:
                cat(DOCTOR);
                break;
                case 1:
                cat(DOCTOR2);
                break;
        }
        ob->add("hen/money",-1000);
        return 1;
}
