#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
int extra,lvl,lv;
 int i;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("����뷢ֻ����ս���еĶ���ʹ�á�\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "stick" )
 return notify_fail("������û�й����ø�ƨ����\n");
 if( (int)me->query("force") <= 1000 )
 return notify_fail("����������������ʹ������뷢��\n");
 extra = me->query_skill("yinglong-stick",1) / 5;
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg = HIW  "$Nһ����ȣ�ʹ����ʥ�ž���"HIR"����뷢"HIW"�����е�"+ weapon->name() +"�����һ����$n������\n" NOR;
        message_vision(msg, me, target);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
lvl=extra/10;
if(lvl>4) lvl =4;
for(i=0;i<=lvl;i++)
 {
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
}
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->start_busy(2);
 return 1;
}

