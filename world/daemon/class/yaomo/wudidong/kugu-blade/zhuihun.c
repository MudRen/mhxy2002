//write by swagger
//2001.5.10

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
int damage, def, extra;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
 return notify_fail("��Ѫ����ֻ���޵׶����˲ſ����ã�\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "blade" )
 return notify_fail("�������޵�������ʹ��Ѫ����\n");
 if ((int)me->query_skill("kugu-blade", 1) < 100 )
 return notify_fail("�㵶��������죬ʹ����Ѫ����\n");
 if ((int)me->query_skill("huntian-qigong", 1) < 100 )
 return notify_fail("��Ļ���������Ϊ������\n");
 if ((int)me->query_skill("yaofa", 1) < 100 )
 return notify_fail("���������Ϊ������\n");
 if (me->query_temp("xieji_busy")) 
 return notify_fail("���ں����л�û������!\n");
 if( (int)me->query("force") <= 1200 )
 return notify_fail("������������ʹ��Ѫ������Σ�գ�\n");
 extra = me->query_skill("kugu-blade",1) / 5;
// me->add_temp("apply/attack", extra);
// me->add_temp("apply/damage", extra);
 msg = HIC "\n$N���˼����������һ�ӣ���ʱ����������Χ��Ĺ���ɭɭ��
$Nһ����Ц���͵�һ�ɣ��������������ʧ��һ������С�\n" NOR;
        message_vision(msg, me, target);
    if( random((int)me->query("max_mana")*4) > (int)target->query("max_mana"))
{
msg = YEL"\n$n������ͻ������������ε���ͷת�����Ѳ�֪�Լ����ںδ�!\n\n" NOR;
message_vision(msg, me ,target);
target->start_busy(1+random(1));
 msg =  HIC "�����У�$N��"+ weapon->name() +"���Լ�����һ�գ���ʱһƬѪ�����$n��ӿ������
�漴һʽ��Ѫ��׷�꡹����Ѫ�����ŵ�Ӱ����������$n��ͷ���䣡\n\n"NOR;
        message_vision(msg, me, target);
msg = HIR  ">>"+ weapon->name() +"--Ѫ��һ��"NOR"��"WHT"ƽƽ����һ����
��һ��û���κ���ʽ������ȴ�·�����������ı仯����Ȼ���У�ȴʤ�����У�\n" NOR;
       message_vision(msg, me, target);
if (me->query_skill("parry") > random(target->query_skill("parry"))*4/5)
        {
             msg = HIC"$n��û������������У�һ��Ѫ���Ѿ�������һ�㣬���������\n"NOR;
                damage = (int)me->query_skill("parry", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
        target->receive_damage("kee", damage-150,me);
        target->receive_wound("kee", damage*1/3, me);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        }
     else {
            msg = HIC"$næһ�˹�������һ���������л��������е�������\n"NOR;
            message_vision(msg, me, target);
        }
msg = HIR  ">>"+ weapon->name() +"--Ѫ������"NOR"��"WHT"$NҲ�ɾ�ת����
һ���㼱��磬��̤���ţ��������У�ʽʽ��$n���벻���ķ�λ���������\n" NOR;
       message_vision(msg, me, target);
    if (random(me->query("combat_exp")) > (target->query("combat_exp"))/3)
     {
     msg = HIC"$nһ����æ���ң���֪�����ȥ�м��⾲��ˮ�������ĵ�����\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", damage*2, me);
     target->receive_wound("kee", damage/3, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$nȴ�ľ���ˮ�����в��У��߽���$N�������Ĺ��ơ�\n"NOR;
            message_vision(msg, me, target);
        }

//me->add_temp("apply/attack", -extra);
// me->add_temp("apply/damage", -extra);
 me->add("force", -100);
 me->add("mana", -200);
 me->add("eff_kee", -20);
}
else {
msg = YEL"\n$n���Ѿ�����$N����ͼ������һ�����ѱܿ����������硣\n" NOR;
message_vision(msg, me ,target);
 me->start_busy(2+random(1));
 me->add("force", -200);
 me->add("kee", -20);
}
 me->set_temp("xieji_busy",1);
 call_out("remove_effect",5+random(5),me);
 return 1;
}
void remove_effect(object me, object target) {
 string msg;
  if (!me) return;
  me->delete_temp("xieji_busy");
msg = HIR"\n����������ɢȥ��һ����Ӱ�Ӻ��������˳�����\n" NOR;
message_vision(msg, me ,target);
}

