//By tianlin@mhxy for 2002.1.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
         set_name("���ؿ�", ({ "ji yankao", "yankao", "ji", "kao", "master" }));
             set("title", MAG "���챱����΢���"NOR);   
	set("long", @LONG
һλ������ɣ����������������ڽ����� �������յ�Ůǰ����
LONG);
         set("gender", "Ů��");
         set("age", 20);
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
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("force", 285);
       set_skill("parry", 285);
       set_skill("sword", 285);
       set_skill("spells", 285);
       set_skill("whip", 285);
       set_skill("pansi-dafa", 285);
       set_skill("lanhua-shou", 285);
       set_skill("jiuyin-xinjing", 285);
       set_skill("chixin-jian", 285);
       set_skill("qin", 285);
       set_skill("yueying-wubu", 285);
       set_skill("yinsuo-jinling", 285);
       map_skill("spells", "pansi-dafa");
       map_skill("unarmed", "lanhua-shou");
       map_skill("force", "jiuyin-xinjing");
       map_skill("sword", "chixin-jian");
       map_skill("parry", "yinsuo-jinling");
       map_skill("dodge", "yueying-wubu");
       map_skill("whip", "yinsuo-jinling");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
	}) );
        create_family("��˿�� ", 1, "��ʦ");
	setup();
	// carry_object("/u/tianlin/zjmaster/putuo/jiasha")->wear();
	// carry_object("/u/tianlin/zjmaster/putuo/staff")->wield();
}
void init ()
{
  add_action("do_back", "back");
}
void attempt_apprentice(object ob)
{
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;

         if (((int)ob->query_skill("pansi-dafa", 1) < 200 )) {
                command("say " + RANK_D->query_respect(ob) + "�������ɷ����Ͽ��ޣ������ѳ�������\n");
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
        command("jump " + ob->query("id") );
         command("say �ã�������ҵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");

        command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��"HIW"ҥ��"HIM"��ĳ�ˣ�"BLINK+HIY+ob->query("name")+NOR+HIM"����ȡ���л������õ�"NOR+MAG"���ؿ�"HIM"������ָ�㣡\n"NOR,users() );
        return; 
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	      ob->set("class", "xian");
             ob->set("title",MAG"��˿��"YEL"ɢ����"CYN"����"NOR);
}
int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("33tian/from");

  message_vision("$N����$n��$N�ط���\n",who,me);
  there = "/d/city/kezhan";

  message_vision("$N��������������$n��Զ����ȥ����\n",me,who);
  who->move(there);
  message_vision(HIM"�����������һֻ�޴�ķ�������һ����ֻ��$N��������������\n"NOR,who);
  
  return 1;
}

�
