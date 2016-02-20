// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("���Ÿ�˹", ({"aiya gaosi", "gaosi"}));
        set("long", "�����ǵİ��Ÿ�˹���������Ŀ��ء�\n");
        set("gender","����");
        set("title", "�������ǡ�");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4000000);
        set("daoxing",4000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "���Ÿ�˹˵��������������Ľ̻�����ˣ������������У�\n"   
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
        set("max_force", 4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4000);
        set("max_gin", 4000);
        set("max_sen", 4000);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
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
        message_vision(HIG"$N�߾�˫�֣�ʹ����ѧ�������ս�����\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N��һ���紵������գ��ֵ���������\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
                }
        else
        message_vision(HIG"$N�ڷ�����ת�ţ������������������ս��\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nһ���������죬����ͺ�շ���$n��\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N��ͺ��Χס�����˸����������\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
                }
        else
        message_vision(HIC"$N����һ����𣬰�ͺ�������ˡ�\n"NOR,me);
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

        if((ob&&ob->query("mingjie/si")=="done") && (ob&&ob->query("mingjie/wu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵�������\n"NOR,users());
        ob->set("mingjie/wu","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 60000);
      ob->set("title",HIW"������ڤ��ʿ"NOR);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

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
