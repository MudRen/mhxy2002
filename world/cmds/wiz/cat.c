//By tianlin@Mhxy for 2002.1.2.�޸�

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return notify_fail("����Ҫ��ʾ�Ǹ�����?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
	cat(file);
 CHANNEL_D->do_channel( this_object(), "sys",
sprintf("�����ӡ�-> ��ʦ��%s(%s) ���ڲ쿴(cat) %s�ļ� \n",me->name(1), geteuid(me),file ,  ));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : cat <����>

��ָ�������ֱ�Ӷ�ȡĳ����֮��ʽ��
HELP
    );
    return 1;
}
