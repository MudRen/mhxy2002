// hell.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "������" NOR, ({ "wan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�������ҩ�裬��˵��������skills��\n");
                set("value", 0);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
       
                tell_object(me, HIG "���skills�Ѿ������ˣ�"
                            "����jifa�����skills��Ȼ��������ʦҪdan��ף�����п��֣�\n" NOR);
                            me->set_skill("dodge",100);
                            me->set_skill("force",100);
                            me->set_skill("ghost-steps",100);
                            me->set_skill("gouhunshu",100);
                            me->set_skill("hellfire-whip",100);
                            me->set_skill("jinghun-zhang",100);
                            me->set_skill("kusang-bang",100);
                            me->set_skill("spells",100);
                            me->set_skill("unarmed",100);
                            me->set_skill("literate",100);                            
                            me->set_skill("parry",100); 
                            me->set_skill("tonsillit",100);
                             me->set_skill("zhuihun-sword",100);
                            me->set_skill("stick",100);
                            me->set_skill("zhuihun-sword",100);
                            me->set_skill("whip",120);
                                                 me->set_skill("sword",100);

       destruct(this_object());
	return 1;
}

