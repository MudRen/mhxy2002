// budd_staff.c
//by tianlin 2001/5/1

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIY "�������" NOR, ({ "jingang chanzhang", "staff" , "chanzhang" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǲ����ʦ���������,����������ʮ��������ɵ�.\n");
		set("value", 10000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N���˺ô�ľ�������������̡�\n\n" NOR);
		set("unwield_msg", HIY "\n$N�������еĽ�����ȣ�����������.\n\n" NOR);

	}

	init_staff(80);
	setup();
}
