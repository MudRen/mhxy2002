//By tianlin@mhxy for 2002.1.10���¸ı�

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name(HIM"��ܽ"NOR, ({ "ji fu", "ji","jifu", "fu",}) );
        set("gender", "Ů��" );
        set("age", 21);
        set("agi",30);
        set("str", 60);
        set("per", 29);
        set("nickname", HIG"��ʮ��"HIY"���¶���ʥŮ"NOR);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 2100);
        set("force", 3000);
        set("force_factor", 80);
        set("max_mana", 2300);
        set("mana", 3000);
	 set("max_kee",1000);
        set("max_gin",1000);
        set("max_sen",1000);
        set("chat_chance", 30);
        set("long",
"��λ������ʮ���ĺ���֪����ܽС�㣬Ҳ�Ƕ���ʮ�����Ĵ���\n"
        );
        create_family("��ɽׯ",2,"������������");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "shisan" :),
        }) );

        set("combat_exp", 630000);
        set("daoxing", 1230000);
       set_skill("literate", 80);
       set_skill("unarmed", 100);
       set_skill("dodge", 100);
       set_skill("force", 120);
       set_skill("parry", 115);
       set_skill("sword", 105);
       set_skill("spells", 120);
       set_skill("blade", 125);
       set_skill("lianhuan-zhang", 155);
       set_skill("duo-sword", 185);
       set_skill("cloudforce", 115);
       set_skill("shadowsteps", 135);
       set_skill("xueying-xianfa", 115);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "duo-sword");
       map_skill("parry", "duo-sword");
       map_skill("dodge", "shadowsteps");
        setup();
    //    carry_object(__DIR__"obj/deitysword")->wield();
   //     carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="��ɽׯ" )
     {
       if( (int)ob->query("family/generation") < 3  )
          command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
       else if( (int)ob->query("family/generation") ==3  )
	  command("say �����" + RANK_D->query_rude(ob) + "���Ǳ�����ǲ��������ˣ�\n");
      else 
         {
	  command(":D");
	  command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ�������±���ѧ���ϳ˽�����\n");
	  command("haha");
	  command("recruit " + ob->query("id") );
    //     ob->set("title", HIR"��ɽׯ"NOR);
         ob->set("class", "shenjian");
	 }
     }

    else
      {
       command(":D ");
       command("say �ã�"+ RANK_D->query_respect(ob) +"���㵽����ɽׯ�����г���ͷ�ص�һ�죡\n");
       command("recruit " + ob->query("id") );
			message("system", HIB"����ɽׯ�ֶ���һ������  "HIR+this_player()->name()+HIW"
                 ��ɽׯ"HIY"��������ǿ�ˡ�\n"NOR,users());
   //    ob->set("title", HIR"��ɽׯ"NOR);
       ob->set("class", "shenjian");
      }

  return;
}

