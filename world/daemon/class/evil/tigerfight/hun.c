//modify by ken
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����꡽ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( target == me ) return notify_fail("����ˣ�\n");
        extra = me->query_skill("tigerfight",1) ;
        if(extra < 50 ) return notify_fail("����컢����������������ô��Ҳ���˲�������\n");
        if( (string)me->query("family/family_name") != "ħ��" )
              return notify_fail("���ֲ���ħ�壬�������˾�Ѫ��\n");
        if( (int)me->query("mana") < 400 )
              return notify_fail("��ķ������㣬����ô��Ҳ��������");
        msg = HIG "\n$N������ħ�󷨣�˫�Ʒ���һ��ҫ�۵��̹�̵�$n�������ۣ�" NOR;
        if(random((int)me->query("mana")) >= (int)target->query("mana")/2)
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIG "$Nֻ������ǰһ��Ⱥħ���裬Ԫ�񼸺�Ҫ���϶�����\n" NOR,target);
        target->receive_wound("sen",extra);
        me->receive_curing("sen",extra);
        me->add("mana",-200);
        COMBAT_D->report_status(target);

        }       
        else{
        message_vision(msg+"\n",me,target);
        message_vision( HIB "$N��Ц�������С�ƣ�Ҳ�����ֳ�\n" NOR,target);
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("mana",-300);
        }
        me->start_busy(2);
        return 1;
}
