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
        extra = me->query_skill("zanglong-force",200);
        if ( extra < 100) return notify_fail("��ģ۲����ķ��ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "suodi-steps")
                        return notify_fail("�۾�ͷ��������Ҫ�����أݵ���ͣ�\n");
        tmp = me->query_skill("yujian-sword",240);
        if ( tmp < 50 )return notify_fail("��ģ۷������������ݻ��������죡\n");
        if((int)me->query("max_force") < 2400 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 1600 )
             
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 350 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾�ͷ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIR"$N�ӳ������������е�һʽ��������ͷ��������\n\n\n$N����"+weapon->query("name")+HIR"�ó�һ�У��������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(BLK"$N����"+weapon->query("name")+BLK"�ô�һ�У�����ն����$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(GRN"$N����"+weapon->query("name")+GRN"�ô�һ�У������ģ���$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(BLU"$N����"+weapon->query("name")+BLU"�ô�һ�У���������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"$N����"+weapon->query("name")+WHT"�ô�һ�У���������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG"$N����"+weapon->query("name")+HIG"�ô�һ�У������ϣ���$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(MAG"$N����"+weapon->query("name")+MAG"�ô�һ�У������ϣ���$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"$N����"+weapon->query("name")+HIC"�ô�һ�У�������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"$N����"+weapon->query("name")+HIB"�ô�һ�У۴�ͻ����$n��ȥ��\n\n"NOR,me, target);
        target->start_busy(5);
        COMBAT_D->do_attack(me,target,  me->query_temp("weapon"),TYPE_REGULAR,msg);me->receive_damage("kee", 100);
        
        me->add("force", -1200);
        
        me->start_busy(4);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}