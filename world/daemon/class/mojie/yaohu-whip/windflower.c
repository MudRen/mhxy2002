//windflower.c,�绪Բ����
//created by foc,30-6-01
//�ص�˵�����������빥������ߵ�pfm����������fear�Լ����ԡ�

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
     int damage, mywx, yourwx, yourskill, number, num, t;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("��Ҫ��˭ʹ�á��绪Բ���󡹣�\n");
     if(!me->is_fighting(target))
     return notify_fail("ֻ����ս����ʹ�á��绪Բ���󡹡�\n");
     if(me->query_temp("WF_busy"))
     return notify_fail("�㲻�Ǹո��ù�����\n");
     if((int)me->query_skill("yaohu-whip",1)<100)
     return notify_fail("��������޷��ȼ��������治�������С�\n");
     if((int)me->query_skill("throwing",1)<100)
     return notify_fail("ʹ�����б������㹻�İ���������\n");
     if((int)me->query_skill("whip",1)<100)
     return notify_fail("��Ļ����޷����������졣\n");
/*
     if( me->query_skill_mapped("force")!="yaohu-force" )
     return notify_fail("������ʹ�õ������ԡ�\n");
*/
     if((int)me->query("combat_exp")<800000)
     return notify_fail("�������ڵ���ѧ����ʹ����Ҳ���ж��֡�\n");
     if((int)me->query("daoxing")<200000)
     return notify_fail("�����Ϊ̫���ˣ������ó����ˣ�Ҳûʲô������\n");
     if((int)me->query("max_force")<1500 || (int)me->query("force")<400)
     return notify_fail("����������㣬��ô�����У�\n");
     if((int)me->query("max_mana")<1000 || (int)me->query("mana")<200)
     return notify_fail("ʹ��������ҪһЩ������������ķ�����Ȼ���㡣\n");
     else
{
     damage = (int)me->query_skill("whip",1) + (int)me->query_skill("yaohu-whip",1) + (int)me->query_skill("throwing",1) + (int)me->query_skill("yaohu-force",1) + (int)me->query_skill("force",1);
     yourskill = (int)target->query_skill("parry",1) + (int)target->query_skill("dodge",1) + (int)target->query_skill("force",1);
     if(yourskill<1) yourskill=1;
     mywx=(int)me->query("combat_exp");
     yourwx=(int)target->query("combat_exp");
     message_vision(HIG "$N�����г���һ�ף��ǳ��޾�ȻΧ����$N��ת������\nǿ��������γ����絶������������������\n" NOR,me,target);
     me->add("force",-100);
     if(mywx>yourwx*5)
{
     message_vision(GRN "���$n�ҽ�һ���������Ѿ��������˼�ʮ����ɼ��ǵ��˿ڡ�\n" NOR,me,target);
     tell_object (target, "������������̫�����ˣ��������ɣ�\n");
     target->receive_damage("kee",damage/2);
     target->receive_damage("sen",damage/2);
     target->receive_wound("kee",damage/25);
     target->receive_wound("sen",damage/25);
     COMBAT_D->report_status(target, 0);
     me->start_busy(2);
     return notify_fail("����̫���ˣ�û��Ҫ����ôǿ����ʽ��\n");
}
     if(random((int)target->query_skill("yaohu-force",1)/3*2)>(int)me->query_skill("yaohu-force",1) || random((int)target->query_skill("force",1)/3*2)>(int)me->query_skill("yaohu-force",1))
{
     message_vision(GRN "$n��æ����Լ��������ֵ�ס��$N�絶���������\n" NOR,me,target);
     target->add("force",-100);
     tell_object (me, "��ͻȻ�뵽��ս���������������ֹʹ�þ��С�\n");
     tell_object (target, "�Է�ͻȻֹͣ�˾�����ʹ�á������Է��ܽ�����\n");
     return notify_fail("���ֵ�״̬���������´���Ҳ���û��ô�������ˡ�\n");
}
     if((int)me->query_skill("yaohu-force",1)<random((int)target->query_skill("segokee",1)*4) && (int)target->query_skill("segokee",1)>0)
{
     message_vision(HIY "����$n��ȫ��ų��˽��ɫ��ʥ������$N����������û�����κ����á�\n");
     target->add("force",-50);
}
     message_vision(HIM "$N��ͷ�����ó�һ�����ӣ��������������������̱����һ��Ư���ĺ�Ǿޱ��\n" NOR,me,target);
     me->add("force",-50);
     message_vision(HIR "$N����Ǿޱһ˦�������Ļ������Ǿޱ�Ϸֳ��������������޾�һ�㡣\n" NOR,me,target);
     message_vision(GRN "$N���һ�������绪Բ���󣡡���������������˱仯��\n" NOR,me,target);
     message_vision(RED "$N��ȫ��ų���ɫ���������ǳ��޾�������֮����ת�Ӿ磬�������Χ����$N��\n��ɫ���������ƾ��ˡ���ЩǾޱ����������֮��ת�����������\n�����絶�����������Ϯ��$n��\n" NOR,me,target);
     me->add("force",-200);
{
     if(target->is_busy() || random(mywx)>random(mywx+yourwx/5))
{
    number=damage-(yourskill/3*2)+(damage/yourskill)*100+random(damage/20)+random(10);
    number -= yourskill/10;
    message_vision(GRN "���$n������������������"+chinese_number(number)+"����������Ǿޱ���꣡\n" NOR,me,target);
     target->receive_damage("kee",number*3);
     target->receive_damage("sen",number);
     target->receive_wound("kee",number*2);
     target->receive_wound("sen",number);
     COMBAT_D->report_status(target,0);
}
     else
{
     number=damage-(yourskill/2);
     num=random(number/100+3)+random(11);
     message_vision(GRN "����$n����������������˹�ȥ��������������"+chinese_number(num)+"����������Ǿޱ���ꡣ\n" NOR,me,target);
     target->receive_damage("kee",num);
     target->receive_damage("sen",num);
     target->receive_wound("kee",num);
     target->receive_wound("sen",num);
     COMBAT_D->report_status(target,0);
}
     me->add_temp("apply/dodge",damage/2);
     me->add_temp("apply/parry",damage/2);
     me->add_temp("apply/attack",damage*damage/2);
     me->set_temp("WF_busy",1);
     call_out("remove_effect",10+random(5),me);
     message_vision(HIW "$N������һ�գ�����ͻ�ض���ʧ�����ˡ�\n" NOR,me,target);
     me->start_busy(2);
}
}
     return 1;
}

void remove_effect(object me, int damage)
{
  damage=(int)me->query_skill("whip",1)+(int)me->query_skill("yaohu-whip",1)+(int)me->query_skill("throwing",1)+(int)me->query_skill("yaohu-force",1)+(int)me->query_skill("force",1);
  if (!me) return;
  me->delete_temp("WF_busy");
  me->add_temp("apply/attack",-damage*damage/2);
  me->add_temp("apply/dodge",-damage/2);
  me->add_temp("apply/parry",-damage/2);
  message_vision(HIG "$N�о����Լ�ʹ���ؼ��������ָ��ˡ�\n" NOR,me);
}    
