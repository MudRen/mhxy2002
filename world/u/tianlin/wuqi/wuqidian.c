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
   [1;35m( [1;32m1[1;35m)[0m   [1;31m��ħ[1;36m��[1;31mս��[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m2[1;35m)[0m   [1;36m� [1;37m�� [1;32m��[0m      0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m3[1;35m)[0m   [1;32m��[1;37m ѩ[1;36m ��[1;31m ��[0m   0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m4[1;35m)[0m   [1;31m��[1;36m��[1;37m��[1;32mذ[0m      0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m5[1;35m)[0m   [1;31m����[1;33m��[0m        0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m6[1;35m)[0m   [1;34m����[1;33m����[1;32m��[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m7[1;35m)[0m   [1;37m�Źǿ�ɽ��[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m8[1;35m)[0m   [1;34m����[1;31m����[1;33m�[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m9[1;35m)[0m   [1;35m��ת[1;33m����[1;36m��[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m10[1;35m)[0m  [37m����[33m����ǹ[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m11[1;35m)[0m  [1;37m������[1;33m����[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m12[1;35m)[0m  [37m���Ǻ��⽣[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m13[1;35m)[0m  [1;31mѪ�������[0m    0       0       ���        0      [36m200[33m��[1;33m�ƽ�
   [1;35m( [1;32m14[1;35m)[0m  [1;35m��[1;36m��[1;33m��[1;37m��[0m      0       0       ���        0      [36m200[33m��[1;33m�ƽ�
[1;41m                                                                           [m
LONG);

  set("exits", ([ /* sizeof() == 4 */
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
        int afford,price;
        if(me->is_busy())
                return notify_fail(CYN"��������æ���ء�\n"NOR);
        switch(arg)
        {
                case "1":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/axe");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIR"��ħ"HIC"��"HIR"ս��"NOR"��\n");
                break;
                }
                
                case "2":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/bang");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIC"� "HIW"��"HIG" ��"NOR"��\n");
                break;
                }

                case "3":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/blade");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIG"�� "HIW"ѩ "HIC"�� "HIR"��"NOR"��\n");
                break;
                }
                case "4":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/dagger");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIR"��"HIC"��"HIW"��"HIG"ذ"NOR"��\n");
                break;
                }
                case "5":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/feiyu");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIR"����"HIY"��"NOR"��\n");
                break;
                }
                case "6":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/fork");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIB"����"HIY"����"HIG"��"NOR"��\n");
                break;
                }
                case "7":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/hammer");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIW"�Źǿ�ɽ��"NOR"��\n");
                break;
                }
                case "8":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/mace");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIB "����"HIR"����"HIY"�" NOR"��\n");
                break;
                }
                case "9":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/rake");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIM"��ת"HIY"����"HIC"��"NOR"��\n");
                break;
                }
                case "10":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/spear");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"WHT "����"YEL"����ǹ" NOR"��\n");
                break;
                }
                case "11":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/staff");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIW "������"HIY"����" NOR"��\n");
                break;
                }
                case "12":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/sword");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"WHT "���Ǻ��⽣" NOR"��\n");
                break;
                }
                case "13":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/whip");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIR "Ѫ�������" NOR"��\n");
                break;
                }
                case "14":
                {
                if( !(afford=me->can_afford(2000000)) )  {
                write("�����Ǯ������\n");
                return 1;
                } 
                else if( afford == 2 )
                return 1;
                me->pay_money(2000000);
                obj = new ("/u/tianlin/wuqi/bingqi/yumao");
                obj->move(me);
                me->start_busy(4); 
                write("�������������һ��"HIM"��"HIC"��"HIY"��"HIW"��"NOR"��\n");
                break;
                }
        }
return 1;
}

