// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("��·��", ({"alu li", "li"}));
        set("long", "��ħ�ǵİ�·��������Ŀ��ء�\n");
        set("gender","����");
        set("title", "����ħ�ǡ�");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4100000);
        set("daoxing",4100000);
        set("chat_chance",20);
        set("chat_msg", ({
                "��·��˵�����������ǵ����������ô�����Ұѣ�\n"   
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
        set("max_force", 4100);
        set("force", 8200);
        set("max_mana",4100);
        set("mana",8200);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4100);
        set("max_gin", 4100);
        set("max_sen", 4100);

        setup();
        carry_object(__DIR__"obj/tm_cloth")->wear();
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


     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIG"$N����һ��ʹ������ħ���壡\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N�����˸��䲻����\n"NOR,me);
              message_vision(HIG"$N�������ˣ�\n"NOR,me);

              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/liu");

                }
        else
        message_vision(HIG"$N������һ���������Ƕ��˹�ȥ��\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nһ���������죬һ�ɶ��̴���$n��\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N��Ѭ�Ĳ����˹�ȥ��\n"NOR,me);
              message_vision(HIC"$N�����̴����ˣ�\n"NOR,me);

              me->add("eff_sen",-query("max_sen")/100*15);
              me->move("/d/mingjie/liu1");

                }
        else
        message_vision(HIC"$N����һ�������̴�ɢ�ˡ�\n"NOR,me);
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

        if((ob&&ob->query("mingjie/wu")=="done") && (ob&&ob->query("mingjie/liu2")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵�������\n"NOR,users());
        ob->set("mingjie/liu2","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 70000);
      ob->set("title",HIW"��ħ��ڤ��ʿ"NOR);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

        }
       ::die();
}

