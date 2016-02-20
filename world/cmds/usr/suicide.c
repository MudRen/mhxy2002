// suicide.c
// By tianlin 2001.5.8
// ������ɱ��Ҫ������ݱ�ʶ

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");

	if( !arg ) {
		write("������Ͷ̥��\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("��ɱ�����֣�����Ҫ��Զ������������Ͷ̥��\n");

	if(wizardp(me))
	    return notify_fail("�벻Ҫ��ɱ����ʦ�ʺţ�лл��\n");

	write(
		"�����ѡ����Զ��������ɱ��ʽ�������������Ͼ���Զɾ���ˣ������\n"
		"���������ȷ���Ļ�����������"BLINK HIW"��ݱ�ʶ��\n"NOR);
	CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"����Ѱ��һ���ӱܷ��յķ�����");
	input_to("check_superpasswd", 1, me, 1);
	return 1;
}
// by tianlin 2001.5.8
private void check_superpasswd(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("superpasswd");
	if( crypt(passwd, old_pass)!=old_pass ) {
              write("\n��ݱ�ʶ����\n");
              return;
       }
       write("�������������룺");
       input_to("check_password", 1, me, 1);
}
private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n�����Ҫ��ɱ�ˣ������ʮ�����ڲ���ڣ�����������ˡ�\n\n\n" NOR);
		me->set_temp("suicide_countdown", 30);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :) );
	}
}

private int slow_suicide(object me)
{
	object link_ob;
	int stage;
	string myid, couple;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
		  tell_object(me, 
			HIR "�㻹�� " + stage + " ���ʱ����Ժ�ڡ�"+
			"(��quit���������)\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s(%s) commits a suicide on %s from %s\n", geteuid(me), me->name(), ctime(time()), (string)query_ip_name(me) ) );

	seteuid(getuid());
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
	myid=me->query("id");

	// remove player home.
	rm( "/data/playerhomes/h_"+myid+ __SAVE_EXTENSION__ );

	// remove mailbox.
	rm( "/data/mail/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );

	// remove couple's home as well. (the home is registered by the 
	// couple.)
	couple=me->query("coupld/id");
	if(couple)
	  rm("/data/mail/"+couple[0..0]+"/"+couple+__SAVE_EXTENSION__);


	write("�ðɣ�������:(\n");
	tell_room(environment(me), me->name() +
		"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));
	CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"Ϊ���ӱܳ�����ķ��գ���ǰ���ҽ���ˡ�");
	destruct(me);
	return 0;
}
int halt_suicide(object me)
{
	tell_object(me, "���������ɱ����ͷ��\n");
	CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + "���������¸ҵػ���ȥ��");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:
[1;31mע: ��Ϊ�е���Ұ��Լ����˸����˹һ�,������ȴ����ɱ��,
һ��ȵ�,�벻Ҫ���װ���ݱ�ʶ���߱���,�緢������,
��ʦһ�ɲ����κ�����.[2;37;0m
 
suicide    : ����Ͷ̥
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ���������Լ���ݱ�ʶ��ȷ�����.
 
������ѡ�� :)
 
HELP
);
        return 1;
}
