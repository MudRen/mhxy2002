#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_chuxian();
string ask_cancel();

void create()
{
  set_name("��ʱ�", ({ "zhu feibiao", "zhu", "feibiao" }));
  set("age", 35);
  set("title", HIY"�������"NOR);
  set("gender", "����");
  set("long", "����������ĸ�����\n");
  set("attitude", "peaceful");
       set("class", "xian");
  set("str", 50);
  set("per", 13);
  set("combat_exp", 2000000);
  set("daoxing", 2000000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_mana", 3200);
  set("mana", 3200);
  set("max_force", 3200);
  set("force", 3200);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 230);
    set_skill("tianpeng-force", 230);
  set_skill("dodge", 250);
  set_skill("parry", 230);
  set_skill("rake", 230);
  set_skill("force", 230);
  set_skill("spells", 230);
  set_skill("xbuddhism", 230);
  set_skill("yanxing-steps", 230);
  set_skill("skyriver-rake", 250);
  set_skill("sougu-zhua", 230);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("���", 2, "����");
         set("inquiry", ([
     "����" : (:ask_chuxian:),
   "cancel": (:ask_cancel:),
    ]));
 setup();
  carry_object("/d/tianpeng/obj/gangpa")->wield();
  carry_object("/d/tianpeng/obj/jinjia")->wear();
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}

// void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 1500000 )) {
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
string ask_chuxian()
{
    object me=this_player();

    if((string)me->query("family/family_name")=="���") {
      command("smile "+me->query("id"));
      return "/d/obj/mieyao"->query_yao(me);
    }
    return ("��������,�ι�����?\n");
}

�
