//nuwa.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>
void create()
{
       set_name("Ů�����", ({"nuwa niangniang", "nuwa", "niangniang","master"}));
       set("long", "����������������������������ء�\n");
       set("title", "[1;35m�¹���ʦ[2;37;0m");
       set("gender", "Ů��");
       set("age", 30);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "��������");
       set("cor", 30);
       set("per", 30);
	set("looking", "üͷ΢����������ɫ��");
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 15000);
       set("max_force", 7500);
       set("force_factor", 200);
       set("max_mana", 7500);
       set("mana", 15000);
       set("mana_factor", 100);
       set("combat_exp", 4000000);
  set("daoxing", 5000000);

       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("force", 300);
       set_skill("parry", 300);
       set_skill("sword", 300);
       set_skill("spells", 300);
	set_skill("moonshentong", 300);
	set_skill("baihua-zhang", 300);
	set_skill("moonforce", 300);
	set_skill("snowsword", 300);
	set_skill("moondance", 300);
	set_skill("whip",300);
	set_skill("jueqingbian",300);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	map_skill("whip",  "jueqingbian");
   set("inquiry",([
  ]));
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),
                (: cast_spell, "mihun" :),
        }) );

create_family("�¹�", 1, "��");
setup();

     //   carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{	
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	string *sname;
  	mapping skl;
  	int i;
	if (!ob->query_temp("koujian_nuwa"))
	{
		command("look "+ob->query("id"));
		command("say "+"��λ"+RANK_D->query_respect(ob)+"�����������ƺ�����ðɣ�������ذɡ�");
		return;
	}

  	if ( !((string)ob->query("gender")=="Ů��")){
	   command("shake");
    	   command("say �����¹�ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
	   return;
	}

  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say ��λ" + RANK_D->query_respect(ob) + "��δ���������ѹأ������������������ѧ��\n");
	   return;
      	}

	if ( (string)ob->query("family/family_name")!="�¹�") {
	   	command("shake");
		command("say " + RANK_D->query_respect(ob) +
			"������ȥѧЩ��������ɡ�\n");
        	return;
	}
    if ( ((int)ob->query("combat_exp") < 1000000) || ((int)ob->query("daoxing")<1000000)) {
	command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
	return;
	}
        command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��"HIW"ҥ��"HIM"��ĳ�ˣ�"BLINK+HIR+ob->query("name")+NOR+HIM"�õ�Ů������ָ�� ��\n"NOR,users() );
        return; 
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
              ob->set("title",HBBLU+HIY"Ů��������µ���"NOR);
}
