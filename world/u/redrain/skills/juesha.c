//write by swagger
//2001.5.10

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
int damage, def;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("�̹ž�ɱֻ�ܶ�ս���еĶ���ʹ�á�\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "mace" )
 return notify_fail("��������ﵲ���ʹ�þ�ɱ��\n");
 if ((int)me->query_skill("pangu-mace", 1) < 120 )
 return notify_fail("��ﵷ�������졣\n");
 if ((int)me->query_skill("yulong-force", 1) < 120 )
 return notify_fail("����ڹ���Ϊ������\n");
 if (me->query_temp("juesha_busy")) 
 return notify_fail("�����������̫�󣬵�һ�����ð�!\n");
 if( (int)me->query("force") <= 1200 )
 return notify_fail("������������ʹ���̹ž�ɱûʲô������\n");
 msg = HIW "\n$N���˵����ɫ��Ĳ԰ף�����"+ weapon->name() +HIW"���ź�����������$n��ɨ������\n\n" NOR;
        message_vision(msg, me, target);
    if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/4)
{
msg = YEL"$nһ㶣����Ծ��ı�����һ�����ġ�" NOR;
message_vision(msg, me ,target);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
{
 msg =  HIC "$N���쳤Х��һʽ"HIW"���̹ž�ɱ��"HIC"����ޱȵ���$n�����ҳ���ﵣ�\n"NOR;
        message_vision(msg, me, target);
me->set("juesha", 5);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
me->set("juesha", 6);
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
me->set("juesha", 7);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 me->delete("juesha");
 me->add("force", -200 - me->query("force_factor"));
 me->add("mana", -50);
}
}
else 
{
msg = YEL"\n$n���Ѿ�����$N����ͼ��û���ϵ���\n" NOR;
message_vision(msg, me ,target);
 me->add("force", -200 - me->query("force_factor"));
}
 me->set_temp("juesha_busy",1);
 call_out("remove_effect",4+random(4),me);
 return 1;
}
void remove_effect(object me, object target) {
 string msg;
  if (!me) return;
  me->delete_temp("juesha_busy");
message_vision(HIB"$N���ڹ���תһ���죬��ɫ�ָֻ��˺���\n"NOR,me);

}
