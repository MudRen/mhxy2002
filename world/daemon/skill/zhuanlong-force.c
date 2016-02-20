
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("ת��������ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("bibotan") + "/zhuanlong-force/" + func;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 50 ) return 2;
	else if ( level < 100 ) return 3;
	else if ( level < 150 ) return 4;
	else if ( level < 200 ) return 5;
	else if ( level < 250 ) return 6;
	else if ( level < 300 ) return 7;
	else if ( level < 350 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 3 )
		return HIB "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 5 )
		return HIM "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 7 )
		return WHT "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 9 )
		return HIY "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else 
		return HIW "��"+chinese_number( stage(level) )+"�㡡" NOR;
}

