// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("zanglong-force",130);
        if ( extra < 100) return notify_fail("��ģ۲����ķ��ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("sword");
        if ( dodskill != "yujian-sword")
                        return notify_fail("�۰��塤����������Ҫ�۷������������ݵ���ͣ�\n");
        tmp = me->query_skill("yujian-sword",130);
        if ( tmp < 50 )return notify_fail("��ģ۷������������ݻ��������죡\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 600 )
             
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰��塤��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIC"$N�ӳ������������е�һʽ���������塤����������\n\n\n$N����"+weapon->query("name")+HIW"ֱ��$n��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N����"+weapon->query("name")+HIW"б��$n��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"$N����"+weapon->query("name")+HIW"�ݶ�$n��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW"$N����"+weapon->query("name")+HIW"�ӽ����������$nɱȥ��\n\n"NOR,me, target);
        target->start_busy(2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->receive_damage("kee", 100);
        
        me->add("force", -600);


        me->start_busy(3);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}