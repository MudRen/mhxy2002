inherit NPC;
#include <ansi.h>

void create()
{
  set_name("��˽�", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 70);
  set("title", HIY"����Ԫ˧"NOR);
    set("gender", "����");
  set("long", "�ٺ٣�����������ʶ����\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
       set("class", "xian");
  set("combat_exp", 12000000);
  set("daoxing", 8000000);

  set("max_kee", 3000);
  set("max_sen", 3000);
  set("max_force", 6300);
  set("force", 12600);
  set("max_mana", 6300);
  set("mana", 12600);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 500);
  set_skill("dodge", 500);
  set_skill("parry", 500);
  set_skill("rake", 500);
  set_skill("force", 500);
  set_skill("spells", 500);
  set_skill("xbuddhism", 500);
  set_skill("yanxing-steps", 500);
  set_skill("skyriver-rake", 500);
  set_skill("sougu-zhua", 500);
  map_skill("unarmed", "sougu-zhua");
  map_skill("force", "lengquan-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",5);
  set("chat_msg",({
    "��˽��ֺǺǵ�˵����˭�ܸ�������ȥ�ҵ�ԵĶ�������\n",
    "��˽�����˵�����·���ˮ���ˣ�����õ��ȼü���\n",
    "��˽�˵��������ҪѰ���������Ƽ��ȣ�������������˧��Ʒ��Ʒ����\n",
    "��˽�˵������������̰�죬��������ո����磬��ƽ�����Ҳ�ܳ������ʡ�\n",
    "��˽����������˵����������Ϊ�Լ����������ռ�������ʳ���ô����˶�����������\n",
    "��˽�Ť����ȥ���������Ľ����ર�઴����������\n",
    "��˽���������ˮͰ������ƺ����˹��˵ع�����ȥ��\n",
  }));
  set("inquiry", ([
        "here":   "��������˧��Ҳ�����������������̫�������ڴ˿�����ר����ʳ����ҵ��\n",
        "name":   "��˽䣬˭�˲�֪Ҳ��\n",
     ]));
   create_family("���", 1, "��");
  setup();
  carry_object("/d/tianpeng/obj/tianpengpa")->wield();
  carry_object("/clone/armor/jinjia")->wear();
}
void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 3000000 )) {
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
                ob->set("per","11");
}
�


�
