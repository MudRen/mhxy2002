//modify by ken the new ʮ����ħ
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int addon, tmp, atk;
        object weapon;
        extra = me->query_skill("tianmo-blade",1);
        if ( extra < 120) return notify_fail("�����ħ������ʽ���������죡\n");

        addon = me->query_skill("dimo-steps",1);
        tmp= me->query_skill("force",1);
        if ( addon < 120 )return notify_fail("��ĵ�ħ�����˲����������죡\n");
        if ((int)me->query("force")<1000)
                return notify_fail("������������ˡ�\n");
        
        if(me->query("family/family_name") != "ħ��")
                return notify_fail("��ʡʡ���ˡ�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("û�±�����ʮ����ħ��\n");
        
        atk = (addon+tmp)/2;
        me->add_temp("apply/attack",atk);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIW"\n$N������ͨ������ħ������ʽ����һ���ǳɣ�\n "NOR, me,target);
        message_vision(HIR"��ħ���ѣ�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"ħ��է�֣�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"������ħ��\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"��ħ���ڣ�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM"$nʹ����ħ������ʽ����ʽ�����е�ħ��Ѹ���ޱȵؿ���$N�ġ�\n"NOR,target,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-atk);
        me->add_temp("apply/damage",-extra);
        me->add("force",-500);
me->start_busy(random(1));
        return 1;
}
