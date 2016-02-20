#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��������졹��\n");

        if(!me->is_fighting())
                return notify_fail("���������졹ֻ����ս����ʹ�ã�\n");
        if(me->query("family/family_name")!="���ƶ�")
                return notify_fail("��ǻ��Ƶ��ӣ��޷�ʹ�á��������졹��\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("���������졹������ϻ�ħ�ķ�����ʹ�á�\n");
                
if((int)me->query_skill("huomoforce",1) <100)
                return notify_fail("��Ļ�ħ�ķ����𻹲�����ʹ�������������졹��\n");
	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("dali-bang", 1) < 100)
                return notify_fail("��Ĵ����������𻹲�����ʹ����һ�л������ѣ�\n");

        if(me->query_temp("qt_busy")) 
               return notify_fail("����ù��������죬���µȻ����ð�..\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIY"\n$N���һ�������������������͵ļ����˴�������ɱ�־�ѧ���������졹!\n"NOR,me,target);

        me->set_temp("DLB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("DLB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("DLB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("DLB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("DLB_perform");

        target->receive_damage("kee",((int) me->query("str")*10));
        target->receive_wound("kee",((int) me->query("str")*10));


        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->set_temp("qt_busy",1);
        call_out("remove_effect",5+random(3),me);
        me->start_busy(2);
        return 1;
}


void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("qt_busy");
}