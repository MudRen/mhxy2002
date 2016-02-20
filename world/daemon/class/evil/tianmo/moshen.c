// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target || !target->is_character() )
                return notify_fail("��Ҫ��˭ʹ��ħХ��\n");
        if( target->is_corpse() )
                return notify_fail("�������ˣ�ֻ�л��˲��ܾ��ѡ�\n");
        if((int) me->query_skill("tianmo",1) < 80)
                return notify_fail("�����ħ�󷨲������");
        if( (int)me->query("mana") < 2000 ) return notify_fail("�������������\n");
        if( me->query("sen") <= 300 )
                return notify_fail("����񲻹���\n");
        me->receive_damage("sen", 30);
        me->add("mana", -500);
        message_vision( HIY "$Nһ�ַ���$n���������, һ������$n�ĺ���, �����۾���������...\n" NOR, me, target);
        if( random(me->query("max_mana")) > 100 )
                target->revive();
        else
                me->unconcious();
        if( me->is_fighting() )
                me->start_busy(3);
        return 1;
}
