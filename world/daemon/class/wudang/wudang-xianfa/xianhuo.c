//By tianlin@mhxy for 2001.9.30
//�벻Ҫ��!
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
		return notify_fail(CYN"��Ҫ��˭ʹ��"YEL"����"BLINK+HIR"�ɻ�"NOR+CYN"��\n"NOR);

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail(CYN"��ķ���������\n"NOR);

	if((int)me->query("sen") < 20 )
		return notify_fail(HIC"��ľ����޷����У�\n"NOR);

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write(MAG"���,û��������\n"NOR);
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
		YEL "$N�������˼������ģ����������"NOR+HIR"��"NOR+HIW"��"NOR+BLINK+HIW"���ܴ��"NOR+HIW"��"NOR+HIR"��"NOR+YEL"\nֻ�����ܿ���絽$n��ͷ��,���˺�һ���Ϩ��\n" NOR,
			//initial message
		HIC "���$n�Ѿ����յò��������ˣ�\n" NOR, 
			//success message
		HIW "����$n��һ˲����˹�ȥ��\n" NOR, 
			//fail message
		HIB "���Ǵ��$n�Է���һ����������$N������˹�����\n" NOR, 
			//backfire initial message
		HIC "���$n�Ѿ����յò��������ˣ�\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

       me->start_busy(1+random(1));
       target->start_busy(1+random(2));
       return 3+random(4);
}

