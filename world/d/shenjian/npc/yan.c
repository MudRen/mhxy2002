#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
        
   set_name("��ʮ��", ({ "master yan", "master",  "yan", "master shisan" }) );
        set("nickname", HIW "������Ȼ������ �����������"NOR);
	set("gender", "����");
	set("age", 20);
	set("attitude", "heroism");
	set("per", 9);
	set("max_kee", 2850);
	set("max_gin", 2800);
	set("max_sen", 2850);
	set("force", 8000);
	set("max_force", 15000);
	set("force_factor", 150);
	set("max_mana", 5600);
	set("mana", 8300);
	set("mana_factor", 100);
	set("combat_exp", 5500000);
	set("daoxing", 6500000);
        set("long",
"һ�����侲����,����һ��������������Į��ƣ�룬ȴ��ƫƫ�����ֱ��˵�ɱ����
�������뽣ʮ����ʱ�������������������������꣬���ѷŲ������еĽ�������Ҳ
���������¡��������½�ʱ������������Ҫ������\n"	);
        create_family("��ɽׯ", 1, "����");
       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("force", 285);
       set_skill("parry", 285);
       set_skill("sword", 285);
       set_skill("spells", 285);
       set_skill("blade", 285);
       set_skill("lianhuan-zhang", 285);
       set_skill("duo-sword", 285);
       set_skill("qingfeng-jian", 285);
       set_skill("cloudforce", 285);
       set_skill("shadowsteps", 285);
       set_skill("xueying-xianfa", 285);
       set_skill("shenji-blade", 285);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "duo-sword");
       map_skill("parry", "qingfeng-jian");
       map_skill("dodge", "shadowsteps");
       map_skill("blade", "shenji-blade");
        setup();
        carry_object("/obj/cloth")->wear();
     //   carry_object("/obj/weapon/sword")->wield();
	//carry_object(__DIR__"obj/oldskin")->wear();

}


void attempt_apprentice(object ob)
{
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;
  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say ��λ" + RANK_D->query_respect(ob) + "��δ���������ѹأ������������������ѧ��\n");
	   return;
      	}
	if ( (string)ob->query("family/family_name")=="��ɽׯ") {
		command("smile");
		command("say �ܺã��Ҿ������㣬ϣ������Ŭ�������������\n");

		command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��ҥ�ԡ�ĳ�ˣ�"BLINK+HIR+ob->query("name")+NOR+HIM"��������ĥ��,����Ѱ����ʮ����\n"NOR,users() );
		return;
	}

	command("shake");
	command("say " + "�߿��߿���\n");
	return;
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
                ob->set("title",HBRED+HIR"����"HIY"ʮ��"HIC"��"HIW"����"NOR);
}
 
