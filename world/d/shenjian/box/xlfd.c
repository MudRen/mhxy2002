
#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(RED "С��ɵ�" NOR, ({ "flying blade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ���˼����µ�С��ɵ�\n");
		set("unit", "��");
		set("value", 1000);
		set("base_unit", "��");
		set("base_weight", 1);
		set("no_get",1);
		set("no_drop",1);
		set("base_value", 1);
		set("wield_msg","$N��֪������ͻȻ��ק��һ�ѱ�����$n�������\n");
	}
	set_amount(1);
	init_throwing(100);
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