
#include <login.h>;
inherit F_CLEAN_UP;
object make_body(object ob);
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob,user;
        if(!arg)
                return notify_fail("�÷�:xokip ID\n");
        ob=find_player(arg);
        if(!ob)
        {
        ob = new(LOGIN_OB);
        ob->set("id",arg);
        if( !ob->restore() )
                return notify_fail("û�������ҡ�\n");
        else
                {
            if( objectp(user = make_body(ob)) ) 
     if( user->restore() )  {    
            reset_eval_cost();
            user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        user->set_encoding(ob->query_encoding());       
           user->delete("ok_ip");
           tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                + ")��okip�Ѿ�ɾ��\n");
         log_file( "changepw.log", sprintf("%s %s(%s)ɾ����%s(%s)��okip\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           user->save();
           destruct(ob);
           destruct(user);
           return 1;
        }
        }
        }
        link_ob=ob;
        if(link_ob)
        {
                link_ob->delete("ok_ip");
                link_ob->save();
        tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                        + "��okip�Ѿ�ɾ��\n");
                return 1;
        }
        else
                return notify_fail("�����޷������޸ġ�\n");
        return 1;
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        if(!ob->query("body")) {
          return 0;
        }
        user = new(ob->query("body"));
        if(!user) {
                write("���ڿ������������޸��������ĳ�ʽ���޷����и��ơ�\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());

        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : xokip ID

���ָ�����ɾ����ҵ�okip

HELP
    );
    return 1;
}

