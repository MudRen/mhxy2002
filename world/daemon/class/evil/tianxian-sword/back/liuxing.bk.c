// ken xyj
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;
        extra = me->query_skill("tianxian-sword",1);
        if ( extra < 90) return notify_fail("������ɽ���������û���ã������õó�����\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("���빥��˭��\n");

        if(!me->is_fighting())
                return notify_fail("��ɲ����������.\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("������������㷢���ǡ�\n");

        if((int)me->query("force") < 700 )
                return notify_fail("������������ã���ô��Ҳ���������ǣ�\n");

        weapon = me->query_temp("weapon");
        msg = HIY  "$N����һ�����е�"+ weapon->name()+  "��ʱ�������������ǣ���籩������$nɨ����" NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",extra/10);
        me->add_temp("apply/damage",extra/10);
        lmt = random(3)+3;
        for(i=1;i<=lmt;i++)
        {
        msg =  HIR "��"+chinese_number(i)+"����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
        me->start_busy(3);
        return 1;
}
