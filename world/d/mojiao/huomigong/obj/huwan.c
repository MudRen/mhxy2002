//modify by ken 2001.7.2
#include <ansi.h>

inherit ITEM;

int do_eat(string);
int do_tun(string);
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
        add_action("do_tun", "tun");
}

void create()
{
        set_name(HIC "����" NOR, ({"hu wan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ħ���ı�֮���Ļ��衣\n");
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
        if(victim->query("family/family_name") != "ħ��")
                return notify_fail("���䲻��ħ�����ˣ�����Ҳ����(tun)��\n");

        abc = (int)victim->query("HY_eat");
            if ( abc > 2 ) 
     {
     message_vision(HIR "$N����һ�Ż��裬ֻ���ø��ڴ���һ��˺���ѷΰ�ľ�ʹ.......\n" NOR, victim); 
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
        victim->add("HY_eat",1);
        victim->skill_death_recover();
        victim->save();
        message_vision(HIG "\n$N����һ�����裬��Ŀ��������\n\n" NOR, victim);

        destruct(this_object());
        return 1;
      }
}
int do_tun(string arg)
{
        object victim = this_player();
        int aa;


        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        
        aa = (int)victim->query("HY_tun");
            if ( aa > 1 ) 
     {
     message_vision(HIR "$N����һ�Ż��裬������ǰ����ֱð��������һ������ֱ�嶥��.......\n" NOR, victim); 
       victim->unconcious();
       victim->die();
       victim->set_temp("death_msg","�𶾷������ˡ�\n");

       destruct(this_object());
      }
    else
    {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        victim->add("max_mana",33);
        victim->add("max_force",33);
        victim->add("force",3333);
        victim->add("mana",3333);
        victim->add("HY_tun",1);
//      victim->skill_death_recover();
        victim->save();
        message_vision(HIG "\n$N����һ�����裬��Ŀ��������\n\n" NOR, victim);

        destruct(this_object());
        return 1;
      }
}
