// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("bellicosity") < (int)me->query_skill("beiming",1) * 10 )
                return notify_fail("���ɱ���������޷����������ı�ڤ�񹦡�\n");

/*	if( (int)me->query_skill("beiming", 1) >= 250 )
		return notify_fail("����������ޣ��Ա�ڤ���������˼��ޡ�\n");
*/
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ڤ��ֻ����ѧϰ��Ӧ������ߣ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("kof") + "/beiming/" + func;
}

