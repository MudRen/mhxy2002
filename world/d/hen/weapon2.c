// by happ@YSZZ
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "���������̵�");
  set ("long", @LONG

[37m         [32;47m     �y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y      [1;37;40m��
[37m         [1;31;47m     [37;42m �ףţ��УϣΣ�  �ӣԣϣң�  ���������� [31;47m      [37;40m��
[37m         [32;47m     [37;42m�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{[1;47m      [40m��
[37m      [1m   ��[47m������[33;46m����������������������������������[37;47m��������[m
[37m      [1m   ��[47m������[33;46m����������������������������������[37;47m��������[m
[37m      [1m   ��[47m������[33;44m��      ��      ��      ��      ��[37;47m��������[m
[37m      [1m   ��[47m������[33;44m���������੤�������������੤������[37;47m��������[m
[37m      [1m   ��[47m������[33;44m���n�n�n���n�n�n���n�n�n���n�n�n��[37;47m��������[m
[37m      [1m   ��[47m������[32;43m����������������������������������[37;47m��������[m
[1;33m      ����������������������������������������������������������[m
[37m  [1;41m [NO]  [������]  [����]  [����]  [�ٶ�]  [����]  [����]  [�ٶ�]  [��  ��][m
   ( 1)  ��ͭ��       50       0       0      20       0       0      6000
   ( 2)  ���׽�       80       0       0      30       0       0     10000
   ( 3)  ����      100      20       0      40       0       0     15000
   ( 4)  ���齣      100      40       0      35      20       0     15000
   ( 5)  ʨͷ����    150       0       0      60       0       0     35000
   ( 6)  ������      200       0       0     100       0       0     50000
   ( 7)  �ƽ�ʥ��    300     300     300     100      20       0    150000
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "north": __DIR__"miscshop",
]));

        setup();
}
void init()
{
        object ob = this_player();
        ob->command_function("cls");
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object ob = this_player();

        if(!present("zhandou ji",ob)) return 0;


        switch(arg)
        {
                case "1":
                {
                if( ob->query("hen/money") < 6000 )
                        {
                        write("���Ǯ����������\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/qtj") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -6000);
                ob->set("hen/attack",ob->query("hen/attack")+20);
                ob->add("hen/life",50);
                write(HIC"��������һ����ͭ�����������ӣ��㣬�����ӣ�����\n"NOR);
                ob->set("hen/inventory/qtj",1);
                break;
                }

                case "2":
                {
                if( ob->query("hen/money") < 10000 )
                        {
                        write("���Ǯ����������\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/qlj") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -10000);
                ob->set("hen/attack",ob->query("hen/attack")+30);
                ob->add("hen/life",80);
                write(HIC"��������һ�����׽�������+30,����+80��\n"NOR);
                ob->set("hen/inventory/qlj",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 15000 )
                        {
                        write("���Ǯ����������\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/cyd") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -15000);
                ob->set("hen/attack",40);
                ob->add("hen/life",100);
                ob->add("hen/fali",20);
                write(HIC"��������һ��������������+40,����+100,����+20��\n"NOR);
                ob->set("hen/inventory/cyd",1);
                break;
                }


                case "4":
                {
                if( ob->query("hen/money") < 15000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/wqj") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -15000);
                ob->set("hen/defence",ob->query("hen/defence")+20);
                ob->set("hen/life",ob->query("hen/life")+100);
                ob->add("hen/fali",40);
                ob->add("hen/attack",35);
                write(HIC"��������һ�����齣��������+20,����+35,����+100,����+40��\n"NOR);
                ob->set("hen/inventory/gttoukui",1);
                break;
                }


                case "5":
                {
                if( ob->query("hen/money") < 35000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/stbd") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -35000);
                ob->add("hen/attack",60);
                ob->add("hen/life",150);
                write(HIC"��������һ��ʨͷ������������+150,����+60��\n"NOR);
                ob->set("hen/inventory/stbd",1);
                break;
                }

                case "6":
                {
                if( ob->query("hen/money") < 50000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/tld") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -50000);
                ob->add("hen/life",200);
                ob->add("hen/attack",100);
                write(HIC"��������һ����������������+200,����+100��\n"NOR);
                ob->set("hen/inventory/tld",1);
                break;
                }

                case "7":
                {
                if( ob->query("hen/money") < 150000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/hjsz") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -150000);
                ob->add("hen/defence",ob->query("hen/defence")+20);
                ob->set("hen/life",ob->query("hen/life")+300);
                ob->set("hen/fali",ob->query("hen/fali")+300);
                ob->set("hen/attack",ob->query("hen/attack")+100);
                ob->set("hen/speed",ob->query("hen/speed")+300);
                write(HIC"��������һ���ƽ�ʥ�ȡ�������+20,����+300,����+300,����+100,�ٶ�+300\n"NOR);
                ob->set("hen/inventory/hjsz",1);
                break;
                }


        }
        return 1;
}
