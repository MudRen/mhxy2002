// huanyang.c ������

#include <ansi.h>

inherit ITEM;

int do_eat(string);
create();
/*
create()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô����Ļ���������������! \n");
        }
                                              
        add_action("do_eat", "eat");
}
*/
void create()
{
        set_name(HIG "������" NOR, ({"huanyang dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������������˵����������֮Ч��\n");
                set("value", 100000);
        }

        set("is_monitored", 1);
  
     setup();
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
            who->query("name")+"��"HIW+
                        MISC_D->find_place(environment(this_player()))+HIM"�õ��˴�˵�е�"+name()+HIM"��\n");
}

void init()
{        add_action("do_eat", "eat");
    call_out("self_dest",1+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}


int do_eat(string arg)
{
        object victim = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if(this_player()->query("huanyang") < 0 )
{
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                victim->add("potential",
                        (int)victim->query("potential") - (int)victim->query("learned_points") );
        victim->skill_death_recover();

   victim->add("daoxing",victim->query("death/dx_loss"));
        victim->add("huanyang",1);
             victim->save();

        if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIG "\n$N����һ����������Ӳ�ǴӰ��޳��������ѣ������һ��С����\n\n" NOR, victim);

 //       destruct(this_object());
//        return 0;
}else{      message_vision(HIG "\n$N����һ����������Ӳ�ǴӰ��޳��������ѣ������һ��С������ϧ�Ǽٵġ�\n\n" NOR, victim);
}
        destruct(this_object());
        return 1;

}

