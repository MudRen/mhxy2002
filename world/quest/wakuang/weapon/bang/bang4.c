#include <weapon.h>
#include <ansi.h>

inherit STICK;
inherit F_UNIQUE;
void create()
{
        set_name("�����",({ "biyu bang", "biyu", "stick", "bang" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value", 0);
        set("treasure",1);
        set("rigidity", 1);
        set("sharpness", 1);
        set("unique", 1);
        set("weapon_prop/dodge", -2);
        set("weapon_prop/parry", 1);        
        set("material", "steel");
        set("long", "���ǰѳ��صĴ����������������͸������֮�⡣\n");
        set("wield_msg", HIC "ֻ������������һ�����ڹ����֣�$N��������µ�$n���ñ�ֱ��\n" NOR);
        set("unwield_msg", HIC "���������һ������֮�⣬��ৡ��ط������䡣\n" NOR);
        set("unequip_msg", HIC "���������һ������֮�⣬��ৡ��ط������䡣\n" NOR);
}
        init_stick(60);
        setup();
}
