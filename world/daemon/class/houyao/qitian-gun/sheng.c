#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl,lv;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ʥ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( me->query_skill("qitian-gun",1) < 80 )
                return notify_fail("�����������𲻹�ʹ�á�ʥ�־���\n");
           weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "stick"  )
                return notify_fail("�������ʹ�ñ���ʱ����ʹ[����һ������\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("��Ķ���û���ñ�����\n");
        myexp = (int) me->query("combat_exp")/1000;
        mystr = (int) me->query("str");
        yourexp = (int) target->query("combat_exp")/1000;
        yourstr = (int) target->query("str");
        lv  = (int) me->query_skill("stick") ;
        lvl = (int) target->query_skill("dodge")+1;
        msg = YEL "$Nһ���֣�$n�ı�����֪��ô�������˵��£� \n" NOR;
if(objectp(weapon) )
{
        if( random(myexp * lv * mystr) > (yourexp * yourstr *lvl)/3 )
        {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(2);
        }
        else 
        {
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
        }
                me->start_busy(2);
}
        return 1;
}

