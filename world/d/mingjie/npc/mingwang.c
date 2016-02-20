// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("����˹", ({"hadis", "ming wang"}));
        set("long", "��˵�е�ڤ������˹.\n");
        set("gender","����");
        set("title", "��ڤ����");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
            set("combat_exp",5500000);
          set("daoxing",5500000);
        set("chat_chance",20);
        set("chat_msg", ({
                "����˹˵����������Ǽ������磡\n"   
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
        set_skill("tianxie", 350);
        map_skill("sword","westsword");
        map_skill("spells","tianxie");
        map_skill("dodge","balei");
        set("max_force", 7000);
        set("force", 14000);
        set("max_mana",7000);
        set("mana",14000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 7000);
        set("max_gin", 7000);
        set("max_sen", 7000);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object ghost;
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
              message_vision(HIR"$N˵��������֮�þ�����\n",ob);

        if(random(2)==0)
                {
              message_vision(YEL"$N��ڤ��֮�����˸����ţ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*25);
              me->add("eff_sen",-query("max_sen")/100*25);
                }
else        message_vision(YEL"$N���ȼ�֮�����ȶ��ˡ�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N����һ������һ������֮����$n��ȥ��\n",ob,me);

        if(random(2)==0)

                {
              message_vision(YEL"$N��ʱ��������ͷ��\n"NOR,me);
                 me->add("eff_kee",-query("max_kee")/100*30);
              me->add("eff_sen",-query("max_sen")/100*30);
                }
        else
        message_vision(YEL"$N��æ�㿪�ˡ�\n"NOR,me);
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

        if((ob&&ob->query("mingjie/tu5")=="done") && (ob&&ob->query("mingjie/jingtu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "����ڤ����\n"NOR,users());
        ob->set("mingjie/jingtu","done");
        ob->add("mingjie/number",1);
    ob->set("title",HIW"�ŵ��ȵ���ʿ"NOR);
           ob->save();
         ob->add("daoxing", 150000);
       tell_object(ob,"��Ӯ����һ����ʮ�����");

        }
       ::die();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
        add_action("do_none","dahan");


}
int do_none()
{
        object me = this_object();
        message_vision("$N��Цһ�����������ҵĹ�������˵���㣡����\n",me);
        return 1;
} 
