//By tianlin@mhxy for 2001.9.26
//�����Ż�
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("�������", ({ "zhixiang daozhang", "zhixiang", "daozhang" }));
        set("long",
                "�������䵱�����������ÿ�����䵱�������̫���ˣ�����\n"
                "�����µļ�����ľ��ʿ��æ�������ˡ�\n"
                "��������ʮ�ꡣ\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_kee", 800);
        set("max_sen", 400);
        set("force", 700);
        set("max_force", 700);
        set("mana", 700);
        set("max_mana", 700);
        set("force_factor", 130);
        set("combat_exp", 50000);
        set("daoxing", 115000);

        set_skill("force", 70);
        set_skill("wudang-force", 60);
        set_skill("dodge", 70);
        set_skill("tiyunzong", 70);
        set_skill("unarmed", 70);
        set_skill("taiji-quan", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("wudang-jian", 60);

        map_skill("force", "wudang-force");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}
