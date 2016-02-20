#include <ansi.h>
#include <combat.h>

inherit SSERVER;
// inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
int skill;
  skill=(int)me->query_skill("baguazhen", 1);
        if( target != me )
        return notify_fail("��ֻ�ܽ��۰��Ż���������Լ������ϡ�\n");
        if( (int)me->query("force") < 300 ) 
        return notify_fail("�������������\n");
        if( (int)me->query_temp("huashen") )
        return notify_fail("���Ѿ���ʩչ�۰��Ż�����ˡ�\n");
	if( me->query_temp("weapon") )
		return notify_fail("��ֻ�з�����������ʹ����һ�С�\n");
        if( (int)me->query_skill("baguazhen", 1) < 40 ) 
		return notify_fail("��İ�����̫���ˣ���ʹ������һ�У�\n");
	if( (int)me->query_skill("wuxing-quan", 1) < 40 ) 
		return notify_fail("�������ȭ��̫���ˣ���ʹ������һ�У�\n");
        if( (int)me->query_skill("taiyi", 1) < 40 ) 
		return notify_fail("���̫���ɷ�̫���ˣ���ʹ������һ�У�\n");
        message_vision( HIR"$N��Хһ����ʹ���������еģ۰��Ż���ݣ���Ӱ�����䣬$N����Ʈ��������\n" NOR, me);
        me->add("force", -150);
        me->add_temp("apply/dodge", skill/5);
        me->add_temp("apply/attack", skill/5);
        me->add_temp("apply/defense", skill/5);
        me->set_temp("huashen", 1);
 me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :),skill/2);
        if( me->is_fighting() ) me->start_busy(4);
        return 1;
}
void remove_effect(object me, int amount)
{       amount=((int)me->query_skill("baguazhen", 1)/5);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/defense", - amount);
        me->delete_temp("huashen");
        tell_object(me, "��ģ۰��Ż����ʩչ��ϣ��������ˡ�\n");
return;
}
