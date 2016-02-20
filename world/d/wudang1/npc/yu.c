//By tianlin@mhxy for 2001.9.27
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name("������", ({ "yu lianzhou", "yu" }));
	set("nickname", HIW"�䵱"NOR+HIR"����"NOR);
	set("long", 
		"������������Ķ����������ۡ�\n"
		"��������ʮ�꣬��Ŀ��࣬�������ء�\n"
		"�����䵱�����������ڶ�������ȴ�����\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "wudang");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 3500);
	set("max_sen", 3800);
	set("force", 5000);
	set("max_force", 5000);
	set("mana", 5000);
	set("max_mana", 5000);
       set("force_factor", 140);
       set("mana_factor", 140);
	set("combat_exp", 1800000);
	set("daoxing", 1800000);

	set_skill("force", 210);
	set_skill("wudang-force", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 230);
	set_skill("unarmed", 180);
	set_skill("taiji-quan", 240);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("spells", 200);
	set_skill("taiji-jian", 210);
	set_skill("liangyi-jian", 180);
	set_skill("wudang-xianfa", 200);
	set_skill("literate", 150);

	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
        set("inquiry", ([
      "kill": (: ask_mieyao :),
      "cancel": (: ask_cancel :),
      "����": (: ask_cancel :),
]) );

	create_family("�䵱��", 2, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang1/obj/whiterobe")->wear();
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
string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="�䵱��") {
    tell_room(environment(me),"�����۾������еĳ�������ʱ���һ����\n");
    write(HIY+"/d/obj/mieyao"->query_yao(me)+NOR);
    return (HIG"��������,������ħΪ����.\n"NOR);
    }
    return ("ƶ����֪��");
}

string ask_cancel()
{
    object me=this_player();
    
    if("/d/obj/mieyao"->delete_mieyao(me))
      me->add("faith",-5);
    return ("û�õĶ�����");
}
