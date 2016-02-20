// unbrella by LitChi

#include <ansi.h>
#include <weapon.h>

inherit UMBRELLA;

void create()
{
	set_name(HIR"�ռ���ɡ"NOR, ({ "umbrella", "san" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�����ǿ��ɡ��\n");
		set("value", 90000);
		set("material", "crimsonsteel");
	}
	init_umbrella(200);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ����$n���������С�\n");
	set("unwield_msg", "$N�����е�$n�������\n");

// The setup() is required.

	setup();
}
