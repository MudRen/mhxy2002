//write by swagger
//�����߻� by skyer
//2002/2/20
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg , str;
int extra;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("���֮��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 if(me->query("family/family_name")!="��ѩɽ")
 return notify_fail("�����֮�衱ֻ��ѩɽ�������˲ſ����ã�\n");
      if (me->query_skill("bainiao-jian",1)<100) 
          return notify_fail("��İ��񽣷���ô�ã����˭����\n");
      if (me->query_skill("xiaoyaoyou",1)<100) 
          return notify_fail("�����ң����ô�ã����˭����\n");
        if( me->query("force_factor") > 50)                return notify_fail("�����֮�衹�������в������������������ܽ������飿\n");
weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "sword" )
 return notify_fail("�������޽�������ʹ�÷��֮�裡\n");
 if( (int)me->query("force") <= 1500 )
 return notify_fail("����������������ʹ�÷��֮�裡\n");
 {
 extra = me->query_skill("bainiao-jian",1) ;
 msg = HIW  "\n$N��ɫ��Ȼ����֮���μ�ת�������ѩ����֮��˶��裡\n���𣬳����𣡷�Ϣ������ȴ�޴���������\n" NOR;
        message_vision(msg, me, target);
//   if( random((int)me->query_skill("xiaoyaoyou")*4) > (int)target->query_skill("dodge"))
{
msg = WHT"\n$n����������ͣ��ƺ�������������!\n\n" NOR;
message_vision(msg, me ,target);
target->start_busy(random(1));
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg =  HIC "$N�������������������䣬������$n����������\n" NOR;
        message_vision(msg, me, target);
msg = HIB  "\n   >>>>$N�̳�һ����������    "HIC""BLINK"ˮ��к��"NOR"" NOR;
       message_vision(msg, me, target);
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
msg = HIB  "   >>>>$N�̳�һ����������    "HIC""BLINK"��������"NOR"" NOR;
       message_vision(msg, me, target);
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
msg = HIB  "   >>>>$N�̳�һ����������    "HIC""BLINK"��������"NOR"" NOR;
       message_vision(msg, me, target);
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
       me->set("fenghuang", 12);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->set("fenghuang", 13);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->start_busy(random(3));
 me->add("force", -200);
 if (target->query("eff_kee")<0 || !living(target) )  
{str="��˵"+target->name()+HIM"��"+me->name()+HIM"��һʽ"HIY"��˶���"HIM"��ȥ�����޵ظ�����˵"+target->name()+HIM"�������޵ظ����������裡\n"NOR;
 message("channel:rumor",HIM"\n��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
}
else {
msg = YEL"\n$n����Ŀ���$N��׾���趯������¶����Ū��Ц�ݡ�\n" NOR;
message_vision(msg, me ,target);
 me->start_busy(2);
 me->add("force", -200);
 me->add("kee", -20);
}
}
 me->delete("fenghuang");
 me->set_temp("fenghuang_busy",1);
 call_out("remove_effect",3+random(8),me);
 return 1;
}
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("fenghuang_busy");
}
