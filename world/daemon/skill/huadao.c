// force.c

#include <ansi.h>

inherit SKILL;
int valid_learn(object me) { return 1; }
string level_description(int level)
{
	int grade;
	string *level_desc = ({
BLU "����ɫä" NOR,
HIB "�ܱ����" NOR,
HIY "��ʶ���" NOR,
HIC "��ͨ԰��" NOR,
YEL "ʶ������" NOR,
HIM "�������" NOR,
WHT "��������" NOR,
CYN "�ɻ�����" NOR,
HIG "�ɶ��칤" NOR,
HIW "԰����˫" NOR,
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
