// �����ȷ�

inherit SKILL;

mapping *action = ({
([	"action" : "$N��������߳����������£��ҽŽ���������߳���һʽ��׷����硹����$n��$l",
    "dodge" : 10,
	"parry" : -20,
    "damage_type" : "����",
	"skill_name" : "׷�����"
]),
([	"action" : "$NͻȻһ�������ź󷭣�һʽ�����߱�����������$n��$l�߳�����",
        "dodge" : -5,
	   "parry" : -15,
        "damage_type" : "����",
	"skill_name" : "���߱���"
]),
([	"action" : "$Nʹһʽ�����Ʋ��¡����εض��������ڿ���һ�ǣ����ȳ�ʽ����$n���ؿ�",
        "dodge" : 15,
		"parry" : -10,
        "damage_type" : "����",
	"skill_name" : "���Ʋ���"
]),
([	"action" : "$N����һ����������������һʽ����ɨ���ݡ��������Ժ���ǰ��ɨ$n��$l",
    "dodge" : -10,
    "parry" : -20,
    "damage_type" : "����",
	"skill_name" : "��ɨ����"
]),
([	"action" : "$N������ն���˫��������ʹһʽ���������¡�������Ӱ������$n",
     "dodge" : 0,
	"parry" : -20,
    "damage_type" : "����",
	"skill_name" : "��������"
]),
});
int valid_learn(object me)
{
	if( (int)me->query_skill("zhuanlong-force",1) < (int)me->query_skill("chuanyun-tui",1)/2)
		return notify_fail("����ķ���������տ���޷��������Ĵ����ȣ�\n");


	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("���ȷ�������֡�\n");
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
	return CLASS_D("bibotan") + "/chuanyun-tui/" + func;
}


