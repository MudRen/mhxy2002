//By tianlin@mhxy for 2002.1.17

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int cast(object me, object target)
{
        int skill;
// if( target != me ) return 
//  notify_fail("��ֻ�ܽ�����������������Լ������ϡ�\n");
        if( (int)me->query("mana") < 2*(int)me->query_skill("buddhism"))
        return notify_fail("��ķ��������ˣ�\n");
        if( (int)me->query_temp("daoqian") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query("sen") < 50 )
        return notify_fail("��ľ����޷����У�\n");
        skill = (int) me->query_skill("buddhism",1);
        if(skill < 50) return notify_fail("��Ĵ�˷𷨵ȼ�������\n");
        skill = random(skill)+skill;
        me->add("mana", -100);
        message_vision( HIC"\n$N"NOR+HIC"΢һ���񣬱���ó�һ���������ɫ�������֡�\n" NOR, me);
        me->add_temp("apply/dodge", skill);
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,skill :), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("apply/dodge", - amount);
        me->delete_temp("daoqian");
   message_vision(HIB"$N"NOR+HIB"���İ���������ȥ�ˡ�\n"NOR,me);
}
