#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int delay, myhand;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("Ф�粻��ս���в���ʹ��!\n");

        myhand=(int)me->query_skill("iori-kuihua",1);
        if(myhand>160) myhand=160; // mon 12/7/98
        if(myhand<50) 
                return notify_fail("���[�ٷ�ʰ��ʽ.����]����������Ф��Ҳ���á�\n");

        delay=myhand/16;

        if( target->is_busy() )
                return notify_fail(target->name() + "�Ѿ�����һ���ƴ����ͷת����\n");

        msg = HIB "$N����ʽͻȻһ�䣬"BLINK""HIR"Ф��"NOR""HIB"..$Nһ�����,һֻ�ֻ�����˳�ȥ\n"NOR;
        //change totoal random to half random half ur own value to make the sucessrate more stable
        if( ((random(me->query("combat_exp"))*3/4 + (me->query("combat_exp")/4) > (int)target->query("combat_exp")*5/8 ))) {
                msg += RED"$n��һ���ƴ����ͷת�򣬱粻���ϱ�\n"NOR;
                msg += HIB"���$p��$P���˸����ֲ�����\n" NOR;
                target->start_busy(delay);
                me->start_busy(random(2));
        } else {
                msg += "����$p������$P����ͼ����û�б�ץס��\n" NOR;
                me->start_busy(2+random(1));
        }
        message_vision(msg, me, target);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        return 1;
}

