// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("ϴ�õ�����", ({ "panzi"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ��ϴ�õ����ӡ�\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(3);
	setup();
}
