#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
void lianhuan_ok(object); 
int perform(object me, object target) 
{ 
        object weapon; 
                 
        if( !target ) target = offensive_target(me); 

        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
                return notify_fail("��Ҫ��˭ʩչ����֮����\n"); 

        if(!me->is_fighting()) 
                return notify_fail("��������ֻ����ս����ʹ�ã�\n"); 

        if((int)me->query("max_force") < 300 ) 
                return notify_fail("�������������\n"); 

        if((int)me->query("force") < 350 ) 
        return notify_fail("����������㣡\n"); 

        if((int)me->query("kee") < 100 ) 
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n"); 
                
        if((int)me->query("sen") < 100 ) 
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n"); 
        

        if((int)me->query_skill("kugu-blade", 1) < 50) 
                return notify_fail("��Ŀݹǵ����𻹲�����ʹ����һ�л������ѣ�\n"); 

        if(me->query_temp("no_lianhuan"))  
              return notify_fail("����ʹ���˾Ͳ����ˣ�\n"); 
        me->delete("env/brief_message"); 
        target->delete("env/brief_message"); 

      message_vision(HIC"\n��Ц���У�$N����һ�䣬����ޱ�������������$n�����˷���ʤ����\n"NOR,me,target); 

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
   COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 


        me->receive_damage("sen", 50); 
        me->receive_damage("kee", 50); 
        me->set_temp("no_lianhuan",1); 
   me->start_busy(1);
  call_out("lianhuan_ok",2+random(3),me); 


        if( !target->is_fighting(me) ) { 
                if( living(target) ) { 
                        if( userp(target) ) target->fight_ob(me); 
                        else target->kill_ob(me); 
                } 
        } 

        return 1; 
} 

void lianhuan_ok(object me) 
{ if (!me) return; 
      me->delete_temp("no_lianhuan"); 
}          

