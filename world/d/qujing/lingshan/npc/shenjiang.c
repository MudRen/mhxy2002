//live

inherit NPC;
void set_skills(object);

void create()
{
  set_name("��", ({ "shen jiang", "jiang","guard"}) );
  set("gender", "����" );
       set("long",
                "ֻ�����콫��\n
���������ٷ磬����ս�ף��������ݣ��Ѳ�֪ɱ��������ħ�����\n");
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "aggressive");
   set("no_nk_reward",1);
  set("combat_exp", 2000000);
  set("daoxing", 2000000);



  set_skill("force",  150); 
  set_skill("spells", 150); 
  set_skill("unarmed",150);
  set_skill("blade",  150);
  set_skill("dodge",  150);
  set_skill("parry",  150);
  set_skill("yaofa", random(50)+150);
  set_skill("ningxie-force", 150);
  set_skill("kugu-blade",  random(50)+150);

  map_skill("force", "ningxie-force");
  map_skill("spells", "yaofa");
  map_skill("blade", "kugu-blade");
  set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "diyu" :),
				(: cast_spell, "bite" :),
				                
        }) );


  set("max_kee", 4000);
  set("eff_kee", 4000);
  set("kee", 4000);
  set("max_sen", 4000);
  set("eff_sen", 4000);
  set("sen", 4000);
  set("force", 5300);
  set("max_force", 5300);
  set("mana", 4400);
  set("max_mana", random(800)+4200);
  set("force_factor", 150);
  set("mana_factor", 100);

  setup();

  carry_object("/d/obj/armor/tongjia.c")->wear();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/obj/weapon/blade/yanblade.c")->wield();
}

void init()
{
  object ob=this_player();

  ::init();
     remove_call_out("greeting");
     call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  object me=this_object();
  message_vision("$N�ȵ����üһ����Ҳ������\n",me);
  command("kill " + ob->query("id"));
  kill_ob(me);
  }

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}




void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object kongque;
  
  if (ob)
  {
  message_vision ("\n$N�ҽ�һ��������Ϊ���Ρ�\n",me);
    kongque = new ("/d/xueshan/npc/kongque-mingwang.c");
  message_vision ("\nһ�������������ƿ���ɢ�䣬һλ�����Գ�������ǰ��\n",me);
   message_vision ("\n���߿��˿�$N������˵������Ȼ���������Ե������������.\n",ob);
   ob->move("/d/qujing/lingshan/shandong.c");
  }
  destruct(me);
}