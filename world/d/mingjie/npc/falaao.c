inherit NPC;
#include "star.h"
#include <ansi.h>;
 
void create()
{
        set_name("������", ({"fala ao", "ao"}));
        set("long", "�����Ƿ����µڶ����Ŀ��ء�\n");
        set("gender","Ů��");
        set("title", "�������ǡ�");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
           set("combat_exp",3700000);
          set("daoxing",3700000);
        set("chat_chance",20);
        set("chat_msg", ({
                "������˵�����������䷸��̰�������ˣ�������Ϊ������ͷȮ��ʳ���\n"   
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
        set_skill("shuangzi", 350);
        map_skill("sword","westsword");
        map_skill("spells","shuangzi");
        map_skill("dodge","balei");
        set("max_force", 3700);
        set("force", 7400);
        set("max_mana",3700);
        set("mana",7400);
        set("mana_factor",180);
        set("force_factor", 150);
        set("max_kee", 3700);
        set("max_gin", 3700);
        set("max_sen", 3700);

        setup();
        carry_object(__DIR__"obj/ts_cloth")->wear();
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
        message_vision("����֮��������±ç������\n",me);
        return 1;
} 

void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;

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
        message_vision(HIG"$N�ֳ�ħ�٣������һ�������������������\n",ob,me);

        if(random(4)==0)

                {
              message_vision(HIG"������$N���������Ķ������ˣ�\n"NOR,me);
              me->add("eff_sen",-query("max_sen")/100*12);
 
                }
        else
        message_vision(HIG"����ס���䣬����$N�����࣡\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nһ���֣�һͷ������ͷȮ��������$n��\n",ob,me);

        if(random(4)==0)

                {
              message_vision(HIC"$N����ҧ�˸����ţ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*12);
           

 
                }
        else
        message_vision(HIC"$N��Ϳ������ˣ��ӻ����ó�һ����ͷ���ѹ������ˡ�\n"NOR,me);
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

        if((ob&&ob->query("mingjie/yi")=="done") && (ob&&ob->query("mingjie/er")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵ڶ�����\n"NOR,users());
        ob->set("mingjie/er","done");
        ob->add("mingjie/number",1);
           ob->add("daoxing", 30000);
     ob->set("title",HIW"������ڤ��ʿ"NOR);
          ob->save();
  tell_object(ob,"��õ�����ʮ�����!");

        }
       ::die();
}

