// san.c  ��Ůɢ��

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����Ůɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if (((string)me->query("family/family_name") != "�¹�")||(string)me->query("gender")!="Ů��")
                return notify_fail("�ף������¹���Ů��\n");
        if( (int)me->query_skill("snowsword", 1) < 100 )
                return notify_fail("��ķ��ѩ�轣������죬����ʹ�á�\n");
        
        if((int)me->query_skill("moonforce", 1) < 100 )
          
                return notify_fail("��ı����ڹ�ʵ��̫�û���á���Ůɢ������\n");

        if( (int)me->query("force", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á���Ůɢ������\n");
        if(me->query_temp("san_busy"))
               return notify_fail("���ˣ���ɢ���ˡ�����\n");            
                        
        msg = CYN "$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��\n"NOR;

//      if( !target->is_killing(me) ) target->kill_ob(me);

        if ((random(me->query("combat_exp"))>target->query("combat_exp")/2)||(random(me->query_skill("sword")) > target->query_skill("parry")/2 ))
        {
                target->start_busy(random(4)+1);
                
                damage = (int)me->query_skill("moonforce", 1);
                damage = damage +  (int)me->query_skill("snowsword", 1);
                damage = damage +  (int)me->query_skill("sword", 1)/2;
                
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);
                me->add("force", -200);
                msg += HIR"ֻ��$N������Ϊһ�ߣ�����$n,\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target,1);
        } else 
        {
                msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
                me->add("force", -100);
                me->start_busy(random(4));
                message_vision(msg, me, target);
        }
        me->set_temp("san_busy",1);
        call_out("san_can",4+random(4),me);
        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
void san_can(object me) {
  if (!me) return;
  me->delete_temp("san_busy");
}
