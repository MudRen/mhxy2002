inherit SKILL;
string *dodge_msg = ({
        "$nȫ����ǧ�ٸ���Ӱ,��������$N��һ�С�\n",
        "$n���۵�����μ������㿪$N������һ����\n",
        "$n������������Х�������������⡣\n",
        "$n˫����̤�����������ޱ�����ص������ߡ�\n",
        "$n���λ�ʵΪ��,�㿪��$N��һ�С�\n",
        "$n�ڿ�һԾ��˫�������̤���㿪���ߡ�\n",
        "$n���λζ���ȫ����������Ӱ�ӳ����⡣\n",
        "$n����һ������������һ���ޱȹ��������Ť���ŵ������ߡ�\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("�������̫���ˣ���������ħ�����˲���\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("����������㣬��������ħ�����˲���\n");
        me->receive_damage("kee", 30);
        me->add("force",-5);
        return 1;
}
