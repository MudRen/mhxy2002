#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����", ({ "long zhang", "zhang", "staff" }));
        set_weight(5000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�ĳ��ȡ�\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
}
        init_staff(10);
        setup();
}
