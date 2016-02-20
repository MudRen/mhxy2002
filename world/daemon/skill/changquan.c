//��ȭ changquan.c
//menpai skill(can also be used by non-menpai NPCs)

inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N����һ�����������һ��[37m�������ڡ�[2;37;0m��׼$n�ı��Ӻ��������˹�ȥ",
                "dodge":                5,
                "parry":                5,
	    "force":		90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�֣���ȭ������һ��[36m���β�Ѱ�ߡ�[2;37;0m����$n��$l�к���ȥ",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��ȭ��$n����һ�Σ�����ʹ�˸�[33m��Ҷ��͵�ҡ�[2;37;0m��$n��$l����һץ",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N����һ������ȭ��������ȭ���磬һ��[31m���ڻ����ġ�[2;37;0m�Ʋ��ɵ��ػ���$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N������ʽ��һ��[1;36m��˫������[2;37;0mʹ�û����з硣����ȴ����һ������$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������𣬴��һ������������[1;32m�������ཻ��[2;37;0m��\n������$n���һ������ȭ����$n�������˹�ȥ",
                "dodge":                5,
                "parry":                5,
	    "force":		120,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�����󹭲���˫��ʹ�˸�[35m������Ʊա�[2;37;0m��$n��$lһ��",
                "dodge":                5,
                "parry":                5,
	    "force":		50,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����������һ����ȭ����$n$l������һȭ�߹�һȭ��\n��һ�е����ֻ��൱���ţ�����[1;33m������������[2;37;0m",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ�����ʹ�˸�[1;32m�������̸���[2;37;0m������ɨ��$n��$l",
                "dodge":                5,
                "parry":                5,
	    "force":		50,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��ת�����ƻ��أ����Ʒ���ʹ�˸�[1;32m��������ɽ��[2;37;0m��$n��ͷһ��",
                "dodge":                5,
                "parry":                5,
	    "force":		90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С�\n˵ʱ����ʱ�죬ֻ��$Nһ��������˫���ѵ���$n��$l",
                "dodge":                5,
                "parry":                5,
	    "force":		100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("����ȭ������֡�\n");
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
	if( (int)me->query("sen") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
 return CLASS_D("fighter") + "/changquan/"+func;
}
