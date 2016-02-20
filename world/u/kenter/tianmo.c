//master2.c
//modify by ken
inherit NPC;
inherit F_MASTER;
string jion_me(object me);
void create()
{
  set_name("��ħ����", ({ "lao ren", "tian", "mo", "tianmo", "ren", "master", "shifu" }));
  set("title", "��ħ������");
  set("gender", "����");
  set("age", 63);
  set("str", 30);
  set("per", 30);
  set("int", 40);
  set("cor", 90);
  set("cps", 90);
  set("long", "��ħ���������ν�����ʦ����Ҳ�ǽ�����������֮һ��\n");
  set("combat_exp", 2400000);
  set_skill("literate", 120);
  set_skill("blade", 170);
  set_skill("force", 170);
  set_skill("dodge", 170);
  set_skill("parry", 170);
  set_skill("spells", 170);
  set_skill("unarmed", 170);
  set_skill("huolong-zhang", 170);
  set_skill("dimo-steps", 170);
  set_skill("tianmo-blade", 140);
  set_skill("evil-force", 170);
  set_skill("tigerfight", 170);
  set_skill("tianmo",170);
  map_skill("unarmed", "tigerfight");
  map_skill("force", "evil-force");
  map_skill("spells", "tianmo");
  map_skill("blade", "tianmo-blade");
  map_skill("parry", "tianmo-blade");
  map_skill("dodge", "dimo-steps");
  set("max_sen", 5500);
  set("max_kee", 5500);
  set("force", 5000);
  set("max_force", 5500);
  set("force_factor", 280);
  set("max_mana",5500);
  set("mana",7000);
  set("mana_factor",300);
/*
  set("inquiry", ([
                   "���": (: jion_me :),
                   "jion": (: jion_me :),
                   ]) );

*/
  create_family("ħ��", 1, "����");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "blade", "tiandirenmo" :),
  }) );

  setup();
  carry_object("/d/mojiao/obj/fireblade")->wield();
  carry_object("/d/mojiao/obj/pifeng")->wear();
}


string jion_me(object me)
{
      me=this_player();   
      me->set_temp("jion", 1);
      command("nod");
      return ("�����ҽ̿ɼ������̣�ϰ�ҽ������񹦣����Ը�⣨�ʣɣϣΣ���");
}
void init()
{
  add_action("do_jion", "jion");
}
int do_jion(string arg)
{
  if(this_player()->query_temp("jion"))
    {
      message_vision("$N���������Ը��Ͷ�̡�\n\n", this_player());
      command("say �ܺã�����ǰ���ɵ��¿ɲ����ˣ����Ƿ����޳��Ļ�����������");
      this_player()->delete("betray/count");
      this_player()->delete("betrayer");
      this_player()->set("class","evil");
      this_player()->set("jion_mj","1");
      this_player()->create_family("ħ��",4,"����");
      this_player()->set_temp("jion", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}
