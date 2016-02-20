//�����β�����dragonfight.c
// cglaem...12/19/96.
//meipai skill(only dragon related NPCs can use it)

inherit SKILL;
#include <ansi.h>;
mapping *action = ({
	([	"action":
"$N����Ծ��һ��"+BLINK""+HIC"���������졹"NOR+"��˫������ɽ����֮�ƻ���$n��$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		150,
		"damage_type":		"����",
		"weapon" :		"˫��",
		"parry_msg":	"ֻ�������ϡ�һ������$N���ָ�",
	]),
	([	"action":
"$N���˷�����ͻȻ������ǰ����ָ�繳����׼$n��$lһ��ץ�˹�ȥ",
		"dodge":		10,
		"parry":		-20,
		"force":		100,
		"damage_type":		"ץ��",
		"weapon":		"������ָ",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
	([	"action":
"ֻ��$Nһ����˫��������һ��ɨ��$n����һ��"+BLINK""+HIC"��������β��"NOR+"�����Ƿ���ʤ��",
		"dodge":		-10,
		"parry":		-20,
		"force":		120,
		"damage_type":		"����",
		"weapon":		"˫��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
	([	"action":
"$N����������ʹ��һ��"+BLINK""+HIC"����ս��Ұ��"NOR+"��Х���к�����ϣ���$nֱײ����",
		"dodge":		10,
		"parry":		-10,
		"force":		100,
		"damage_type":		"ײ��",
		"weapon":		"ȫ��",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
            ([	"action":
"ֻ��$Nһ������ڰ�գ�һ��"+BLINK""+HIC"�������ĺ���"NOR+"����δ��������ȫ��������$n",
		"dodge":		0,
		"parry":		-20,
		"force":		150,
		"damage_type":		"����",
		"weapon":		"����",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
            ([	"action":
"$N����һ������$n�������һȭ������"+BLINK""+HIC"������������"NOR+"�������ף������ޱ�",
		"dodge":		10,
		"parry":		-30,
		"force":		180,
		"damage_type":		"����",
		"weapon":		"ȭͷ",
                "parry_msg":    "ֻ�������ϡ�һ������$N���ָ�",
	]),
});

int valid_learn(object me)
{
	if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
		return notify_fail("��������ķ���������տ���޷������������β�����\n");


	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�����β���������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
                return notify_fail("��������ķ���������տ���޷������������β�����\n");

	if( (int)me->query("sen") < 50)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");

	if( (int)me->query("kee") < 50 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -20);

	return 1;
}

string perform_action_file(string func)
{
	return CLASS_D("dragon") + "/dragonfight/" + func;
}
