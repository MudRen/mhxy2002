
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("[1;32;5;43m��̫��[m", ({ "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ƴɵĸֽ������ֽ��ڽ���֮��ǳ����С�\
n");
                set("value", 2000000);
                set("material", "gold");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(700);
        setup();
}
