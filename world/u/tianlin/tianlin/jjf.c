// jjf.c ������

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
                                     me->set_skill("bawang-qiang",100);
                            me->set_skill("changquan",100);
                            me->set_skill("dodge",100);
                            me->set_skill("force",100);
                            me->set_skill("lengquan-force",100);
                            me->set_skill("literate",100);
                            me->set_skill("mace",100);
                            me->set_skill("parry",100);
                            me->set_skill("spear",100);
                            me->set_skill("unarmed",100);                            
                            me->set_skill("wusi-mace",100); 
                             me->set_skill("yanxing-steps",100);
                            me->set_skill("sanban-axe", 100);
                            me->set_skill("axe",100);
                            me->set_skill("baguazhou",100);
                            me->set_skill("spells",100);
           
       destruct(this_object());
	return 1;
}


