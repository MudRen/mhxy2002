//By tianlin@mhxy for 2001.9.18
//���������̵�ʱ,����Ҫ�Ǻ�����һ��������npc����ȥ����,�е㲻���,
//(1)��npc���ױ�ɱ��,Ҫ�����npc����no_dieҲ��,����Ҳ����ô��,��û����
//�ʸ�,(2)������ROOM����Ļ�,���ϵ�����ͽ����,����ROOM���ܻ���,������
//Ϊ����,��ҿ���ģ�µ���һ��,�벻Ҫ�����ߵ�����..лл!!!(xixi)
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIB"���ߵ�"NOR);
  set ("long", @LONG

[1;33m������������������������������������������������������������������������������
[1;31m  ��[37;41m ��� [31;40m��[37;41m ��      Ʒ [31;40m����[37;41m Ч            �� [31;40m����[37;41m ��     �� [31;40m��
[37m     [1;35m[[32m 1[35m]     [32m�ٹ���          [37m��ʳ�����ˮ�ӵ�ƿ��[2;37;0m       [36m2[33m��[1;33m�ƽ�           
[37m     [1;35m[[32m 2[35m]     [36mкҩ            [37m��ʳ�����ˮ��Ϊ0[2;37;0m          [36m5[33m��[1;33m�ƽ�          
[37m     [1;35m[[32m 3[35m]     [33m��ҩ            [37mֻҪ��һ�����ָܻ���Ѫ����[2;37;0m [36m10[33m��[1;33m�ƽ�          
[37m     [1;35m[[32m 4[35m]     [31m��ҩ            [37mֻҪ��һ�����ָܻ���������[2;37;0m [36m10[33m��[1;33m�ƽ�          
[37m     [1;35m[[32m 5[35m][2;37;0m     [33mǧ���˲���      [1;37m�ָ���Ѫ�;���500��[2;37;0m        [36m50[33m��[1;33m�ƽ�          
[37m     [1;35m[[32m 6[35m]     [37m�ٱ���          [37m�������޵�װ����[2;37;0m           [36m70[33m��[1;33m�ƽ�         
[37m     [1;35m[[32m 7[35m]     [33m�����          [37m��10������[2;37;0m                 [36m20[33m��[1;33m�ƽ�         
[37m     [1;35m[[32m 8[35m][2;37;0m     [31mɱ����          [1;37m��ɱ��100��[2;37;0m                [36m9[33m��[1;33m�ƽ�         
[37m     [1;35m[[32m 9[35m]     [35m����⨺�����    [37m��10��������10�㷨�����ֵ[2;37;0m [36m15[33m��[1;33m�ƽ�         
[37m     [1;35m[[32m10[35m]     [36m��ɽѩ��        [37m�ָ������ͷ������ֵ[2;37;0m       [36m200[33m��[1;33m�ƽ�         
[37m     [1;35m[[32m11[35m]     [31m������֥        [37m�ӷ������ֵ20��[2;37;0m           [36m100[33m��[1;33m�ƽ�         
[1;33m������������������������������������������������������������������������������[2;37;0m
LONG);

  set("exits", ([ /* sizeof() == 4 */
        // "enter": __DIR__"road3",
         "west": __DIR__"daojudian",
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

