inherit SKILL;


mapping *action = ({
	([	"name":			"�ɻ�����",
		"action":
"$N����$w�󿪴��أ�ÿһ����$n��ȥ�������ƿ�ɽ��һ�㣬��һ���Ƶ��۵ġ��ɻ����ࡹ",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"ѩ������",
		"action":
"ֻ��$N�������ˣ�������ббԾ������$w��ֱ����$n��$l��ȥ\n"
"����һ�С�ѩ�����졹��",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"����"
	]),
        ([      "name":                 "�仨��ѩ",
                "action":
"$N������ǰ������$w���裬һ�С��仨��ѩ���ó����Ž�â����$n������������",
		"dodge":		-10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����׷��",
                "action":
"$N���˷��������һ����Х������$w�������ֱָ$n��$l������ɽ����Х��ġ�����׷�꡹��ȫ��$n������",
                "dodge":                -10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�����ķ�",
                "action":
"ֻ��$N�����أ�ʹ��һ�С������ķ���������$w�������ó���㺮�ǣ�ֱ��$n��$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "̫�׷ɻ�",
                "action":
"$N��ȻԾ��һʽ��̫�׷ɻ��������潣����$n���ļ������������������������꣬$n�������ܵù�",
		"dodge":		-5,
		"parry":		-5,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"��Ӱ��",
		"action":
"$N�������Ž��������ֽ���ס������һʽ����Ӱ�񻨡�������$wƽƽ�̳���\n"
"���⼱����������֪����δ�",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"��Ʈ���",
		"action":
"$N��һ���������������߽���һ������һ����һʽ����Ʈ��ҡ�����������Ʈ�ݣ���������Ĺ���$n��$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("���������Ϊ������޷�ѧϰ�ɻ�������\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ������\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("feihua-sword");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ���ɻ������к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ���ɻ��������߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NĬĬ������һ�����Ȼ������һ��ɻ�������\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("yhg") + "/feihua-sword/"+func;
}
��
