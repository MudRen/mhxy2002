#include <ansi.h>

inherit ITEM;

int do_trap(object me);

void create()
{
        set_name("�����", ({ "mouse trap", "trap", "jia" }) );
        set_weight(10);
	 set("value", 50);
	 set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
        }
        setup();
}

void init()
{
	object me = this_player();

	if (me)
		call_out("do_trap", 1, me);
}

int do_trap(object me)
{
	if (present(me, environment(this_object()))) {
		message_vision(HIR"ֻ����ž����һ����$N�����ϵ�������Ӽ�ס�ˣ�\n"NOR, me);
                      me->add("kee",-1000);
                me->start_busy(5 + random(4));
	}
}
