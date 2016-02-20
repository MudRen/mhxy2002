//master2.c
//modify by ken
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("��̫��", ({ "master fu", "fu", "mo", "tianmo", "ren", "master", "shifu" }));
  set("title", "��ħ���ܹ�");
  set("gender", "����");
  set("age", 33);
  set("str", 30);
  set("per", 30);
  set("int", 40);
  set("cor", 90);
  set("cps", 90);
  set("long", "����������ħ�õ��ܹܣ�Ҳ�ǵ�ħ���˵İ�ͽ��\n");
  set("combat_exp", 2400000);
  set_skill("literate", 180);
  set_skill("blade", 190);
  set_skill("force", 180);
  set_skill("dodge", 185);
  set_skill("parry", 200);
  set_skill("spells", 190);
  set_skill("unarmed", 180);
  set_skill("huolong-zhang", 180);
  set_skill("dimo-steps", 190);
  set_skill("tianmo-blade", 200);
  set_skill("evil-force", 190);
  set_skill("unarmed", 180);
set_skill("tigerfight", 190);
  set_skill("tianmo",200);
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
  set("inquiry", ([
                   "���": (: expell_me :),
                   "leave": (: expell_me :),
                   ]) );

  create_family("ħ��", 1, "����");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "blade", "tiandirenmo" :),
  }) );

  setup();
  carry_object("/d/mojiao/obj/fireblade")->wield();
  carry_object("/d/mojiao/obj/pifeng")->wear();
}


string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="ħ��")
    {
      me->set_temp("betray_mojiao", 1);
      command("hmm");
      command("say �ѵ��������������㣿");
      return ("���й��������мҹ�:��������ʦ�žͱ����ܷ������Ը��(agree)��");
    }
  return ("�Ϸ�֪��");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray_mojiao"))
    {
      message_vision("$N���������Ը����̡�\n\n", this_player());
      command("say �ã���Ȼ�����С���ݲ����������������������ı�߾Ͱɣ�");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/mojiao", 1);
//    this_player()->set("combat_exp", this_player()->query("combat_exp")*90/100);
      this_player()->delete_skill("tianmo");
      this_player()->delete_skill("tianxian-sword");            
      this_player()->delete_skill("tianmo-blade");
      this_player()->delete_skill("evil-force");
      if(this_player()->query("JZD_eat")) {this_player()->add("max_mana",-300);}
      else {this_player()->add("max_mana",-random(200));}
      if(this_player()->query("jion_mj"))             {this_player()->set("combat_exp",this_player()->query("combat_exp")*60/100);}
      else {this_player()->set("combat_exp", this_player()->query("combat_exp")*90/100);}
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "ħ����ͽ");
      this_player()->set_temp("betray_mojiao", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}

