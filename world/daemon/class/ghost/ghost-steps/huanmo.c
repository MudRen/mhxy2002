#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int myexp,yourexp,lvl;
 int sen;
 object weapon;
 if( !target ) target = offensive_target(me);
if( !target||!target->is_character()||!me->is_fighting(target) )
  return notify_fail(HIC"��"HIR"��ħ��Ӱ"HIC"��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 weapon = me->query_temp("weapon");
 myexp = (int) me->query("combat_exp");
 yourexp = (int) target->query("combat_exp");
lvl = (int) me->query_skill("ghost-steps")/30;
msg = RED "$Nʹ����Ӱ���ٲ����еľ�ѧ�ۻ�ħ��Ӱ�ݣ�\n$n"NOR+RED"��Χ�������ع�Ӱ��һʱ����������" NOR;
if(random(myexp)>yourexp/2)
 {
 message_vision(msg + "\n", me, target);
  msg = "���$n"NOR"ʲô���������ˣ�\n";
  message_vision(msg, me, target);
target->start_busy(lvl);
me->start_busy(1);
 }
 else
{
msg = "��ʧ���ˡ�\n";
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
   me->start_busy(2);
}
 return 1;
}
