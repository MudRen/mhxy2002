//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name(HIR"��"HIC"��"HIW"��"HIG"ذ"NOR, ({"nielong bi", "hanbi", "dagger","bi" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ϡ��֮����\n");
		set("value", 50);
		set("no_sell",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
              set("rumor_msg",1);
              set("is_monitored", 1);
		set("material", "steel");
	}
	init_dagger(50+random(50));
	set("wield_msg", YEL"$N"NOR+YEL"�ӻ�������һ��$n"NOR+YEL"�������С�\n");
	set("unwield_msg", YEL"$N"NOR+YEL"�����е�$n"NOR+YEL"���뻳�С�\n");
	setup();
}
