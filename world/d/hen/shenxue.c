// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "��ѧ����");
  set ("long", @LONG

        ������������� [1;32mxue_shenxue [m ��ѧϰ��ѧ�γ̡�

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"xxroad2",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_shenxue");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/anticmagic") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m��������[m";
        }

        if( ob->query("hen/anticmagic") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m���м���[m";
        }

        if( ob->query("hen/anticmagic") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m���߼���[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("���Ǯ����ѧϰ��ѧ�γ̡�\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);


                cat(GOD);

        write("�㻨�� "+fee+" Ԫѧϰ��ѧ"+lv+"�γ̡�\n");
        ob->query("hen/anticmagic")<10000?ob->add("hen/anticmagic",1):
        ob->set("hen/anticmagic",10000);
        ob->add("hen/might",1);
        ob->add("belief",1);
        return 1;
}
