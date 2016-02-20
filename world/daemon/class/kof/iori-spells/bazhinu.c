#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 140;
        damage_adj = 130;
 

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭����[��ǧ����ʰҼʽ.����Ů]��\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("���޷����о�����ȥ������\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("������Ϊʲô���������ˣ�\n");
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
                HIG "$N�������˼������ģ�"NOR""BLINK HIR"[��ǧ����ʰҼʽ.����Ů]"NOR""HIG",һ��Ӱ�Ӵ�$N�󴩳�,��һ��ı���$n...\n" NOR,
                        //initial message
                HIY "һ����Ϯ��,$n��Ӱ��ץס,���顱�ľ���,$n��ը����!\n" NOR, 
                        //success message
                HIW "����$n����Ĭ���������Ϊ����.\n" NOR, 
                        //fail message
                HIR "����Ӱ��ȴʧȥ�˿��ƣ����ɼ���$N���ը��!\n" NOR, 
                        //backfire initial message
                HIY "һ����Ϯ��,$n��Ӱ��ץס,���顱�ľ���,$n��ը����!\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}

