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
        extra = me->query_skill("zhanma-blade",130);
        if ( extra < 100) return notify_fail("��ģ�ն���ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("blade");
        if ( dodskill != "zhanma-blade")
                        return notify_fail("��ն������Ҫ��ն���ݵ���ͣ�\n");
        tmp = me->query_skill("zhanma-blade",130);
        if ( tmp < 50 )return notify_fail("��ģ�ն���ݻ��������죡\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ն����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIC"$Nʹ��ն���е�����ն��\n\n\n$N����"+weapon->query("name")+HIW"��������$n�ӳ���һ��!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N����"+weapon->query("name")+HIW"��$n�ӳ��ڶ�����\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW"$N����"+weapon->query("name")+HIW"��$n�ӳ���������\n\n"NOR,me, target);
        target->start_busy(2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->receive_damage("kee", 100);
        
        me->add("force", -400);


        me->start_busy(4);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}