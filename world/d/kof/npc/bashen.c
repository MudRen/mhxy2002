//by tianlin 2001.5.1
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"bashen an", "bashen"}));
        set("gender", "����" );
        set("age", 30);
        set("long", "����ȭ������ܳ�����һ���������˲�ֻ�������ǲ�����������.\n");
        set("combat_exp", 320000);
  set("daoxing", 3200000);

        set("attitude", "friendly");
        create_family("��֮��", 2, "��ͽ");
	set("int", 25+random(5));
        set_skill("unarmed", 280);
        set_skill("iori-kuihua", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 200);  
        set_skill("iori-spells", 200);  
        set_skill("literate", 10);
        set_skill("dodge", 280);  
        set_skill("force", 280);   

        map_skill("spells", "iori-spells");
        map_skill("unarmed", "iori-kuihua");


        set("per", 30);
        set("max_kee", 62500);
        set("max_gin", 2400);
        set("max_sen", 32400);
        set("force", 12450);
        set("max_force", 4300);
        set("force_factor", 350);
        set("mana", 2450);
        set("max_mana", 2300);
        set("mana_factor", 108);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({	
              (: cast_spell, "bazhinu" :),
              (: perform_action,"unarmed","xiaofeng" :),
              (: perform_action,"unarmed", "kuihua" :),
        }) );

        setup();
       // carry_object("/d/kof/obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp") < 1000)) {
	command("say " + RANK_D->query_respect(ob) +
"�������,�����Զ��.�����������������Ұ�.");
	return;
	}
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"�ҿ������ͦͶԵ��.�Ҿ���������.��һ��Ҫ���������հ���ɱ�˲�����\n");
        command("recruit " + ob->query("id") );
}
// int recruit_apprentice(object ob)
// {
       // if( ::recruit_apprentice(ob) )
               // ob->set("class", "taoist");
// }

�