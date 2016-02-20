// shutdown.c
//by tianlin@Mhxy for 2002.3.10,�޸ĺ�login��Ҿ����
#include <net/daemons.h>//�����ǵ��ð汾,����MUD_NAME����� 
#include <ansi.h>//�����ǵ�����ɫ����
#include <command.h>//�����ǵ���include�µ�command.h����
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;

	if( me->query("id") != "tianlin") //��������id.˭ʹ��.������������tianlin.����ֻ��tianlinʹ��
       return notify_fail("Ŀǰϵͳֻ����tianlin������\n");

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");

	message( "system","�Բ�����Ϸ�������������Ժ�һ�����������λ����Ρ�\n"NOR, users() );
	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}
	log_file("static/CRASHES","�� "+BLU+ me->query("name")+NOR+HIY" <"+me->query("id")+">"+NOR"������������"+MUD_NAME+"���ڣ�"
		+BJTIME_CMD->chinese_time(1,time()) + "\n");
	write_file("/log/static/shutdown",""+HIY+me->query("name")+NOR+"("+HIB+me->query("id")+NOR+") "HIC"shutdown "NOR+WHT+MUD_NAME+"��:"
		+ BJTIME_CMD->chinese_time(1,time()) + "\n", 1);//�����ǵ���bjtime�����chinese_timeʹ��1
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();//����dns_master���ҹر�
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
 
