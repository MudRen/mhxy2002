//link

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("������",({ "panzi","zang panzi" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ������������ӡ�\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(4);
	setup();
}
