#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int addon, tmp;
        object weapon;
        extra = me->query_skill("bingpo-blade",1);
        if ( extra < 90) return notify_fail("��ı��Ǻ������������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "xiaoyaoyou")
                        return notify_fail("����һ����Ҫ��ң�ε���ϣ�\n");
        addon = me->query_skill("xiaoyaoyou",1);
        if ( addon < 90 )return notify_fail("�����ң�λ��������죡\n");
        tmp = me->query_skill("ningxie-force",1);
        if ( tmp < 90 ) return notify_fail("��ı�����Ѫ�����費�㣡\n");
        if ((int)me->query("force")<900)
                return notify_fail("�������������\n");
        if ((int)me->query("combat_exp") < 2000000 )
                return notify_fail("��ĵ��в��������ܹ�����ʩչ�������\n");
        
        if(me->query("family/family_name") != "��ѩɽ")
                return notify_fail("�㲻��ѩɽ���ӣ��⺮��һ���İ����ƺ��������ã�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(BLU"������һ����"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        weapon = me->query_temp("weapon");
        me->add_temp("apply/damage",extra/2);
        me->add_temp("apply/attack",tmp/2);
        message_vision(HIW"\n$N����$n"HIW"���¶��ϴ��컮����һʱ�������ѩ����\n"NOR,me,weapon);
        message_vision(HIY"Ʈѩʽ---$N����$n"HIY"˳��ѩ��ʹ��һ�У�\n"NOR,me,weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_vision(HIC"��ѩʽ---$N����$n"HIC"�����˷�׷Ӱ���ã�\n"NOR,me,weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_vision(HIB"��ѩʽ---$N����$n"HIB"�������浶��������\n"NOR,me,weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_vision(HIW"$N�Կ��л�����棬��������$n"HIW"�ĺ����и���������\n"NOR,me,weapon);
        me->add_temp("apply/damage",-extra/2);
        me->add_temp("apply/attack",-tmp/2);

        me->add("force",-300);
        me->start_busy(3);
        return 1;
}

