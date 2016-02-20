// sun wukong.c
// By tianlin 2001.5.8
// ����lingtai��Ϊlingtai���ռ�boss,skills��Ϊ300��.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name("�����", ({"sun wukong","sun", "wukong"}));
       set("long", "һ��������ߣ����ݸɸɣ������ë�������\n");
       set("title", HIR"�����ʥ"NOR);
       set("gender", "����");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦү");
       set("per", 26);
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 150);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 3456000);

       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("parry", 285);
	set_skill("stick", 285);
	set_skill("sword", 285);
	set_skill("liangyi-sword", 285);
	set_skill("spells", 285);
	set_skill("dao", 285);
	set_skill("puti-zhi", 285);
	set_skill("wuxiangforce", 285);
	set_skill("force", 285);
	set_skill("qianjun-bang", 285);
	set_skill("jindouyun", 285);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"stick","qiankun" :),
        (: perform_action,"stick", "pili" :),
        }) );

create_family("����ɽ���Ƕ�", 1, "��");
setup();

        carry_object("/d/lingtai/obj/jiasha")->wear();
        carry_object("/d/obj/weapon/stick/jingubang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
	if ((int)ob->query("daoxing") < 1000000 ) {
  	command("say ��λ" + RANK_D->query_respect(ob) + "�ҿ���ĵ��л����Զ��,��������ҲҪ��һǧ��ĵ��а�!\n");
	return;
	}
	if ((int)ob->query_str() < 25) {
	command("say ��λ" + RANK_D->query_respect(ob) + "��ı���̫���,�㻹��ȥ�ұ��˰�.\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("qianjun-bang", 1) < 180 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���ǧ������̫����,�㻹����������.\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "��������,����Բ�����.");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �����������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
	   ob->set("title", RED"�����ʥ�״�����"NOR);
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n����մ��һ��:���д������Ѱ������������.\n\n", environment());
        command("pa wukong");
        message("sound", "\n�����һŭ֮��,�ɻ��˻���ɽ!\n\n", environment());
        }

        destruct(this_object());
}

�

