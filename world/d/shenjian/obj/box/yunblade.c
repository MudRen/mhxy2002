// yunblade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(MAG"嫺�����"NOR, ({ "yunblade" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
	
		set("no_get",1);
		set("no_drop",1);	set("material", "iron");
		set("long", "����һ������ѩ���ĳ��������м�������Ѫ��������
������ƥ��ӳ��������\n");
		set("wield_msg", "ֻ�������һ����$n���ʷɳ�������Ծ��$N
���С�˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_blade(100);
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