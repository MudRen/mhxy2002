// huanyang.c ������
//By tianlin@mhxy for 2002.1.24,����
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

                                              
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

int do_eat(string arg)
{
        object victim = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        if (this_player()->query("tianlin-hyd-30") >=1 )
        return notify_fail("�ٺٺٱ������ˣ�\n");
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
                        (int)victim->query("potential") - (int)victim->query("learned_points") );
	victim->skill_death_recover();

   victim->add("daoxing",victim->query("death/dx_loss"));
        victim->save();

	if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );
//By tianlin@mhxy for 2002.1.24
//������WIZȨ����player�κΰ��� 
       message_vision(HIG "\n$N����һ����������Ӳ�ǴӰ��޳��������ѣ������һ��С����\n\n" NOR, victim);

        this_player()->add("tianlin-hyd-30",1);
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
void init()
{
         if (!wizardp(this_player())) {
                 set("no_get", "�ٺ٣����ΰ�! \n");
                          set("no_give","��ô����ҩ�����������ˣ�\n");
                  set("no_drop","��ô����Ļ���������������! \n");
                 set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
    }

          add_action("do_eat", "eat");
    }
