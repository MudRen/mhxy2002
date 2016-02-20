// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "������");
  set ("long", @LONG

        ������������� [1;32mmeirong [m �������ݵ������

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"syroad6",
]));

        setup();
}

void init()
{
                add_action("do_work","meirong");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-7);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);

        write("ͼƬ��ȱ\n");

        if( time() - ob->query("hen/last_meirong") < 180 )
        {
        write("����С���������ظ���ͬһ�����顣\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/might",-3);
        ob->add("hen/money",200+random(20));
        ob->set("hen/last_meirong",time());

        return 1;
}
