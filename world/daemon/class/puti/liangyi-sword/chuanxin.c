//���Ľ�
//by swagger

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int meexp, youexp, extra;
        object weapon;
     
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("���Ľ�ֻ����ս����ʹ��\n");
   if((int)me->query_skill("liangyi-sword",1) < 60)
    return notify_fail("��Ľ����ȼ�����!\n");
   if((int)me->query_skill("wuxiangforce",1) < 60)
    return notify_fail("����ڹ��ȼ�����!\n");
 if (me->query_temp("chuan_busy")) 
      return notify_fail("�������������л���Σ��!\n");
   if( (int)me->query("force") < 1000)
   return notify_fail("�������̫��,������������!\n");
        if(! me->query_temp("weapon"))
                return notify_fail("�����޽��������ô��Ľ�!\n");

    meexp = (int)me->query("combat_exp");
    youexp = (int)target->query("combat_exp");
   msg = WHT
"\n$Nһ����Ц�����бб�̳������·���һ��!\n
$nһ��֮��,�ǽ�ȴ��������Ĵ���$n������!!\n\n" NOR;
message_vision(msg, me ,target);
    if( random(meexp*4) > youexp)
{
msg = HIR"\nֻ��$nһ���Һ�,$N�Ľ��Ѿ����Ķ���!!\n" NOR;
message_vision(msg, me ,target);
target->start_busy(1+random(2));
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
}
else {
msg = HIR"\n$n�͵�һ���������ⶾ���Ĵ���һ����\n" NOR;
message_vision(msg, me ,target);
me->start_busy(1+random(1));
}
me->set_temp("chuan_busy",1);
call_out("remove_effect",3+random(3),me);
me->add("force",-100);
        return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("chuan_busy");
}
