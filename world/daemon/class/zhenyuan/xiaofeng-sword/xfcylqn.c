//xfcylqn.c by greenwc

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
               return notify_fail("��Ҫ��˭ʩչ��һ�С����������Ȫ������\n");

       if(!me->is_fighting())
               return notify_fail("�����������Ȫ����ֻ����ս����ʹ�ã�\n");

if((int)me->query("force") < 500 )
	return notify_fail("����������㣡\n");

  if((int)me->query("sen") < 200 )
            return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
      if((int)me->query_skill("xiaofeng-sword", 1) < 100)
            return notify_fail("���������½����������죬������������������ɣ�\n");

      me->delete("env/brief_message");
target->delete("env/brief_message");

message_vision(HIC"\n$N����������һ��ת�����н��Ѿ����ڣ�$nֻ�����ˡ���\n"NOR,me,target);

me->set_temp("XXX_perform", 9);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->set_temp("XXX_perform", 10);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->receive_damage("sen", 20);
me->add("force", -70);
me->start_busy(1+random(2));

 if((int)me->query_skill("moonforce", 1) > 119)
{
         me->set_temp("XXX_perform", 11);  
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

         me->set_temp("XXX_perform", 12);  
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->receive_damage("sen", 30);
me->add("force", -80);
me->start_busy(1+random(2));
}

     me->delete_temp("XXX_perform");

       if( !target->is_fighting(me) ) {
              if( living(target) ) {
                     if( userp(target) ) target->fight_ob(me);
                     else target->kill_ob(me);
}
}

  return 1+random(2);
}
