// sanqing.c by yushu@SHXY 2000.11
//by tianlin@mhxy for 2001.9.3�޸�����busy time
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
         if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"HIM"��һ�������塹"NOR"��\n");

        if( !me->is_fighting() )
                return notify_fail(""HIM"��һ�������塹"NOR"ֻ����ս����ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(""HIM"��һ�������塹"NOR"�����ý���\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("�������������\n");
     if( time()-(int)me->query_temp("sanqing_end") < 2 )
                return notify_fail(YEL"�����ö�Ͳ����ˣ�\n"NOR);
        if( (int)me->query_skill("sanqing-jian",1) < 100 )
                return notify_fail("������彣���������ң��޷�ʹ��"HIM"��һ�������塹"NOR"��\n");
        msg = HIM "$N"HIM"ʹ����ׯ�۾���"HIY"��һ�������塹"HIM"������Ȼ�ӿ�,���ս����γ�����������\n" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("sanqing-jian",1)/2);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add_temp("apply/attack", - (int)me->query_skill("sanqing-jian",1)/2);

       me->add("force", -50);
       me->set_temp("sanqing_end",time());
       me->start_busy(0);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}