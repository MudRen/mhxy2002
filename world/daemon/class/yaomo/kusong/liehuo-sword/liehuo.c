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
                return notify_fail("��Ҫ��˭ʩչ��һ�С��һ��彣�С���\n");

        if(!me->is_fighting())
                return notify_fail("���һ��彣�С�ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

   if((int)me->query("force") < 500 )
     return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("liehuo-sword", 70) < 70)
                return notify_fail("����һ𽣷����𻹲�����ʹ����һ�л������ѣ�\n");
               
               if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("�һ��彣�б�����ϻ�ħ�ķ�����ʹ�á�\n");
          
              me->delete("env/brief_message");
            target->delete("env/brief_message");

message_vision(HIR"\nֻ�������һ�����,�һ�Ϊ�������,ֱ����$n��\n"NOR,me,target);

        me->set_temp("XFJ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("XFJ_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("XFJ_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("XFJ_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              
              me->set_temp("XFJ_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete_temp("XFJ_perform");

        me->receive_damage("sen", 100);
        me->add("force", -300);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}