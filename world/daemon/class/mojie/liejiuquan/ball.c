//ball.c ���ߺ���
//created by foc,25-08-01
//˵��������������������

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
     int damage, myto, urto, mysk, ursk, n;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("��Ҫ��˭ʹ�á����ߺ��򲨡���\n");
     if((int)me->query("kee")<200)
     return notify_fail("�������ڵ�״���������ų�̫����ƨ�ġ�\n");
     if((int)me->query("force")<300 || (int)me->query("max_force")<1400)
     return notify_fail("������������Է������С�\n");
     if((int)me->query_skill("unarmed",1)<110 || (int)me->query_skill("liejiuquan",1)<50)
     return notify_fail("�������ڵ�ȭ����Ϊ����������\n");
     if(me->query_skill_mapped("force")!="spiritforce"||me->query_skill_mapped("force")!="segokee")
     return notify_fail("��ʹ�õ������ԡ�\n");
     if((int)me->query("combat_exp")<200000)
     return notify_fail("һ����ȥ�ɣ���ž����˶���ս����\n");
     if((int)me->query("daoxing")<200000)
     return notify_fail("�����Ϊ��������\n");
     else
{
     mysk=(int)me->query_skill("unarmed",1)+(int)me->query_skill("liejiuquan",1)+(int)me->query_skill("force",1)+(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*5;
ursk=(int)target->query_skill("dodge",1)*3/2+(int)target->query_skill("parry",1)*3/2;
    myto=(int)me->query("combat_exp")+mysk;
    urto=(int)target->query("combat_exp")+ursk;
    damage=mysk-ursk+random(mysk-ursk/2);
    if(damage<1) damage=1;
    if((string)me->query_mapped_skill("force")=="spiritforce")
    message_vision(HIM "$N������һ̧��ǿ����Ϻ�ɫ�������������оۼ���һ��������\n" NOR,me,target);
    if((string)me->query_mapped_skill("force")=="segokee")
    message_vision(HIY "$N��ȫ��ų����ɫ��ʥ������ǿ������ܿ���\n$N���������оۼ���һ����â�����������\n" NOR,me,target);
    message_vision(HIW "ֻ��$N�����������ٿ�һ�ף����ŷ�����ϣ��ҽ�����\n�����֮���������ϡ����������ת�������������ǰ�Ϯ��$n��\n" NOR,me,target);
{
    me->add("force",-300);
    me->set_temp("ball_busy",1);
    me->start_busy(3);
    if(random(myto)>=random(myto/2+urto/2) || target->is_busy())
{
    message_vision(GRN "���$n����������������������С�\n�����˺�ɶ������ڿ�������һ��������"+BLINK""+HIR"Ѫ��"NOR"��\n" NOR,me,target);
    target->receive_damage("kee",damage);
    target->receive_damage("sen",damage); 
    target->receive_wound("kee",damage/3*2);
    target->receive_wound("sen",damage/3*2);
    COMBAT_D->report_status(target,0);
    COMBAT_D->report_sen_status(target);
    me->start_busy(2+random(2));
}
    else
{
    n=(int)target->query("kar")*2;
    if(n<50 && n>=40 )
    message_vision(GRN "����$n����һ�������˹�ȥ��û���ܵ��κ��˺���\n" NOR,me,target);
    if(n<40 && n>=30 )
{
    message_vision(GRN "����$n�鼱���ǣ�ʹ�������ţ�����\n���˿�ȥ��������������һ���С�ˡ�\n" NOR,me,target);
    target->receive_damage("kee",100);
    target->receive_wound("kee",5);
}
    if(n<30 && n>=10)
{
    message_vision(GRN "����$nƴ��ȫ������$N��������������һ�ߡ�\n" NOR,me,target);
    me->command("kao");
    target->add("force",-50);
}
    else
{
    message_vision(GRN "����$nƴ�����������㵲ס����һ����\nҲû�����ˣ�����ȫ��ȴ��һƬ��ʹ��\n" NOR,me,target);
    target->start_busy(2);
}
}
}
}
    return 1;
}

void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("ball_busy");
}
