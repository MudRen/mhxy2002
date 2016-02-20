//By tianlin@mhxy and elva@mhxy for 2001.9.27
//�����Ż�

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "[1;37m̫��[1;33m����[2;37;0m");
	set("long", 
		"�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
		"��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
		"��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_kee", 3000);
	set("max_sen", 2800);
	set("force", 5700);
	set("max_force", 5700);
	set("mana", 4900);
	set("max_mana", 4900);
       set("force_factor", 140);
       set("mana_factor", 140);
	set("combat_exp", 5000000);
	set("daoxing", 6000000);
        set("chat_msg_combat", ({
 //               (: perform_action, "sword.ren" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	set_skill("force", 300);
	set_skill("wudang-force", 300);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 300);
	set_skill("taiji-quan", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 300);
	set_skill("wudang-xianfa", 300);
	set_skill("spells", 300);
	set_skill("literate", 290);

	map_skill("force", "wudang-force");
	map_skill("spells", "wudang-xianfa");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");

	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "wudang");

	setup();
       carry_object("/d/wudang1/obj/jian.c")->wield();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 500000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
        if ( ((int)ob->query("daoxing") < 500000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��з������Ŭ������");
                return;
        }
	if ((int)ob->query_skill("wudang-force", 1) < 200) {
		command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����̫�����϶��µ㹦��");
		return;
	}
    if ((int)ob->query_skill("wudang-xianfa", 1) < 200)
    {
        command("say ���䵱���˵����书��������书�벻����ѧ�ķ���");
        command("say " + RANK_D->query_respect(ob) +
            "�Ƿ�Ӧ�ö�������¾���");
        return;
    }
	if (ob->query_int() < 30) {
		command("say ���䵱���书ȫ�ӵ��������");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("chat ����������������");
	command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
	command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m�䵱��[1;37m������[1;31m����[1;37m����[2;37;0m");
}
