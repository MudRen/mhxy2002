inherit SKILL;

#include <ansi.h>

string level_description(int level)
{
        if ( level < 10 )
                return BLU "������ʼ" NOR;
        else if ( level < 30 )
                return HIB "�����;" NOR;
        else if ( level < 60 )
                return YEL "�ռ�����" NOR;
        else if ( level < 100 )
                return CYN "��ͷ����" NOR;
        else if ( level < 150 )
                return HIW "����ľ��" NOR;
        else
                return HIR "�޿ɾ�ҩ" NOR;
}
int valid_enable(string usage)
{
        return usage=="force";
}
int practice_skill(object me)
{
        return notify_fail("������ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("idle-force") + "/idle-force/" + func;
}

