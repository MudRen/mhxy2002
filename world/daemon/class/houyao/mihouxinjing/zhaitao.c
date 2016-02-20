// zhaitao.c
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
 int success_adj, damage_adj;
 success_adj = 130;
 damage_adj = 80;
 if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      target->is_corpse()
 ||      target==me)
  return notify_fail("��Ҫ��˭ʩչ���ժ�ң�\n");
 if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
  return notify_fail("��ķ���������\n");
 if((int)me->query("sen") < 100 )
  return notify_fail("���޷����о���������׼��\n");
 me->add("mana", -25-2*(int)me->query("mana_factor"));
 me->receive_damage("sen", 50);
 if( random(me->query("max_mana")) < 50 ) {
  write("���ˣ������Ƕ���֪���Ķ���ˣȥ�ˣ�\n");
  return 1;
 }
 SPELL_D->attacking_cast(
  me,
   //attacker
  target,
   //target
  success_adj,
   //success adjustment
  damage_adj,
   //damage adjustment
  "kee",
   //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
  HIC "\n$N�������˾����ģ���ա�֨֨�������ֳ�һȺ���ӣ���$n��˺��ҧ��\n" NOR,
   //initial message
  HIR "\n���$n����������������ҧ��Ѫ��ɽ���\n" NOR,
   //success message
  HIC "\n$n��æһ��������һ�ԡ�\n" NOR,
   //fail message
  HIC "ֻ��$nһ��ŭ�𣬺����ŵñ治�����ˣ�������$Nҧȥ��\n" NOR,
   //backfire initial message
  HIC "���$n����������������ҧ��Ѫ��ɽ���\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
 me->start_busy(1+random(1));
 return 1+random(1);
}
