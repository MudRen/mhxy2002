// LLY@FYSY 
// cloth.c
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        string *order=({"��ɫ", "��ɫ", "��ɫ",
"��ɫ","��ɫ","��ɫ"});
        set_name((order[random(6)]) +"����", ({ "cloth", "jcloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "����һ��ɽׯ���˵��ճ���װ��\n");
		set("material", "cloth");
		set("armor_prop/armor", 30);
	}
	setup();
}
