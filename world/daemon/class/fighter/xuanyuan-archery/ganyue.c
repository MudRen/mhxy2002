// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("lengquan-force",200);
        if ( extra < 100) return notify_fail("��ģ���Ȫ�񹦣ݻ��������죡\n");
        tmp = me->query_skill("xuanyuan-archery",200);
        if ( tmp < 50 )return notify_fail("��ģ���ԯ���ݻ��������죡\n");
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
                return notify_fail("�����Ǹ��£�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIR"$Nʹ����ԯ���������ܾ�ʽ����\n\n\n$N����"+weapon->query("name")+HIR"�ó�һ�У۰ٲ��������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(BLK"$N����"+weapon->query("name")+BLK"�ô�һ�У��������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(GRN"$N����"+weapon->query("name")+GRN"�ô�һ�У���ë��������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(BLU"$N����"+weapon->query("name")+BLU"�ô�һ�У���ë���������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(WHT"$N����"+weapon->query("name")+WHT"�ô�һ�У���ñ���伦����$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIG"$N����"+weapon->query("name")+HIG"�ô�һ�У���ë���������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(MAG"$N����"+weapon->query("name")+MAG"�ô�һ�Уۼ��ɵ������$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIC"$N����"+weapon->query("name")+HIC"�ô�һ�У۲�����ˣ���$n��ȥ��\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIB"$N����"+weapon->query("name")+HIB"�ô�һ�У�û���ˣ���$n��ȥ��\n\n"NOR,me, target);
        target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->receive_damage("kee", 100);
        
        me->add("force", -1200);
        
        me->start_busy(1);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}