//flyhit.c ʥ�����ն
//created by foc,02-7-01
//�ص�˵���������������Լ��������У��Լ���ɣ�


#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int time;
    if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
    return notify_fail("���˭ʹ��ʥ�����ն��\n");
    if(!me->is_fighting())
    return notify_fail("�������ս����ʹ�����У������ǲ�������͵Ϯ�ġ�\n");
    if(!me->query_temp("keearmor"))
    return notify_fail("�����ڲ�û�д������ֶ��¼�����״̬��\n");
    if((int)me->query_skill("segokee",1)<60)
    return notify_fail("���ʥ������ûǿ���㹻�ĳ̶ȡ�\n");
    if((int)me->query("combat_exp")<1600000)
    return notify_fail("����δ����ս����������ȽϺá�\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("�����Ϊ��������ʹ�����С�\n");
    else
{
    time=5-(int)me->query_skill("segokee",1)/50;
    message_vision(HIY "$N����ͻȻ����ˣ�ȫ�������ɱ�⡣���ϵ����ֶ���\n�Լ��⿪�ˣ���ȴ��δɢȥ��ǿ����������ϼ�����$N������֮�С�\n" NOR,me,target);
    me->add("force",-400);
    me->start_busy(time/2);
    call_out("flyhit", time, me, target);
}
    return 1;
}

int flyhit(object me, object target)
{
    int mysk, yoursk, myexp, yourexp, damage;
    if(!living(target) || target->is_corpse() || target->is_ghost())
    return notify_fail("�����ƺ�û��Ҫ�����С�\n");
    else
{
    mysk=(int)me->query_skill("segokee",1)*3 + (int)me->query_skill("force",1)+(int)me->query_skill("dodge",1);
    yoursk=(int)target->query_skill("force",1)+(int)target->query_skill("dodge",1);
    myexp=(int)me->query("combat_exp");
    yourexp=(int)target->query("combat_exp");
    damage=(mysk-yoursk/2)+(int)me->query_skill("segokee",1)*3+random(myexp/1000);
    message_vision(HIY "$N����ӰͻȻ���ģ������������ȴ��ø���ǿ�󣬳���ɱ�⡣\n$n���ɵĴ��˸��������Ȼ��$N�����ֶ��·�����ֵ�������\n�������ֶ��¸���$N�������ٳ���$n���˹�����\n" NOR,me,target);
   if(random(myexp)>=random(myexp/2+yourexp/3) || target->is_busy())
{
   message_vision(HIR "���$n������������Ȼ��$N����ô���˹�ȥ��\n$N�������𣬵���Ѫȴ��$n��ȫ����õ�廨һ��ʢ����Ϣ��\n" NOR,me,target);
   target->receive_damage("kee",damage);
   target->receive_damage("sen",damage);
   target->receive_wound("kee",damage);
   target->receive_wound("sen",damage);
   COMBAT_D->report_status(target,0);
   me->start_busy(random(3)+2);
   tell_object (target, "������ƺ��Լ��������������ȥ�������Լ�ȫ����\nð������Ѫ�����Ȼû��һ��ʹ�У�\n");
   tell_object (me, "���ֱ�����һ���������ƺ��Ѿ�����ˡ�\n");
}
   else
{
   message_vision(GRN "����$n�߾�շת��Ų֮���ܣ����ڱ��˿�ȥ��ȴ�Ѿ�����ͷ�󺹡�\n" NOR,me,target);
   me->start_busy(random(3)+3);
   tell_object (target, "�ۣ����գ���\n");
   tell_object (me, "���ֵ��������������´ο��ܾ�û��ô�����ˡ�\n");
}
}
}