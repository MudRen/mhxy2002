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
  return notify_fail("����նֻ�ܶ�ս���еĶ���ʹ�á�\n");
 if(me->query("family/family_name")!="��ѩɽ")
 return notify_fail("������ն��ֻ��ѩɽ�Ĳſ����ã�\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "blade" )
 return notify_fail("�������޵�������ʹ�ú���ն��\n");
 if ((int)me->query_skill("bingpo-blade", 1) < 100 )
 return notify_fail("�㵶��������죬ʹ��������ն��\n");
 if ((int)me->query_skill("ningxie-force", 1) < 100 )
 return notify_fail("���������Ϊ������\n");
 if (me->query_temp("xieji_busy")) 
 return notify_fail("��շ�������,���û���Σ��!\n");
 if( (int)me->query("force") <= 1200 )
 return notify_fail("������������ʹ�ú���ն����Σ�գ�\n");
 msg = HIC "\n$Nһ����Х������һ�ӣ���ʱ��Χ��Ȼ��������ޱȣ�
$N������Ѫ��,һ�Ŵ̹ǵĺ�����$nֱ�ƶ���!\n" NOR;
        message_vision(msg, me, target);
    if( random((int)me->query("max_mana")*4) > (int)target->query("max_mana"))
{
{
msg = YEL"\n$n��$N���������ź������˸�����!\n\n" NOR;
message_vision(msg, me ,target);
target->start_busy(1+random(1));
 msg =  HIC "$N����"+ weapon->name() +"����һ��,����Ҳ�����ڿն���,
�漴һʽ������ն���ó�����������$nӭ��������\n\n"NOR;
        message_vision(msg, me, target);
 def=(int)target->query_temp("apply/armor_vs_force");
        }
    if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
     {
     msg = HIC"$nһ����æ���ң���֪�����ȥ�м��⾲��ˮ�������ĵ�����\n"NOR;
     damage=random(800)+me->query("force_factor");
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

 me->add("force", -100);
 me->add("mana", -200);
}
else {
msg = YEL"\n$n���Ѿ�����$N����ͼ������һ�����ѱܿ������ź�����\n" NOR;
message_vision(msg, me ,target);
 me->start_busy(2+random(1));
 me->add("force", -200);
 me->add("kee", -20);
}
 me->set_temp("xieji_busy",1);
 me->start_busy(1);
 call_out("remove_effect",5+random(5),me);
 return 1;
}
void remove_effect(object me, object target) {
 string msg;
  if (!me) return;
  me->delete_temp("xieji_busy");
msg = HIR"\n����һ��,����������ɢȥ�ˡ�\n" NOR;
message_vision(msg, me ,target);
}

