//������100�����II
// guanshi.c ƽ���ǿ�ջ����
//����lywin 2000/6/1 ��ͯ��
#include <ansi.h>
#include <command.h>
inherit NPC;

string ask_gongzuo();
void create()
{
        set_name("����", ({"guan shi", "guan"}));
        set("gender", "����");
        set("age", 35);
        set("long", 
                "����ƽ����ջ�Ĺ��£���Ȼ��æ����ȴ�ܿ��ġ�\n");
        set("qi", 100);
        set("max_kee", 100);
        set("sen", 100);
        set("max_sen", 100);
        set("per", 22);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: ask_gongzuo :),
                "panzi": (: ask_gongzuo :),
        ]) );

        setup();
        carry_object("/obj/loginload/linen.c")->wear();
}

string ask_gongzuo()
{
        object me,ob;
        me = this_player(); 

        if( me->query_temp("gongzuo/xipanzi")< 1)
                return "�㻹����ȥ����С������к��ɡ�\n";
        if( me->query_temp("gongzuo/gepanzi")> 0)
                return "�Ҳ��Ǹ��������������ѵ��㶪������";
        ob = new("/d/kaifeng/obj/zhangpanzi");
        ob->move(me);
        me->set_temp("gongzuo/gepanzi", 1);
        message_vision("���¸���$Nһ�������ӡ�\n",me);
        return "�ðɣ����ȥ����ϴ�ϸɾ���Щ���Ӱɡ�";

}