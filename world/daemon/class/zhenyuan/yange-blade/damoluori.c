//by yushu@MHXY 2001
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
                return notify_fail("��Ҫ��˭ʩչ��һ�С���Į���ա���\n");

        if(!me->is_fighting())
                return notify_fail("����Į���ա�ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("yange-blade", 1) < 60)
                return notify_fail("��ġ���赶�������������죡\n");

        if((int)me->query_skill("taiyi", 1) < 60)
                return notify_fail("���̫���ɷ����𻹲�����ʹ����һ�л������ѣ�\n");
               
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("��Į���ձ��������Ԫ�񹦲���ʹ�á�\n");
          
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIR"\n$N����һ������������һת��һ�С���Į���ա�����������\n"NOR,me,target);

        me->set_temp("YGD_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("YGD_perform");
        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
             
              me->start_busy(3);
        return 1;
}


