//By tianlin@mhxy for 2001.9.30

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("̫������"BLINK+HIR"������"NOR"�־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("taiji-jian", 1) < 50 )
		return notify_fail("���̫������������죬�����á������־���\n");

	if( (int)me->query_skill("wudang-force", 1) < 60 )
		return notify_fail("����䵱�ڹ�������죬����ʹ�á������־���\n");

	extra = me->query_skill("taiji-jian",1) / 20;
	extra += me->query_skill("wudang-force",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	message_vision(HIR"$N�����̫���񹦣ݣ�ͬʱʹ��"HIY"��̫�������У�"NOR+HIR"��"NOR+BLINK+HIR"������"NOR+HIR"�־������е�"+ weapon->name() +" һ������һ�л���Ȧ���������Ļ���$n��"NOR,me,target);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  BLINK HIC "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	message_vision(HBRED HIW"$N�ý�����һ��Ȧ��һ��������������\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("force", -100);
	me->start_busy(3);
	return 1;
}

