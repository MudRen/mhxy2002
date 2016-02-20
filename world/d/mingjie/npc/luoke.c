inherit NPC;
#include "star.h"
#include <ansi.h>;
 
void create()
{
        set_name("���", ({"luo ke", "ke"}));
        set("long", "��˵�е��������ļ��ˣ��������Ŀ��ء�\n");
        set("gender","����");
        set("title", "������ǡ�");
        set("age",37);
        set("con",30);
        set("spi",40);
        set("per",30);
        set("str",35);
        set("int",35);
            set("combat_exp",3800000);
        set("daoxing",3800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "���˵��������ʯ��û��ô�򵥡���\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 250);
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
        set("max_force", 3800);
        set("force", 7600);
        set("max_mana",3800);
        set("mana",7600);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3800);
        set("max_gin", 3800);
        set("max_sen", 3800);

        setup();
        carry_object(__DIR__"obj/tjx_cloth")->wear();
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
 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }

     switch(random(6))

     {        
        case 0:
        {
        message_vision(HIC"$Nʹ������������תʯ�ڵ�����\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N���ڵ����˸����ţ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*13);
                }
        else
        message_vision(HIC"$N��ܼ�ʱ���ڵ��ڵ������˸��󶴡�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N����һ�ӣ����г���������ʯ��\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$Nû���ļ��㿪������ʯ���ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*13);
                }
        else
        message_vision(HIC"$Nһ����Ц���㿪����������ʯ��\n"NOR,me);
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

        if((ob&&ob->query("mingjie/er")=="done") &&(ob&&ob->query("mingjie/san")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵�������\n"NOR,users());
        ob->set("mingjie/san","done");
        ob->add("mingjie/number",1);
          ob->add("daoxing", 40000);
       ob->set("title",HIW"�����ڤ��ʿ"NOR);
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
