//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name(YEL"��԰"NOR+CYN"����"NOR, ({ "shouyuan daozhang", "shouyuan", "daozhang" }));
        set("long",
                "�������������԰������԰������\n"
                "��������ʮ�꣬��Щ��԰���¡�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "wudang");
        set("str", 21);
        set("int", 21);
        set("con", 21);
        set("dex", 21);

        set("max_kee", 600);
        set("max_sen", 300);
        set("force", 500);
        set("max_force", 500);
        set("mana", 500);
        set("max_mana", 500);
        set("force_factor", 40);
        set("mana_factor", 40);
        set("combat_exp", 30000);
        set("daoxing", 4000);

        set_skill("force", 50);
        set_skill("wudang-force", 40);
        set_skill("spells", 50);
        set_skill("wudang-xianfa", 40);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 50);
        set_skill("taiji-quan", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("wudang-jian", 40);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 4, "����");
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
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
}
