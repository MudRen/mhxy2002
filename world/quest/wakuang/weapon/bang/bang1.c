#include <weapon.h>
inherit STICK;

void create()
{
        set_name("ľ��", ({ "mubang", "bang", "stick" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", "����һ����ͨ��ľ����\n");
        set("value", 0);
        set("material", "steel");
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
}
        init_stick(10);
        setup();
}
