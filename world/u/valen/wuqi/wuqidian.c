//By tianlin@mhxy for 2001.9.18
//���������̵�ʱ,����Ҫ�Ǻ�����һ��������npc����ȥ����,�е㲻���,
//(1)��npc���ױ�ɱ��,Ҫ�����npc����no_dieҲ��,����Ҳ����ô��,��û����
//�ʸ�,(2)������ROOM����Ļ�,���ϵ�����ͽ����,����ROOM���ܻ���,������
//Ϊ����,��ҿ���ģ�µ���һ��,�벻Ҫ�����ߵ�����..лл!!!(xixi)
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", NOR"����"HIC"��"NOR"�̵�");
  set ("long", @LONG

[37m         [32;47m     �y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y�y      [1;37;40m��
[37m         [1;31;47m     [37;42m            [1;35m��[5m[1;36m��[0m[37;42m[1;35m������ר����[0m[37;42m            [31;47m      [37;40m��
[37m         [32;47m     [37;42m�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{[1;47m      [40m��
[37m      [1m   ��[47m������[33;46m����������������������������������[37;47m��������[m
[37m      [1m   ��[47m������[33;46m����������������������������������[37;47m��������[m
[37m      [1m   ��[47m������[33;44m��      ��      ��      ��      ��[37;47m��������[m
[37m      [1m   ��[47m������[33;44m���������੤�������������੤������[37;47m��������[m
[37m      [1m   ��[47m������[33;44m���n�n�n���n�n�n���n�n�n���n�n�n��[37;47m��������[m
[37m      [1m   ��[47m������[32;43m����������������������������������[37;47m��������[m
[1;33m      ����������������������������������������������������������[m
[37m  [1;41m [NO]  [������]   [�ӷ���]  [����]  [������]   [���Ṧ]  [��  ��][m
   ( 1)  ��ͭ��       50       0         20        0        6000
   ( 2)  ���׽�       80       0         30        0        10000
   ( 3)  ����      100       0         40        0        15000
   ( 4)  ���齣      100       0         35        0        15000
   ( 5)  ʨͷ����    150       0         60        0        35000
   ( 6)  ������      200       0         100       0        50000
   ( 7)  �ƽ�ʥ��    300       300       100       0        150000
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
        // "enter": __DIR__"road3",
         "east": __DIR__"daojudian",
]));

        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object obj;
        object me=this_player();
        int afford;
        if(me->is_busy())
                return notify_fail(CYN"��������æ���ء�\n"NOR);
        switch(arg)
        {
                case "1":
                {
                if( !(afford=me->can_afford(20000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(20000);
                obj = new ("/u/tianlin/wuqi/daoju/dan");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIG"�ٹ���"NOR"��\n");
                break;
                }
                
                case "2":
                {
                if( !(afford=me->can_afford(50000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(50000);
                obj = new ("/u/tianlin/wuqi/daoju/xieyao");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һƿ"HIC"кҩ"NOR"��\n");
                break;
                }

                case "3":
                {
                if( !(afford=me->can_afford(100000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(10000);
                obj = new ("/u/tianlin/wuqi/daoju/xianyao");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIY"��ҩ"NOR"��\n");
                break;
                }

                case "4":
                {
                if( !(afford=me->can_afford(100000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(10000);
                obj = new ("/u/tianlin/wuqi/daoju/shenyao");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIR"��ҩ"NOR"��\n");
                break;
                }
 
                case "5":
                {
                if( !(afford=me->can_afford(500000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(500000);
                obj = new ("/u/tianlin/wuqi/daoju/renshen");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"YEL"ǧ���˲���"NOR"��\n");
                break;
                }

                case "6":
                {
                if( !(afford=me->can_afford(700000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(700000);
                obj = new ("/u/tianlin/wuqi/daoju/bag");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIW"�ٱ���"NOR"��\n");
                break;
                }

                case "7":
                {
                if( !(afford=me->can_afford(200000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(200000);
                obj = new ("/u/tianlin/wuqi/daoju/bi");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIY"�����"NOR"��\n");
                break;
                }

                case "8":
                {
                if( !(afford=me->can_afford(90000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(90000);
                obj = new ("/u/tianlin/wuqi/daoju/shaqi");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"RED"ɱ����"NOR"��\n");
                break;
                }

                case "9":
                {
                if( !(afford=me->can_afford(150000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(150000);
                obj = new ("/u/tianlin/wuqi/daoju/taowang");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIM"����⨺�����"NOR"��\n");
                break;
                }

                case "10":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/daoju/xuelian");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIC"��ɽѩ��"NOR"��\n");
                break;
                }

                case "11":
                {
                if( !(afford=me->can_afford(1000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                me->pay_money(1000000);
                obj = new ("/u/tianlin/wuqi/daoju/lingzhi");
                obj->move(me);
                me->start_busy(4); 
                write("������ߵ�����һ��"HIR"������֥"NOR"��\n");
                break;
                }
        }
return 1;
}

