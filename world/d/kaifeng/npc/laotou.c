// By tianlin 2001.5.1
inherit NPC;
#include <ansi.h>
inherit F_MASTER;

void create()
{
       set_name("����ͷ", ({"yu laotou","laotou"}));

        set("long","����ͷ������˧����Ŀ����ϴ�ү��\n");
       set("gender", "����");
       set("age", 20);
 	set("title", "[1;32m����˧���ܹ�[2;37;0m");
        set("int", 25);
       set("attitude", "peaceful");
        set("combat_exp", 1200000);
  set("daoxing", 1500000);


        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","tianpeng");
       set("per", 10);
	set("str", 30);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 2600);
  set("max_mana", 2000);
  set("mana", 4000);
  set("force", 4000);
  set("force_factor", 100);
  set("mana_factor", 120);
  set_skill("unarmed", 200);
  set_skill("dodge", 190);
  set_skill("parry", 160);
  set_skill("rake", 150);
  set_skill("force", 190);
  set_skill("spells", 180);
  set_skill("fofa", 180);
  set_skill("literate", 120);
  set_skill("tianpeng-zhang", 200);
  set_skill("bajie-force", 170);
  set_skill("chaos-steps", 190);
  set_skill("skyriver-rake", 160);
  map_skill("force", "bajie-force");
  map_skill("spells", "fofa");
  map_skill("rake", "skyriver-rake");
  map_skill("unarmed", "tianpeng-zhang");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "chaos-steps");
	create_family("����˧��", 2, "����");

        setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  command("pat "+me->query("id"));
  command("say �ܺã�ʱ����������֮��"+myname+"���Ŭ�������ձض��гɡ�");
  command("recruit " + me->query("id") );
message("system", HIY"����˧���ֶ���һ������  "+this_player()->name()+HIW"
           ����˧����������ǿ�ˡ�\n"NOR,users());
  return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
ob->set("class", "tianpeng");
               // ob->set("title", "��ʯɽ�̲�̶С��");
        }
}

�
