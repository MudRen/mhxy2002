// umbrella.c

#include <ansi.h>;
#include <weapon.h>

inherit UMBRELLA;

void create()
{
        set_name(HIR"������ɡ"NOR, ({"umbrella", "san"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
		set("value", 500);
		set("material", "iron");
                set("long", HIW"����һ��������ͬС�ɵ���ɡ��NOR,\n");
                set("wield_msg", "$N���һ�����λε�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���������ɡ�ס�\n");
	}
        init_umbrella(80);
	setup();
}
