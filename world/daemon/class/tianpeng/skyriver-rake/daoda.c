//by tianlin 2001.7.30
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"HIY"������һ�ҡ�"NOR"��\n");

        if(!me->is_fighting())
                return notify_fail(""HIY"������һ�ҡ�"NOR"ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 800 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 900 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ���̫�����ʹ��͵Ϯ֮�� ?\n");

          if(me->query("family/family_name") != "����˧��" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

        i=(int)me->query_skill("skyriver-rake",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("�������ٷ����������죬��Ҫ�����ϰ����ʹ�����У�\n");

  if (me->query_temp("fc_pfm_busy")) return notify_fail("���в��ܳ�ʹ��\n");
        message_vision(HIC"\n$Nװ������,Խ��Խ��,��ʱ��ͻȻ��ͷ,���һ��: "HIR"��!"NOR"\n\n"HIY"������ʹ��������ٷ��е�"HIW"����"HIG"<<<"BLINK"����һ��"NOR+HIG">>>."NOR,me);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("QJB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100+random(100));
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

//        me->start_busy(2);
   me->set_temp("fc_pfm_busy",1);
   me->set_temp("no_move",1);
  call_out("remove_effect",1+random(3),me);
  call_out("remove_no_move",1,me);
        return 1;
}

void remove_effect(object me) {
  if (me)  me->delete_temp("fc_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
