#include <weapon.h>
inherit FORK;

void create()
{
        set_name("ͭ��", ({ "tong fork", "fork", "cha" }));
        set_weight(5000);
        if (clonep())
set_default_object(__FILE__);
else {
                set("unit", "��");
                set("long", "����һ����ͨ��ͭ�档\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ر���\n");
}
        init_fork(10);
        setup();
}
