// yuchangjian.c 
//create by lixin
#include <weapon.h>
#include <ansi.h>
inherit STAFF;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"�ն�" NOR+HIC "��" NOR, ({"pudu zhang", "zhang", "staff"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ҷ�ȱ����ն�������\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", YEL "�����ӷ�һ����Ż�Ϊ�ն���������$N���$N�۳�������͵Ĺ�ã����ͬ���滯��\n" NOR);
                set("unwield_msg",YEL "$N���ϵķ�����������ˣ�$n"+YEL"Ҳ��Ϊһ����ãֱ��������\n");
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_staff(120);
        setup();
}
