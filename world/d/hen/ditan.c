// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "��̯");
  set ("long", @LONG

        ������������� [1;32m  bai_ditan[m �Ϳ��Զ����Լ�����Ƥ��

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"syroad4",
]));

        setup();
}

void init()
{
                add_action("do_work","bai_ditan");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-5);
        ob->add("hen/dirty",7);
        ob->add("hen/happy",-7);
        ob->add("hen/satisfy",-7);
        
        cat(HAWKER);
        write("�ڵ�̯Ҫ�㾯����..:p\n");

        if( time() - ob->query("hen/last_ditan") < 180 )
        {
        write("����С���������ظ���ͬһ�����顣\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",150+random(20));
        ob->set("hen/last_ditan",time());
        
        return 1;
}
