//By tianlin@mhxy for 2001.9.30
//�����޸�
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�������", ({ "guxu daozhang", "guxu" }));
	set("long", 
		"�����������۵ĵ��ӹ��������\n"
		"��������ʮ�꣬�����䵱�ɵ����¡�\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
       set("class", "wudang");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_kee", 1000);
	set("max_sen", 800);
	set("force", 1000);
	set("max_force", 1000);
	set("mana", 1000);
	set("max_mana", 1000);
       set("force_factor", 90);
       set("mana_factor", 80);
	set("combat_exp", 60000);
	set("daoxing", 128000);

	set_skill("force", 60);
	set_skill("wudang-force", 40);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 40);
	set_skill("unarmed", 60);
	set_skill("taiji-quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);
	set_skill("wudang-xianfa", 60);
	set_skill("spells", 60);
  	set_skill("literate", 80);

	map_skill("force", "wudang-force");
	map_skill("spells", "wudang-xianfa");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 3, "����");
	set("class", "wudang");

	set("inquiry", 
		([
			"���¾�" : (: ask_me :),
		]));
                                
	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m�䵱��[1;37m��[1;31m��[1;37m������[2;37;0m");
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/d/wudang1/obj/daode");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}
