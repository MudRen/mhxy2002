// modify by ken 2001.3.9
inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("������", ({ "master xiao", "xiao", "yun","zhongyun", }));
   set("title", "ħ���������");
   set("long", @LONG
�������������ϴ�������ʦ�֣�Ҳ�ǽ�ħ�޺޵�ʦ����һ�����ѧ��ɲ�
�ڽ��е�λ��Ϊ������������ħҲ��������ĺܣ�Ҳ���޺���Ϊ������
�ˡ�
LONG);
   set("gender", "����");
   set("age", 87);
   set("attitude", "friendly");
   set("rank_info/self", "����");
   set("rank_info/respect", "����");
   set("class", "evil");
   set("str",100);
   set("per",100);
   set("max_kee", 7000);
   set("max_gin", 7000);
   set("max_sen", 7000);
   set("force", 10000);
   set("max_force", 7000);
   set("force_factor", 300);
   set("max_mana", 8000);
   set("mana", 16000);
   set("mana_factor", 300);
   set("combat_exp", 9000000);
   set_skill("literate", 320);
   set_skill("spells", 320);
   set_skill("tianmo", 320);
   set_skill("unarmed", 320);
   set_skill("tigerfight", 320);
   set_skill("dodge", 320);
   set_skill("dimo-steps", 320);
   set_skill("blade", 350);
   set_skill("parry", 320);
   set_skill("force", 300);
   set_skill("evil-force", 300);
   set_skill("sword", 300);
   set_skill("nature",300);
   set_skill("tianmo-blade", 350);
   set_skill("tianxian-sword", 300);
   map_skill("spells", "tianmo");
   map_skill("unarmed", "tigerfight");
   map_skill("dodge", "dimo-steps");
   map_skill("force", "evil-force");
   map_skill("parry", "tianmo-blade");
   map_skill("blade", "tianmo-blade");
   map_skill("sword", "tianxian-sword");
   set("chat_chance_combat", 20);
   set("chat_msg_combat", ({
    (: perform_action, "blade", "tiandirenmo" :),
  }) );


   create_family("ħ��", 1, "�������");

   setup();
   carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/mojiao/obj/fireblade")->wield();
// carry_object("/u/ken/obj/long-blade");
}

void attempt_apprentice(object ob)
{

   if (!((string)ob->query("zap/kill") =="done" )) {
     command("say �Ϸ���Ͳ���ͽ�ˡ�\n");
     write("�����������ǲ�Ը��ͽ�ܡ�\n");
     return;
   }   
   if (((int)ob->query_skill("tianmo", 1) < 201 )) {
     command("say " + RANK_D->query_rude(ob) + "�������������ħ������Ϊ����,������ҵ�ͽ�ڡ�\n");
     return;
   }

   if ((int)ob->query("combat_exp") < 4000000 ) {
     command("say ���˰ɣ��Ϸ���ͽ�ڡ�\n");
   return;
   }
   command("nod " + ob->query("id") );
   command("say û����Ⱳ�ӻ����յ���ôһ������֮�š�\n");

   command("recruit " + ob->query("id") );
   return;   
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "evil");
                ob->set("title", "ħ�̴󻤷�");
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
