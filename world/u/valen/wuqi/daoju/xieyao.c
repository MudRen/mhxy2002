//xieyao.c

#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIC"кҩ"NOR, ({"xie yao", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����й���ӵ�ҩ��\n");
                      set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{

        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        me->set("food", 0);
        me->set("water", 0);
        me->add("sen", -50);
        tell_object(me,"��о��������е�����,ͻȻ������,����������³�һЩ����.\n");
 	if( me->query("combat_exp") < 200000 )
        {
        me -> unconcious();
        return 1;
        destruct(this_object());
         }
        destruct(this_object());
        return 1;
}
