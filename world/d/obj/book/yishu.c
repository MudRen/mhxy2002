//Cracked by Roath
//chunyang.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"����٢ҽ�顿"NOR, ({"huatuo yishu","yishu","book", "shu"}));
	set_weight(1000);
	if( clonep() ) 
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ��С���ӡ��������ɷ���Ĵ��֡���٢ҽ�顿�»���һ��С�֣���٢����\n");
		set("material", "paper");
		set("value", 1000);
		set("skill", ([
			"name": "medical",
			"dx_required": 1000,
			"sen_cost": 40,
			"difficulty": 30,
			"max_skill": 180,
		]) );
	}
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
 //   if(!this_object()) return;
//    if(!who) return;
//              if(this_player()->query("get")=="dan")
  CHANNEL_D->do_channel(this_object(), "rumor", 
	    this_player()->name()+"��"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"�õ��˴�˵�е�"NOR+name()+HIM"��\n");
}
void init()
{ 
	add_action("do_eat", "eat");
       call_out("self_dest",1200+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}



