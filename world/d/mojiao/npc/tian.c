inherit NPC;
#include "power.h"
 
void create()
{
        set_name("��ħ", ({"tianmo", "arch devil"}));
        set("long", "�㿴��һ������ɱ�����ˣ����������ܲ����ǡ�\n");
        set("gender","����");
        set("title", "ħ���������");
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
        set("combat_exp",9000000);
//      set("daoxing",3000000);
        set("chat_chance",20);
        set("attitude", "friendly");
        set_skill("dodge", 350);
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("tianxian-sword",350);
        set_skill("tianmo",350);
        set_skill("dimo-steps",350);
        set_skill("spells",350);
        set_skill("huolong-zhang", 350);
        map_skill("sword","tianxian-sword");
        map_skill("unarmed","huolong-zhang");
        map_skill("spells","tianmo");
        map_skill("dodge","dimo-steps");
        set("max_force", 6000);
        set("force", 9000);
        set("max_mana",8000);
        set("mana",16000);
        set("mana_factor",250);
        set("force_factor", 250);
        set("max_kee", 5500);
        set("max_gin", 5500);
        set("max_sen", 5500);

        setup();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        int mywx, obwx;
     mywx=me->query("combat_exp");
     obwx=ob->query("combat_exp");
     obwx=obwx * 8;

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
        message_vision(HIC"$N�����˾����ͻȻ����������һ������������$n��\n",ob,me);

        if(obwx>random(mywx+obwx))      

                {
              message_vision(HIC"���$n�����˸����ţ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
                }
        else
        message_vision(HIC"���Ǳ�$N�㿪�ˡ�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N���һ����ѪȾ���գ���\n",ob,me);

        if(obwx>random(mywx+obwx))      


                {
              message_vision(HIR"ֻ��������һ��Ѫ��һ����$n�ѱ�һ�Ѿ޴��ޱȵ�ħ�п��˸�������\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
                }
        else
        message_vision(HIW"���Ǳ�$n�㿪�ˡ�\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N���һ������Ѫ��ɽ����\n",ob,me);
                              
        if(obwx>random(mywx+obwx))      


                {
              message_vision(HIR"$N��һ�ӣ���ʱ���Ѫ���ܲ���һ���������籩����������$n��\n"NOR,me);
              me->start_busy(1);
              me->add("eff_kee",-2*query("max_kee")/15);
                }
        else
        message_vision(HIY"��û��$N�������꣬$n��һ�ƴ���$N��\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{
        object ob = query_temp("my_killer");        
        ob->start_busy(3);
        ob->set("mojiao/pk","done");
       ::die();
}
