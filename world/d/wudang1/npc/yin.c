//[4;53m[1;31mBy tianlin@mhxy and elva@mhxy for 2001.9.27[2;37;0m
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ͤ", ({ "yin liting","yin"}));
        set("nickname", HIW"�䵱"NOR+HIR"����"NOR);
        set("long",
                "��������������������ĵ��ӡ��䵱����֮��������ͤ��\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ������ܸɣ�������������һ�ȴһֱһ�������ı��顣\n");
        set("gender", "����");
        set("age", 23);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 26);
        set("int", 39);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 5000);
        set("max_force", 1000);
        set("mana", 5000);
        set("max_mana", 1000);
       set("force_factor", 50);
       set("mana_factor", 40);
        set("combat_exp", 1250000);
        set("daoxing", 1000000);

        set_skill("force", 195);
        set_skill("wudang-force", 200);
        set_skill("spells", 195);
        set_skill("wudang-xianfa", 170);
        set_skill("dodge", 195);
        set_skill("tiyunzong", 190);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 160);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("liangyi-jian", 200);
        set_skill("literate", 125);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
        if ((int)ob->query_skill("wudang-force", 1) < 140) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
	command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "Ҳ��" +
		"�ұ����ˣ������������ɡ�");
	command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m�䵱��[1;37m��[1;36m��[1;37m������[2;37;0m");
}

