//�����Ľ�.c by yushu 2001.2
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
            if(!target) target = offensive_target(me);
            if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С������Ľ�����\n");

         if(!me->is_fighting())
                return notify_fail("�������Ľ���ֻ����ս����ʹ�ã�\n");

        if(me->query("family/family_name")!="�¹�")
                return notify_fail("�����¹��Ĳ����á������Ľ�����\n");

/* if(me->query("moon/jueqing_perform")!=1)
                return notify_fail("�㻹û��ᡸ�����Ľ�����\n");
*/
        if((int)me->query("max_force") < 500)
                     return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

         if((int)me->query("sen") < 250)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

         if((int)me->query_skill("snowsword",1) < 120)
                return notify_fail("��ķ��ѩ�轣�����𻹲������޷�ʹ�á������Ľ���!\n");

        weapon=me->query_temp("weapon");
            message_vision(HIW"\n$N���㾫�񣬶��ִ̳�һ����"+weapon->query("name")+"�����ĵ���âֱ��$n!\n"NOR, me, target);
            message_vision(HIR"\n$Nһʽ���������������У��������տ�����������̤���㡹λ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIG"\n$Nһʽ��¥���������������д�Լ�����ӡ���ռס���ҡ�λ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIC"\n$Nһʽ������Ը���������ڵ�ԸΪ����֦������̤��Ǭ����������λ��\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIB"\n$Nһʽ���쳤�ؾ���ʱ�����˺������޾��ڡ����ɡ�������Ǭ�����ˣ�\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
        me->receive_damage("sen", 100);
        me->add("force", -200);

            if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2+random(2));

        return 1;
}


