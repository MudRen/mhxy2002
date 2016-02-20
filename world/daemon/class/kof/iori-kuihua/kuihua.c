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
                return notify_fail("��Ҫ��˭ʩչ��[�ٷ�ʰ��ʽ.����]��\n");

        if(!me->is_fighting())
                return notify_fail("[�ٷ�ʰ��ʽ.����]ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("iori-kuihua", 1) < 150)
                return notify_fail("���[�ٷ�ʰ��ʽ.����]�ּ��𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");

        message_vision("\n$Nʹ��-"HIY"[�ٷ�ʰ��ʽ.����]"NOR"-"BLINK HIR"������������"NOR+HIG".."NOR"\n", me);


        me->set_temp("kuihua_per", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"����һ��"NOR"-------"BLINK HIR"�ٺ���\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"��������"NOR"-------"BLINK HIG"�丫��\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"��������"NOR"-------"BLINK HIR"������\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("kuihua_per");

        me->receive_damage("kee", 50);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

