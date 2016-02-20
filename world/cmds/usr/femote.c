// COMMAND STD femote.c
// Last modified by zeus@DJX Oct.28.1999

#include "/doc/help.h"

int help(object me);

string do_search(object me,string name,string msg,string substr,string text)
{
        if(!msg)
                return 0;

        if(strsrch(msg,substr)!=-1)
        {
                msg = replace_string(msg, "$n", "(�Է�)");
                msg = replace_string(msg, "$N", me->name(1));
                msg = replace_string(msg, "$P", "��");
                msg = replace_string(msg, "$p", "(��/��)");
                msg = replace_string(msg, "$S", RANK_D->query_self(me));
                msg = replace_string(msg, "$s", RANK_D->query_self_rude(me));
                msg = replace_string(msg, "$R", "(�Է������)");
                msg = replace_string(msg, "$r", "(�Է������)");
                msg = replace_string(msg, "$C", "(�Լ����س�)");
                msg = replace_string(msg, "$c", "(�Է����س�)");
                return sprintf("emote ��: %s %s\n%s\n",
                                        name,text,msg);
        }
        return 0;
}

int main(object me, string arg)
{
        mapping emote;
        string *emotes, msg, str;
        int i,c;

        if( !arg || arg == "")
                return help(me);

        emotes = EMOTE_D->query_all_emote();

        msg = "��ѯ���\n";
        msg+= "------------------------------------------------------------\n";
        for(i=0;i<sizeof(emotes);i++)
        {
                emote = EMOTE_D->query_emote(emotes[i]);

                if(emote)
                {
                        str = do_search(me,emotes[i],emote["myself"],arg," [�Լ�����]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["others"],arg," [�����˿���]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["myself_self"],arg,"<�Լ�> [�Լ�����]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["others_self"],arg,"<�Լ�> [�����˿���]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["myself_target"],arg,"<����> [�Լ�����]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["target"],arg,"<����> [�Է�������]");
                        if(str)
                                msg+=str;
                        str = do_search(me,emotes[i],emote["others_target"],arg,"<����> [�����˿���]");
                        if(str)
                                msg+=str;
                }
        }
        msg+= "------------------------------------------------------------\n";
        me->start_more(msg);

    return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : femote <�ַ���>��

���ָ����������� emote ��Ѱ�Һ�����ָ�����ַ���
��emote��

HELP
        );


return 1;
}

string short_help()
{
        return "Ѱ��emote";
}

