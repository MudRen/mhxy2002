//ziyandan.c ���׵�
//created by foc,25-08-01
//˵����������������������

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
     int damage, myto, urto, mysk, ursk, n1;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("��Ҫ��˭ʹ�á����׵�����\n");
     if((int)me->query("kee")<300)
     return notify_fail("�������ڵ�״���������ų�̫����ƨ�ġ�\n");
     if((int)me->query("force")<400 || (int)me->query("max_force")<1500)
     return notify_fail("������������Է������С�\n");
     if((int)me->query_skill("unarmed",1)<160 || (int)me->query_skill("liejiuquan",1)<100)
     return notify_fail("�������ڵ�ȭ����Ϊ���ò�������\n");
     if(me->query_skill_mapped("force")!="spiritforce" && me->query_skill_mapped("force")!="segokee")
     return notify_fail("��ʹ�õ������ԡ�\n");
     if((int)me->query("combat_exp")<800000)
     return notify_fail("һ����ȥ�ɣ���ž����˶���ս����\n");
     if((int)me->query("daoxing")<400000)
     return notify_fail("�����Ϊ��������\n");
     else
{
     mysk=(int)me->query_skill("unarmed",1)+(int)me->query_skill("liejiuquan",1)+(int)me->query_skill("force",1)+(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*5;

ursk=(int)target->query_skill("dodge",1)*3/2+(int)target->query_skill("parry",1)*3/2;
    myto=(int)me->query("combat_exp")+mysk;
    urto=(int)target->query("combat_exp")+ursk;
    damage=mysk-ursk/3*2+random(mysk-ursk/2)+random((int)me->query("combat_exp")/5000);
    if(damage<1) damage=1;
    if((int)me->query_skill("spiritforce",1)>0)
    message_vision(HIM "$N˫��һչ��ǿ����Ϻ�ɫ�������̴�����\n�ͷų������γ����������Ϻ�ɫ������\n" NOR,me,target);
    if((int)me->query_skill("segokee",1)>0)
    message_vision(HIY "$N��ȫ��ų����ɫ��ʥ������ǿ������ܿ���\n$N�����ܾۼ���������â�����������\n" NOR,me,target);
    message_vision(HIW "$N���һ�������е��������������������ҽ����������֮����\n����Щ���ϡ������������������ת�������������ǰ�����$n��\n" NOR,me,target);
{
    me->add("force",-600);
    me->start_busy(3+random(3));
    me->set_temp("ZY_busy",1);
    call_out("remove_effect",30+random(5),me);
    if(random(myto)>=random(myto/3+urto/2) || target->is_busy())
{
    n1=(int)me->query_skill("liejiuquan",1)*3+random((int)me->query_skill("liejiuquan",1));
    message_vision(GRN "���$n����������ȫ�����¹�����"+chinese_number(n1)+"��������\n�����˺�ɶ������ڿ�����������������"+BLINK""+HIR"Ѫ��"NOR"��\n" NOR,me,target);
    target->receive_damage("kee",damage*n1/5000);
    target->receive_damage("sen",damage*n1/5000); 
    target->receive_wound("kee",damage*n1/2000);
    target->receive_wound("sen",damage*n1/2000);
    COMBAT_D->report_status(target,0);
    COMBAT_D->report_sen_status(target);
}
    else message_vision(GRN "����$nһ����������շת��Ų֮�ܣ�������˹�ȥ��\n" NOR,me,target);
}
}
    message_vision(GRN "$nָ��$N���������������ҳ����У�\n" NOR,me,target);
    target->kill_ob(me);
    me->kill_ob(target);
    return 1;
}

void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("ZY_busy");
}
