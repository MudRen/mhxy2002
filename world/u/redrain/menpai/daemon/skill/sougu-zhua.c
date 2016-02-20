//sougu-zhua.c ���ѹ�צ��weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N�������������ֻ��أ��������ĳʰ��죬����һ������֮������$n$l",
                "dodge":                 35,
                "parry":                35,
	    "force":		80,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N��������������λ��˫��һ������ͻȻ����������$n$lһ��һ��",
                "dodge":                -25,
                "parry":                -25,
	    "force":		70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ����һ������߳����������С�����ȴ����һ��֮�´����벻���ĽǶ�������$n��$l",
                "dodge":                25,
                "parry":                25,
	    "force":		60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�ٺ�һЦ��˫���ڿ����л����������죡�����ݺ���ͻȻ�ɳ�һ�ƣ�������Ϣ������$n$l",
                "dodge":                -35,
                "parry":                -35,
	    "force":		100,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N����һ�ݣ���$n���������������ʱ��$N���ֱ۾���û����ͷ�Ƶ�����һ������������ػ�����$n$l",
                "dodge":                -25,
                "parry":                -25,
	    "force":		90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����������ת�����������ݰ���$n��ȥ��תһȦ��һ�ƣ����Ʋ���$n��$l",
                "dodge":                35,
                "parry":                35,
	    "force":		60,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$Nһ����Х����������ˮ�����������ƣ�������ת�����಻��������$n����Ҫ��",
                "dodge":                25,
                "parry":                35,
	    "force":		80,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N����һ�ݣ�����ʹ��ɨ���ȣ�˫��ȴ���������ϣ�����ֱ��ػ���$n$l",
                "dodge":                -15,
                "parry":                -15,
	    "force":		60,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("���ѹ�צ������֡�\n");
               if(me->query("family/family_name") != "���")
                return notify_fail("ֻ������ĵ��Ӳ��ܹ�ѧϰ[�ѹ�צ]��\n");
 return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
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
       if(me->query("family/family_name") != "���")
         return notify_fail("ֻ������ĵ��Ӳ��ܹ���ϰ[�ѹ�צ]��\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 4 );
                switch(random(3)) {
                        case 0: return "��������������һ�����죬�����ǹ����������\n";
                        case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
                        case 2: return "ֻ����$n��$l��������һ�� ...\n";
                }
        }
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/sougu-zhua/" + func;
}


