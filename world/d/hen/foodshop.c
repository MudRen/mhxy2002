// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "ʳƷ��");
  set ("long", @LONG

[1;37m������������������������������������������������������������������������������
[1;31m  ��[37;41m ��� [31;40m��[37;41m ��      Ʒ [31;40m����[37;41m Ч            �� [31;40m����[37;41m ��     �� [31;40m��
[37m     [1;35m[[37m 1[35m]     [36m�óԵ�ʳ��      [37m�����ָ�50            [33m50           
[37m     [1;35m[[37m 2[35m]     [36m��ζ����ʳ      [37m�����ָ�100           [33m120          
[37m     [1;35m[[37m 3[35m]     [36m���ô���      [37m�����ָ�500           [33m500          
[37m     [1;35m[[37m 4[35m]     [36m������֥      [37m�����ָ�1000          [33m1000          
[37m     [1;35m[[37m 5[35m]     [36mǧ���˲���      [37m�����ָ�500           [33m800          
[37m     [1;35m[[37m 6[35m]     [36m��ɽѩ��        [37m�����������          [33m10000         
[1;37m������������������������������������������������������������������������������
LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"road3",
]));

        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object ob = this_player();

        switch(arg)
        {
                case "1":
                {
                if( ob->query("hen/money") < 50 )
                        {
                        write("��ֻ��"+ob->query("hen/money")+"Ԫ�ˡ�\n");
                        return 1;
                        }
                cat(BUYFOOD);
                ob->add("hen/inventory/food",1);
                ob->add("hen/money",-50);
                write("������һ��ʳ�\n");
                break;
                }
                
                case "2":
                {
                if( ob->query("hen/money") < 120 )
                        {
                        write("��ֻ��"+ob->query("hen/money")+"Ԫ�ˡ�\n");
                        return 1;
                        }
                if( random(2) == 0 )
                cat(BUYLS1);
                cat(BUYLS2);
                ob->add("hen/inventory/lingshi",1);
                ob->add("hen/money",-120);
                write("��������һ����ʳ��\n");
                break;
                }

                case "3":
                {
                if( ob->query("hen/money") < 500 )
                        {
                        write("��ֻ��"+ob->query("hen/money")+"Ԫ�ˡ�\n");
                        return 1;
                        }
                cat(BUYDABU);
                ob->add("hen/inventory/dabu",1);
                ob->add("hen/money",-500);
                write("������һ�Ŵ��衣\n");
                break;
                }

                case "4":
                {
                if( ob->query("hen/money") < 1000 )
                        {
                        write("��ֻ��"+ob->query("hen/money")+"Ԫ�ˡ�\n");
                        return 1;
                        }
                write("������һ����֥��\n");
                ob->add("hen/inventory/lingzhi",1);
                ob->add("hen/money",-1000);
                break;
                }
               
                case "5":
                {
                if( ob->query("hen/money") < 800 )
                        {
                        write("��ֻ��"+ob->query("hen/money")+"Ԫ�ˡ�\n");
                        return 1;
                        }                write("������һ���˲Ρ�\n");
                ob->add("hen/inventory/renshen",1);
                ob->add("hen/money",-800);
                break;
                }
                case "6":
                {
                if( ob->query("hen/money") < 10000 )
                        {
                        write("��ֻ��"+ob->query("hen/money")+"Ԫ�ˡ�\n");
                        return 1;
                        }
                write("������һ��ѩ����\n");
                ob->add("hen/inventory/xuelian",1);
                ob->add("hen/money",-1000);
                break;
                }
        }
return 1;
}

