#include <weapon.h>

inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name("����", ({ "tie fork", "cha", "fork" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ�����档\n");
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
        init_fork(30);
        setup();
}
