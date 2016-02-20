
// reboot.c

#include <net/daemons.h>
#include <mudlib.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help (object me);
int main(object me, string arg)
{
	int time;
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");
	if(!arg) {
		write(CHINESE_MUD_NAME + "Ŀǰ����������������"HIR+chinese_number(AUTOBOOT_D->query_time())+ NOR"���ӡ�\n");
		return help(me);
	}
	if(!sscanf(arg,"%d",time)) return help(me);
	if(time<3) return notify_fail("��������������������\n");

	message( "system", HIR"ע�⣡��Ϸ"+chinese_number(time)+"���Ӻ�����������\n"NOR, users() );
	AUTOBOOT_D->set_time(time);

	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: reboot ������
 
X���Ӻ���������Ϸ��
 
HELP
);
        return 1;
}
 

