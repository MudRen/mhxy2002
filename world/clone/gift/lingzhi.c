// lingzhi.c ������֥
//������lywin�ĵ�ԭ��,�������Ǽ���ѧ��Ǳ�ܵ��ҿ���һ��,��֥Ӧ���Ǽӷ�����,���������˵�Ķ�.(xixi)
//by tianlin 2001/5/1

#include <ansi.h>
inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIC"������֥"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ���������������֥����˵���˿ɵõ�һ���ķ�����Ϊ��\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("max_mana", 100);
	this_player()->add("mana",300);
	message_vision("$N����һ��������֥���������Լ��ķ�����ǿ����� !\n", this_player());
	destruct(this_object());
	return 1;
}

