//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name(HIR"��ħ"HIC"��"HIR"ս��"NOR, ({ "zhan axe", "axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
              set("rumor_msg",1);
		set("no_sell",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
              set("is_monitored", 1);
		set("material", "steel");
		set("long", "����һ�ѳ��ص�"HIC"��ħ"HIC"��"HIC"ս��"NOR"�����������ǳ�˳�֡�\n");
		set("value", 500);
		set("wield_msg", "$N�ó�һ��$n��������������ֱ˵��Ȼ���񸫰���\n");
		set("unwield_msg", "$N�������е�$n,���������˿�����\n");
	}
	init_axe(100+random(100), TWO_HANDED);
	setup();
}
