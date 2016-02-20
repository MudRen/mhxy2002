// created by ken 2001.3.9
inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
   set_name("�޺�", ({ "master hate", "ken", "hate","dom", }));
   set("title", "��ħ");
   set("long", @LONG
�����޺ޣ���˵��ħ���кܴ��ԴԵ�����㿴������ʱ�������������һ������ܣ���Ϥ������
LONG);
   set("gender", "����");
   set("age", 35);
   set("attitude", "friendly");
   set("rank_info/self", "��ħ");
   set("rank_info/respect", "��ħ");
   set("class", "evil");
   set("str",100);
   set("per",100);
   set("max_kee", 6000);
   set("max_gin", 6000);
   set("max_sen", 6000);
   set("force", 12000);
   set("max_force", 6000);
   set("force_factor", 300);
   set("max_mana", 7000);
   set("mana", 14000);
   set("mana_factor", 300);
   set("combat_exp", 8800000);
   set_skill("literate", 300);
   set_skill("spells", 290);
   set_skill("tianmo", 290);
   set_skill("unarmed", 300);
   set_skill("huolong-zhang", 300);
   set_skill("dodge", 300);
   set_skill("dimo-steps", 300);
// set_skill("blade", 330);
   set_skill("parry", 300);
   set_skill("force", 280);
   set_skill("evil-force", 280);
   set_skill("sword", 320);
// set_skill("nature",300);
// set_skill("tianmo-blade", 330);
   set_skill("tianxian-sword", 290);
   map_skill("spells", "tianmo");
   map_skill("unarmed", "huolong-zhang");
   map_skill("dodge", "dimo-steps");
   map_skill("force", "evil-force");
   map_skill("parry", "tianxian-sword");
// map_skill("blade", "tianmo-blade");
   map_skill("sword", "tianxian-sword");
   set("chat_chance_combat", 30);
   set("chat_msg_combat", ({
     (: cast_spell, "lei" :),
     (: cast_spell, "fog" :),
   }) );

   create_family("ħ��", 1, "ħ��");

   setup();
// carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/mojiao/obj/tx")->wield();
// carry_object("/u/ken/obj/windblade");
}

void attempt_apprentice(object ob)
{
/*
   if (!((int)ob->query("ffb/kill") < 1 )) {
     command("say ���������³����飮\n");
     write("�������޺޲���������Ϊͽ��\n");
     return;
//  }   
//  if (((int)ob->query_skill("force", 1) < 201 )) {
//  command("say " + RANK_D->query_rude(ob) + "�������������ħ������Ϊ����,������ҵ�ͽ�ڡ�\n");
//  return;
   }
*/
   if ((int)ob->query("combat_exp") < 2300000 ) {
     command("say ���У�����ѧ�ϻ�Ҫ�����󾫰���\n");
   return;
   }
   command("nod " + ob->query("id") );
   command("say �ã��Ҿ������㡣\n");

   command("recruit " + ob->query("id") );
   return;   
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "evil");
                ob->set("title", "����ħ��");
        }
}


void init()
{
     object me;
   
     ::init();
    add_action("do_exercise",({"bian"}));
     if( interactive(me = this_player()) && !is_fighting() ) {
     call_out("greeting", 0, me);
}
}

void greeting(object me)
{
      int mykar=me->query_kar();
      if( random(mykar) > 100) return;
      else
 {
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      return;
    }
}
int do_exercise(string arg)
{
    write("�������˼�������,�������ʲô����ʲôҲû������\n");
    return 1;
}
