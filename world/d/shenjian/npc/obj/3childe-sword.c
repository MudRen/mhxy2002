// LLY@FYSY 
// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����ү�Ľ�", ({ "3childe-sword", "sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѻ���Ƥ��,�ƽ��̿ڵĳ���,���߳�����,������Լ��ʮ�������ҡ�\n");
		set("value", 76000);
		set("material", "steel");
	}
	init_sword(65);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "����һ����$N�����к�Ȼ����һ��$n��\n");
	set("unwield_msg", "$N���е�$n��һ�󽣹�֮����Ѳ�����\n");

// The setup() is required.

	setup();
}
