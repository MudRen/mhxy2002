#include <weapon.h>
#include <ansi.h>

inherit SPEAR;
inherit F_UNIQUE;
void create()
{
        set_name("��Ѫǹ",({ "bixie qiang", "bixie", "spear", "qiang" }) );
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
                set("long", "���ǰѱ�Ѫǹ��ǹ����������͸������֮�⣬��������ޱȡ�\n");
                set("wield_msg", HIC "ֻ�������ˡ���һ�����ڹ����֣�$N��������µ�$n���ñ�ֱ��\n" NOR);
                set("unwield_msg", HIC "��Ѫǹ����һ������֮�⣬��ৡ��ط������䡣\n" NOR);
                set("unequip_msg", HIC "��Ѫǹ����һ������֮�⣬��ৡ��ط������䡣\n" NOR);
}
        init_spear(60);
        setup();
}
