// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

string level_description(int level)
{
	int grade;
	string *level_desc = ({
	BRED+	BLU "��ͨ����" NOR,
	BRED+	BLU "��֪һ��" NOR,
	BYEL+	HIB "֪�����" NOR,
	BYEL+	HIB "�Ĳ��Ȼ" NOR,
	BBLU+	YEL "��ѧ���" NOR,
	BBLU+	YEL "�߲�˶��" NOR,
	BRED+	HIG "��ѧ����" NOR,
	BMAG+	HIW "ѧ��Ž�" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

