//lifecure.c ʥ����
//created by foc,02-7-01
//�ص�˵�������������ϵ�Ч�����޹���Ч������������Ч����

#include <ansi.h>

int exert(object me, object target)
{
    int effect;
    if((int)me->query_skill("segokee",1)<40)
    return notify_fail("���ʥ����������ǿ���޷������������á�\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("�����Ϊ������\n");
    if((int)me->query("max_force")<1000 || (int)me->query("force")<600)
    return notify_fail("���������������������\n");
    if( !target
        ||      !target->is_character()
        ||      target->is_corpse())
    return notify_fail("��Ҫ����˭��\n");
    if(target->is_fighting(me))
    return notify_fail("���������ˣ�������ó�����\n");
    else
    {
    effect=(int)me->query_skill("segokee",1)*2;
    message_vision(HIW "$N����������ȫ��ų���͵Ĺ�â�����ɫ��ʥ��������˴���ɫ��\n$N�����ַ����ؿڣ���ɫ������������������������\n" NOR,me);
    target->receive_curing("kee",effect*10);
    target->receive_curing("sen",effect*10);
    target->add("kee",effect*30);
    target->add("sen",effect*30);
    me->add("force",-100);
    me->start_busy(2);
    tell_object (target, "��е�����һ�����ɣ�˵�������������\n");
}
    return 1;
}
