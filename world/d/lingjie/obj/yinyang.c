// thin_sword.c

#include <weapon.h>

inherit UMBRELLA;

void create()
{
	set_name("����ɡ", ({ "yinyang san", "umbrella", "san" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 7000);
		set("material", "steel");
		set("long", "����һ������ɡ,��������;Ҫ�Լ�����ˡ�\n");
		set("wield_msg", "$N��ৡ���һ����$n���������С�\n");
		set("unequip_msg", "$N�����е�$n�������\n");
	}
	init_umbrella(70);
	setup();
}
