// zouxiao.c by yushu 2000.11
//xixi
//�ȼ����������������ֵ�д��,���ܸ�xyj2000��һ��,��Ϊ�Ҵ�ûѧ��zouxiao
#include <ansi.h>
inherit SKILL;
int valid_learn(object me) { return 1; }
string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "������ȫ" NOR,
		HIB "��������" NOR,
		HIY "��������" NOR,
		HIC "��ͨ����" NOR,
		YEL "������ɫ" NOR,
		HIM "���Ը߸�" NOR,
		WHT "��������" NOR,
		CYN "�����㾦" NOR,
		HIG "�ɶ��칤" NOR,
		HIW "�＼��˫" NOR,
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
