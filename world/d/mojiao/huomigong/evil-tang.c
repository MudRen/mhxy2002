inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��֮��");
        set("long", @LONG

����һ��޴�ĺ�ɫɽʯ���������м����˳��������˾������ʯ���ϵ�
������ӡ(strike)��ÿ����ӡ�������߷���ǳ�������������Կ������ڵ�
�ҽ�����������ֻ�������������ƣ���֪���ж�߲Żᵽ����
LONG
        );
	set("outdoors","mojiao");
	setup();
}
void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}
int do_step(string arg)
{
	if(!arg || arg != "strike" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(HIY "$Nһ��������ӡ�ϣ�ֻ��������ģ�һ����\n�±����ѿ���һ���Ż���\n" NOR, this_player());
	set("exits/enter", __DIR__"hateroom");
        if(!this_player()->query("app/hate"))
        {
                this_player()->set("app/hate",1);
        }
	return 1;
}
int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("��Ҫ���ϻ�������\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$NС�������������ȥ�������������������ڡ�\n" NOR, me);
		message_vision(HIR "\n$N����һ��ûץ�ȣ���Σ���ϵ�����ȥ��\n" NOR, me);
		me->move(__DIR__"yadi");
                me->receive_wound("kee", 50);
                me->receive_wound("sen", 50);
		message_vision(HIR "\n$N��Σ���ϵ������������ص�ˤ�������ף�\n" NOR, me);
		me->unconcious();
	}
	else {
		message_vision(HIY "$NС�������������ȥ�������������������ڡ�" NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}
