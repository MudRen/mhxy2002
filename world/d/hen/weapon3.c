// by happ@YSZZ
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "�Ų������̵�");
  set ("long", @LONG

[37m         [32;47m     �y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y      [1;37;40m��
[37m         [1;31;47m     [37;42m �ףţ��УϣΣ�  �ӣԣϣң�  �Ų������� [31;47m      [37;40m��
[37m         [32;47m     [37;42m�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{[1;47m      [40m��
[37m      [1m   ��[47m������[33;46m����������������������������������[37;47m��������[m
[37m      [1m   ��[47m������[33;46m����������������������������������[37;47m��������[m
[37m      [1m   ��[47m������[33;44m��      ��      ��      ��      ��[37;47m��������[m
[37m      [1m   ��[47m������[33;44m���������੤�������������੤������[37;47m��������[m
[37m      [1m   ��[47m������[33;44m���n�n�n���n�n�n���n�n�n���n�n�n��[37;47m��������[m
[37m      [1m   ��[47m������[32;43m����������������������������������[37;47m��������[m
[1;33m      ����������������������������������������������������������[m
[37m  [1;41m [NO]  [������]  [����]  [����]  [�ٶ�]  [����]  [����]  [�ٶ�]  [��  ��][m
   ( 1)  �ܽ���Ь      0       0       0       0       0      10       800
   ( 2)  ����ľ��      0       0       0      15       0      10      1000
   ( 3)  �ؼ���Ь      0       0       0       0      10      10      1500
   ( 4)  NIKE�˶�Ь   70       0       0       0      10      40      8000
   ( 5)  ����Ƥѥ     80      20       0      10      25      20     12000
   ( 6)  ����ħѥ    100     100       0      30      50      60     25000
   ( 7)  �ƽ�ʥѥ    300     300     300      50     100     100    150000
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"miscshop",
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
                if( ob->query("hen/money") < 800 )
                        {
                        write("���Ǯ����������\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/sltx") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -800);
                ob->add("hen/speed",10);
                write(HIC"��������һ��������Ь�����ٶȼӣ�����\n"NOR);
                ob->set("hen/inventory/sltx",1);
                break;
                }

                case "2":
                {
                if( ob->query("hen/money") < 1000 )
                        {
                        write("���Ǯ����������\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/dymj") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -1000);
                ob->set("hen/attack",ob->query("hen/attack")+15);
                ob->add("hen/speed",10);
                write(HIC"��������һ������ľ�죨����+15,�ٶ�+10��\n"NOR);
                ob->set("hen/inventory/dymj",1);
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 1500 )
                        {
                        write("���Ǯ����������\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/tjyx") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -1500);
                ob->set("hen/speed",10);
                ob->add("hen/defence",10);
                write(HIC"��������һ���ؼ���Ь�����ٶ�+10,����+10��\n"NOR);
                ob->set("hen/inventory/tjyx",1);
                break;
                }


                case "4":
                {
                if( ob->query("hen/money") < 8000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/nike") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -8000);
                ob->set("hen/defence",ob->query("hen/defence")+10);
                ob->set("hen/life",ob->query("hen/life")+70);
                ob->add("hen/speed",40);
                write(HIC"��������һ��NIKE�˶�Ь.���ٶ�+40,����+70,����+10��\n"NOR);
                ob->set("hen/inventory/nike",1);
                break;
                }


                case "5":
                {
                if( ob->query("hen/money") < 12000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/eypx") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -12000);
                ob->add("hen/attack",10);
                ob->add("hen/life",80);
                ob->add("hen/fali",20);
                ob->add("hen/speed",10);
                ob->add("hen/defence",25);
                write(HIC"��������һ������Ƥѥ��������+80,����+10,�ٶ�+10,����+25,����+20��\n"NOR);
                ob->set("hen/inventory/eypx",1);
                break;
                }

                case "6":
                {
                if( ob->query("hen/money") < 25000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/ftmx") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -25000);
                ob->add("hen/attack",30);
                ob->add("hen/life",100);
                ob->add("hen/fali",100);
                ob->add("hen/speed",60);
                ob->add("hen/defence",50);
                write(HIC"��������һ������Ƥѥ��������+100,����+30,�ٶ�+60,����+50,����+100\n"NOR);
                ob->set("hen/inventory/ftmx",1);
                break;
                }

                case "7":
                {
                if( ob->query("hen/money") < 150000 )
                        {
                        write("���Ǯ�������ˣ�\n");
                        return 1;
                        }
                if( ob->query("hen/inventory/hjsx") )
                        {
                        write("���Ѿ���ͬ����װ���ˣ�\n");
                        return 1;
                        }
                ob->add("hen/money", -150000);
                ob->add("hen/defence",ob->query("hen/defence")+100);
                ob->set("hen/life",ob->query("hen/life")+300);
                ob->set("hen/fali",ob->query("hen/fali")+300);
                ob->set("hen/attack",ob->query("hen/attack")+50);
                ob->set("hen/speed",ob->query("hen/speed")+300);
                write(HIC"��������һ���ƽ�ʥѥ��������+100,����+300,����+300,����+50,�ٶ�+300\n"NOR);
                ob->set("hen/inventory/hjsx",1);
                break;
                }


        }
        return 1;
}
