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
                return notify_fail("��Ҫ��˭ʩչ��һ�С�"CYN"��"YEL"��"HIM"����"NOR"����\n");

        if(!me->is_fighting())
                return notify_fail("��"CYN"��"YEL"��"HIM"����"NOR"��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

          if(me->query("family/family_name") != "����˧��" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query_skill("skyriver-rake", 1) < 80)
                return notify_fail("�������ٷ����𻹲�����ʹ������һ�У�\n");
       message_vision(CYN"\n$N������һ��,ͻȻʹ������Ǿ���<<<"CYN"��"YEL"��"HIM"����"NOR+CYN">>>��\n"NOR,me,target);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 3);
       message_vision(MAG"\n$N˫��һ�������а��Ӽ�Ӳ�ޱȣ��޼᲻�ݣ��˺�����Ϊ���¡�\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       
	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 4);
       message_vision(HIC"\n$N��Ȼ�������ðң���ɨ��·��һ��"HIG"����ɨǧ����"NOR+HIC"�����������޵� !\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
       
	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 6);
       message_vision(HIW"\n$N˫�ָ߾ٰ��ӣ��Ӹ߿����£��˺���������˺��¡�\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 9);
       message_vision(HIY"\n$N���㶯�����ȣ��û���ǿ���ƣ�һ�б�һ������, �Է��Ѿ�������ͷ�����͡�\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));       

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 10);//һ�б�һ������.
       message_vision(HIM"\n$N���һ��˵��: "RED"����������"NOR+HIM" �԰�����һ����˵��\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}

