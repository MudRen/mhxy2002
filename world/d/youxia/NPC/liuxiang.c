
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 //created 23-06-2001 ����Ʈ(piao)

//yegucheng.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_map(object me);
int do_yes(string arg);


void create()
{
       set_name("������", ({ "chu liuxiang", "chu", "liuxiang" }) );

       set("long", "���������ǵ�����������֮һ���˳ơ���˧������\n");
      set("faith",4000);
       set("gender", "����");
     set("title", HIW "��˧����"NOR);
   set("class", "youxia");
       set("age", 34);
       set("attitude", "friendly");
        create_family("��������", 1, "��");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 2000);
       set("max_gin", 1100);
       set("max_sen", 2000);
       set("force", 8000);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
       set("daoxing", 2000000);
        set("eff_dx", 250000);
        set("nkgain", 400);
            set("chat_chance", 10);
        set("chat_msg", ({
            "������˵�������Һ����Ŵ�ѩ����ֿ�ѣ���С���к��¾�Ȼ�����ң�����
��˵����÷ɽׯ�ĺ�ɽ�д��ٲ��������Ǯ�ƣ�����Ҫ���������������ߣ������ҾͶ�����һ�£�\n",
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :)
   }) );

       set_skill("unarmed", 250);
       set_skill("tanzhishentong", 250);
       set_skill("dodge", 250);
       set_skill("piaoxiang",250);
     
       
         map_skill("unarmed", "tanzhishentong");
         
       map_skill("dodge", "piaoxiang");
   

        set("inquiry", ([
        "Ѫ��Ʈ��" : (: give_map :),

]) );

setup();
       
        carry_object("/d/youxia/obj/flsword");
        carry_object("/d/youxia/obj/wushicloth")->wear();
}


void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="��������") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say ��λ"+ RANK_D->query_respect(ob) + "���书��΢�����������Ǽ�����������Ұɡ�\n");
   return;
   }
        command("smile");
   command("say �ܺã�ԭ����λ"  + RANK_D->query_respect(ob) +"����������ͽ�ܣ��ðɣ�������������Ϊͽ��\n");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
       command("recruit " + ob->query("id") );
       ob->set("title", HIW"�������洫����"NOR);
  return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "��Ȼ�Ѿ���������,������Ѱ���˰ɣ�\n");
        return;
}
void init()
{
      ::init();
//      re_rank(this_player())
      add_action("do_fuming","fuming");
      add_action("do_yes", "yes");
}


string give_map(object me)
{
        me=this_player();
        me->set_temp("need_map", 1);
        return ""HIW"��Ѫ��Ʈ�㡽"HIC"���ұ����书�ľ���,����Ҫ��(yes)��"NOR"\n";
}


int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if(me->query_temp("need_map")) 
        {
                message_vision("$N�������Ҫ��\n\n", me);

               if(me->query("family/family_name") != "��������" )
                return notify_fail("������˵������ƭ�����ɵ��ؼ���û�ţ�\n");

                if( query("no_map") == 0 )
                {
                        message_vision("������˵�����ã����Ҹ����Ȿ�ؼ��ɣ�\n", me);
                        me->set_temp("need_map", 0);

                        carry_object("/d/youxia/obj/piaoxiang");
                        command("give book to " + me->query("id"));
                        set("no_map", 1);
                        call_out("regenerate", 480);
                }
                else
                {
                        message_vision("������˵�����ұ��������һ���ģ����Ǹղű���Ҫ���ˡ�\n", me);
                }

                return 1;
        }
        return 0;
}

int regenerate()
{
        set("no_map", 0);
        return 1;
}



