// sgzl
// ��ͻ������

/*
��ͻ����    dodge  -4    parry  -4    damage  25
���������������ɹ���,�ǹŴ������湦��!�����޵�!
*/

// ����ͻ,����ͻ,����ͻ,����ͻ,ǰͻ
// ��ħͻ,���ͻ,����ͻ,����ͻ,����ͻ

inherit SKILL;


mapping *action = ({
        ([      "name":                 "����ͻ",
                "action":
"$N��������,����$w���գ���$n��ȥ�������ƿ�ɽ��һ�㣬��һ�����ۺ�ġ�����ͻ��",
                "dodge":                -15,
                "parry":                -10,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"ֻ��$N���ָ�����������轣������$w��$n��ȫ��ȥ\n"
"����һ�С�����ͻ����",
                "dodge":                -15,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"$N������ǰ������$w���裬һ�С�����ͻ���ó����Ž�â����$n������������",
                "dodge":                -10,
                "parry":                -15,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"$N���˷��������һ����Х������$w������$n��$l��ȥ������ɽ����Х��ġ�����ͻ����ȫ��$n������",
                "dodge":                -10,
                "parry":                -25,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "ǰͻ",
                "action":
"ֻ��$N������أ�ʹ��һ�С�ǰͻ��������$w���ٷɽ���������㽣����ֱ��$n��$l��ȥ",
                "dodge":                -5,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��ħͻ",
                "action":
"$N����ǰ����һʽ����ħͻ�������潣��$N�����һ��,���ϵ�����$n��ȥ��$n�������ܵù�",
                "dodge":                -15,
                "parry":                -15,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "���ͻ",
                "action":
"$N�������Ž�,һʽ�����ͻ��������$w�������ң����������â\n"
"���м����������������Է�",
                "dodge":                -15,
                "parry":                -15,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"ֻ��$N������������,���鼫Ϊ�˷ܣ������������$wһ�̣�\n"
"$wֱ��$nͷ������һ�С�����ͻ����Ȼ��ʫ�续",
                "dodge":                -10,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"ֻ��$w�͵���$n��ȥ,$n����֪��������ͻ��������,��������,�ѱ�ͻ������",
                "dodge":                -20,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"ֻ��$N��$n��ȥ,$n����ʶ�����С�����ͻ��������",
                "dodge":                -15,
                "parry":                -15,
                "damage":               25,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ͻ",
                "action":
"$NͻȻ��ɫͻ�䣡����$wҲ��$nնȥ��\n"
"�ۼ�$N$wֱ��$n��$l��$nȴ��֪��η������С�����ͻ��",
                "dodge":                -5,
                "parry":                -15,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "˫��ͻ",
                "action":
"$N����ͻ�䣬����$w��$n��ȥ,������ý��״���$n,��һ�С�˫��ͻ��ȥ�Ʒ���ʤ��,ֱ��$n��$l",
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
                return notify_fail("������Ƿ�ѣ�ǿ����ͻ�����к����档\n");
        if ((int)me->query("force") < 5)
                return notify_fail("���������㣬ǿ����ͻ�������߻���ħ��Σ�ա�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$NĬĬ������һ�����Ȼ������һ����ͻ������\n", me);
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
        return CLASS_D("yujian") + "/yatu-sword/"+func;
}