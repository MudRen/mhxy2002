
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("���׷�", ({ "rice", "�׷�"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ִ���Ӳ���ǻ��е㷢�����׷���\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
	setup();
}

int finish_eat()
{
	set_name("���ϴ�", ({ "bag" }) );
	set_weight(50);
	set("long", "һֻ�ù��Ĳ��ɽ������ϴ���\n");
	return 1;
}
