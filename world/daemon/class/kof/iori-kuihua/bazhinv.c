//bazhinv.c by yushu 2001.1
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
            if(!target) target = offensive_target(me);
            if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�����Ů����\n");

        if(!me->is_fighting())
                return notify_fail("������Ů��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 250)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("bashen",1) < 150)
                return notify_fail("��İ��������������𻹲������޷�ʹ�á�����Ů��!\n");

        weapon=me->query_temp("weapon");

        message_vision(HIR"\n$N��һ��:����!��ǧ����ʮһʽ����Ů,ֱ����$n!\n"NOR, me, target);
            message_vision(HIR"\n$Nһʽ��ȭ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIC"\n$N��һʽ��ȭ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIB"\n$Nһʽǰ��ȭ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIM"\n$Nһʽ�ε���\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIY"\n$Nһʽ��ȭ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIG"\n$N��һʽ��ȭ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(WHT"\n$N˳��ץס��$n�Ĳ��ӣ�\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIR"\n$N���Լ���ͷ����$n��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);

        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1);

        return 1;
}


