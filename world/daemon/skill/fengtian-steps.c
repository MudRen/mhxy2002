// ���������Ʋ�
//creay by focus

inherit SKILL;

string *dodge_msg = ({
        "$n����������ת��$N�����\n",
        "$n���ն���$N��ǰ��Ȼʧȥ$n����Ӱ��\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 0 )
                return notify_fail("�������������û�а취�����������Ʋ���\n");

        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("��������������������������������Ʋ���\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("lingjie")+"/fengtian-steps/" + func;
}
