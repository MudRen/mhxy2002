//stick.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit STICK;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW "���"NOR +HIC"��"NOR, ({"tianji gun", "gun"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѷ�����ɫ��ã�Ķ̰�����˵��"+HIC"�������"NOR+"���ù���������\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIW"$N�ӱ���С�ļ������ó���һ���̹�����ϸһ�������Ǵ�˵�е�$n"+HIW"��\n"NOR);
                set("unwield_msg",HIW "$N����������һ��������������ֲ���$n��\n");
        }
        init_stick(120);
        setup();
}

