// yulong-steps.c ��

inherit SKILL;

string *dodge_msg = ({
        "����$n����һת��ʹ�������ξ��졹����ز������ܿ�����һ�С�\n",
        "$nһ�С�������β����������ת��ٿ����һ��Ų�������ߡ�\n",
        "$n����Ʈ����հ֮��ǰ�������ں�ȴ�ǡ����ɷ��衹������\n",
        "$nʹ�������ڻ�Ծ����������ˮ�滬��һ�㣬���λ��˿�ȥ��\n",
        "����$n����ӰƮƮ���죬��˿��������������һʽ���������̡���\n"
});

int valid_enable(string usage)
{
        return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 35 )
                return notify_fail("�������̫���ˣ���������������\n");
        me->receive_damage("kee", 25);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("bibotan") + "/yulong-steps/" + action;
}

