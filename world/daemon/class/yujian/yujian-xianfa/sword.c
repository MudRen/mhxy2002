// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 50;
        damage_adj = 50;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩ��������\n");

        if((int)me->query("mana") < 300+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 400 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 500 ) {
                write("�������ɽ���û�ա�\n");
                return 1;
        }
        

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "qi",           
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "\n$N�������˾����ģ�����߳�һλ��ò���ŵĽ��ɣ�˫�ָ���һ�ѽ�������Ȼ���֣�����������������$n��\n" NOR,
                        //initial message
                HIR "\n������͡���һ��������$n����͸�������\n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR, 
                        //success message
                HIC "���Ǻ����һ��$n��������ѷɽ���\n" NOR, 
                        //fail message
                HIC "���ǽ��ⱻ$n�Է�������������$N��ȥ��\n" NOR, 
                        //backfire initial message
                HIR "��������$n����͸��������ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}