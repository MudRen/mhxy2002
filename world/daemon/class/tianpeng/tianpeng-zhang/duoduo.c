//by tianlin 2001.7.30
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
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ͱ��ˡ���\n");

        if(!me->is_fighting())
                return notify_fail("�����ͱ��ˡ�ֻ����ս����ʹ�ã�\n");

          if(me->query("family/family_name") != "����˧��" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("kee") < 500 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

          if((int)me->query_skill("tianpeng-zhang", 1) < 100)
                  return notify_fail("��������Ʒ����𻹲�����ʹ�ò�������\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	if (! present(target,environment(me))) return 1;
        message_vision(HIC"$N˫����ȭ,������ǰ,һȭ����$n!\n\n"NOR,me, target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIC"$N����һȭ,�����һ����ĵط�,$n�����һ��!\n\n"NOR,me, target);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIC"$N����һȭ,��������ǰ��ȭ��ĵط�,$n����Ĺ��ڵ�!\n\n"NOR,me, target);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");
        target->start_busy(1);

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

