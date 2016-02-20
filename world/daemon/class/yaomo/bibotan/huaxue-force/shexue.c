// shexue.c ��������ȡ������weiqi...
#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
        int qi_gain, qi_lost, ap, dp, success;
        string msg;     

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        return notify_fail("�����˭ʹ�����ľ���\n");
    
        if( target == me ) return notify_fail("���Լ���\n");

        if(target->query_temp("netdead")) return notify_fail("�û��٣���̫�񻰰ɣ�\n");

        if( (int)me->query_skill("huaxue-force", 1) < 30 )
                return notify_fail("��Ļ�Ѫ����Ϊ̫�ͣ�����ʹ�����ľ���\n");

        if( (string)me->query("family/family_name") != "��ʯɽ�̲�̶" )
                return notify_fail("�㲻�ữѪ�񹦣�����ʹ�����ľ���\n");

        if(!me->is_fighting()||!target->is_fighting())
                return notify_fail("ֻ����ս������ȡ������\n");

        if( (int)me->query("kee")  > 3*(int)me->query("max_kee")/2 )
                return notify_fail("��������̫����ӯ��������Ҫ��ը�ˡ�\n");

        qi_lost = target->query("kee") / 5;

        if(qi_lost < 5 )
                return notify_fail("�Է���Ѫ�Ѿ������ˡ�\n");
        
        msg = HIC
"\n$N͵͵����Ѫ�񹦣����$n����Ѫ����ס�������������ˣ�\n" 
NOR;

        success = 1;

        ap = me->query_skill("force");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared exp and force level. 
        //note: has nothing to do with target's force level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared max_mana, ������ǿӦ�ò��¹�

        if(success == 1 ){
                msg +=  HIC "���$nͷƤһ�飬ֻ������������ԴԴ���ϵ����˳�ȥ��\n" NOR;
                qi_lost=qi_lost-random(qi_lost/2);
                target->receive_damage("kee", qi_lost, me);

                qi_gain = qi_lost;
                if( (int)target->query("max_kee") < (int)me->query("max_kee") )
                        qi_gain = qi_gain * (int)target->query("max_kee")/(1+(int)me->query("max_kee"));
                //here, the more the max_kee of your target, the more the qi_gain.
                //and always qi_gain <= qi_cost.

                if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
                        qi_gain = qi_gain * (int)target->query("combat_exp")/(1+(int)me->query("combat_exp"));
                //here, we decrease the qi_gain futher more according to dao-xing so she-qi from too weak players or NPCs is useless.
                if( qi_gain > 0 ) me->add("kee", qi_gain);

                //here also add some huaxue-force point.
                if( qi_gain > 0 
                && (int)me->query("combat_exp") < (int)target->query("combat_exp") 
                && (int)me->query_skill("huaxue-force",1) <= 150
                && random(10) < 1 )
                {
                        me->improve_skill("huaxue-force", qi_gain);
//                      tell_object(me, "A\n");
                } else {
//                      tell_object(me, "B\n");
                        qi_gain=qi_gain/5;
                        if( qi_gain < 0 ) qi_gain =1;
                        me->improve_skill("huaxue-force", qi_gain, 1);
                }
        } else {
                msg +=  HIC "���$nһŤͷ�����˿�ȥ��\n" NOR;   
        } 

        message_vision(msg, me, target);
        if( success == 1 ) COMBAT_D->report_status(target);

//he'll try kill you...
        if( living(target) ) target->kill_ob(me);

        me->start_busy(1);        
        return 1;
}