#include <weapon.h>

inherit STICK;
inherit F_UNIQUE;
void create()
{
        set_name("���", ({ "da bang", "bang", "stick" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","һ�������\n");
        set("value", 0);
        set("unique", 1);
        set("rigidity", 1);
        set("sharpness", 1);
        set("material", "blacksteel");
        set("weapon_prop/dodge", 2);
        set("treasure",1);
        set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        set("unequip_msg", "$N�����е�$n�������䡣\n");
}
        init_stick(30);

        setup();
}