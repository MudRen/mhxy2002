// gangjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("[1;32m��ĸ����ʯ[m", ({"diamon" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ǧ���Ѽ�����ĸ�̱�ʯ,�\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�Żᶵ�\n");
        }
        init_dagger(25,0);
        setup();
}
