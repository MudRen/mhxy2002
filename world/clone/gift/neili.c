// lingzhi.c ǧ��ѩ��
//����(lywin)2000/4/22
//by tianlin 2001/5/1

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"����ѩ��"NOR, ({"xue lian", "lian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�������������ѩ������˵����֮��,����������������Ϊ��\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("max_force", 100);
	this_player()->add("eff_force", 100);
	message_vision("$N����һ������ѩ����ͻȻ��������������м������������ں��ֱײ��һ��Żָ����� !\n", this_player());
	destruct(this_object());
	return 1;
}

