#include <ansi.h>
#include <login.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���޳�", ({ "bai wuchang","wuchang", "gargoyle" }));
        set("long","һ�����°׾���Ƥ��ʹ�ߣ����׵����Ͽ������κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
        set("per", 10);
        set("str", 25);
        set("int", 25);
        set("age", 30);
        set("title", "�л�˾��");
        set("combat_exp", 120000);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("class", "youling");
        set("force", 1500);
        set("max_force", 800);
        set("force_factor", 50);
        set("max_mana", 600);
        set("mana", 1000);
        set("mana_factor", 40);
        set_skill("ghost-steps", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);
        set_skill("gouhunshu", 100);
        set_skill("jinghun-zhang", 100);
        set_skill("force", 100);
        set_skill("tonsillit", 100);
        set_skill("stick", 100);
        set_skill("kusang-bang", 100);
        map_skill("stick", "kusang-bang");
        map_skill("parry", "kusang-bang");
        map_skill("spells", "gouhunshu");
        map_skill("dodge", "ghost-steps");
        map_skill("force", "tonsillit");
        map_skill("unarmed", "jinghun-zhang");

         set("chat_msg_combat", ({
         (: exert_function, "powerup" :),
         (: exert_function, "sheqi" :),
         (: exert_function, "recover" :),
         (: cast_spell, "gouhun" :),
        }) );
        setup();
 carry_object("/d/obj/cloth/bai")->wear();
 carry_object("/d/obj/weapon/stick/bang")->wield();
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
void die()
{
message_vision("$N����������ʧ��!\n",this_object());
   destruct(this_object());
} 
