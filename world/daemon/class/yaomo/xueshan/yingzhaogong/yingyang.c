// yingzhaogong.c ��Ұӥ��
// By tianlin 2001.5.1
#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

/*	if((int)me->query_str() < 30)
		return notify_fail("���������,����ʹ����Ұӥ�\n");
*/
	if((int)me->query_skill("ningxie-force",1) < 100)
		return notify_fail("�������Ѫ���Ĺ�������������ʹ����Ұӥ�\n");

	if((int)me->query_skill("yingzhaogong",1) < 100)
		return notify_fail("���ӥצ������Ϊ����,Ŀǰ������ʹ����Ұӥ�\n");

	if((int)me->query("force") < 800)
		return notify_fail("���������ڲ���, ����ʹ����Ұӥ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ�������!\n");

	msg = HIY "$Nʹ��ӥצ����������Ұӥ���˫צ���ץ��$n��ȫ��ҪѨ��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ) {
		msg += "���$p��$P���˸����ֲ�������ʱ�������ã�\n" NOR;
		target->start_busy( (int)me->query_skill("yingzhaogong",1) / 10 + 2);
		me->add("force", -150);
	} else {
		msg += HIG "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
