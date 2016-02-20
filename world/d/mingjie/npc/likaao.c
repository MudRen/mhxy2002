// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("������", ({"lika ao", "ao"}));
        set("long", "������������ ���������ڰ�����Ŀ��ء�\n");
        set("gender","����");
        set("title", "�������ǡ�");
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
            set("combat_exp",3900000);
        set("daoxing",3900000);
        set("chat_chance",20);
        set("chat_msg", ({
                "������˵��������ֻ����������ͨ����\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 350);
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("westsword",350);
          set_skill("balei",350);
        set_skill("spells",350);
        set_skill("jinniu", 350);
        map_skill("sword","westsword");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3900);
        set("force", 7800);
        set("max_mana",3900);
        set("mana",7800);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3900);
        set("max_gin", 3900);
        set("max_sen", 3900);

        setup();
        carry_object(__DIR__"obj/tz_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;

 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
if(!present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIC"$NͻȻ�ѹ�Ūû�ˣ�\n",ob,me);

        if(random(3)==0)
                {
              message_vision(HIC"$N�����İ�����\n"NOR,me);
              me->add("eff_sen",-query("max_sen")/100*14);
              

                }
        else
        message_vision(HIC"$N����һ����ԭ���ǻþ���\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nʹ����ѧ����������������\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N����Ķ��䶼���ˡ�\n"NOR,me);
              me->add("eff_kee",-query("max_sen")/100*14);
          

                }
        else
        message_vision(HIC"$N��ס���䣬ʲôҲû������\n"NOR,me);
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

        if((ob&&ob->query("mingjie/san")=="done") && (ob&&ob->query("mingjie/si")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵�������\n"NOR,users());
        ob->set("mingjie/si","done");
        ob->add("mingjie/number",1);
       ob->add("daoxing", 50000);
       tell_object(ob,"��Ӯ������ʮ�����");
       ob->set("title",HIW"������ڤ��ʿ"NOR);
         ob->save();

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

