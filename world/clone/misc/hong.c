

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void init()
{
        add_action("do_back", "back");
}
void create()
{
        set_name(HIR"���ź�"NOR, ({"back", "macru", "aomen hong"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�����ɣ���ջع飬�����Ǹ����Ɑ���ź졣��back��\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 15);
        }

      set("liquid", ([
                "type": "alcohol",
                "name": "�վ�",
                "remaining": 15,
                "drunk_supply": 6,
        ]));
}

int do_back()
{
        int fw;
        int force_limit, neili_limit, force_skill, add_skill, improve;
        object me = this_player();
        me->set("sen",me->query("max_sen"));
        me->set("eff_sen",me->query("max_gin"));
        me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("force",me->query("max_force"));
        me->add("max_force",10);
        me->add("max_mana",10);
   message_vision(HIR"$N���������һ�°Ѱ��ź���棬���м�����֣�\n"NOR,me);
        destruct(this_object());
        return 1;
}
