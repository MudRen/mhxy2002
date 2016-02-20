// Ⱥ������
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int skill, skill1, skill2;
        object weapon1, weapon2;

        if(!target) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�Ⱥ�����ס���\n");

        if(!me->is_fighting())
                return notify_fail("��Ⱥ�����ס�ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 250)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("huntian-hammer",1) < 80)
                
return notify_fail("��Ļ��촸���𻹲�����ʹ����һ�л�������!\n");

        if((int)me->query_skill("fengbo-cha",1) < 80)
        return notify_fail("��ķ粨ʮ���漶�𻹲�����ʹ����һ�л�������!\n");

        if((int)me->query_skill("dragonfight",1) < 80)
                return notify_fail("������β������𻹲�����ʹ����һ�л�������!\n");

        weapon1=me->query_temp("weapon");
        weapon2=present("fork", me);
        if(!objectp(weapon2)) 
                return notify_fail("������û����ȫ��ô������һ�е�����?\n");

        message_vision(HIC"\n$N����һ����������˫�֣���Ȼ������٣������Ļû�����������������������𣬶�ʱ�׵罻�ӣ�$N���ƴ���ˡ�Ⱥ�����ס������С�\n"NOR, me, target);

        me->set_temp("BWQ_perform", 1);
        COMBAT_D->do_attack(me, target, weapon1);

        message_vision(HIC"\n����$n��æ���мܣ�$N�ó�"+weapon2->query("name")+"��������"NOR, me, target);

        weapon1->unequip();
        weapon2->wield();

        me->set_temp("FBC_perform", 2);
        COMBAT_D->do_attack(me, target, weapon2);

        me->set_temp("HTC_perform", 3);
        COMBAT_D->do_attack(me, target, weapon2);

        
message_vision(HIC"\n����$n��æ���мܣ�$N����"+weapon2->query("name")+"����������"NOR, me, target);

        weapon2->unequip();

        me->set_temp("DRF_perform", 2);
        COMBAT_D->do_attack(me, target,weapon1);

        me->set_temp("HTC_perform", 3);
        COMBAT_D->do_attack(me, target, weapon1);

        
me->set_temp("HTC_perform", 8);
        COMBAT_D->do_attack(me, target, weapon1);

        
me->delete_temp("FBC_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        weapon2->unequip();
        weapon1->wield();
        me->start_busy(3);

        return 1;
}
