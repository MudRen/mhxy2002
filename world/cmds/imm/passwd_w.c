// ��ע������!����������֮�ݺ�������(202.103.98.74-5555)
// �� ���� ��С����(xhm)������ƽ(tianping)  
// passwd_w.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
        if (ob->query("password_w")) {
                write("Ϊ�˰�ȫ���������������ԭ������ʦר�����룺");
                input_to("get_old_pass", 1, ob);
                return 1;
        }
        write("�������µ���ʦר�����룺");
        input_to("get_new_pass",1,ob);
        return 1;
}

private void get_old_pass(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("password_w");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("�������\n");
                return;
        }
        write("�������µ���ʦר�����룺");
        input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
        write("\n��������һ���µ���ʦר�����룺");
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
        if( !ob->set("password_w", new_pass) ) {
                write("������ʧ�ܣ�\n");
                return;
        }

        ob->save();
        write("�������ɹ�\��\n");
}

int help(object me)
{
        write(@HELP
ָ���ʽ : passwd_w
 
���ָ������޸�����������롣
 
HELP
    );
    return 1;
}
