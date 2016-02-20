//created by ken
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("����?û�ţ�\n");
        if( me->query("mana") < 1000 )
                return notify_fail("��ķ�������,�ܲ��ˣ�\n");
        if( me->query("max_mana") < 1000 )
                return notify_fail("��ķ��������ߣ����������ħ��\n");
        if( me->query("force") < 1000 )
                return notify_fail("����������㣬���������ħ��\n");
        if( me->query("max_force") < 1000 )
                return notify_fail("����������㣬���������ħ��\n");
        if( me->query("sen") <= 700 )
                return notify_fail("��ľ������㣬���Ǳ������ˣ�\n");
        if( me->is_ghost())
                return notify_fail("���˹����ʵ��ɣ�\n");     
        if((int) me->query_skill("tianmo",1) < 180)
                return notify_fail("�����ħ�󷨻��������������ǲ�������ˣ�");
        if( target )
                return notify_fail("��ֻ�ܶ��Լ����䣡\n");
        write("��Ҫ��������һ������ߣ�");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write("��ֹ���䡣\n");
                return;
        }

        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
        || !ob->query("max_force") || !ob->query("force")) {
                write("���޷����ܵ�����˵����� ....\n");
                write("��Ҫ���Ƕ�ȥ��");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("ս���в����ܣ�\n");
                return;
        } else if( me->query("max_mana") < 1000 ) {
                write("������������ˣ�\n");
                return;
        }
        me->add("force",-1000);
        me->add("mana", -1000);
        me->receive_damage("sen", 200);
        
        message_vision( MAG "$N���һ������ħ���ڣ�\n" NOR, me);
        if( random(me->query_skill("spells")) < (int)ob->query("mana") / 300 ) {
                write("��������Ч�������������������á�\n");
                return;
        }
        if( random(50) > 
        (int)(me->query_skill("tianmo",1))){
                write("��������Ч��������������̫����\n");
                return;
        }
        if(environment(ob)->query("no_fight")) {
              write("������ȥ���ˣ�\n");
              return;
        }
        if(environment(ob)->query("no_magic")) {
              write("�����㲻��ȥ��\n");
              return;
        }                message( "vision", MAG "\n��������һֻ���ְ�" + me->name() + "��ץ��Ȼ��Ͳ����ˣ�\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(10);
        message( "vision", HIY "\n����Ͽ���ͻȻ����һֻ���ƣ�һ�ѽ�"+me->name()+"����������\n\n" NOR,
                environment(ob), ({ me }) );
}
