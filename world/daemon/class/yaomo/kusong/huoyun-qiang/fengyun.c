// fengyun.c  huoyun-qiang ������һǹ��
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("������һǹ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (me->query("family/family_name")!="���ƶ�")
        return notify_fail("�㲻�ǻ��ƶ����ӣ��ò��ˡ�����һǹ��!\n");
    if( (int)me->query_skill("huoyun-qiang", 1) < 100 )
          return notify_fail(WHT"��Ļ���ǹ��������죬��ʹ����������һǹ����\n"NOR);
    if(me->query_temp("no_fengyun"))
      return notify_fail("����û�з��ƿ�������!\n");      
    if( (int)me->query_skill("force", 1) < 100 )
        return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á�����һǹ���������Լ��ľ�����\n"NOR);
    if (me->query("force")<300)
           return notify_fail("�������������޷��������ơ�\n");    
    msg = HIC "$Nǹ������һָ����߷���ͻ��ǹЮ���ף�����㼲��$n��\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/2||
        random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        //me->start_busy(1);
        target->start_busy(random(4));
        damage = (int)me->query_skill("spear");
        damage = damage + random(damage);
        target->receive_damage("kee", damage,me);
        target->receive_wound("kee", damage/3,me);
        target->receive_damage("sen", damage/3,me);
        target->receive_wound("sen", damage/6,me);
        me->add("force", -damage/3);
   msg += HIR"�����һǹ���ض�������$n���Ͽ��˸����ڴֵ�Ѫ����,��Ѫ����������\n"NOR;
     message_vision(msg, me, target);
      COMBAT_D->report_status(target,1);
    } else
    {
        me->start_busy(random(3));
        msg += HIY"����$p������$P����ͼ�����������һ�ߡ�\n"NOR;
          message_vision(msg, me, target);
    }
  
    me->set_temp("no_fengyun",1);
     call_out("remove_effect",4+random(5),me);
     if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("no_fengyun");
}
