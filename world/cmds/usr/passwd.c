//By tianlin@mhxy for 2002.1.21,����passwd˫�㱣��

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write(HIC"Ϊ�˰�ȫ�����������������"HIW"��ݱ�־"NOR+HIC"��"NOR);
	input_to("check_superpasswd",  1, me, 1);
	return 1;
}
private void check_superpasswd(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("superpasswd");
	if( crypt(passwd, old_pass)!=old_pass ) {
              write(HIG"\n��ݱ�ʶ����\n"NOR);
              return;
       }
       write(HIR"\n\nΪ�˰�ȫ�ڼ����������������룺\n\n"NOR);
       write("�������������룺");
       input_to("get_old_pass", 1, link_ob );
}
private void get_old_pass(string pass, object ob)
{
	string old_pass;

	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write(HIG"�������\n"NOR);
		return;
	}
	write(HIY"�������µ����룺"NOR);
	input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
	write(HIY"\n��������һ���µ����룺"NOR);
	input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("�Բ�������������벢����ͬ������ʹ��ԭ�������롣\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("password", new_pass) ) {
		write("������ʧ�ܣ�\n");
		return;
	}

	ob->save();
	write("�������ɹ���\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ : passwd
 
���ָ������޸�����������롣
 
HELP
    );
    return 1;
}
 
