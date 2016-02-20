// tianlei.c 

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ٽ�˫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("�����޽�,����ôʹ�ó��ٽ�˫����\n");

        if( (int)me->query_skill("liangyi-jian", 1) < 200 )
		return notify_fail("������ǽ�����δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("force", 1) < 600 )
		return notify_fail("�������������㣬����ʹ���ٽ�˫����\n");	

    msg = HIY "\n$N��Ȼ������һ������ �� ˫ ���������ϵĽ���糵������������һ�������潣�ƿ�쭶������Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") ){
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("sword", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("force", -600);
	return 1;
}
