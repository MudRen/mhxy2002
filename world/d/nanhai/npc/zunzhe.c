#include <ansi.h>

inherit NPC;

void create()
{
   set_name("Τ������", ({ "zunzhe" }) );
   set("long", "���Ǵ���������Τ�����ߣ����Ž�ħ���ߡ���Ϊ�͹��������й�����Ե�֣�
�ʶ�Э���������������ɣ����䵱�������ߡ�\n");
   set("attitude", "friendly");

   set("max_gin", 1000);
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("max_force", 1000);
   set("force", 1000);
   set("force_factor", 5);
   set("max_mana", 1000);
   set("mana", 1000);
   set("mana_factor", 10);
   set("str", 30);
   set("cor", 30);
   set("cps", 25);

   set("combat_exp", 500000);

   set_skill("staff", 100);
   set_skill("parry", 100);
   set_skill("lunhui-zhang",100);
   set_skill("dodge", 100);
   set_skill("lotusmove",100);
   set_skill("spells",100);
   set_skill("buddhism",100);
   
   map_skill("staff","lunhui-zhang");
   map_skill("parry","lunhui-zhang");
   map_skill("dodge","lotusmove");
   map_skill("spells","buddhism");
   
   set("chat_chance_combat", 40);
   set("chat_msg_combat", ({
      (: cast_spell, "bighammer" :),
      (: cast_spell, "yinshen" :),
        }) );

   setup();

   carry_object("/d/obj/armor/tianjia")->wear();
   carry_object("/d/nanhai/obj/budd_staff")->wield();
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

   message_vision(HIB "\n$N����һ������Ԯ��\n" NOR, who);       
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

void die()
{
    object ob = this_object();
    object *inv;
    int i;

    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++)
    {
        destruct(inv[i]);
     }
    return ::die();
}
