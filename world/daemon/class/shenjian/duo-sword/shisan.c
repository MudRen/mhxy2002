// LLY@FYSY
//By tianlin@mhxy for 2001.11.27.�޸ĳ�XYJ�汾
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt;
	object weapon;
	extra = me->query_skill("duo-sword",1);
	if ( extra < 110) return notify_fail("��Ķ��������������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ҫ��˭ʹ����һ��"HIY"((����ʮ��ʽ))��\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <110)
return notify_fail("����ķ����������죡\n");
	 msg = HIR  "$N���赭д���ӳ����⣬һ˲�����ʹ������ʮ��ʽ�����е�"+ weapon->name()+  NOR+HIR"��������.\n�����Ǻ�ˮ�����$n�̳�,��ؼ��ݷ������ɱ����\n\n" NOR;
        message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/10);
	me->add_temp("apply/damage",extra/10);
	lmt = random(13)+1;
	for(i=1;i<=lmt;i++)
	{
message_vision(BLINK HIR"------>>>>>>��"HIC+chinese_number(i)+HIR"��<<<<<<------"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        msg = CYN "\n\n$N�ĵ�"+chinese_number(i-1)+"���̳������еı仯���������������ˮ�ѵ���ͷ������Ҳ���ˣ�������\n\n"NOR;
	message_vision(msg,me,target);
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
	me->start_busy(2);
	return 1;
}
