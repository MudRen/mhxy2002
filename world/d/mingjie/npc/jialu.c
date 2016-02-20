inherit NPC;
#include "star.h"
#include <ansi.h>;
void get_date();
 
void create()
{
        set_name("��·", ({"jia lu", "lu"}));
        set("long", "��Ȫ�ڶ���----����Ǽ�·\n");
        set("gender","����");
        set("title", "������ǡ�");
        set("age",37);
        set("attitude", "friendly");
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
            set("combat_exp",3500000);
          set("daoxing",3500000);
        set("chat_chance",20);
        set("chat_msg", ({
                "��·˵������Ҫ�ɹ�������,ֻ�����ҡ�����\n"   
        }));
          set_skill("dodge", 350);
          set_skill("force", 350);
          set_skill("parry", 350);
          set_skill("unarmed", 350);
        set_skill("westsword",350);
        set_skill("sword", 350);
        set_skill("baiyang", 350);
        map_skill("sword","westsword");
        map_skill("spells","baiyang");
         set("max_force", 3500);
         set("force", 7000);
         set("max_mana",3500);
         set("mana",7000);
         set("mana_factor",50);
         set("force_factor", 50);
       set("max_kee", 3500);
       set("max_gin", 3500);
        set("max_sen", 3500);

        setup();
        carry_object(__DIR__"obj/tj_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
// add_action("do_none","exert");

}
int do_none()
{
        object me = this_object();
        message_vision("$N��Цһ�����������ҵĹ�������˵���㣡����\n",me);
        return 1;
} 


void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
    
     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
      
     switch(random(4))
     {        
        case 0:
        {
        message_vision(HIR"$N˫��һ�ӣ�ʹ����������ת������\n",ob,me);

        if(random(2))
        
                {
              message_vision(HIR"$N��$n�Ľ���ı������ף�\n"NOR,me,ob);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIR"$N����׾ٵĶ����$n�Ĺ�����\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N���½�ʹ�������������糱����ȭ��\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N�����У�һ������ͷ�������ˣ�\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N���������У���㿪�ˣ�\n"NOR,me);
        }
        break;

      

  }
 //       if( present(me,environment()) )  return ;

        if( random(10) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if(ob&&ob->query("mingjie/river")!="done")
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "������"+environment(ob)->query("short")+"\n"NOR,users());
        ob->set("mingjie/river","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 10000);
            ob->set("title",HIW"�����ڤ��ʿ"NOR);
            ob->save();
        tell_object(ob,"��Ӯ����ʮ�����");
        
        }
       ::die();
}

