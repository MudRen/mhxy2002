// sgzl
// ������������

/*
����������    dodge  -4    parry  -4    damage  25
���������������ɹ���,�ǹŴ������湦��!�����޵�!
*/

// �����,������,˫����,������,������
// ������,������������,����������,���������

inherit SKILL;


mapping *action = ({
        ([      "name":                 "�����",
                "action":
"$N��������,����$w���գ���$n��ȥ�������ƿ�ɽ��һ�㣬��һ�����ۺ�ġ��������",
                "dodge":                -15,
                "parry":                10,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"ֻ��$N���ָ�����������轣������$w��$n��ȫ��ȥ\n"
"����һ�С�����������",
                "dodge":                -5,
                "parry":                -10,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"$N������ǰ������$w���裬һ�С����������ó����Ž�â����$n������������",
                "dodge":                -10,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"$N���˷��������һ����Х������$w������$n��$l��ȥ������ɽ����Х��ġ�����������ȫ��$n������",
                "dodge":                -10,
                "parry":                -5,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"ֻ��$N������أ�ʹ��һ�С���������������$w���ٷɽ���������㽣����ֱ��$n��$l��ȥ",
                "dodge":                -5,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"$N����ǰ����һʽ���������������潣��$N�����һ��,���ϵ�����$n��ȥ,��������������$n�������ܵù�",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������������",
                "action":
"$N�������Ž�,һʽ�������������硹������$w�������ң����������â\n"
"���м����������������Է�",
                "dodge":                -15,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "���������",
                "action":
"ֻ��$N������������,���鼫Ϊ�˷ܣ������������$wһ����\n"
"$wֱ��$nͷ������һ�С���������ᰡ���Ȼ��ʫ�续",
                "dodge":                -10,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����������",
                "action":
"ֻ��$w������佣â���͵���$n��ȥ,$n����֪����������������������,��������,�ѱ���������",
                "dodge":                -20,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��������ҧ",
                "action":
"ֻ��$N��$n��ȥ,$n����ʶ�����С���������ҧ��������",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������",
                "action":
"$NͻȻ��ɫͻ�䣬������ؽ���,�ּ��ٰγ�,����ͽ��׷�������,������������һ��������$wҲ��$nնȥ��\n"
"�ۼ�$N$wֱ��$n��$l��$nȴ��֪��η������С���������",
                "dodge":                -5,
                "parry":                -15,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "˫����",
                "action":
"$N����ͻ�䣬����$w��$n��ȥ,������ý��״���$n,��һ�С�˫������ȥ�Ʒ���ʤ��,ֱ��$n��$l",
                "dodge":                -10,
                "damage":               25,
                "damage_type":          "����"
        ]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("���������Ϊ������޷�ѧϰ������������\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ����������ϰ������\n");
        return 1;
}

int practice_skill(object me)
{
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("yujian-sword");

        if (dod<swo/2)
                return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("������Ƿ�ѣ�ǿ�������������к����档\n");
        if ((int)me->query("force") < 5)
                return notify_fail("���������㣬ǿ���������������߻���ħ��Σ�ա�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$NĬĬ������һ�����Ȼ������һ�������������\n", me);
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
        return CLASS_D("yujian") + "/yujian-sword/"+func;
}