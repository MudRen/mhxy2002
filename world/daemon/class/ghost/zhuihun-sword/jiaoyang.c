// By tianlin 2001.5.1
//�Ҿ��ż���0Ҳ̫����,������enforce 50����ͦ��.(snicker)
#include <ansi.h>

inherit SSERVER;
string msg;

int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("��"HIR"��"HIC"��"HIM"��"HIY"��"NOR"��ֻ����ս����ʹ�á�\n");

        if( me->query("force_factor") > 50)
                return notify_fail("��"HIR"��"HIC"��"HIM"��"HIY"��"NOR"�������������������,��enforce 50���ڡ�\n");
   
        if( (int)me->query_skill("tonsillit", 1) < 120 )
                return notify_fail("��ġ������ķ���������죬����ʹ�á������ƻ𡹡�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��"HIR"��"HIC"��"HIM"��"HIY"��"NOR"�������ý�����ʩչ��\n");
	if(me->query_temp("last_jiaoyang")+5>time())
		return notify_fail("��ո�ʹ����"HIR"��"HIC"��"HIM"��"HIY"��"NOR"��,��ЪһЪ�ɡ�\n");

        if( (int)me->query_skill("zhuihun-sword", 1) < 120 )
                return notify_fail("��ġ�׷�꽣��������죬����ʹ�á������ƻ𡹡�\n");
        if( (int)me->query("force") < 1000  ) 
                return notify_fail("�������������\n");

        skill = me->query_skill("zhuihun-sword");
        msg =  HIY "$N��Хһ��,ʹ��"HIR"��׷�꽣��"NOR+HIY"�еľ�����"BLINK+HIR"��"HIC"��"HIM"��"HIY"��"NOR+HIY"����ħ�����$n�̳�"BLINK+HIC"��"NOR+HIY"����\n"NOR;
        message_vision(msg, me, target);

        me->add("force", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();

        msg = WHT"���ա�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = WHT"�����\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = MAG"�񶫡�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = MAG"�񷽡�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIG"�񽿡�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIG"������\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"���ơ�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"����\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);

        if( me->is_fighting() ) me->start_busy(0);
        me->set_temp("last_jiaoyang",time());
        return 1;
}
