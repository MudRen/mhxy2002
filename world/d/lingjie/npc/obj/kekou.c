

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ɿڿ���", ({ "cocacola", "kele" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һƿ��һ���ɿڵĿɿڿ��֡�\n");
		set("unit", "ƿ");
		set("value", 400);
		set("max_liquid", 15);
	}

		set("liquid", ([
		"type": "cola",
		"name": "����",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}

