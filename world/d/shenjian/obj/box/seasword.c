#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��Ԩ��", ({ "sea sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѿ����н����ĳ����������ûƽ������ɡ�\n");
		set("value", 1);
		set("material", "gold");
		set("no_get",1);
		set("no_drop",1);
	}

	init_sword(110);
	set("wield_msg", "$N���һ��$n�������У������Ͼ�������������֮����\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
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