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

                return notify_fail("��Ҫ��˭ʩչ��һ�С�һ��ն����\n");
        if(!me->is_fighting())

                return notify_fail("��һ��ն��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
             
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
               if (me->query_skill_mapped("force")!="zanglong-force")

                return notify_fail("һ��ն������ϲ����ķ�����ʹ�á�\n");


   i=(int)me->query_skill("zhanma-blade",1)+(int)me->query_kar();
        if( i < 120)

                return notify_fail("���ն�����𻹲�����ʹ����һ�л������ѣ�\n");

   me->delete("env/brief_message");
   message_vision(HIW"\n$N˫�־ٵ�,$N���һ������һ��ն��!!!\n"NOR,me);
   target->delete("env/brief_message");

        me->set_temp("XFJ_perform", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        target->start_busy(3);

        me->delete_temp("XFJ_perform");

        me->receive_damage("sen", 200+random(200));
        me->add("force", -500);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
        me->start_busy(2);
}