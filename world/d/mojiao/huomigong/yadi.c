inherit ROOM;
#include <ansi.h>
#include <command.h>

void create()
{
        set("short", "�µ�");
        set("long", @LONG

�������ǰ��һ���ҽ��������ڵ��ҽ���ͣ�������Ұ���
������һЩ��С�Ĺ�ľ����ľ�Ժ���һ���������Ƶ�Σ
��(clip)�������Ը߲����ʵĸо���
LONG
        );
        set("item_desc", ([
                "ϸɳ": "��׵�ɳ̲��¶��һ�Ǿɲ���\n",
                "Σ��": "�±���ͬ������һ���㣬�������ˣ������ݲ�����̧ͷ����\n����Լ�ɼ�������ͻ��һ���ɫ��ɽʯ��\n",
        ]) );
	set("outdoors","mojiao");
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}



int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || arg != "clip") {
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	me = this_player();
	mlvl = (int)me->query_skill("dodge");
	if(mlvl < 70) 
		message_vision(HIY "\n$N����������ȥ�����˲��������ɣ�ֻ�����ֽŷ������»�����ȥ��\n" NOR, me);
	else {
		message_vision(HIY "\n$NС�������������ȥ�������������������ڡ�\n" NOR, me);
		me->move(__DIR__"evil-tang");
	}
	return 1;
}

