// by gslxz@mhsj 2001/11/21 (�Ż�)
inherit NPC;
#include <ansi.h>

void create()
{
  set_name("С��", ({ "xiao cui", "cui", "xiao" }));
  set("age", 13);
    set("title", "���");
    set("nickname", HIM"ʹ��Ѿͷ"NOR);
    set("gender", "Ů��");
  set("long", "���������Ѿ�ߡ�\n");
  set("attitude", "peaceful");
  set("class", "xian");
  set("str", 50);
  set("per", 30);
  set("combat_exp", 700000);
  set("daoxing", 150000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_mana", 2000);
  set("mana", 4000);
  set("max_force", 2000);
  set("force", 4000);
  set("force_factor", 90);
  set("mana_factor", 90);
  set_skill("unarmed", 160);
  set_skill("literate", 200);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("force", 160);
    set_skill("tianpeng-force", 160);
  set_skill("spells", 160);
  set_skill("xbuddhism", 165);
  set_skill("yanxing-steps", 160);
  set_skill("sougu-zhua", 160);
    map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("parry", "sougu-zhua");
  map_skill("dodge", "yanxing-steps");
   create_family("���", 3, "����");
  setup();
  carry_object("/d/tianpeng/obj/pink")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 200000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "�ĵ��в��������Щ��ѧ�ط�������������\n");
	return;
	}

	if ( (string)ob->query("family/family_name")=="���") {
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�������������������\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
               ob->set("class", "xian");
                ob->set("per",11);
}
�


�
