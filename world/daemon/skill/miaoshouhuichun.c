// ���ֻش�
// 97/9/30  by Aug

inherit SKILL;




int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("literate", 1) < 40 )
		return notify_fail("�����ѧ�������㣬�����������ֻش��ľ��衣\n");
		
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취ʹ�����롣\n");

	return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}



