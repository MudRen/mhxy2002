#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����Ŵ󿪡���\n");
//                        if(me->query("family/family_name") != "���޵ظ�")
//                return notify_fail(HIG"�����Ŵ󿪡�"+NOR"��ڤ�粻��֮�ܣ�\n");

        if(!me->is_fighting())
                 return notify_fail("�����Ŵ󿪡�ֻ����ս����ʹ�ã�\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

//        if((int)me->query_skill("zhuihun-sword", 1) < 100)
//                return notify_fail("���׷�꽣���𻹲�����ʹ����һ�л������ѣ�\n");

//        if((int)me->query_skill("kusang-bang", 1) < 100)
//                return notify_fail("��Ŀ�ɥ�����𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("hellfire-whip", 1) < 120)
                return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");

        weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
        }

        me->delete("env/brief_message");
        target->delete("env/brief_message");

message_vision(HIR"\n$Nһ�ƴ����ؿ��ϣ�һ����Ѫ������У���Ȼ����˫�֡�\n"NOR+ HIC"$N������߶�ţ��������������һ�ȼ��������ڤ���뿪������֮�š���\n "NOR, me);

//      me->set("HellZhen", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\nڤ��˵���������Ŵ󿪡�\n"+ HIC"����ð�����������飬��Χ��$N��$n�ǻ�����׼������������\n"NOR,target,me);

//      me->set("HellZhen", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\nڤ��˵������С���꡻\n"+ HIC"Զ����������������ǰ���$n��$N�����Ծ���,���Խ��Խ�ࡣ\n"NOR,target,me);

//      me->set("HellZhen", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\nڤ��˵�������޳�������\n"+ HIC"�׺ڶ��޳�ͻȻ������$N��$n����ǰ������ս��������\n"NOR,target,me);

//      me->set("HellZhen", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\nڤ��˵�������������֡�\n"+ HIC"�������ڵص���ŭ�ȵ���$N���Ҿ�����������������\n"NOR,target,me);

//      me->set("HellZhen", 6);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\nڤ��˵�����������ֻء�\n"+ HIC"�ز��������ڿ��д�ŭ�����η���֣��ڴ���Ұ��������\n"NOR,target,me);

//      me->set("HellZhen", 6);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\nڤ��˵�����ڶ��ɻظ���\n"NOR,target,me);
//      me->delete("HellZhen");

        if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);

       me->receive_damage("kee", 0);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}