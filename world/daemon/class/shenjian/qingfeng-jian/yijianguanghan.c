// LLY@FYSY
//�ٷ�֮�ٵ������,�м�ǧ��Ҫʹ��
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("qingfeng-jian",1);
	if ( extra < 50) return notify_fail("��ģ����ϸ�����ὣ�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��һ���⺮��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	message_vision(HIB "$Nһ���̳������Ŷ�$n˵����������һ�������ڱ��У����ǲ��У��ٶ�ǧ�ٽ�Ҳ��û�õġ���\n" NOR,me,target);
	if(random((int)target->query("combat_exp")) > (int)me->query("combat_exp"))
	{
	msg = HIW "һ�������$n���ϴ�����\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);	
        
        me->start_busy(1);
        return 1;
        }
	else
        {
	msg = "$n���Ʋ��ã�����Ծ��...\n";
        message_vision(msg,me,target);
	me->start_busy(0);
        return 1;
	}
	return 1;
}
