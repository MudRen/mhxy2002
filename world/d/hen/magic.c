// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "ħ������");
  set ("long", @LONG

        ������������� [1;32mxue_magic [m ��ѧϰħ���γ̡�

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"xxroad4",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_magic");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/max_fali") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m��������[m";
        }

        if( ob->query("hen/max_fali") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m���м���[m";
        }

        if( ob->query("hen/max_fali") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m���߼���[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("���Ǯ����ѧϰħ���γ̡�\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);

	
	switch(random(2))
	{
		case 0:
                cat(MAGIC1);
		write("�ߵ�+���β+����+���=??\n");
		break;

		case 1:
		cat(MAGIC2);
		write("�ұ� �ұ� �ұ���..\n");
		break;
	}


        write("�㻨�� "+fee+" Ԫѧϰħ��"+lv+"�γ̡�\n");
        ob->query("hen/max_fali")<50000?ob->add("hen/max_fali",2):
        ob->set("hen/max_fali",50000);
        return 1;
}
