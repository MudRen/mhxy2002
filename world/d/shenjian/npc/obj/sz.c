// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��֦", ({ "shuzhi", "zhi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"����һ����֦��С������ϲ��������������������֡�\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(15);
        setup();
}
 
