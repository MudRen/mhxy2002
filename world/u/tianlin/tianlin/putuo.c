// putuo.c ������

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
                                     me->set_skill("buddhism",100);
                            me->set_skill("dodge",100);
                            me->set_skill("force",100);
                            me->set_skill("jienan-zhi",100);
                            me->set_skill("literate",100);
                            me->set_skill("lotusforce",100);
                            me->set_skill("lotusmove",100);
                            me->set_skill("lunhui-zhang",100);
                            me->set_skill("parry",100);
                            me->set_skill("spells",100);                            
                            me->set_skill("staff",100); 
                            me->set_skill("unarmed",100);

       destruct(this_object());
	return 1;
}

