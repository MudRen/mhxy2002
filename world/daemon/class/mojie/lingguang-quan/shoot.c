//shoot.c �鵯
//created by foc,1-7-01
//�ص�˵����ɱ������ǿ�����ڣ�������ʹ�õ�������Ӧ�ľͶࡣ

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    int damage, myexp, urexp, mysk, ursk, chance;
    if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me )
    return notify_fail("��Ҫ��˭���鵯��\n");
    if( (int)me->query_skill("lingguang-quan",1)<80)
    return notify_fail("������ȭ��ʹ�û���������\n");
    if((int)me->query_skill("segokee",1)<10)
    return notify_fail("�����Ž������ۼ����������鵯������û�гɹ���\n");
    if((int)me->query_skill("spiritforce", 1) < 80 )
    return notify_fail("�����Ž������ۼ����������鵯������û�гɹ���\n");    
    if (me->query_skill_mapped("force") != "spiritforce"||
me->query_skill_mapped("force") != "segokee")
    return notify_fail("������ʹ�õ������ԡ�\n");
    if( (int)me->query("max_force") < 1200 || (int)me->query("kee")<300 || (int)me->query("force")<400 )
    return notify_fail("�鵯��Ҫ���ĺܶ������ģ������ڵ���������������\n");
    if( (int)me->query("kee") < 200) 
    return notify_fail("��ͻȻ�����Լ������������Ը������е����ģ����ǰ�ϧ�����ĺã�\n");
    if((int)me->query("combat_exp")<200000 || (int)me->query("daoxing")<200000)
    return notify_fail("�����Ϊ̫���ˡ�\n");
    else
{
    mysk=(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*10+(int)me->query_skill("unarmed",1)+(int)me->query_skill("dodge",1);
    ursk=(int)target->query_skill("parry",1)+(int)target->query_skill("dodge",1);
    myexp=(int)me->query("combat_exp");
    urexp=(int)target->query("combat_exp");
    damage=5*mysk-ursk+random(myexp/1000)-random(urexp/3000);
    me->add("force",-400);
    message_vision(HIW "$N������ʳָ�ϲ��Ͼۼ���������ǿ�������Ҳ��֮���С�\n���ţ�$N�������������֣����һ�������鵯����һ���޴��\n�������̱��������������$nֱ���ȥ��\n"  NOR,me,target);
{
    if(random(myexp)>random(myexp/2+urexp/2) || target->is_busy())
{
    if((int)target->query_skill("segokee",1)*6 > (int)me->query_skill("spiritforce",1))
{
    message_vision(HIY "���$nȫ��ų����ɫ��ʥ��������$N���鵯��\n����ȫ��ס�ˣ�û���ܵ�һ���˺���\n" NOR,me,target);
    target->add("force",-50);
    me->start_busy(2);
    tell_object (me, "���ֱȽ�ǿ�����������в�����Ч��\n");
    tell_object (target, "�û��ᣬ�ô˹�����\n");
    return notify_fail("������������ʽ��Ҳ�������õġ�\n");
}
    if(random((int)me->query_skill("spiritforce",1))<random((int)target->query_skill("spiritforce",1)/5*3) && !target->is_busy())
{
    message_vision(HIC "����$n���Լ�������������˫��֮�ϣ�ȫ����$N���鵯�����ˡ�\n" NOR,me,target);
    target->add("force",-200);
    me->start_busy(3);
    tell_object (target, "�û��ᣬ�ô˹�����\n");
    return notify_fail("���ֵ�����Ҳ����������Ҫ������ʽ������\n");
}
    else
{
    message_vision(GRN "$n���ڶ�����������$N���鵯���˸����ţ�\n��������һ������һ����ɿ�ȥ��\n");
    me->start_busy(3);
    target->receive_damage("kee",damage);
    target->receive_wound("kee",damage);
    COMBAT_D->report_status(target,0);
}
}
}
}
    return 1;
}
