//juding.c 
// by mhsj@gslxz 2001/7/25

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        int ii,req,num_pahen,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string pahen_type,b_unit;

   int wound=0;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("��Ҫ����˭��\n");
       
        if(!me->is_fighting())
                return notify_fail(HIR"�������۶���"NOR+WHT"ֻ����ս����ʹ�ã�\n"NOR);
 
      weapon = me->query_temp("weapon");
      req=(int)me->query_skill("rake", 1)+(int)me->query_skill("skyriver-rake", 1); 

       if(me->query("family/family_name") != "���")
                return notify_fail("[�����۶�]ֻ��������Ӳ���ʹ�ã�\n");

      if (weapon)  

      if (me->query_skill_mapped("force")!="tianpeng-force")
                return notify_fail("[�����۶�]������������ķ�����ʹ�á�\n");
      if(req < 80)
            return notify_fail(WHT"����ļ��𣬻����ܹ�ʹ��"HIR"[�����۶�]"NOR+WHT"��\n");
       if (me->query("force")<200)
           return notify_fail(WHT"���������̣�����ʹ��"HIR"[�����۶�]"NOR+WHT"��\n");

        if( time()-(int)me->query_temp("juding_end") < 3 )
                return notify_fail("���в���ʹ��̫�࣡\n");

         me->add("force", -100);

        if(num_pahen <=0) 
           { pahen_type="�ٺ�"; damage=me->query("force_factor")+100; }
        else if (req < 150)
           { pahen_type=weapon->query("pahen/type"); damage=me->query_temp("apply/damage");}

        msg = HIY"$N����������"NOR+weapon->query("name")+HIY"��$n"HIY"ʹ����һ���������"HIR"[�����۶�]"HIY"��\n" NOR;

        if (num_pahen > 100 || num_pahen == 0) max_hit=100;
        else max_hit=weapon->query("pahen/now");

        num_hit=random(max_hit/2)+(max_hit/2);

        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;

        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp")/135;
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}

        if (hitt==0)
	  {
           msg += HIY "$n"HIY"��æ�˹����壬�����$N��һ����\n"NOR;
           message_vision(msg, me, target);
//           me->start_busy(random(3));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
    if (random(damage)>target->query_temp("apply/armor"))  {
       target->receive_wound("kee",damage-target->query_temp("apply/armor"),me);
       wound=1;
  }
           msg += HIY "$N����$n"HIY"����"+chinese_number(hitt)+HIY"�٣�$n"HIY"�������������ϱ�$N���е�\n"NOR+weapon->query("name")+HIY"������š���\n"NOR;
           message_vision(msg, me, target);
       me->start_busy(random(2));
     COMBAT_D->report_status(target,wound);
           if(!target->is_busy())
           target->start_busy(random(5));
           }
        msg = HIY "$n"HIY"�����˼�������$N�����е�������̫��үͷ�϶������ҿ����\n�Ĳ��ͷ��ˣ�\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);
    me->set_temp("juding_end",time());
    call_out("remove_effect",3+random(5),me);
        return 1;
}

