// shutdown.c

#include <net/daemons.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");

	message( "system", BLINK HIC"�Բ�����Ϸ�������������Ժ�һ�����������λ����Ρ�\n"NOR, users() );
	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}
	log_file("static/CRASHES", geteuid(me) + "��������"+MUD_NAME+"�ڣ�"
		+ ctime(time()) + "\n");
	write_file("/log/static/shutdown", geteuid(me) + "��������"+MUD_NAME+"�ڣ� "
		+ ctime(time()) + "\n", 1);
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: shutdown
 
��������������Ϸ��
 
HELP
);
        return 1;
}
 
