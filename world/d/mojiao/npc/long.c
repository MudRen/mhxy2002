// modify by ken 2001.3.9
inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("������", ({ "master long", "long", "yun","chengyun", }));
   set("title", "ħ�̸�����");
   set("long", @LONG
�������ǵ�ħ���˵ĵ���������Ҳ�Ƿ�ɰ׵�ʦ�ڣ���һ����ѧ���Ż���������ʦ��
���θ�����ְ֮��������ڵĴ�С����.
LONG);
   set("gender", "����");
   set("age", 37);
   set("attitude", "friendly");
   set("rank_info/self", "����");
   set("rank_info/respect", "������");
   set("class", "evil");
   set("str",100);
   set("per",100);
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 10000);
   set("max_force", 4500);
   set("force_factor", 300);
   set("max_mana", 8000);
   set("mana", 16000);
   set("mana_factor", 300);
   set("combat_exp", 8000000);
   set_skill("literate", 220);
   set_skill("spells", 250);
   set_skill("tianmo", 250);
   set_skill("unarmed", 320);
   set_skill("tigerfight", 320);
   set_skill("dodge", 300);
   set_skill("dimo-steps", 300);
   set_skill("blade", 330);
   set_skill("parry", 300);
   set_skill("force", 280);
   set_skill("evil-force", 280);
   set_skill("sword", 270);
   set_skill("nature",270);
   set_skill("tianmo-blade", 330);
   set_skill("tianxian-sword", 290);
   map_skill("spells", "tianmo");
   map_skill("unarmed", "tigerfight");
   map_skill("dodge", "dimo-steps");
   map_skill("force", "evil-force");
   map_skill("parry", "tianmo-blade");
   map_skill("blade", "tianmo-blade");
   map_skill("sword", "tianxian-sword");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "lei" :),
//   (: cast_spell, "fog" :),
   }) );

   create_family("ħ��", 1, "������");

   setup();
   carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/obj/weapon/blade/jindao")->wield();
   carry_object("/d/mojiao/obj/long-blade");
}

void attempt_apprentice(object ob)
{
/*
   if (!((string)ob->query("ljm/kill") =="done" )) {
     command("say ��������ǿ��ԣ�" + RANK_D->query_rude(ob) + "��СС����������ɱ����,�����к��á�\n");
     write("���������˷�ɰ׵����ǰݲ������ġ�\n");
     return;
   }   
   if (((int)ob->query_skill("tianmo", 1) < 201 )) {
     command("say " + RANK_D->query_rude(ob) + "�������������ħ������Ϊ����,������ҵ�ͽ�ڡ�\n");
     return;
   }
*/
   if ((int)ob->query("combat_exp") < 1000000 ) {
     command("say ���" + RANK_D->query_rude(ob) + "���������ˡ�\n");
   return;
   }
   command("nod " + ob->query("id") );
   command("say ���������ǫ���ѧ�����ܹذ�ͬ�ţ��Ҿ����������ͽ�ڡ�\n");

   command("recruit " + ob->query("id") );
   return;   
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "evil");
                ob->set("title", "ħ�̻���");
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
