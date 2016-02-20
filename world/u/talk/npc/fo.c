//By tianlin@mhxy for 2002.1.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
	set_name("��������", ({ "rulai fo", "fo", "master" }));
	set("title", "������Ӱ�٤��");   
	set("long", @LONG
��ȴ���ɽ������ɲ������Ӱ�٤��������ү��
LONG);
	set("gender", "����");
	set("age", 150);
	set("attitude", "heroism");
	set("per", 9);
	set("max_kee", 2850);
	set("max_gin", 2800);
	set("max_sen", 2850);
	set("force", 15400);
	set("max_force", 8000);
	set("force_factor", 50);
	set("max_mana", 5000);
	set("mana", 11300);
	set("mana_factor", 20);
	set("combat_exp", 2330000);
	set("daoxing", 7450000);

	set_skill("literate", 180);
	set_skill("spells", 285);
	set_skill("buddhism", 285);
	set_skill("unarmed", 285);
	set_skill("blade", 285);
	set_skill("cibei-dao", 285);
	set_skill("huadao", 180);
	set_skill("jienan-zhi", 285);
	set_skill("dodge", 285);
	set_skill("lotusmove", 285);
	set_skill("parry", 285);
	set_skill("force", 285);
	set_skill("lotusforce", 285);
	set_skill("staff", 285);
	set_skill("lunhui-zhang", 285);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "yinshen" :),
		(: cast_spell, "lianhua" :),
	}) );
        create_family("�Ϻ�����ɽ", 1, "����");

	setup();
	carry_object("/u/tianlin/zjmaster/putuo/jiasha")->wear();
	carry_object("/u/tianlin/zjmaster/putuo/staff")->wield();
}

void attempt_apprentice(object ob)
{
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;

        if (!((string)ob->query("bonze/class") =="bonze" )&& !wizardp(ob)) {
                command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
                write("���������������δ��ȳ�����Ϊ���졣\n");
                return;
        }       
        if (((int)ob->query_skill("buddhism", 1) < 210 )) {
                command("say " + RANK_D->query_respect(ob) + "���ڷ��Ͽ��ޣ������ѳ�������\n");
                return;
        }
  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say ��λ" + RANK_D->query_respect(ob) + "��δ���������ѹأ������������������ѧ��\n");
	   return;
      	}
        command("pat " + ob->query("id") );
        command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");

        command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��"HIW"ҥ��"HIM"��ĳ�ˣ�"BLINK+HIR+ob->query("name")+NOR+HIM"����ȡ���л������õ����������ָ�㣡\n"NOR,users() );
        return; 
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "bonze");
              ob->set("title",HIY"�ȹ��նɷ���"NOR);
}

�
