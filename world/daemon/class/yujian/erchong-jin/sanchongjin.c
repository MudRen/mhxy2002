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
        //extra = me->query_skill("zanglong-force",120);
        //if ( extra < 100) return notify_fail("��ģ۲����ķ��ݻ��������죡\n");
        //dodskill = (string) me->query_skill_mapped("force");
        //if ( dodskill != "zanglong-force")
        //                return notify_fail("�����ؾ�����Ҫ�۲����ķ��ݵ���ͣ�\n");
        //tmp = me->query_skill("erchong-jin",120);
        //if ( tmp < 50 )return notify_fail("��ģ۶��ؾ��ݻ��������죡\n");
        if((int)me->query("max_force") < 1500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 1000 )
             
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ؾ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIC"$N˫����ȭ,������ǰ,һȭ����$n!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"$N����һȭ,�����һ����ĵط�,$n�����һ��!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"$N����һȭ,��������ǰ��ȭ��ĵط�,$n����Ĺ��ڵ�!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->start_busy(2);
        me->receive_damage("kee", 100);
        
        me->add("force", -400);


        me->start_busy(3);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}