//By tianlin@mhxy for 2002.1.17

// bighammer.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
       string str;//ҥ�Եı���
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ�ô�����ħ�ƴ�˭��\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("���޷����о������������Լ��ˣ�\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("����û��Ӧ������һ�ΰɣ�\n");
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
		HIC "$N"NOR+HIC"�������˼������ģ�������ֳ����У���Ҷ�����ߣ�������ִ\nһ���޴��ޱȵĽ�ħ�ƣ�������һ����$n"NOR+HIC"��ͷ���£�\n" NOR,
			//initial message
		HIC "���ѹ�����ţ����û��$n"NOR+HIC"ѹ�⣡\n" NOR, 
			//success message
		HIC "����$n"NOR+HIC"��ǧ��һ��֮�ʶ��˿�����\n" NOR, 
			//fail message
		HIC "���ǽ�ħ�Ʊ�$n"NOR+HIC"�Է���һ���������ҵ���$N"NOR+HIC"�Ķ��ţ�\n" NOR, 
			//backfire initial message
		HIC "����Ҹ����ţ����û��$n"NOR+HIC"�ұ⣡\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=HIG+target->name()+HIM"��"HIR+me->name()+HIM"��"HIY"���"HIM"��ѧ"HIW"��������ħ�ơ�"NOR+HIM"��ȥ�����޵ظ���";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
	me->start_busy(1+random(2));
	return 3+random(5);
}

