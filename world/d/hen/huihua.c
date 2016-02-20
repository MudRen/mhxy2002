// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "�滭����");
  set ("long", @LONG

        ������������� [1;32mxue_huihua [m ��ѧϰ�滭�γ̡�

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"xxroad5",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_huihua");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/art") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m��������[m";
        }

        if( ob->query("hen/art") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m���м���[m";
        }

        if( ob->query("hen/art") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m���߼���[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("���Ǯ����ѧϰ�滭�γ̡�\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
	        ob->add("hen/dirty",5);


                cat(DRAW);

        write("�㻨�� "+fee+" Ԫѧϰ�滭"+lv+"�γ̡�\n");
        ob->query("hen/art")<50000?ob->add("hen/art",2):
        ob->set("hen/art",50000);
        ob->add("hen/feel",1);
        return 1;
}
