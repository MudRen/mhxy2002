// by happ@YSZZ

#include <hen.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ιʳ");
  set ("long", @LONG

        �����������[1;33m feed[m ָ��ι�����С����
 
        [1;33m feed 1 ��[m�Է�          [1;33mfeed 2 �� [m����ʳ  
        [1;33m feed 3 ��[m����          [1;33mfeed 4 �� [m����֥
        [1;33m feed 5 ��[m�˲�          [1;33mfeed 6 �� [m��ѩ��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"road1",
]));

        setup();
}

void init()
{
        add_action("do_feed","feed");
}

int do_feed(string arg)
{
        object ob = this_player();

        if( ! present("zhandou ji",ob) )   return 0;
        ob->command_function("cls");


        switch(arg)
        {
                case "1":
                {
                if( ob->query("hen/inventory/food")  < 1 )
                        return notify_fail("���ʳ�ﲻ���ˣ���ȥ��ɣ�\n");
                switch(random(3))
                {
                case 1:
                cat(EAT);
                break;
                case 0:
                cat(DRINK);
                break;
                case 2:
                cat(MILK);
                break;
                }
                ob->add("hen/life",50);
                break;
                }

                case "2":
                {
                if( ob->query("hen/inventory/lingshi")  < 1 )
                        return notify_fail("�����ʳ�����ˣ���ȥ��ɣ�\n");

                cat(FOOD);

                ob->add("hen/life",100);

                ob->query("hen/happy") < 95 ?
                ob->add("hen/happy",5+random(3)) :
                ob->set("hen/happy",100);
                ob->add("hen/weight",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/inventory/dabu")  < 1 )
                return notify_fail("��Ĵ󲹲����ˣ���ȥ��ɣ�\n");

                cat(EATDABU);
                ob->add("hen/life",500);
                break;
                }

                case "4":
                {
                if( ob->query("hen/inventory/lingzhi")  < 1 )
                        return notify_fail("�����֥û���ˣ���ȥ��ɣ�\n");

                write(HIC"����� 1000 �����������\n"NOR);

                ob->add("hen/life",1000);
                break;
                }

                case "5":
                { 
                       if( ob->query("hen/inventory/renshen")  < 1 )
                        return notify_fail("����˲β����ˣ���ȥ��ɣ�\n");

                write(HIC"����� 500 ��ķ�����\n"NOR);

                ob->query("hen/fali") + 500 > ob->query("max_fali") ?
                ob->set("hen/fali",ob->query("max_fali")) :
                ob->add("hen/fali",1000);

                break;
                }
                
                case "6":
                {
                if( ob->query("hen/inventory/xuelian")  < 1 )
                        return notify_fail("���ѩ�������ˣ���ȥ��ɣ�\n");

                write(HIC"��ķ����ӵ������\n"NOR);
                ob->set("hen/fali",ob->query("hen/max_fali"));
                break;
                }
        }

        ob->command_function("shape");

        return 1;
}
