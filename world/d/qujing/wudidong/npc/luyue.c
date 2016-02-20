//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
	set_name("����", ({ "lu yue", "luyue", "lu" ,"monster"}));
	set("title", HIY"���֮�����"NOR);   
	set("long", @LONG
����ԭΪ����������ʿ���������ι�ͨ��������£�������֮��
����Ϊ���֮�����ְ֮������������λ����
LONG);
	set("gender", "����");
	set("age", 20);
	set("attitude", "heroism");
	set("per", 9);
	set("max_kee", 1850);
	set("max_gin", 1800);
	set("max_sen", 1850);
	set("force", 8000);
	set("max_force", 5000);
	set("force_factor", 150);
	set("max_mana", 2600);
	set("mana", 4300);
	set("mana_factor", 100);
	set("combat_exp", 2500000);
	set("daoxing", 4500000);

  set_skill("unarmed", 285);
  set_skill("dodge", 285);
  set_skill("parry", 285);
  set_skill("spells", 285);
  set_skill("yaofa", 285);
  set_skill("sword",285);
  set_skill("qixiu-jian",285);
  set_skill("blade", 285);
  set_skill("kugu-blade", 285);
  set_skill("literate", 180);
  set_skill("lingfu-steps", 285);
  set_skill("yinfeng-zhua", 285);
  set_skill("force", 285);   
  set_skill("huntian-qigong", 285);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
              (: exert_function, "recover" :),
	//	(: cast_spell, "jingang" :),
	}) );
        create_family("�ݿ�ɽ�޵׶�", 1, "��ʦ");

	setup();
	carry_object("/d/obj/weapon/blade/yanblade")->wield();
	carry_object("/u/tianlin/obj/goldarmor")->wear();
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
	if ( (string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�") {
		command("smile");
		command("say �ܺã��Ҿ������㣬ϣ������Ŭ�������������\n");

		command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��"HIW"ҥ��"HIM"��ĳ�ˣ�"BLINK+HIR+ob->query("name")+NOR+HIM"Ѱ�ҵ��޵׶���ʦ"HIY"�������"HIM",�õ���"HIY"�������"HIM"��ָ�㣡\n"NOR,users() );
		return;
	}

	command("shake");
	command("say " + "�߿��߿���\n");
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
              ob->set("title",HIR"Ѫ����"NOR);
}

�
