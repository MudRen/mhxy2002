
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���¿���", ({ "bskl", "kele" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һƿ����ȥ�����İ��¿��֡�\n");
		set("unit", "ƿ");
		set("value", 400);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "cola",
		"name": "����",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}

