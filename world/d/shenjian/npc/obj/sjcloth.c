// LLY@FYSY 
// cloth.c
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
         set_name("��������", ({ "sjcloth"}) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "������ɽׯ�е�λ����֮�˲��ܴ���������,����������˵���ڽ����еĵ�λ֮��ߡ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 40);
	}
	setup();
}
