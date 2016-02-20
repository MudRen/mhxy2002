// skyriver.c ������ٷ��� by snowcat
//by tianlin 2001.7.30�޸�
/*
��ӷ�    dodge  -30    parry  -15    damage  25
����Ϊ����ˮ�񣭣���˽����������乥��֮����ȣ����м�
֮����ʤһ�
*/

// �����۶�  ������Ԫ
// ������׾  �������� 
// �������  ��������
// ���۹㺮  Ϸˣ�϶�
#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":
"$N��һ��ʹ��"BLINK+HIM"�������۶���"NOR"�����Ծ��������϶���$w��$n��$lֻһ��",
		"dodge":		-45,
		"parry":		-15,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"ͻȻ$N���˼��������ջص��һ��"BLINK+HIB"��������Ԫ��"NOR"��$w��ջ���һ������������$n��$l",
		"dodge":		-15,
		"parry":		-10,
		"damage":		35,
		"damage_type":	"����"
	]),
	([	"action":
"$N�л�������һ�ζ���$w��ȴ�䲻��һ��"BLINK+HIY"��������׾��"NOR"˫��б����תɨ��������$n��ʱ�����ֽ�",
		"dodge":		-20,
		"parry":		-20,
		"damage":		25,
		"damage_type":	"����"
	]),
	([	"action":
"$N������$w����ɲ�����$n���⣬��ͷһ��"BLINK+HIR"���������ġ�"NOR"��$n��æ��ת��ֻ��$w��$l��ֻ������֮����",
		"dodge":		-40,
		"parry":		-5,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"$N�����������$wһ�����ģ�$n��δ����������һ��"BLINK+HIC"�����������"NOR"ֱ����$n��$l",
		"dodge":		-35,
		"parry":		-25,
		"damage":		35,
		"damage_type":	"����"
	]),
	([	"action":
"$n��Ȼ����$N����һ̧ͷֻ��$N��԰��$wһʽ"BLINK+WHT"���������á�"NOR"����������һ�㾶ֱɨ��$n$l",  
		"dodge":		-25,
		"parry":		-10,
		"damage":		20, 
		"damage_type":	"����"
	]),
	([	"action":
"$N�ó�һ��"BLINK+HIW"�����۹㺮��"NOR"������Ȧ�⸴�ָ���ײ��Ȧ�ڣ�ֻ��$w���·�����Ѹ�ײ����ڶ�֮������$n��$l",
		"dodge":		-25,
		"parry":		-20,
		"damage":		30,
		"damage_type":	"����"
	]),
	([	"action":
"$N��Цһ��������˫��һ��"BLINK+MAG"��Ϸˣ�϶�"NOR"��ˣ������$w�ַ���һ�̣�$w����ͷ����$n",
		"dodge":		-35,
		"parry":		-15,
		"damage":		25,
		"damage_type":	"����"
	]),
	
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 40 )
		return notify_fail("�������������û�а취������ٷ���\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "rake" )
		return notify_fail("���������һ���ٲ������ٷ���\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="rake" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ����ٷ���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ������ٷ���\n");
	return 1;
}
int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/skyriver-rake/" + func;
} 
