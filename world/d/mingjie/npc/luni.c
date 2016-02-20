// by happ@YSZZ
 
inherit NPC;
#include "star.h"
#include <ansi.h>;
 
void create()
{
        set_name("·��", ({"lu ni", "ni"}));
        set("long", "ڤ�編ͥ�Ĵ�ͥ��\n");
        set("gender","����");
          set("title", HIY"����Ӣ�ǡ�"NOR);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",3600000);
          set("daoxing",3600000);
        set("chat_chance",20);
        set("chat_msg", ({
                "·��˵�������ྲ�������Ƿ�ͥ����\n"   
        }));
        set_skill("dodge", 350);
        set("attitude", "friendly");
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("westsword",350);
        set_skill("balei",350);
        set_skill("spells",350);
        set_skill("jinniu", 350);
        map_skill("sword","westsword");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3600);
        set("force", 7200);
        set("max_mana",3600);
        set("mana",7200);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3600);
        set("max_gin", 3600);
        set("max_sen", 3600);

        setup();
        carry_object(__DIR__"obj/ty_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");

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
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     switch(random(8))
     {        
        case 0:
        {
        message_vision(YEL"$N�ְֳͱ�¡֮�ޣ�ʹ���������������������\n",ob,me);


       if(random(4)==0)
                {
              message_vision(YEL"$N���ͱ�¡֮�ޣ����˸����ţ���ʱ�˺����ۣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*11);
              me->add("eff_sen",-query("max_sen")/10*11);
                }
        else
        message_vision(YEL"$N�������ó��ͱ�¡֮�ޣ���һ������ˣ��ͱ�¡֮�޸����ʹ��У�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�����дʣ��㱻$N�͵��˻�������ܿ࣡\n",ob,me);

                if(random(4)==0)

                {
              message_vision(YEL"$N�챻�ջ��ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*11);
              me->add("eff_sen",-query("max_sen")/100*11);
                }
        }
        break;


  }
        if( random(10) == 5 )

        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("mingjie/river")=="done") && (ob&&ob->query("mingjie/yi")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵�һ��!\n"NOR,users());
        ob->set("mingjie/yi","done");
        ob->add("mingjie/number",1);
          ob->add("daoxing", 20000);
      ob->set("title",HIW"��Ӣ��ڤ��ʿ"NOR);
        ob->save();
          tell_object(ob,"��Ӯ���˶�ʮ�����");

        }
       ::die();
      }
