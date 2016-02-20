// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("��ŵ�ն�", ({"miluo taoer", "miluo"}));
        set("long", "�����ǵ���ŵ�ն����������Ŀ��ء�\n");
        set("gender","����");
        set("title", "�������ǡ�");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4200000);
        set("daoxing",4200000);
        set("chat_chance",20);
        set("chat_msg", ({
                "��ŵ�ն��Ժ���˵������ڤ��ʮ���������ҹܵģ�\n"   
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
        set("max_force", 4200);
        set("force", 8400);
        set("max_mana",4200);
        set("mana",8400);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3500);
        set("max_gin", 3500);
        set("max_sen", 3500);

        setup();
        carry_object(__DIR__"obj/tn_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
//        add_action("do_none","exert");

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


     switch(random(9))
     {        
        case 0:
        {
        message_vision(HIG"$N˵������ȥ��һ���ѡ���\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIG"$N��һ���紵����һ����\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi");

                }
        else
        message_vision(HIG"$N�ڷ�����ת�ţ������������������ս��\n"NOR,me);
        }
        break;

  case 1:
        {
        message_vision(HIG"$N˵������ȥ�ڶ����ѡ���\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIG"$N��һ���紵���ڶ�����\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi1");

                }
        else
        message_vision(HIG"$N�ڷ�����ת�ţ������������������ս��\n"NOR,me);
        }
        break;
  case 2:
        {
        message_vision(HIG"$N˵������ȥ�������ѡ���\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIG"$N��һ���紵����������\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi2");

                }
        else
        message_vision(HIG"$N�ڷ�����ת�ţ������������������ս��\n"NOR,me);
        }
        break;
       case 3:
        {

        message_vision(HIC"$N˵��������ȥ���ĺ��ѡ���\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIC"$N��һ��������ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi3");
                
}
        else
        message_vision(HIC"$N�ó����ӣ��ѹ⵲ס�ˡ�\n"NOR,me);
        }
        break;
case 4:
        {

        message_vision(HIC"$N˵��������ȥ���庾�ѡ���\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N��һ��������ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi4");
                
}
        else
        message_vision(HIC"$N�ó����ӣ��ѹ⵲ס�ˡ�\n"NOR,me);
        }
        break;
case 5:
        {

        message_vision(HIC"$N˵��������ȥ�������ѡ���\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N��һ��������ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi5");
                
}
        else
        message_vision(HIC"$N�ó����ӣ��ѹ⵲ס�ˡ�\n"NOR,me);
        }
        break;
 case 6:
        {

        message_vision(HIC"$N˵��������ȥ���ߺ��ѡ�n��\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N����Ӱ��Ӱ��ץ���ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi6");

                }
        else
        message_vision(HIC"$N������һ���ƴ��Ӱ�������˻�ȥ��\n"NOR,me);
        }
        break;
 case 7:
        {

        message_vision(HIC"$N˵��������ȥ�ڰ˺��ѡ�n��\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIC"$N����Ӱ��Ӱ��ץ���ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi7");

                }
        else
        message_vision(HIC"$N������һ���ƴ��Ӱ�������˻�ȥ��\n"NOR,me);
        }
        break;
 case 8:
        {

        message_vision(HIC"$N˵��������ȥ�ھź��ѡ�n��\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIC"$N����Ӱ��Ӱ��ץ���ˣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi8");

                }
        else
        message_vision(HIC"$N������һ���ƴ��Ӱ�������˻�ȥ��\n"NOR,me);
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

        if((ob&&ob->query("mingjie/liu2")=="done") && (ob&&ob->query("mingjie/qi")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"��ڤ�硿�ŵ���(Ya dian na):"+ob->name()+
        "�����˵�������\n"NOR,users());
        ob->set("mingjie/qi","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 80000);
      ob->set("title",HIW"������ڤ��ʿ"NOR);
           ob->save();
         tell_object(ob,"��Ӯ���˰�ʮ�����");

        }
       ::die();
}

