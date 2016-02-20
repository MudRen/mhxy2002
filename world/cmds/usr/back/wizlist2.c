// by tianlin 2001.7.1

#include <ansi.h>
inherit F_CLEAN_UP;
mapping levels=([
        "(admin)"       :       "[1;37m��    ��[2;37;0m",
        "(arch)"        :       "[1;36m�� �� ʦ[2;37;0m",
        "(wizard)"      :       "[1;33m��    ʦ[2;37;0m",
        "(apprentice)"  :       "[1;35m��ϰ��ʦ[2;37;0m",
        "(immortal)"    :       "[1;32m������ʦ[2;37;0m",
        "(elder)"       :       "[31m�������[2;37;0m",
]);     
string query_time(int time);

void create() { seteuid( getuid() ); }

int main(object me, string arg)
{
        string *list;
        int i, inv=0;
        string msg, time_msg;
        object ob, body;
        msg=""HIW"��"HIG"�λ�"HIW"���Ρ�"HIG"����վ����Ա������\n"NOR;
        msg+=""HIC"�ԡ�"HIB"����������������������������������������������������������������������������������"HIC"�ԡ�\n"NOR;
        msg+=""CYN"         ������        Ӣ��<id>   Ȩ�޵ȼ�          ״̬          ��������˵��    \n"NOR;
        msg+=""HIB"������������������������������������������������������������������������������������������\n"NOR;


        list = sort_array(SECURITY_D->query_wizlist(), 1);

        for(i=0;i<sizeof(list);i++)
        {
                inv=0;
                ob=new(LOGIN_OB);
                ob->set("id", list[i]);
                ob->restore();
                if(objectp(body=find_player(list[i])) && !body->query("env/invisibility"))
                {
                        time_msg=sprintf(" ���ߣ�%s", 
                                query_time(body->query_temp("temp_time")));
                        inv=1;
                }
                else time_msg=sprintf(" ���ߣ�%s", 
                        query_time(ob->query("last_on")));
                msg+=sprintf("\t  %-13s%-9s  %s%s%-26s%s%s\n", ob->query("name"), list[i],
                        levels[SECURITY_D->get_status(list[i])], 
                        inv?HBRED+HIY:NOR, time_msg, NOR,
                        ob->query("duty")?ob->query("duty"):"������������"); 
                destruct(ob);
        }
        msg+=""HIC"�ԡ�"HIB"���������������������������������������������������������������� "HIW"�λ�����"HIB" ��������"HIC"�ԡ�\n"NOR;
        msg+=sprintf(""HIR"��"HIW" %s (�ൺ��վ)"HIC" ���ڹ���%sλ����Ա��\n"NOR, MUD_NAME, chinese_number(sizeof(list)));
        write(msg);
        return 1;
}

string query_time(int time)
{
        string msg;
        int day, hour, min;
        
        time=time()-time;
        
        msg="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;
        if(min<1)
                min=1;
        if(day)
                msg+=sprintf("%s��", chinese_number(day));
        if(day<10 && hour)
                msg+=sprintf("%sСʱ", chinese_number(hour));
        if(!day && hour<20 && min)
                msg+=sprintf("%s����", chinese_number(min));
        return msg;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wlist

��; : �г�Ŀǰ���е���ʦ����(��������ʦ)��
HELP
     );
     return 1;
}

