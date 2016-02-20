// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ��[1;36m�������ƶˡ�[2;37;0m�������$N��һ�С�\n",
	"$n�������һ�ݣ�ʹ��һ��[1;32m���������ӡ�[2;37;0m���ܹ���$N�Ĺ�����\n",
	"$nʹ��[37m��ǧ��������[2;37;0m��ǡ�ö����$N�Ĺ��ơ�\n"
       "����$n����Ʈ��,һ��[35m��Ц���쳾��[2;37;0m,����һ�ݣ����ѱܿ���\n",
       "$nʹ��[33m�����¹�����[2;37;0m,������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
       "$nһ��[36m���������ʡ�[2;37;0m,����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취���������²���\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("������������������������������²���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
