#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIG "��ͭ��" NOR, ({ "huangtong zhang", "zhang", "staff", "huangtong" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰѻƲӲӵ��ȡ�\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("treasure",1);
                set("wield_msg", "ֻ������������һ�����ƹ���֣�$N��$n��������¡�\n");
                set("unequip_msg", "$N�������е�$n��\n");
}
        init_staff(40);
        setup();
}