#include <weapon.h>

inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name("����", ({ "tie zhang", "zhang", "staff" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�������������\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_msg", "$N��$n���ñ�ֱ��\n");
                set("unequip_msg", "$N�������е�$n��\n");
}
        init_staff(30);
        setup();
}