//by tianlin 2001.8.16������ɫ�޸�
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int myexp, yourexp;
   object weapon;    
       if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail(""HIY"����"NOR+WHT"����"NOR"ֻ����ս����ʹ��.\n");
        weapon = me->query_temp("weapon");
    if (!weapon||weapon->query("skill_type") != "sword" )
         return notify_fail("�������޽�������ʹ��"HIY"����"NOR+WHT"����"NOR"��\n");
   if( (int)me->query_skill("bainiao-jian",1) < 80)
   return notify_fail("��İ��񽣷��ȼ�������!\n");
   if( (int)me->query_skill("ningxie-force",1) < 80)
   return notify_fail("��ı�����Ѫ������������.\n");
   if( (int)me->query("max_force") < 800)
   return notify_fail("�������̫����!\n");
   if( (int)me->query("force") < 400)
   return notify_fail("�������������.\n");;
  myexp = (int)me->query("combat_exp")/1000*(int)me->query_skill("sword");
  yourexp = (int)target->query("combat_exp")/1000*(int)target->query_skill("dodge");
   msg = HIC
"$N����һ��,��Ȼ����һ���ö�������,ϸ��������,ƽ������,���µ���.\n"
"����������մ�����а֮��,�����Ϲ�����---"NOR+BLINK+HIY"����"NOR+BLINK+WHT"����"NOR+HIC"!!\n" NOR;;
          if( random(myexp*3) > yourexp)
          {
        msg += HIG
       "$n����������,�����Եĵ��˸���һ��.\n" NOR;
        target->start_busy(3);//���Է�����busy,�Ҹ��Ӵ���һ��busy.by tianlin
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        msg += BRED+HIY"$Nȴ��������,�����һ����ĽǶȴ���,������,��,��,��֮����.�������⾳������Ȥ!\n" NOR;
        me->start_busy(1);
        me->add("force",-100);
          }
        else
        {
      msg += HIY
        "$n�ƺ����������������Ȥ������ر���һ�ԡ�\n" NOR;
        me->start_busy(2);
        me->add("force",-50);  
        }
        message_vision(msg, me, target);
        return 1;
}
