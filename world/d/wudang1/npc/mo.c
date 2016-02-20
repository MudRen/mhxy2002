//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ī����", ({ "mo shenggu", "mo" }));
        set("nickname", HIW"�䵱"NOR+HIR"����"NOR);
        set("long",
                "���������������С���ӡ��䵱����֮ĩ��Ī���ȡ�\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "��������ʮ��ͷ��ͣ��Ե�����δ�ѣ�����ݳ���ü������\n");
        set("gender", "����");
        set("age", 21);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_kee", 1800);
        set("max_sen", 800);
        set("force", 1800);
        set("max_force", 1800);
        set("mana", 1800);
        set("max_mana", 1800);
        set("force_factor", 50);
        set("mana_factor", 50);
        set("combat_exp", 200000);
        set("daoxing", 560000);

        set_skill("force", 80);
        set_skill("wudang-force", 90);
        set_skill("spells", 80);
        set_skill("wudang-xianfa", 90);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 90);
        set_skill("unarmed", 80);
        set_skill("taiji-quan", 85);
        set_skill("parry", 90);
        set_skill("sword", 90);
        set_skill("liangyi-jian", 90);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "Ī��������˵������ʯ����ڿ��Դ����ջ�ġ�\n",
            "Ī����б����һ�ۣ�����аħ����Ͳ�����ڵ��ˡ�\n",
            "Ī����͵͵�����㣺�����һ��Ҫע�����ܵġ�\n",
            "Ī�����Ժ���˵����ֻ�����䵱�������µ����ڡ�\n",
            "Ī���ȶ�����������������Ա�������Ϊ�������֣�һ��Ҫѧ���¾���\n"
        }));

        create_family("�䵱��", 2, "����");

        setup();
        set("inquiry", ([
           "ʯ��":     "��ʯ����ڿ��Դ����ջ�ġ�",
           "���":     "�����һ��Ҫע�����ܵġ�",
           "������":   "�Ҷ�ʦѧ�����ˣ����������ĵ�ѧ�ķ���"]) );
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
        if ((int)ob->query_skill("wudang-force", 1) < 130) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
}
