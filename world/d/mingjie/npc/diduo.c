// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("�϶����ȶŶ�", ({"di duo", "duo"}));
        set("long", "����ǵĵ϶����ȶŶ����ڰ����Ŀ��ء�\n");
        set("gender","����");
        set("title", "������ǡ�");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4500000);
        set("daoxing",4500000);
        set("chat_chance",20);
        set("chat_msg", ({
                "�϶����ȶŶ�˵������������ʥ��ʿ�ķ�Ĺ��\n"   
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
        set("max_force", 4500);
        set("force", 9000);
        set("max_mana",4500);
        set("mana",9000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4500);
        set("max_gin", 4500);
        set("max_sen", 4500);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
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
        message_vision(RED"$N�߾�˫�֣�ʹ����ѧ������ʵ����������\n",ob,me);

                if(random(3)==0)

                {
              message_vision(RED"$N����һ�����ң�\n"NOR,me);
              me->add("eff_sen",-query("max_sen")/100*15);
                }
        else
        message_vision(RED"$N�Ͻ��������飬�������һ�٣�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIW"$N������һ�˵������������������\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIW"$N�����ڱ��У�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
                }
        else
        message_vision(HIW"$N������գ���û��$N��\n"NOR,me);
        }
        break;
    }
        if( random(10) == 3 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}

void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("mingjie/qi")=="done") && (ob&&ob->query("mingjie/ba1")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵ڰ�����\n"NOR,users());
        ob->set("mingjie/ba1","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 100000);
      ob->set("title",HIW"�����ڤ��ʿ"NOR);
           ob->save();
         tell_object(ob,"��Ӯ����һ�������");

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
