// uptime.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <mudlib.h>
#include <ansi.h>

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int l, t, d, h, m, s;
	string time;

	l = AUTOBOOT_D->query_time();
	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	if(l>=60)
		write(CHINESE_MUD_NAME + "�Ѿ�ִ����" + time + "��\n");
	else 
		write(CHINESE_MUD_NAME + "�Ѿ�ִ����" + time +"��Ŀǰ����������������"HIR+chinese_number(l)+ NOR"���ӡ�\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ����������λ����Ρ������Ϸ�Ѿ�����ִ���˶��.
 
HELP
    );
    return 1;
}
