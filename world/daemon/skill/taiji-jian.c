//[4;53m[1;31mBy tianlin@mhxy for 2001.9.30[2;37;0m

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ��"HIR"��"NOR+HIW"̫������"NOR+HIR"��"NOR"������$w��һ�����߰����$n��$l",
		"dodge":		0,
		"damage":		70,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ����ɽ�����е�"HIR"��"NOR+HIY"������ħ"NOR+HIR"��"NOR"���������ն��$n��$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ��"HIR"��"NOR+HIC"�˷���"NOR+HIR"��"NOR"�����ζ�Ȼ�������ߣ�����$wն��$n��$l",
		"dodge":		0,
		"damage":		80,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�й�ֱ����һʽ"HIR"��"NOR+HIG"���ѵ�ˮ"NOR+HIR"��"NOR"��׼$n��$l�̳�һ��",
		"dodge":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һԾ������$wһ��"HIR"��"NOR+HIW"�������"NOR+HIR"��"NOR"��׼$n��$lбб�̳�һ��",
		"dodge":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$wƾ��һָ��һ��"HIR"��"NOR+CYN"��ȥ����"NOR+HIR"��"NOR"����$n��$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취��̫��������\n");

	if( (string)me->query_skill_mapped("force")!= "wudang-force")
		return notify_fail("̫��������������䵱���ڹ���������\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ̫��������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ��̫��������\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("wudang") + "/taiji-jian/" + action;
}
