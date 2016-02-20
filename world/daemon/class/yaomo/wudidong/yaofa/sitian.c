// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

    success_adj = 155;
       damage_adj = 125;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����ʴ�죿\n");

           if((int)me->query_skill("yaofa") < 25 )
           return notify_fail("�������̫���ˡ�����\n");   
        if((int)me->query("mana") < 150+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 150 )
                return notify_fail("���޷����о�����\n");
                

        me->add("mana", -150-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 120);

        if( random(me->query("max_mana")) < 50 ) {
                write("����С�����ǽ��춼˯��ȥ�ˡ�\n");
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
                "both",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIR "\n$N���������˼��䣬��ʱ��֪��������ܳ��������󣬷�����$n��ˮ���ӿȥ��\n" NOR,
                        //initial message
                HIR "\nֻ����$n�ҽ�����������Ⱥ��˺ҧ��Ѫ��ģ�����Ҳ��̶ã�\n" NOR, 
                        //success message
                HIR "$n������˦�����ϵ�����������Ȼû�����ˣ������Ǳ������Ϊ�Ǳ���\n" NOR, 
                        //fail message
                HIR "$n���һ������Ⱥ�ƺ������������㣬����$N��ȥ��\n" NOR, 
                        //backfire initial message
                HIR "��Ⱥ��$n���ϼ�̤�������ϳ�������Ѫ��$n��ҧ�����������\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}

