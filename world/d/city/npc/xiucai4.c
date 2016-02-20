inherit NPC;
#include <ansi.h>
string * degree_desc = ({
       BLU "��ä" NOR,
       BLU "ͯ��" NOR,
       BLU "���" NOR,
       CYN "����" NOR,
       CYN "��Ԫ" NOR,
       CYN "��ʿ" NOR,
       CYN "��Ԫ" NOR,
       GRN "��ʿ" NOR,
       GRN "̽��" NOR,
       GRN "����" NOR,
       GRN "״Ԫ" NOR,
       HIY "����Ժʿ" NOR,
       HIY "����˶ʿ" NOR,
       HIY "���ֲ�ʿ" NOR,
       HIY "����Ժ����" NOR,
       HIR "����ʿ" NOR,
       HIR "ѧʿ" NOR,
       HIR "�ڸ��ѧʿ" NOR,
       HIR "�ڸ��׸�" NOR,
       MAG "��ѧ����ʦ" NOR,
       HIW "ʥ��" NOR,
});
int ask_degree();
string apply_gongming(object me);

void create()
{
        set_name("��֪��", ({"he zhizhang", "he", "zhizhang"}));
        set("gender", "����");
        set("age", 55);
        set("title", "���Ӽ��ѧʿ");
        set("str", 25);
        set("int", 30);
        set("long", "��֪���ǹ��Ӽ��ѧʿ��ͳ��ȫ�����˿��Լ�������\n");
        set("combat_exp", 30000);
  set("daoxing", 50000);

        set("attitude", "friendly");
        set("class", "scholar");
        set_skill("unarmed", 50);
        set_skill("dodge",50);
        set_skill("literate", 100);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);
        set("inquiry", ([
                "name" : "��������ҳ�...�Ϸ��֪���ɻ��϶��͹��Ӽ��ѧʿ��ʵ�������ҵ���\n",
                "here" : "������ǹ��Ӽࡣ\n",
                "����ʶ��": "���ˣ��������Եط��ˣ�\n",
                "ѧϰ" : "ֻҪ�ܹܸ��϶������Ǿ��գ�\n",
                "����" : (: apply_gongming :),
            "ѧλ" : (:ask_degree:),
        ]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
int recognize_apprentice(object ob, object who)
{
/*
        object tongpai;
        if( !tongpai = present("tong pai", ob))
return notify_fail("��֪��Ц����û���ܹܸ����Ͽɣ����ǲ�������ѧ���ģ�\n");
        if((string)tongpai->query("player") != (string)ob->id())
return notify_fail("��֪�µ�����һ�ۣ�ѧ��֮���������ף�����\n");
*/  
      return 1;
}

string apply_gongming(object me)
{
        me=this_player();
        if( me->query("class") != 0 ) //means already has a class
        {
                return "���������ǹ������̣��ֺαع������ϣ�\n";
        }
        else
        {
                message_vision("��֪��˵�������������ǹ������̣��ֺαع������ϣ�\n", me);
                message_vision("��֪�¶�$N̾�˿���������Ȼ���������...\n", me);
                me->set("class", "scholar");
                if( me->query_skill("literate", 1) < 20 )
                        return "�Ը��µĲ�ʶ����ֻ�ܴ�ͯ������\n";
                else if( me->query_skill("literate", 1) < 100 )
                        return "�Ը��µĲ�ʶ��������Ż��ǿ��Եġ�\n";
                else    return "�Ը��µĲ�ʶ��������ѧʿû���⡣\n";
        }
}
int ask_degree()
{
        int lv;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 5);
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 3) 
        {
               command("say "+ob->query("name")+"�����ǵ�īˮҲ����˼��? �������ѧλ������! \n");
               ob->set("xuewei",degree_desc[lv]);
               return 1;
        }
        if (lv < 10) 
{
               command("say "+ob->query("name")+"������������ǰ;���ܸ�������ѧλ���㣬�����ú�Ŭ��! \n");
               ob->set("xuewei",degree_desc[lv]);
               return 1;
}
        else
{
               command("say ��Ȼ�ǳ���������ǰ�˰���"+ob->query("name")+"���ҷǳ��������л���Ϊ����ѧλ! \n");
               ob->set("xuewei",degree_desc[lv]);
               return 1;
}}
