//by tianlin 2001.10.7�޸�

#include <ansi.h>
inherit SSERVER;
#include "/u/tianlin/eff_msg.h";
int def;

int perform(object me, object target)
{       
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail(""HIR"��"NOR+HIC"����"NOR+HIR"��"NOR"ֻ����ս����ʹ�á�\n");
        if( (int)me->query_skill("duo-sword", 1) < 100 ||
           (int)me->query_skill("sword", 1) < 100 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ��"HIR"��"NOR+HIC"����"NOR+HIR"��"NOR"��\n");

        if((int)me->query_skill("cloudforce", 1) <100)
return notify_fail("�������ڵ��ڹ���Ϊ��ʹ����"HIR"��"NOR+HIC"����"NOR+HIR"��"NOR"��\n");

        if (me->query_skill_mapped("sword") != "duo-sword")
return notify_fail("�������ڵ��ڹ���Ϊ��ʹ����"HIR"��"NOR+HIC"����"NOR+HIR"��"NOR"��\n");

        if( (int)me->query("max_force") < 1200 )
return notify_fail("�������ڵ��ڹ���Ϊ��ʹ����"HIR"��"NOR+HIC"����"NOR+HIR"��"NOR"��\n");

        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
       msg = HIW "\n\n$NͻȻ�������������е����һʽ,����.���м�������׺�,ֱ��$n���ؿڣ���\n\n\n\t\t\t"NOR+HIY"��"NOR+CYN"��"NOR+BLINK+HIR"��"NOR+CYN"��"NOR+HIY"��\n\n\n" NOR;
if (me->query("combat_exp")/2 > target->query("combat_exp")/3)
        {
                me->start_busy(1);
                target->start_busy(2);
                damage = (int)me->query_skill("duo-sword", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("duo-sword", 1) > 70)
               target->set_temp("last_damage_from", me);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -50);                
                msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        msg = MAG "\nֻ��$N���еĽ������ַ����˾��춯�صĵڶ���\n" NOR;
        message_vision(msg, me, target); 
       msg = HIY "\n\n\n\t\t\t��"NOR+CYN"��"NOR+BLINK+HIR"��"NOR+CYN"��"NOR+HIY"��\n\n\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("duo-sword", 1);
                damage = damage+(int)me->query_skill("sword", 1);
                damage = (damage + random(damage))/2;
                
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                me->add("force", -random(damage/10));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
