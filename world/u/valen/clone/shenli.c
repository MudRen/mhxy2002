// shenliwan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "������" NOR, ({ "shenli wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ��԰԰�������裬��˵���˿�����ǿ������\n");
                set("value", 10000);
		set("unit", "��");
	}
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
                
tell_object(me, HIR "�����˫�۷����������ǳ���ð�Ƶ��������ˡ�\n" NOR);      
                me->add("str", 0);

       destruct(this_object());
	   return 1;
}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "���ڵ��ϣ������ˡ�\n");
    destruct(me);
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    this_player()->name()+"��"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"�õ��˴�˵�е�"+name()+HIM"��\n");
}
void init()
{ 
	add_action("do_eat", "eat");
       call_out("self_dest",1200000+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}

