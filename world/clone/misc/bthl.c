#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"���Ǻ�«"NOR, ({"bingtang hulu", "hulu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 20);
        }
        setup();
}

int init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();

        if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
        if( me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        message_vision("$N����һ��" + name() + "��\n", me);
        me->add("max_force",1);
        me->start_busy(2);
        call_out("des",1);
        return 1;
}

void des()
{
        destruct(this_object());
}
