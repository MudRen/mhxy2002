//link 2001.2.20
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("umbrella");
        skill2 = me->query_skill("force");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "umbrella")
                        return notify_fail("��û���ûɡ��ô��ʹ����ʯ���𡹣�\n");
        if( !me->is_fighting()|| !living(me) )
                return notify_fail("����ʯ����ֻ����ս����ʹ�á�\n");

 if( (int)me->query("max_force") < 600 )
                return notify_fail("���������Ϊ�������ߣ�\n");

     if( (int)me->query("force") < 200 )
                return notify_fail("�����ڵ��������㣡\n");

     if( skill < 70)
                return notify_fail("���������ɡ����Ϊ����������ʹ�á���ʯ����! \n");

   if( skill2 < 50)
                return notify_fail("������ķ�����Ϊ����������ʹ�á���ʯ����! \n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "umbrella")
                return notify_fail("����ʯ���𡹱�����ɡ����ʩչ��\n");
        if(me->query("family/family_name")!="���")
                return notify_fail("��������ӣ��޷�ʹ�á���ʯ���𡹡�\n");

 
    if (skill<100 || weapon->query("endure")<100)
        {
msg = BLINK HIY"$N��Ȼ�����������������������ɡ����ʱɡ�����ѣ����硸��ʯ���𡹣�����ɡӰ��$n�����ȥ��\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
                destruct(ob);
 
                ap = (int)((me->query("combat_exp"))*(me->query("cor")));
  dp = (int)(((target->query("combat_exp"))*(target->queryr("cor")))/2);

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = RED "$nһ����������������ɡӰ��ȻǶ����$n�����ϣ�$n�ҽ�һ��������¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        qi_wound = 100 + skill + random(skill*2);

                        if(qi_wound > target->query("kee")) qi_wound = (target->query("kee") + 1);
                        target->add("kee", -qi_wound);
                        target->add("eff_qi", -(qi_wound/4));
                        COMBAT_D->report_status(target, 0);
  me->start_busy(1+random(2));
                        me->add("force",-400);
                }
                else
                {
                        msg = HIG "ֻ��$n���ҵ�������һ��ؼ��ɳ��죬����������������ɡӰ��\n\n"NOR;
                        message_vision(msg, me, target);
me->start_busy(1);
                        me->add("force",-100);
                }

                call_out("perform_jiaoyang", 10, me);
                return 1;
        }
      else if(skill<100 && weapon->query("endure")>=100)
        {
                msg = BLINK HBRED "$N��Ȼ���������������һ���Ҫʩչ���ɡ�еľ�������ʯ���𡱣�ȴ���Ϲ�����
�㣬��Ȼû����������$w��\n" NOR;
                msg += HIR "$n��Ҫ������ͻȻ���ֻ����ѵã���ʱ������������\n\n";
                message_vision(msg, me, target);
                me->add("force",-50);
me->start_busy(1+random(3));
        }
        else
        {
                msg = WHT "$NͻȻ���������������"+weapon->query("name")+WHT"��ɡӰ���£�����һ�񣬾�Ȼʹ�������ɡ�еġ���ʯ���𡱣����ɡ����$n��\n\n" NOR;
                message_vision(msg, me, target);

                ap = ((me->query("combat_exp"))*(me->query("con")));
             dp = ((target->query("combat_exp"))*(target->query("con")))/10;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$nһ���������������ɡӰǡ���������������$n�����ϣ�$n�ҽ�һ������
��¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        qi_wound = 100 + skill + random(skill*2);

                        if(qi_wound > target->query("kee")) qi_wound = (target->query("kee") + 1);
                        target->add("kee", -qi_wound);
                        target->add("eff_qi", -(qi_wound/4));
                        COMBAT_D->report_status(target, 0);
   me->start_busy(1 + random(1));
                        me->add("force",-400);
                }
                else
                {
                        msg = HIG "ֻ��$n���ҵ�������һ��ؼ��ɳ��죬����������������ɡӰ��\n\n"NOR;
                        message_vision(msg, me, target);
   me->start_busy(2);
                        me->add("force",-100);
                }

                return 1;
        }

        return 1;
}
