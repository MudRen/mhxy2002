// ��Ӱ�����У���Ӱ���ٽ�
// design by lsj 2001.9.4
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int mep,tap,chance;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����Ӱ���ٽ�����\n");

        if(!me->is_fighting())
                return notify_fail("����Ӱ���ٽ���ֻ����ս����ʹ�ã�\n");

        if(me->query("family/family_name")!="��ʥ��")
                return notify_fail("������ʥ�ŵĲ����á���Ӱ���ٽ�����\n");
        if((int)me->query("max_force") < 800 )
                return notify_fail("���������Ϊ������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û�취����������\n");

        if((int)me->query_skill("mizongbu", 1) < 150)
                return notify_fail("������ٲ���Ϊ��������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("feisheng", 1) < 150)
                return notify_fail("��ķ����󷨵ȼ�����������ʹ����һ�У�\n");

        if((int)me->query_skill("wuying", 1) < 150)
                return notify_fail("�����Ӱ����Ϊ��������ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("sword", 1) < 150)
                return notify_fail("��Ļ���������Ϊ��������ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("��Ļ����Ṧ��Ϊ��������ʹ����һ�л������ѣ�\n");
        if (target->is_busy())
                return notify_fail("�Է��Ѿ���æ�����ˣ����ֽ����ɣ�\n");

        msg = HIG"\n$N�Ĳ�����Ȼ�ӿ죬��Ӱ���Ʈ�����������������û����߸���Ӱ����$n��\n"NOR;
        mep=(int)me->query("combat_exp")+(int)me->query("daoxing");
        tap=(int)target->query("combat_exp")+(int)target->query("daoxing");
        chance = (int)(random( mep + tap ) / tap * 100);
        if( chance > 35 ) 
        {
                target->start_busy(5);
                me->start_busy(1);
                msg += HIY"���$n"NOR+HIY"����Ӱ���˸���ͷת��\n"NOR;
        COMBAT_D->report_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        }
        else 
        {
                me->start_busy(2);
                msg += HIW"$n"NOR+HIW"ǿ�����񣬿�����������$N����ֻ���˳�����֮�⡣\n"NOR;
                msg += HIY"���$n"NOR+HIY"û�б���Ӱ���Ի�\n"NOR;
        }
        message_vision(msg, me, target);
        me->add("force",-150);
        me->add("sen",-50);
        return 1;
}
