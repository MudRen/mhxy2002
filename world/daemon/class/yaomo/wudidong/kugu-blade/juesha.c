//focus 2001.5.1
#include <ansi.h>
inherit SSERVER;
#include "/u/tianlin/eff_msg.h";

int perform(object me, object target)
{       
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("���ݹǾ�ɱ��ֻ����ս����ʹ�á�\n");
       
        if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
            return notify_fail("���ݹǾ�ɱ��ֻ���޵׶����˲ſ����ã�\n");

        if( (int)me->query_skill("kugu-blade", 1) < 160 ||
           (int)me->query_skill("blade", 1) < 160 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á��ݹǾ�ɱ����\n");
        if((int)me->query_skill("dodge", 1) <160)
            return notify_fail("�������ڵ��Ṧ��Ϊ��ʹ�������ݹǾ�ɱ����\n");
        if((int)me->query_skill("force", 1) <160)
            return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�������ݹǾ�ɱ����\n");
        if( (int)me->query("max_force") < 1200 )
            return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�������ݹǾ�ɱ����\n");
        if( (int)me->query("force") < 1600 )
            return notify_fail("�������������\n");
       msg = HIM"\n$NͻȻ�ٿ�����, ����һ�����ѻ���$n���ؿڣ���\n" NOR;
if (random(me->query("combat_exp")) > target->query("combat_exp")/5)
        {
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("kugu-blade", 1);
                damage = damage + random(damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);               
                me->add("force", -200);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("kugu-blade", 1) > 160)
                {
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                         }
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg += HIG"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
                if(me->query_skill("kugu-blade", 1) > 180)
                {
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                 }
        }
        message_vision(msg, me, target);
        return 1;
}

// �ڶ���

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("force", 1) < 1000 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
if (random(5)>2)
        msg = HIC"\n����$NͻȻһ������,бб�˵�,ļ���������,$n��ǰһ��Ӱ!!\n"NOR;
else 
        msg = HIG"\n����$NͻȻһ������,бб�˵�,ļ���������,$n��ǰһ��Ӱ!!\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
        {
       msg = CYN "�����Ӱ�У�һ���Կ���ɱ��.....!!!\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("blade", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);               
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("force", 1) > 180)
                {
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
                 }
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg = WHT"����$p�ϵ�֮��,�������У�����$N�������ˡ�\n"NOR;
                if(me->query_skill("force", 1) > 200)
                {
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
                 }
        }
        message_vision(msg, me, target);
        return 1;
}

//������

int perform3(object me, object target)
{
        string msg,weapon;
        int p,extra,j;
       j=2+random(3);
    extra = (int)me->query_skill("dodge");
    weapon = me->query_temp("weapon");  
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("����ӵ�һЦ,�����ջ�����ĵ��⣬��Ȼ����!!\n");
        if( (int)me->query("force", 1) < 800 )
                return notify_fail("���Ҫ�ٳ���������ȴ�����Լ������������ˣ�\n");     
    msg = HIR
"\n$N�������һ�Ŷ���,����֮��,��Ȼվ��$n��ǰ,
$nֻ�������ϼ,��ס$nȫ��,$N��籩�����������!!\n"NOR;
message_vision(msg, me, target);
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/dodge", extra);
        me->add_temp("apply/parry", extra);
for (p=1;p<2+random(4);p++)
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        if( !target->is_fighting(me) ) 
                if( living(target) ) 
                        if( userp(target) ) target->fight_ob(me);
        me->add("force", 400);
    msg = YEL
"\n\n$N���ӵ�һЦ,�����ջ�����ĵ��⣬��Ȼ����!!\n"NOR;
message_vision(msg, me, target);
    msg = YEL
"����ĵ��⻺������,$n��ʱһ��,ѹ������!!\n"NOR;
message_vision(msg, me, target);
        me->add_temp("apply/parry", -extra);
        me->add_temp("apply/dodge", -extra);
        me->add_temp("apply/attack",-extra);
        me->start_busy(1+random(2));
/*
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/4))
    {                if(me->query_skill("fly-king", 1) > 200)
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
     }
*/
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("force", 1) < 1000 )
                return notify_fail("���Ҫ�ٳ����Ļ���ȴ�����Լ������������ˣ�\n");     
if (random(5)>2)
        msg = YEL"\n�����ϵ���$N�ص�֮��,$N����һ�ͣ��ֻ���$n\n"NOR;
else 
        msg = RED"\n\n�����ϵ���$N�ص�֮��,$N����һ�ͣ��ֻ���$n\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > random(target->query("combat_exp")*3))
        {
       msg = CYN "$n�������Ѿ���������,$N��������,��ǰ����һ��\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("force", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage*2);
                target->receive_wound("kee", damage);               
                me->add("force", -300);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
if (me->query_skill("spells", 1) > 200 && random(10)>3)
                {
if (random(5)>2)
       
    msg = BLU"$N�������һ�Ŷ���,����֮��,��Ȼվ��$n��ǰ,$N����Ǳ������!!\n"NOR;
else 
    msg = "$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n";
       
                   message_vision(msg, me, target);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                 }
             else {
                   msg = YEL"\n\n$N���ӵ�һЦ,�����ջ�����ĵ��⣬��Ȼ����!!\n"NOR;
                   msg += YEL"����ĵ��⻺������,$n��ʱһ��,ѹ������!!\n"NOR;
                   message_vision(msg, me, target);
                  }
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg = HIC"����$pһ������,������$N�����Ľ�����\n"NOR;
        message_vision(msg, me, target);
if (me->query_skill("yaofa", 1) > 200 && random(10)>6)
                {
if (random(5)>2)
         msg = HIB"$N�����������$n������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n"NOR;
else 
    msg = "$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n";
                   message_vision(msg, me, target);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                 }
             else {

             remove_call_out("perform3");
                call_out("perform3", 1, me, target);    
                  }
        }
                me->add("force", 400);                
        return 1;
}
