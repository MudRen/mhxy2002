// update by swagger

#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        object weapon1;
        string weapon,msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("�����Ƹ��꡹ֻ����ս����ʹ�á�\n");
        if( (int)me->query_skill("chuanyun-tui", 1) < 100 ||
           (int)me->query_skill("unarmed", 1) < 100 
                             )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á����Ƹ��꡹��\n");
        if(me->query_skill("force", 1) <100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ���������Ƹ��꡹��\n");        
        if (me->query_skill_mapped("unarmed") != "chuanyun-tui")
                return notify_fail("�������޷�ʹ�á����Ƹ��꡹���й�����\n");                                                                                 
        if( (int)me->query("max_force") < 1200 )
                return notify_fail("���������Ϊ̫��������ʹ�á����Ƹ��꡹��\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
msg = HIC "\n$N��ɫһ�䣬��ŵ�أ����������ת�������漴�����Ƹ��꡹��ɨ��$n��\n" NOR;
msg += WHT "\n��һ���������!�ٶ����!$nһ�֮�䣬�����Ѿ��ߵ�����ǰ��"NOR;
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/2))
        {  
      target->start_busy(1);
if (random(me->query_skill("parry")) > random(target->query_skill("parry")/3*2))
                   {
        msg += HIC "\n$n�мܲ�ס��������һ�ȣ������˸�����!\n" NOR;
                damage = (int)me->query_skill("chuanyun-tui", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage/2 + me->query("force_factor"),me);
                target->receive_wound("kee", damage/4,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
                me->start_busy(2);
                if(me->query_skill("chuanyun-tui", 1) > 129)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                    } else 
                {
        msg += HIB "\nû��$n����������$N��Ȼ���μ�ת�������ȣ�̧���ȣ�
һǰһ��һ������Ϯ��$n��һ�ȿ��һ�ȣ����಻����\n"NOR;
        message_vision(msg, me, target);
for (p=2;p<2+random(2);p++)
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                if(random(me->query_skill("chuanyun-tui", 1))> 119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                 }
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIG"\n$n����һ�����Ǳ������Ķ㿪�ˡ�\n"NOR;
 if(me->query_skill("chuanyun-tui",1)>119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                 }
        message_vision(msg, me, target);
        }
        return 1;
}

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,*limbs;
          if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("�����Ѿ�������ս��\n");
        if( (int)me->query("force", 1) < 1000 )
                return notify_fail("$N�ִ����У�����ȴ�����������޷����У�\n");     
if (random(5)>2)
     msg = HIY "\n$NͻȻ����һ��ǰ�շ����ҽ����϶��£�����糾����$nֱ��������\n"NOR;
              {
      if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3*2))
        {
       msg += MAG "\n$n�������Ŀ���$Nӭ��һ�����£�ȴ���м�֮����\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage/2 + me->query("force_factor"),me);
                target->receive_wound("kee", damage/4,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
                me->start_busy(2);
        } else 
        {       
              me->start_busy(1+random(2));
                me->add("force", -200);                
                msg = WHT"$nһ������,����$N�����Ľ�����\n"NOR;
        message_vision(msg, me, target);
        }
              }
              return 1;
}