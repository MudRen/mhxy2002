#include <ansi.h>

int exert(object me, object target)
{

        if ( !target
      ||      !userp(target)
      ||      target->is_corpse()
      ||      target==me)
                return notify_fail("������˭����鶾��\n");
        if (!target->query_condition("xiangsi"))
        return notify_fail("û���鶾Ϲ��ʲô�ң�\n");
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n");

        if( (int)me->query("force") - (int)me->query("max_force") <  800 )
                return notify_fail("�������������\n");

    if ( (int)me->query_skill("force") < 120 || (int)me->query_skill("guangming-force",1)<120)
                return notify_fail("����ڹ���Ϊ���������˽���鶾��\n");
        
        message_vision(
                HIG "$N����˵��:�ຣ����,���˵ĵط�����������,�������鰮��,��ֻ�ǳ������롣\n\n"NOR,
                me, target );
    if (random(me->query_skill("guangming-force", 1)-20)>50){
                target->apply_condition("xiangsi",0);
                message_vision(
                HIR "$N������ֱ���ĸ�,$n����һ˿�м�,һ˿�������˹�ȥ��\n"NOR,
                me, target );
                target->unconcious();    }
        else {
                message_vision(
                HIW "$NͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ������\n"NOR,
                 me, target );
        }       
 
        target->receive_cuiring("kee", 100 + (int)me->query_skill("force")/2 );
        me->add("force", -600);
        me->set("force_factor", 0);
        return 1;
}
