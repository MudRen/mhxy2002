inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIB"ˮ��"NOR, ({ "pool" , "ˮ��"}) );
	set_weight(500);
	set_max_encumbrance(200000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������۰�Ĺ�â��ˮ�أ����ԣ�����\n");
		set("value", 1);
	}
}
int is_container() { return 1; }
