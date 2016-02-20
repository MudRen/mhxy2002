#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����һ������\n");

        if(!me->is_fighting())
                return notify_fail("�����һ����ֻ����ս����ʹ�ã�\n");

        if(me->query("family/family_name") != "�¹�" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
             
               if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("���һ���������Բ���ķ�����ʹ�á�\n");


   i=(int)me->query_skill("xuanhu-blade",1)+(int)me->query_kar();

        if( i < 120)
                return notify_fail("����������޵����𻹲�����ʹ����һ�л������ѣ�\n");

   message_vision(HIC"\n$N���к���,��Ϊ��ŭ,һ�еķ�ŭ��Ϊ����,ʹ�������һ��!!!\n"NOR,me);

   me->delete("env/brief_message");
   target->delete("env/brief_message");

        me->set_temp("XFJ_perform", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("XFJ_perform");

        me->receive_damage("sen", 100+random(100));
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}