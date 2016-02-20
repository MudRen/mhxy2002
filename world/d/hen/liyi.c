// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "���ǽ���");
  set ("long", @LONG

        ������������� [1;32mxue_liyi [m ��ѧϰ���ǿγ̡�

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"xxroad4",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_liyi");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/decorum") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m��������[m";
        }

        if( ob->query("hen/decorum") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m���м���[m";
        }

        if( ob->query("hen/decorum") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m���߼���[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("���Ǯ����ѧϰ���ǿγ̡�\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);


	write("(ͼƬ��ȱ)\n\nҪ��ֻ����ò�ļ�...\n");

        write("�㻨�� "+fee+" Ԫѧϰ����"+lv+"�γ̡�\n");
        ob->query("hen/decorum")<50000?ob->add("hen/decorum",2):
        ob->set("hen/decorum",50000);
        return 1;
}
