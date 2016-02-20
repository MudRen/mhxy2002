#include <ansi.h>
inherit F_CLEAN_UP;
string *mission,*titlemission; 
string get_titlemission( string );
string fill_blank(string type, int num);
string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD });
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}
int level(mixed, mixed);
string get_mission( string );
int main(object me, string arg)
{
        int i;
        string *list, hood="", str, msg, scr, att, showtime;
        int bos_n, adm_n, arc_n, ang_n, wiz_n, app_n, gen_n, imm_n,eld_n, j, k, time, day, hour, min;
        object login,ob,body;
        mission = explode(read_file("/adm/etc/renwu"), "\n");
        titlemission = explode(read_file("/adm/etc/job"), "\n");
       list = sort_array(SECURITY_D->query_wizlist(), (: level :));
        //�õ����ּ�����ʦ�ĸ�����
        for(i=0; i<sizeof(list); i++) {
                switch (wizhood(list[i])) { 
                        case "(admin)"          :adm_n++;break;
                        case "(arch)"           :arc_n++;break;
                        case "(wizard)"         :wiz_n++;break;
                        case "(apprentice)"     :app_n++;break;
                        case "(immortal)"       :imm_n++;break;
                        case "(elder)"          :eld_n++;break;
                }
        }
        str=""HIW"��"HIG"�λ�"HIW"���Ρ�"HIG"����վ����Ա������\n"NOR;
        str+=""HIC"�ԡ�"HIB"����������������������������������������������������������������������������������"HIC"�ԡ�\n"NOR;
        str +=WHT"��ʦ�ȼ�����       ��ʦID    ״̬  ��ʦ���񼶱�    ��������˵��    \n"NOR;
        str+=""HIB"������������������������������������������������������������������������������������������\n"NOR;
        for(i=0; i<sizeof(list); i++) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        switch (hood) { 
                                case "(admin)"          :msg =HIW"  ��    ��  "NOR;k=adm_n;break;
                                case "(arch)"           :msg =HIC"  �� �� ʦ  "NOR;k=arc_n;break;
                                case "(wizard)"         :msg =HIY"  ��    ʦ  "NOR;k=wiz_n;break;
                                case "(apprentice)"     :msg =HIM"  ��ϰ��ʦ  "NOR;k=app_n;break;
                                case "(immortal)"       :msg =HIG"  ������ʦ  "NOR;k=imm_n;break;
                                case "(elder)"          :msg =HIB"  �������  "NOR;k=imm_n;break;
                        }
                        j=1;
                } else {
                        msg="";
                        j++;
                }
                if ( k == 1) scr=WHT"������"NOR;
                else scr=WHT"���ש�"NOR;

                if ( k!=j && k!=1 && j!=1 ) scr=WHT"  �ǩ�"NOR;
                if ( k==j && k!=1 && j!=1 )     scr=WHT"  ����"NOR;
                   login = new(LOGIN_OB);
                   ob = new(LOGIN_OB);
                   body = LOGIN_D->make_body(ob);
                   me=this_player();
                 if(objectp(login = find_player(list[i])) && me->visible(login)) {
                        att=HIG"����"NOR;
                } else {
                        att="����";
                }
                
                time /= 60;
                min = time%60;
                time /= 60;
                hour = time%24;
                time /= 24;
                day = time;

//                showtime=sprintf("%s%s%s",day?sprintf("%d��",day):"",
//                                        hour?sprintf("%dСʱ",hour):"",
//                                        min?sprintf("%d����",min):"С��һ����");
                 showtime=sprintf(HIR"��"NOR);
                if ( wizhood(list[i])!="(elder)" ) {
                        str += sprintf("%-12s%s "YEL"%-10s"NOR"%s %s%s",msg, scr, list[i], att, get_mission( list[i] ), get_titlemission( list[i]));
                        str += fill_blank(remove_ansi(get_mission( list[i])), 15)+showtime+"\n";
                }
                if (wizardp(me) && wizhood(list[i])=="(elder)" ) {
                        str += sprintf("%-12s%s "YEL"%-10s"NOR"%s %s%s",msg, scr, list[i], att, get_mission( list[i] ), get_titlemission( list[i]));
                        str += fill_blank(remove_ansi(get_mission( list[i])), 15)+showtime+"\n";
                }
        }
        str+=""HIC"�ԡ�"HIB"���������������������������������������������������������������� "HIW"�λ�����"HIB" ��������"HIC"�ԡ�\n"NOR;
        str+=sprintf(""HIR"��"HIW" %s (�ൺ��վ)"HIC" ���ڹ���%sλ����Ա��\n"NOR, MUD_NAME, chinese_number(sizeof(list)));
        me->start_more(str);
        return 1;
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob2) - wiz_level(ob1);
        return ob1 < ob2?-1:1;
}
string get_mission( string wiz)
{
        int i;
        string wname,wmin;
        for(i=0; i<sizeof(mission); i++) {
                if( mission[i][0]=='#' || sscanf(mission[i], "%s %s",
                        wname, wmin)!=2 ) continue;
                if(wname==wiz) return wmin;
        }
        return YEL"�� ����δ�� ��"NOR;
}
string get_titlemission( string wiz)
{
        int i;
        string wtname,wtmin;
        for(i=0; i<sizeof(titlemission); i++) {
                if( titlemission[i][0]=='#' || sscanf(titlemission[i], "%s %s",
                        wtname, wtmin)!=2 ) continue;
                if(wtname==wiz) return wtmin;
        }
        return NOR CYN"�� ��ʱû�� ��"NOR;
}  
string fill_blank(string type, int num)
{
        string bak;
        int i, j;
        bak="";
        i=strlen(type);
        for (j=0; j<num-i; j++ )
                bak+=" ";
        return bak;
}
int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ��������ʦ��ǰ����

HELP
     );
     return 1;
}
