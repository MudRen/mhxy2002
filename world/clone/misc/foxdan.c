//wuchangdan.c
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
        set_name(GRN"�ɵ�"NOR, ({"fox dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ڹ�Ĺ�Ļ�¯����ȡ���ɵ���\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{

        object me = this_player();

        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if (time() - me->query("last_eat/foxdan") < 600)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if(arg=="dan") 
                {
                        me->set("eff_gin",me->query("max_gin"));
                        me->set("gin",me->query("max_gin"));
                        me->set("eff_kee",me->query("max_kee"));
                        me->set("kee",me->query("max_kee"));
message_vision(HIR"$N���µ���һ�������ӵ������𣬶�ʱȫ�����������\n"NOR,me);
                }
                destruct(this_object());
                me->start_busy(2);
                me->set("last_eat/foxdan",time());
                return 1;
}

