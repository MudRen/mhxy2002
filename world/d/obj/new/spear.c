// changqiang.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
//inherit F_UNIQUE; 

void create()
{
	set_name(BLINK HIW"����" NOR+HIC "ǹ" NOR, ({"jingyan spear", "spear"}) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
      set("value", 0);
      set("no_sell",1);
      set("no_give",1);
      set("no_drop",1);
      set("no_get",1);
set("is_monitored", 1);
		set("material", "wood");
		set("long", "�������С���õ�ǹ��\n");
		set("wield_msg", HIM "$N������ͻȻ����һ��$n"+HIM "�����������ɱ����\n" NOR);
set("unwield_msg", HIM "$N���е�$n"+HIM "������ʧ�ˣ�Ҳ��֪��ȥ�����ˡ�\n" NOR);
	}
	init_spear(120);
	setup();
}
