//modify by ken 2001.7.2
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣������ΰ�! \n");
                set("no_drop","��ô�õĶ������붪����ȥ����! \n");
                set("no_sell","������������������Ҳ������\n");
                set("no_give","��ȥ���ˣ�û����£�\n");
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY "������" NOR, ({"jiuzhuan jindan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ħ���ı�֮һ�Ļ�������\n");
                set("value", 100000);
        }

        set("is_monitored", 1);
        setup();
}

int do_eat(string arg)
{
        object victim = this_player();
        int abc;


        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
//        if(victim->query("family/family_name") != "ħ��")
//                return notify_fail("������Ǳ�ԣ�С�����˶���\n");

        abc = (int)victim->query("JZD_eat");
            if ( abc > 2 ) 
     {
     message_vision(HIR "$N����һ�Ż�������ֻ���ø��ڴ���һ��˺���ѷΰ�ľ�ʹ.......\n" NOR, victim); 
       victim->unconcious();
       destruct(this_object());
      }
    else
    {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        victim->add("max_mana",99);
        victim->add("max_force",99);
        victim->add("force",9999);
        victim->add("mana",9999);
        victim->add("JZD_eat",1);
        victim->skill_death_recover();
        victim->save();

        if( userp(victim) ) log_file("JZD_eat", sprintf("%s(%s) Got recovered on %s.\n",         victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIR "\n$N����һ����������ȫ��ð��һ�����⣬�����ֽ������١�\n\n" NOR, victim);

        destruct(this_object());
        return 1;
}
}
