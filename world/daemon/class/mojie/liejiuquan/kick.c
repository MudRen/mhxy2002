//kick.c �����ն��
//created by foc,25-08-01
//˵����һ����С���������е͡�

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
     int damage, myto, urto, mysk, ursk;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("��Ҫ��˭ʹ�á������ն�š���\n");
     if(!me->is_fighting(target))
     return notify_fail("�����������ս���С�\n");
     if(me->query_temp("kick_busy"))
     return notify_fail("�����ʹ�������ն�ţ���ȴ�е��������ġ�\n");
     if((int)me->query("kee")<300)
     return notify_fail("�������ڵ�״���������С�\n");
     if((int)me->query("force")<200 || (int)me->query("max_force")<900)
     return notify_fail("������������Է������С�\n");
     if((int)me->query_skill("unarmed",1)<80 || (int)me->query_skill("liejiuquan",1)<40)
     return notify_fail("�������ڵ�ȭ����Ϊ���ò�������\n");
     if(me->query_skill_mapped("force")!="spiritforce" && me->query_skill_mapped("force")!="segokee")
     return notify_fail("��ʹ�õ������ԡ�\n");
     if((int)me->query("combat_exp")<300000)
     return notify_fail("һ����ȥ�ɣ���ž����˶���ս����\n");
     if((int)me->query("daoxing")<100000)
     return notify_fail("�����Ϊ��������\n");
     else
{
mysk=(int)me->query_skill("unarmed",1)+(int)me->query_skill("liejiuquan",1)+(int)me->query_skill("force",1)+(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*5;

ursk=(int)target->query_skill("dodge",1)*3/2+(int)target->query_skill("parry",1)*3/2;
    myto=(int)me->query("combat_exp")+mysk;
    urto=(int)target->query("combat_exp")+ursk;
    damage=mysk-ursk+random(mysk-ursk/2)+random((int)me->query("combat_exp")/5000);
    if(damage<1) damage=1;
    if((int)me->query_skill("spiritforce",1)>0)
    message_vision(HIM "$N���һ����ǿ����Ϻ�ɫ�������̴�\n�����ͷų�����������$N���ҽ�֮�ϡ�\n" NOR,me,target);
    if((int)me->query_skill("segokee",1)>0)
    message_vision(HIY "$N��ȫ��ų����ɫ��ʥ������ǿ���\n���ܿ���$N���ҽ��Ͼۼ�������\n" NOR,me,target);
    message_vision(GRN "$N�ٿ�Ծ��ʹ�����������ȭ�ľ�����\n"+BLINK""+HIY"�����ն��"NOR"��$n���̸е����乥�Ƶ�ǿ��\n" NOR,me,target);
{
    me->add("force",-300);
    me->start_busy(1+random(2));
    me->set_temp("kick_busy",1);
    call_out("remove_effect",10+random(5),me);
    if(random(myto)>=random(myto/2+urto/2) || target->is_busy())
{
    message_vision(GRN "���$n������������$N�������˸����ţ�\n" NOR,me,target);
    target->receive_damage("kee",damage);
    target->receive_damage("sen",damage);
    target->receive_wound("kee",damage/2);
    target->receive_wound("sen",damage/2);
    COMBAT_D->report_status(target,0);
    COMBAT_D->report_sen_status(target);
}
    else message_vision(GRN "����$n�ܿ���$N�Ĺ�����\n" NOR,me,target);
}
}
    target->kill_ob(me);
    me->kill_ob(target);
    return 1;
}
void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("kick_busy");
}
