//chanshen.c by yushu 2001.1
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
       string msg;
       int delay;
    if( !target ) target = offensive_target(me);
    if( !target
       ||       !target->is_character()
       ||       !me->is_fighting(target) )
         return notify_fail("�㲻��ս���У�����ʹ�á���������\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");

       if (me->query_skill_mapped("force")!="tonsillit")
                return notify_fail("�������������������������ʹ�á�\n");
	if((int)me->query("max_force") < 500)
		return notify_fail("�������������\n");
	if((int)me->query("sen") < 250)
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "�Ѿ���������ˣ��㻹�������\n");

        msg = HIY "$N�з�һ�䣬һ�С�������ֱ˦��$n��\n"NOR;
	me->add("sen", -100);
	me->add("force", -200);
if( random(me->query("combat_exp")) > random((int)target->query("combat_exp"))*3/4) {
                msg += HIR"���$n�������ˣ�\n" NOR;
                delay=(int)me->query_skill("hellfire-whip", 1) /5;
if ( delay > 8 ) delay = 8;
if ( delay < 3  ) delay = 3;
                target->start_busy(delay);
                me->start_busy(1);
        } else {
                msg += HIW"����$n������$N��ͼ�㿪�ˡ�\n" NOR;
                
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}

