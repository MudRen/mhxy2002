#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������ʽ����\n");
        if(!me->is_fighting())
                return notify_fail("��������ʽ��ֻ����ս����ʹ�ã�\n");
       if((int)me->query("max_force") < 1200 )
                return notify_fail("�������������\n");
   if((int)me->query("force") < 1360 )
     return notify_fail("����������㣡\n");
     if((int)me->query("sen") < 600 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
      if((int)me->query_skill("qianjun-bang", 1) < 150)
                return notify_fail("���ǧ�������𻹲�����ʹ����һ�л������ѣ�\n");
  if((string)me->query("family/family_name") != "����ɽ���Ƕ�" )
   return notify_fail("������ʽ�Ƿ���ɽ���Ƕ��Ĳ���֮�أ����������ܹ�����\n");
        me->delete("env/brief_message");
   target->delete("env/brief_message");
message_vision(HIC"\n$N���㾫������һתʹ����̨��ѧ"HIW"��������ʽ��"NOR+HIC"������������$n�����˰��У�\n"NOR,me,target);
        me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
     me->receive_damage("sen", 360);
    me->add("force", -1000);
        if( !target->is_fighting(me) ) {

                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
       }
    me->start_busy(3+random(3));
        return 1;
}

