//by tianlin 2001.7.30
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;


	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ"HIY"����ѹ��"NOR"��\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		write("��⣬û������,FUCK��\n");
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
		HIW "\n$N�������˾����ģ�����г���"HIY"����"NOR+HIW"����Ӱ��"HIY"����"NOR+HIW"һ���շ�������һ���������С�\n���н���"BLINK+HIM"������¥"NOR+HIW"����$n��ͷ���ݺݵ�ѹ����\n" NOR,
			//initial message
		CYN "\n\n                         _//|.-~~~~-,
                       _/66  \       \_@
                      (')_   /   /   |
  "HIB"���Ǳ�������˭?!"NOR+CYN"      '--'|| |-\  /
                           //_/ /_/ \n" NOR, 
			//success message
		HIC "\n˭֪$n�����̫Сû��ѹ�ϣ���ʵ��ϧ��\n" NOR, 
			//fail message
		HIC "��������$n����һ�ߣ�һ��������$N���˹���,һͷ����$N��ͷ���ϣ�\n" NOR, 
			//backfire initial message
		HIC "���һ��: "BLINK+HIR"��\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

