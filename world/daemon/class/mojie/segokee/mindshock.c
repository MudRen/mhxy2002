//mindshock.c ʥ����ɱ��
//created by foc,02-7-01

#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int chance, mysk, yoursk, myexp, yourexp, damage, n;
    if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("���˭ʹ����ɱ����\n");
    if((int)me->query_skill("segokee",1)<30)
    return notify_fail("���ʥ������ûǿ�󵽿�������ز���\n");
    if((int)me->query("combat_exp")<1600000)
    return notify_fail("����δ����ս����������ȽϺá�\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("�����Ϊ��������ʹ�����С�\n");
    else
{
    mysk=(int)me->query_skill("segokee",1)*5+(int)me->query("force_factor")+(int)me->query_skill("force",1);
    yoursk=(int)target->query_skill("dodge",1)/2+(int)target->query_skill("force",1)*2+(int)target->query("apply/armor")/2;
    damage=(mysk-yoursk)+random(myexp/1000);
    if(damage<0 || damage=0) damage=1;
    myexp=(int)me->query("combat_exp");
    yourexp=(int)target->query("combat_exp")/2;
    chance=mysk/6+random(10);
    n=damage*chance;
    message_vision(HIY "$N΢һ����ȫ���ʥ�������̷����˱仯��\n$N˫�۷ų����ɫ�Ĺ⣬�������ϵ���ͻ��\n�ֳ����������߶�����������Ϣ����$nϮȥ��\n" NOR,me,target);
    me->add("force",-300);
    me->start_busy(random(3));
    if(random(myexp)>random(myexp/2+yourexp/2) || target->is_busy())
{
    message_vision(GRN "���$n�ؿ�����"+chinese_number(chance)+"��$N����ɱ�������ؿڵļ������ݣ����˲��ᣡ\n" NOR,me,target);
    target->receive_damage("kee",n);
    target->receive_wound("kee",n);
    COMBAT_D->report_status(target,0);
    tell_object (target, "��е��ؿ�һ���ʹ����ʱ����ʹ��������\n");
    target->start_busy(random(3));
    target->kill_ob(me);
    me->kill_ob(target);
}
    else
{
    message_vision(GRN "����$n�ƺ��Ѿ�������ʲô���Ծ�����Ȼ��ʹ���ض��˿�ȥ��\n" NOR,me,target);
    me->start_busy(1);
    message_vision(GRN "$n��$N��ȵ����������֣����ʲô�ƻ�����\n" NOR,me,target);
    target->kill_ob(me);
    me->kill_ob(target);
}
}
    return 1;
}
