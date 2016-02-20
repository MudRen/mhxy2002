// llink 2001.2.20
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target, *inv;
        int skill, ap, dp, equip;
        int neili_wound, qi_wound ;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("guangming-shouyin",1);

        if( !(me->is_fighting() ))
                return notify_fail("�������ƻ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("���������˹���\n");

        if( skill < 50)
                return notify_fail("��ġ�������ӡ���ȼ�����, ����ʹ���������ƻ𡹣�\n");

        if( me->query_skill("guangming-force",1) < 60)
                return notify_fail("��ġ������ķ����ȼ�����, ����ʹ���������ƻ𡹣�\n");

        if( me->query("force") < 500 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������֣����ƽ������,ʹ��һ��"HIR"�������ƻ�"NOR"����$n���ؿھ�ȥ��\n"NOR;

        ap = ((me->query("combat_exp"))*(me->query_dex()));
        dp = ((target->query("combat_exp"))*(target->query_dex()))/2;

        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("force",-300);


                neili_wound = 100 + random(skill);
                if(neili_wound > target->query("force"))
                        neili_wound = target->query("force");

                qi_wound = target->query("qi") - 50;
//              qi_wound = neili_wound / 5;
//              if(qi_wound > target->query("qi"))
//                      qi_wound = target->query("qi");

                target->receive_damage("qi", qi_wound);
                target->receive_wound("qi", qi_wound);
                target->add("neili", -neili_wound);
                target->start_busy(2);
                me->start_busy(random(2));

                inv = all_inventory(target);
msg += HIR "$nֻ������ǰһ�ڣ�һ�����������������ۡ���һ�����һ����Ѫ��\n"NOR;
                for(equip=0; equip<sizeof(inv); equip++)
                {
                        if( inv[equip]->query("equipped") &&
                                !inv[equip]->query("weapon_prop") )
                        {
msg += RED "$n�ŵ�һ�ɽ�ζ���������ϵ�"+inv[equip]->query("name")+HIR"ȫ�����������չ����˰׻ң������˵��ϣ�\n"NOR;
                        inv[equip]->unequip();
                        inv[equip]->reset_action();
                        inv[equip]->move(environment(target));
                        inv[equip]->set("name", inv[equip]->query("name") + "����Ƭ");
                        inv[equip]->set("value", 0);
                        inv[equip]->set("armor_prop", 0);
                        inv[equip]->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
                        }
                }
        }
        else
        {
msg += HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me)) me->add("force",-300);
                me->start_busy(4);
        }
    message_vision(msg, me, target);

        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);

        return 1;
}
