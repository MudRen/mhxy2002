// blade.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
//inherit F_UNIQUE; 
void create()
{
	set_name(BLINK HIW "��˼" NOR+HIC "��" NOR, ({"xiangsi dao", "dao", "blade"}) );
	set_weight(1000);
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
		set("material", "steel");
		set("name_recognized", "��˼��");
		set("long", HIW "������˼���鵶��\n" NOR);
		set("wield_msg", HIC"$Nһ����Х��һ������ӿ�����������ʱ���ж���һ��$n��\n");
		set("unwield_msg", HIC "$N���ֽ�$n" NOR+HIC"�������У����Ҳ����������\n");
	}
	init_blade(120);
	setup();
}
