// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

        ������������� [1;32m serve [m �ڲ������浱����������

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"syroad3",
]));
        setup();
}

void init()
{
                add_action("do_work","serve");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",8);

        cat(INN);

        if( time() - ob->query("hen/last_canting") < 180 )
        {
        write("����С���������ظ���ͬһ�����顣\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",100+random(20));
        ob->add("hen/homework",1);
        ob->set("hen/last_canting",time());

        return 1;
}
