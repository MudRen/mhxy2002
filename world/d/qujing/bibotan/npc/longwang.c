// By tianlin 2001.5.1
//longwang.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��ʥ����", ({"wansheng longwang", "longwang",  "wang", "long"}));
       set("long", "������ʯɽ�̲�̶��������\n");
       set("title", "��ʯɽ�̲�̶");
       set("gender", "����");
       set("age", 68);
       set("attitude", "peaceful");
       set("gender", "����");
	set("class", "yaomo");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 3000000);
       set("daoxing", 5000000);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 5400);
       set("max_force", 3500);
       set("force_factor", 100);
       set("max_mana", 3400);
       set("mana", 5400);
       set("mana_factor", 100);
        set_skill("zhuanlong-force", 180);
       set_skill("unarmed", 180);
       set_skill("dodge", 180);
       set_skill("huaxue-blade", 180);
       set_skill("blade", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("spells", 180);
       set_skill("chuanyun-tui", 180);
       set_skill("literate", 140);
	set_skill("fork", 180);
        set_skill("yueya-fork", 200);
       set_skill("yulong-steps", 180);
        set_skill("bihai-spells", 180);
        map_skill("dodge", "yulong-steps");
	map_skill("blade", "huaxue-blade");
        map_skill("unarmed", "chuanyun-tui");
        map_skill("parry", "yueya-fork");
        map_skill("fork", "yueya-fork");
       map_skill("force", "zhuanlong-force");
       map_skill("spells", "bihai-spells");
	
       create_family("��ʯɽ�̲�̶", 1, "��ʦ");
       setup();
       carry_object("/d/lingtai/obj/pao")->wear();
       carry_object("/d/obj/weapon/blade/yanblade")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ʯɽ�̲�̶") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ�����С�\n");
	return;
	}
       if( (int)ob->query_skill("bihai-spells", 1) < 120 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����ɵķ�����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "�̲�̶��ʥ�������µ���");

}

        return 0;
}

�
