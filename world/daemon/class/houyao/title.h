/*// weishi.h ��������ʿ, ��ʦ
int ask_me()
{
        string oldtitle;
        object ob, me;
        me = this_object();
        ob = this_player();
        if ((int)ob->query_skill("kurong-changong",1) < 60)
        {
                command("say ���뵱��ʿ���������깦�ɡ�\n");
                return 1;
        }
        oldtitle = ob->query("title");
        if (strsrch(oldtitle, "�������������ҳ�") >= 0)
        {
                ob->set_temp("fight_ok",1);
                command("say �ã���Ȼ������д裬�ǾͿ���ı�������ˡ�\n");
                return 1;
        }
        else
        {
                command("say ֻ�мҳ���������ʿ��\n");
                return 1;
        }
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                command("say ������ʤ����������Ǵ���μҵĺõ��� ! ��ϲ���� !\n");
                command("say ����Ѿ�����ʤ�δ�����ʿ !\n");
                upgrade_title(ob, "��������������ʿ");
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                command("say ����" + RANK_D->query_respect(ob) + 
                        "���ö����ϰ�������ڴ���μ��������г���ͷ�� !\n");
                return 1;
        }
        return 1;  
}
void upgrade_title(object ob,string arg)
{
        string title;
        title=arg+clear_title(ob->query("title"));
        ob->set("title",title);
}
string clear_title(string arg)
{
        if (strsrch(arg, "�������������ҳ�") >= 0)
        {
                arg = replace_string(arg, "�������������ҳ�","");
        }
        return arg;
}
*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 25  )
        {
                command("say ��������ƺ�������");
                return;
        }
        if ((int)ob->query("combat_exp") > 500000 || (int)ob->query("age") >20 )
        {
                command("say ����ô������Ϊͽ���أ�");
                return;
        }
        command("say �ܺã��ܺá���ˮ�����⸴֮�ղ���Զ�ӣ�\n");
        command("recruit " + ob->query("id"));
                ob->set("title","ˮ����Ѳ������");
}
