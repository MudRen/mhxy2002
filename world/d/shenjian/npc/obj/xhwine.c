// LLY@FYSY // waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ƺ�", ({ "wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ƺ�����װ�ܶ�ľơ�\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 30);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "�ӻ���",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}
 