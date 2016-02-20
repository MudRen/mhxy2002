
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells") <= (int)me->query_skill("bihai-spells") )
		return notify_fail("��ķ�����Ϊ����������޷�ѧϰ�̺����ڡ�\n");
	if( (int)me->query("bellicosity") > 2000 )
		return notify_fail("���ɱ��̫�أ��޷�������ԯ���ڡ�\n");
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("bibotan") + "/bihai-spells/" + spell;

	}

string type() { return "magic";}

