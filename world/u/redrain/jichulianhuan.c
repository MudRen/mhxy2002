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
        extra = me->query_skill("kugu-blade",100);
        if ( extra < 100) return notify_fail("��ģۿݹǵ��ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("sword");
        if ( dodskill != "qixiu-jian")
                        return notify_fail("�ۼƳ���������Ҫ�����޽��ݵ���ͣ�\n");
        tmp = me->query_skill("qixiu-jian",100);
        if ( tmp < 50 )return notify_fail("��ģ����޽��ݻ��������죡\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۼƳ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(CYN  "\n\n$N�ӳ��ݹǵ��еľ�����ص�һʽ�������ƣ�����������������\n\n\n��սƪ��\n$N����"+weapon->name()+"ֱ����ĵ��ˣ�" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "ʤսƪ��\n$N����"+weapon->name()+"б����ĵ��ˣ�" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "��սƪ��\n$N����"+weapon->name()+"�ݶ���ĵ��ˣ�" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "��սƪ��\n$N����"+weapon->name()+"�ӽ������������ĵ���ɱȥ��" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(1+random(3));
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}