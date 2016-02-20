//����ɽ�ɡ�mhxy-yushu 2001/2
inherit NPC;
inherit F_MASTER;
int ask_back();
int send_back(object me);
#include <ansi.h>
void create()
{
       set_name("��������", ({"master jingxu","jingxu", "master"}));
       set("title",HIC"��ɽ�ɿ�ɽ��ʦ"NOR);
       set("gender", "����");
       set("age", 220);
	set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
	set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 8000000);
       set_skill("literate", 160);
       set_skill("dodge", 300);
       set_skill("parry", 300);
       set_skill("unarmed", 290);
       set_skill("fumozhang", 290); 
	set_skill("sword", 300);
	set_skill("songhe-sword", 300);
	set_skill("spells", 300);
	set_skill("xianfeng-spells", 300);
	set_skill("yujianshu", 300);
	set_skill("shushan-force", 300);
	set_skill("force", 300);
       set_skill("zuixian-steps", 300);
       map_skill("force", "shushan-force");
	map_skill("sword", "yujianshu");
       map_skill("spells","xianfeng-spells");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "zuixian-steps");
	map_skill("whip", "snowwhip");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
        set("inquiry", ([
                 "��ȥ" : (: ask_back :),
                 "back" : (: ask_back :),
		         "shushan" : (: send_back :),
				 "��ɽ" : (: send_back :),
         ]) );
        create_family("��ɽ��", 1, "����");
        setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/shushan/obj/shenxue")->wear();
}

void attempt_apprentice(object ob)
{	ob=this_player();
       if( (string)ob->query("family/family_name")=="��ɽ��") {
	if ((int)ob->query("daoxing") < 800000 ) {
  	command("say ��ĵ��л����������ҵ��з���������\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 250 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����ɷ����������������,�㻹���ҽ�ʥ�������Ű�!\n");
	command("sigh");
	return;
	}
       command("smile");
       command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
       command("recruit " + ob->query("id") );
       ob->set("shushan/wanjian_perform",1);
       return;
	}
       command("shake");
       command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ�������洫��");

}

        return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "��ɽ��")
    {
    command("say ���ֲ�����ɽ�ɵģ������������");
    return 1;
    }
    if(ob->query("shushan/tuoqiao_cast"))
    { 
    command("say �㲻��֪������? ");
    return 1;
    }
    if(ob->query("family/master_name") == "��������" )
    {
    command("say �����ȥ�����ð�!�ҽ���һ�С�����ѿǡ�!");
    command("say ��(cast tuoqiao)���ܳ�ȥ!");
    command("say �´ν���ʱ�Ͳ�Ҫ��ô�鷳��,ȥ�ؾ���(push ���)�Ϳ����ˡ�");
    ob->set("shushan/tuoqiao_cast",1);
    return 1;
    }
}
int send_back(object me)
{
	me=this_player();
	command("sigh " + me->query("id"));
	command("say " + "����һ��ľͷ...�ã������ȥ�ɡ�\n");
	tell_object(me,"\n�����������泤�䣬������ǰһ��...\n\n�������۾������˹�����\n\n");
	me->move("/d/shushan/shanmen");
	return 1;
}



�
