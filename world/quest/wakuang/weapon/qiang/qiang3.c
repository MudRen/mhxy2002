#include <ansi.h>
#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name(HIG "��ǹ" NOR, ({ "gang qiang", "qiang", "spear"}) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰ��ֳ�����ĸ�ǹ��������������͸���׹⣬��������ޱȡ�\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("treasure",1);
                set("wield_msg", "ֻ�������ˡ���һ�����׹���֣�$N��������µ�$n���ñ�ֱ��\n");
                set("unequip_msg", "$N�����е�$n�������䡣\n");
}
        init_spear(40);
        setup();
}
