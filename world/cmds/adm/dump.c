// dump.c (should be admin cmd?)
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
	string dump;
	seteuid(geteuid(me));
	write(RED"����Dump������\n"NOR);
	dumpallobj();
	dump = read_file("/obj_dump");
	me->start_more(dump);
	write(GRN"������Dump��ɣ�\n"NOR);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : dump
 
�������ڴ��е������״̬dump����Ŀ¼��һ������
OBJ_DUMP���ļ��С�

HELP
    );
    return 1;
}
 
