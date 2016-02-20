//by tianlin 2001.7.31

#include <ansi.h> 
inherit NPC;
string ask_kill();
string ask_cancel();
void create()
{
   set_name("��С��", ({"zhu xiaojie", "zhu", "xiaojie"}));
   set("title", HIC"����"NOR+HIW"����"NOR);
   set("long","������˽������,ѧ��һ���졣\n");
   set("gender", "����" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("class", "tianpeng");
   set("attitude", "peaceful");
   create_family("����˧��", 1, "��ʦ");
  set("combat_exp", 3200000);
  set("daoxing", 3056000);

  set("max_kee", 3500);
  set("max_sen", 3500);
  set("max_force", 4700);
  set("max_mana", 2600);
  set("mana", 5000);
  set("force", 6000);
  set("force_factor", 160);
  set("mana_factor", 120);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("rake", 200);
  set_skill("force", 200);
  set_skill("stick", 100);
  set_skill("sword", 140);
  set_skill("spells", 200);
  set_skill("fofa", 200);
  set_skill("literate", 160);
  set_skill("tianpeng-zhang", 200);
  set_skill("bajie-force", 200);
  set_skill("chaos-steps", 200);
  set_skill("skyriver-rake", 200);
  map_skill("force", "bajie-force");
  map_skill("spells", "fofa");
  map_skill("rake", "skyriver-rake");
  map_skill("unarmed", "tianpeng-zhang");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "chaos-steps");

        set("eff_dx", -200000);
        set("nkgain", 400);

    set("inquiry", ([
     "����" : (:ask_kill:),
     "kill" : (:ask_kill:),
   "cancel": (:ask_cancel:),
    ]));
   setup();
   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/kaifeng/obj/jingangpa")->wield();
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

void attempt_apprentice(object ob)
{
   if( (int)ob->query("str") < 20 ){
     command("kick " + ob->query("id"));
     command("say �������̫С�ˡ�\n");
     return;
   }

   if( (string)ob->query("family/family_name")=="����˧��" ){
     if( (int)ob->query("family/generation") < 2  ){
        command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
     }
     else if( (int)ob->query("family/generation") ==2  ){
        command("say �����" + RANK_D->query_rude(ob) + "������ǲ��үү���ˣ�\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command(":D");
        command("say �����" + RANK_D->query_rude(ob) + "�ǲ��Ǳ�ʦ���ϳ����ˣ���үү�ҽ�������ã����������...\n");
        command("recruit " + ob->query("id") );
     }
     else {
        if( (int)ob->query("combat_exp") >= 500000 ){
          command(":D ");
          command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ���������ĺô���\n");
          command("recruit " + ob->query("id") );
        }
        else {
          command("say �㻹�����ұ������Űɡ�\n");
        }
     }
   }

   else{
     command("hmm");
     command("say ��λ" + RANK_D->query_respect(ob) + "���㻹���ұ����������ɡ�\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tianpeng");
}

void init()
{       
   object ob=this_player();

   ::init();
   if ( ((string)ob->query("gender")=="����") && ((int)ob->query("str") < 20) && (random(3) > 1) )
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
     command("kick " + ob->query("id"));
     command("say ���������");
     command("laugh");
     break;
   }
}

string ask_kill()
{
   object me=this_player();
   
   if(me->query("family/family_name")!="����˧��")
      return ("�㲻�Ǳ�������!");

   command("pat "+me->query("id"));
   command("say ��־����");
   return "/d/obj/mieyao"->query_yao(me);
}
 


