#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"555"NOR, ({"555"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 20);
        }
        setup();
}

int init()
{
        add_action("do_eat", "chou");
}

int do_eat(string arg)
{
        object me = this_player();

        if(!id(arg)) return notify_fail("��Ҫ��\n");
        if( me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        message_vision("$N�ͳ�һֻ" + name() + "������������һ�ڣ���ˬ��\n", me);
        me->add("max_force",1);
        me->start_busy(2);
        call_out("des",1);
        return 1;
}

void des()
{
        destruct(this_object());
}
