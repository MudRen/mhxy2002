//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("�������", ({ "qingxu daozhang", "qingxu","daozhang" }));
        set("long",
                "��������Զ�ŵĵ������������\n"
                "��������ʮ���꣬�����䵱�ɺ�ɽ�����¡�\n");
        set("gender", "����");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
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
        set("force_factor", 40);
        set("mana_factor", 40);
        set("combat_exp", 60000);
        set("daoxing", 60000);

        set_skill("force", 50);
        set_skill("wudang-force", 50);
        set_skill("spells", 50);
        set_skill("wudang-xianfa", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("wudang-jian", 40);
        set_skill("taoism", 50);
        set_skill("literate", 50);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 3, "����");
        set("class", "wudang");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 10000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}
