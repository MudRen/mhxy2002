// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("ϣ��ŵ˹", ({"xipo nuosi", "xipo"}));
        set("long", "��˵�е�˯��\n");
        set("gender","Ů��");
        set("title", "��˯��");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",5000000);
        set("daoxing",5000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "ϣ��ŵ˹˵���������ڤ�����ȹ�����ذ� ��\n"   
        }));
        set_skill("dodge", 350);
        set("attitude", "friendly");
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("westsword",350);
        set_skill("balei",350);
        set_skill("spells",350);
        set_skill("shinu", 350);
        map_skill("sword","westsword");
        map_skill("spells","shinu");
        map_skill("dodge","balei");
        set("max_force", 5000);
        set("force", 10000);
        set("max_mana",5000);
        set("mana",10000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);

        setup();
        carry_object(__DIR__"obj/cs_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
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


     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIC"$Nʹ�����У��������˯�ߡ���\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N���Ƕ㲻�������˯�ߣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*25);
              me->add("eff_sen",-query("max_sen")/100*25);
       
                }
        else
        message_vision(YEL"$N����ˡ�ΰ�硱����Ц�������˲�˯����\n"NOR,me);
        }
        break;


                     
        case 1:
        {
        message_vision(HIC"$Nʹ�����У��������˯�ߡ���\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N���Ƕ㲻�������˯�ߣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*25);
              me->add("eff_sen",-query("max_sen")/100*25);
       
                }
        else
        message_vision(YEL"$N����ˡ�ΰ�硱����Ц�������˲�˯����\n"NOR,me);
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

        if((ob&&ob->query("mingjie/tu4")=="done") && (ob&&ob->query("mingjie/tu5")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "����˴�˵�е�˯��\n"NOR,users());
        ob->set("mingjie/tu5","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 120000);
      ob->set("title",HIW"˯��"NOR);
           ob->save();
         tell_object(ob,"��Ӯ����һ�ٶ�ʮ�����");

        }
       ::die();
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

