
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name( HIR "���촵Ѫ" NOR, ({ "soulcrasher" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѽ�������һ������ɫѪ�۵ĳ�����\n");
		set("value", 1);
set("no_get",1);
		set("no_drop",1);
		set("material", "steel");
		set("rigidity", 20000);
		set("wield_msg", "$N����ɫ�����г��һ����һ������ɫѪ�۵�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�����������ɫ���ʡ�\n");
	}
	init_sword(40);
	setup();
}
void init()
{
	add_action("do_make","remake");
}
int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=new(__DIR__"box");
	obj->move(me);
	if(query("equipped")) unequip();
	tell_object(me,"�㽫���е�"+query("name")+"�ֲ𿪣���ɸ����ӡ�\n");
        destruct(this_object());
	return 1;
}          