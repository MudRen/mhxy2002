//ronger.c
#include <ansi.h>
#include <dbase.h>
inherit NPC;

void create()
{
       set_name(HIW"�ݶ�"NOR, ({"rong er", "ronger"}));
       set("long",
"���ɹ��ǵ�Ů���ѣ�����"HIM"�ݶ�"NOR"��\n");
       set("title", HIC"�����й�Ů��"NOR);
       set("gender", "Ů��");
       set("age", 22);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "���ɽ��");
       set("per", 100);
       set("str", 30);
       set("looking", HIW"�����������ˣ���ɫ���㣬�����϶���ʩҲ����ѷɫ̫�ࡣ"NOR);
       set("bellicosity", 1000);

       set("int", 40);
       set("max_kee", 10000);
       set("max_gin", 10000);
       set("max_sen", 10000);
       set("force", 100000);
       set("max_force", 7500);
       set("force_factor", 100);
       set("max_mana", 7500);
       set("mana", 100000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
  set("daoxing", 3500000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("force", 500);
       set_skill("parry", 500);
       set_skill("sword", 500);
       set_skill("spells", 500);
        set_skill("moonshentong", 500);
        set_skill("baihua-zhang", 500);
        set_skill("moonforce", 500);
        set_skill("snowsword", 500);
        set_skill("moondance", 500);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
   set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
     (: cast_spell, "arrow" :),
        }) );
        set("chat_chance",20);
        set("chat_msg", ({
        "�ݶ���ͷ����˵����Ϊʲô�ҵĹ��Ǹ�絽���ڻ�û�����أ�\n",
        "�ݶ����Ƶ�̾��һ������\n",
        "�ݶ�������˵���Һ����ҵĹ��Ǹ�硣\n", 
        }));

        setup();
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
        carry_object("/d/obj/flower/rose")->wear();
      carry_object("/u/redrain/baoyi")->wear();
        carry_object("/u/redrain/sword")->wield();
}

void die()
{
  if (environment())
  message("sound", "\nֻ���ض����������е��������ɾ����������Ұ���\n", environment());
  message("sound", "\n����ͻȻ������һ�������У���һ�ӣ���ʱһƬ�����ס���ݶ���\n\n", environment());
  set("eff_kee", 90000);
  set("eff_gin", 90000);
  set("eff_sen", 90000);
  set("kee", 90000);
  set("gin", 90000);
  set("sen", 90000);
  set("force", 100000);
  set("mana", 100000);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
        && !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "�ض�������˵����λ" + RANK_D->query_respect(ob) +
"������������ҵĹ��Ǹ�磿\n");
}


