#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("��ǹ", ({ "long spear", "spear", "qiang" }));
        set_weight(5000);
     if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�ľ���ǹ��\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ر���\n");
}
        init_spear(10);
        setup();
}
