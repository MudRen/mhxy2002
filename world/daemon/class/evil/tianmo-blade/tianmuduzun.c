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
        addon = me->query_skill("dimo-steps",1);
        tmp= me->query_skill("force",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("û�±�����ʮ����ħ��\n");

        if(me->query("family/family_name")!="ħ��")
               return notify_fail("��ƾ��Ҳ��͵ѧ�����ϳ˾�ѧû�ţ�\n");

        if((int)me->query_skill("tianmo-blade", 1) < 100)
                return notify_fail("�����ħ������������ʹ�ò�������һ�У�\n");

        if(me->query_temp("pfm_busy_shenmo")+6>time())
                return notify_fail("��ոջ���ʮ����ħ�����ǵ����ٽаɡ�\n");

        atk = (addon+tmp)/2;
        me->add_temp("apply/attack",atk);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIR"��ħ���ѣ�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"ħ��է�֣�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"������ħ��\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"��ħ���֣�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"ħ�����ɣ�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"��ħ����\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"����ħ�Σ�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"��ħ���ڣ�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM"$nʹ����ħ������ʽ����ʽ�����е�ħ��Ѹ���ޱȵؿ���$N�ġ�\n"NOR,target,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-atk);
        me->add_temp("apply/damage",-extra);
        me->set_temp("pfm_busy_shenmo",time());
        return 1;
}
