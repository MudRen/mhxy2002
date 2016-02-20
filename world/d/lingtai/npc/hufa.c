#include <ansi.h>

inherit NPC;

void create()
{
   set_name("����", ({ "hufa" }) );
   set("long", "����һλ����ɽ���Ƕ�ר�����������������ŵ��ӵĻ���Ҳ�л�ɽ֮��\n");
   set("attitude", "friendly");

   set("max_gin", 1000);
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("max_force", 1000);
  set("force",2000);
  set("force_factor",50);
   set("max_mana", 1000);
   set("mana",3000);
   set("mana_factor",75);
   set("str", 30);
   set("cor", 30);
   set("cps", 25);

   set("combat_exp", 200000);
/*
   set("chat_chance", 15);
   set("chat_msg_combat", ({
     name() + "�ȵ������ϣ����Ҷԣ�\n"
   }) );
*/
   set_skill("stick", 100);
   set_skill("parry", 100);
   set_skill("qianjun-bang",100);
   set_skill("dodge", 100);
   set_skill("jindouyun",100);
   set_skill("spells",100);
   set_skill("dao",100);
   
   map_skill("stick","qianjun-bang");
   map_skill("parry","qianjun-bang");
   map_skill("dodge","jindouyun");
   map_skill("spells","dao");
   
   set("chat_chance_combat", 40);
   set("chat_msg_combat", ({
      (: perform_action, "stick.qiankun" :),
      (: cast_spell, "light" :),
      (: cast_spell, "dingshen" :),
      (: cast_spell, "thunder" :)
        }) );

   setup();

   carry_object("/d/obj/armor/tianjia")->wear();
   carry_object("/d/lingtai/obj/bang")->wield();
}

int heal_up()
{
   if( environment() && !is_fighting() ) {
     call_out("leave", 1);
     return 1;
   }
   return ::heal_up() + 1;
}

void leave()
{
   message("vision",
     HIY + name() + "˵�������������Ѿ���ȫ�����¾ʹ˸�ǣ�\n\n"
     + name() + "����һ����⣬���������ʧ�����ˡ�\n" NOR, environment(),
     this_object() );
   destruct(this_object());
}

void invocation(object who)
{
   int i;
   object *enemy;

   message_vision(HIB "\n$N����һ����Х��Ԯ��\n" NOR, who);
   message_vision(HIB "\n$NӦ��������\n" NOR, this_object());
   enemy = who->query_enemy();
   i = sizeof(enemy);
   while(i--) {
     if( enemy[i] && living(enemy[i]) ) {
        kill_ob(enemy[i]);
        enemy[i]->kill_ob(this_object());
     }
   }
  set("possessed",who);
   who->remove_all_killer();
   set_leader(who);
}

void set_hushan()
{
  set("max_force",3000);
  set("force",6000);
  set("max_mana",3000);
  set("mana",6000);
  set("force_factor",150);
  set("mana_factor",150);
  set("combat_exp",1500000);
  
  set_skill("spells",200);
  set_skill("dao",200);
  set_skill("stick",160);
  set_skill("qianjun-bang",180);
  set_skill("jindouyun",190);
  set_skill("dodge",170);
   command("say ��������������������ɽ�ϣ�");
  set("guard",1);
}

void die()
{
  object killer;

  if(objectp(killer=query_temp("last_damage_from")))
    if(query("guard")){
      command("sigh");
      command("say �����Ҳ�Ŭ����ʵ��������δ��ѽ��");
      killer->set_temp("success_hufa",1);
    }
  message_vision("$N����������ʧ��!\n",this_object());
   destruct(this_object());
}
