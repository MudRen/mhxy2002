

// ������ͷ

//׷ɱɱ��֮��
#include <ansi.h>
#define NAME_D "/u/fly/npc/random_name"

inherit NPC;
string *color_title = ({
HIC"[��ңɽׯ]"NOR+"��������",
HIY"[�ʹ���Ժ]"NOR+"���ڸ���",
HIM"[�׺���]"NOR+"����",
HIM"[�߶���]"NOR+"����",
});

void create()
{
    mapping name;

    name = NAME_D->man_name();

    set_name(name["name"],({name["id"]}));
        set("gender", "����" );
    set_name(name["name"],({name["id"]}));
        set("title", color_title[random(sizeof(color_title))]);
       set("long",
                "һλ�������ݵĲ�ͷ����Ĳ��ߣ�������������\n"
                "��˵����̫���Ͼ��޵�������һ���Ĳݿܶ��������֡�\n"
        );
       set("nickname", HIW"������ͷ"NOR);
        set("gender", "����");
        set("attitude", "peaceful");
        
        set("age", 35);
        set("shen", 2000);
        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 35);

        set("force",4000);
        set("max_kee",4000);        
        set("kee",4000);        
        set("combat_exp",2000000);

        set("max_force",4000);
        set("mana",4000);
        set("max_mana",4000);
        set("force_factor", 100);
        set("mana_factor", 250);
        set_skill("spells", 220);
        set_skill("unarmed",220);
        set_skill("parry",220);
        set_skill("dodge",220);
        set_skill("force",220);
        set_skill("sword",220);
        set_skill("NO.1_skill",220);
          map_skill("force", "NO.1_skill");
          map_skill("unarmed", "NO.1_skill");
          map_skill("spells", "NO.1_skill");
          map_skill("sword", "NO.1_skill");
          map_skill("dodge", "NO.1_skill");
   set("chat_chance_combat", 900);
        set("chat_msg_combat", ({
           (: perform_action, "sanmai" :),
          (: perform_action, "cimu" :),
          (: perform_action, "sword.cimu" :),
          (: perform_action, "sword.sanmai" :),
        }) );

        set("chat_chance", 20);
        set("chat_msg", ({
               "��ͷͦ��ͦ�ظ�������Ц��������˵�������ˣ���ЩΪ������������һ���ŷ���ӡ� \n",
               (: random_move :)
       }) );
        setup();

}

void init()
{
        object me, ob;

        ::init();

        ob = this_player();
        me = this_object();
        
     if(userp(me) && killer->query_condition("killer")>10 && userp(ob))
        {
         ob->kill_ob(me);
        me->kill_ob(ob);
        }
     if(userp(me) && killer->query_condition("no_pk_time")>240 && userp(ob))
        {
         ob->kill_ob(me);
        me->kill_ob(ob);
        }
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && (int)ob->query("PKS",1) >36 )
        {
 
         command("say  ��˵��������˲��ٻ��£�����ͺͱ�����һ�ˡ�\n");
         remove_call_out("hiting_ob");
         call_out("hiting_ob", 1, ob);
                 
        }       
}
int hiting_ob(object ob)
{
        object me;
        me=this_object();
        me->set_leader(ob);
         ob->fight_ob(me);
        me->fight_ob(ob);
        remove_call_out("moving_ob");
        call_out("moving_ob",1,ob);
}
int moving_ob(object ob)
{
        if (!ob) return 0;
       if (!living(ob)&&present(this_player(), environment(this_object()))){
        switch( random(3) ) {
        case 0:
                command("say  �����ܣ�֪���ٸ��������˰ɣ�");
        break;
        case 1:
                command("say  ���������ʵʵȥ���Űɡ�");
        break;
        case 2:
                command("nod");
        break;
        }
    ob->move("/d/wiz/punish"); 
        ob->set("eff_jing",1);           
        }
        else {
        remove_call_out("hiting_ob");
        call_out("hiting_ob",1,ob);
        }
}
