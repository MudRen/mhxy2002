#include <ansi.h>

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"��ҩ"NOR, ({"shenyao", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("base_unit", "��");
                set("long", "һ���Դ�������ҩ�裮\n");
                set("value", 10000);
				set("drug_type", "��ҩ");
        }
     set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
//        if ((int)this_player()->query("eff_sen") == 
//            (int)this_player()->query("max_sen"))
//                return notify_fail("�����ڲ���Ҫ����ҩ��\n")
        else {
                this_player()->receive_curing("sen", 9000);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˣ�\n",
this_player());
         add_amount(-1);
                return 1;
        }
}

