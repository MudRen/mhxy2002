// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
        set_name("����", ({"currency"}));
       set("title", HIG"�������"NOR);
      set("gender", "Ů��");
   set("long", "һλ�������˵���Ů,�����¼�,ֱ���˷��ȥ.\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500000);
   create_family("�Ϻ�����ɽ", 2, "����");
   set("age", 16);
   set("per", 100);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "����");
   set("max_kee", 2500);
   set("max_sen", 2500);
   set("force", 3000);
   set("max_force", 2000);
   set("force_factor", 80);
   set("max_mana", 3000);
   set("mana", 5000);
   set("mana_factor", 100);

   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("force", 160);
  set_skill("huntian-qigong", 180);
   set_skill("parry", 160);
   set_skill("dodge", 160);
   set_skill("moondance", 160);
   set_skill("unarmed", 160);
   set_skill("yinfeng-zhua", 160);
   set_skill("sword", 160);
   set_skill("sanqing-jian", 160);

   map_skill("spells", "buddhism");
   map_skill("force", "huntian-qigong");
   map_skill("dodge", "moondance");
   map_skill("unarmed", "yinfeng-zhua");
   map_skill("sword", "sanqing-jian");
  set("chat_chance_combat", 75);
  set("chat_msg_combat", ({
  (: exert_function, "zhangqi" :),
  (: cast_spell, "bighammer" :)
}));
        set("inquiry", ([
                "������"   : (: ask_me :),
                "��۫��"   : "��۫��������������һ��,��������Ӱ�����Ƕ�!\n",
                "��Ӱ"     : "��˵��Ӱ������̩ɽ,Ҳ��֪�����Ǽ�!\n",
                "̩ɽ"     : "�����Ƕ�����,��������Ҳ����!\n",
        ]));

   set("time", 1);
   setup();
   carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

string ask_me()
{
        object ob;
           
    
       if (this_object()->is_fighting())
         return "û��������������, �Ժ���˵��!\n";

   if ( present("qingsuo-sword", this_player()) )
     return "��������������������!!\n";
        if ( present("qingsuo-sword", environment()) )
       return "����߲�����һ����������!!\n";

   if(query("time") <1 )
     return "���ɣ����ɣ���Ҳû�ˣ�\n";

     say("����˵��: �ǵ�Ҫ���㹻����������, ���������!\n");
     this_player()->set_temp("currency_fight", 1);
     return ("�ٺ٣�\n");
}


int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("currency_fight")){
     command("say ���򲻴�,û�������������˰�!!\n");
         return 0;
   }
       // added by snowcat on 6/22/1997
   if (me->is_fighting()){
     command("say ���򲻴�!\n");
     return 0;
   }
   say("����Ц��: �����ﴳ��������ô����, Ҳ��û㤹�˭!\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("currency_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
   object obj;
       // added by snowcat on 6/22/1997
        if (me->query("time")<=0)
                return;
   obj=new("/d/obj/weapon/dagger/qingsuo-sword");
   command("sigh");   
   say("����̾��һ����: ������������˵�����ô��,���򶼻ķ���!\n");
   say("����Ц��: �����ǳ���������ǰ��,һ������ʤ����!\n");
        obj->move(who);
        me->add("time", -1);
message_vision("�����$N��ȻһЦ��: �����������վ���������!\n", who);
   call_out("reg", 750);
}
int reg()
{
   object me, obj; 
   me=this_object();
   me->set("time",1);

//add weapon in case anyone took it already.
   if( !me->query_temp("weapon")){
     obj=new("/d/obj/weapon/sword/qinghong");
     obj->move(me);
     command("wield all");
   }   
   return 1;
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("���ᰲο��:"+msg+"�����,�ؼҺú������,���շ�����!\n");
}
void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;

   // changed by snowcat on 6/24/1997
   // bug abuse: player can exert recover when fight stops,
   //if ((my_kee*100/my_max_kee) <=(whos_kee*100/whos_max_kee) )
   //      player_win (me, who);
   //else player_lose (me, who);
   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);

}

void die()
{

        if( environment() ) {
 message("sound", "\n\nֻ��һ������,���ữ��һ����ϼֱ�ɾ����ȥ������\n\n
�����������Ц��һ��,��ô�����ô�����������\n\n", environment());
        }

        destruct(this_object());
}




