//By tianlin@mhxy for 2001.12.5�����Ż�
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
        int extra1;
	object weapon;
        extra1 = me->query_skill("qingfeng-jian",1);
	if ( extra1 < 60) return notify_fail("��ģ����ϸ�����ὣ�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(""HIR"��"HIC"����һЦ"HIR"��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("sword") / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	message_vision(HBRED+HIW  "$N"HBRED+HIW"����"NOR+HBBLU+HIY+ weapon->name() +NOR+HBRED+HIW"�Ľ�â��$n"HBRED+HIW"ɢ�����������޵�ǳЦ������"NOR,me,target);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(1);
	return 1;
}
