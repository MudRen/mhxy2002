//By tianlin@mhxy and elva@mhxy for 2001.9.25

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ŵ�ɽ", ({ "zhang cuishan", "zhang" }));
        set("nickname", HIC"��"NOR+HIY"����"NOR+HIW"��"NOR);
        set("long",
                "�������������������ĵ��ӡ��䵱����֮����Ŵ�ɽ��\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ�����Ӣ����һ������������ͷ��\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 2500);
        set("force", 2100);
        set("max_force", 2100);
        set("mana", 2000);
        set("max_mana", 2000);
        set("force_factor", 90);
        set("mana_factor", 90);
        set("combat_exp", 500000);
        set("daoxing", 1200000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );
        set_skill("force", 140);
        set_skill("wudang-force", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
        set_skill("unarmed", 140);
        set_skill("taiji-quan", 140);
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("spells", 140);
        set_skill("wudang-xianfa", 140);
        set_skill("liangyi-jian", 140);
        set_skill("taiji-jian", 140);
        set_skill("literate", 150);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "�Ŵ�ɽ��ݺݵ�˵����û������ˢ�ӣ��Ҹ����⽣�ң�\n",
            "�Ŵ�ɽ����̾�����ĸ���ʦ�����ҵ����أ�����Ѽׯһ�١�\n"
        }));

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}

void greeting(object ob)
{
        if( (string)ob->query("class")=="yaomo")
        {
            say(CYN"\n\n�Ŵ�ɽ����ŭ�ݣ���аħ��������˱��ӵ��ˣ���ǿ���䵱����\n\n");
            message_vision("�Ŵ�ɽ�Ӹ����£�����һ�ƣ�$Nֻ��Ӳ�ӣ����ӻ���һ�¡�\n",ob);
            message_vision("�Է����ֳ����漴�ݳ���$N�޷��мܣ�����һ����\n\n\n"NOR,ob);
            ob->move("/d/wudang1/slxl2");
        }
}

void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30)
        {
                command("say ������ʽ������������������ľ��磬����Ҳ�ǰ״\n");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m�䵱��[1;37m��[1;36m��[1;37m������[2;37;0m");
}
