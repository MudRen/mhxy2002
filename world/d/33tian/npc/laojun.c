//By tianlin@mhxy for 2002.1.2.
 
#include <ansi.h>
inherit NPC;
string ziyingsword(object me);
void create()
{
       set_name("̫���Ͼ�", ({"taishang laojun","laojun"}));
       set("long", "�쳾һЦǣ��ţ,���˽����Ҷ���.\n");
       set("title", HBRED+MAG"��������"NOR);
       set("gender", "����");
       set("age", 100);
       set("class", "xian");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
	create_family("��ׯ��", 1, "��ʦ��");
       set("per", 26);
       set("int", 30);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);
       set_skill("unarmed", 285);
       set_skill("wuxing-quan", 285);
       set_skill("dodge", 285);
       set_skill("baguazhen", 285);
       set_skill("parry", 285);
       set_skill("medical",285);
       set_skill("sword", 285);
       set_skill("sanqing-jian", 285);
       set_skill("staff", 285);
       set_skill("fumo-zhang", 285);
       set_skill("hammer", 285);
       set_skill("kaishan-chui", 285);
       set_skill("blade", 285);
       set_skill("yange-blade", 285);
       set_skill("force", 285);   
       set_skill("zhenyuan-force", 285);
       set_skill("literate", 180);
       set_skill("spells", 285);
       set_skill("taiyi", 285);
       map_skill("spells", "taiyi");
       map_skill("force", "zhenyuan-force");
       map_skill("unarmed", "wuxing-quan");
       map_skill("sword", "sanqing-jian");
       map_skill("dodge", "baguazhen");
       map_skill("staff", "fumo-zhang");
       map_skill("blade", "yange-blade");
       map_skill("hammer", "kaishan-chui");

       set("max_kee", 4500);
       set("max_sen", 4500);
       set("force", 6000);
       set("max_force", 5500);
       set("mana", 7000);
       set("max_mana", 4000);   
       set("force_factor", 200);
       set("mana_factor", 200);

       set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
       set("chat_chance_combat", 90);
       set("chat_msg_combat", 
   ({
     (: cast_spell, "zhenhuo" :),
     (: perform_action, "sword", "jianmang" :),
   }) );
      set("inquiry", ([
      "�����«": "�����«��Ϊ��ۿ��򵤴������,��ʢ�鵤,����������.\n",
      "��": (: ziyingsword :),
      "��۫��": (: ziyingsword :),
      "ziying-sword": (: ziyingsword :),
      "jian": (: ziyingsword :),
]));

setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/33tian/obj/yunxue")->wear();
        carry_object("/d/obj/weapon/sword/zijian")->wield();
}
void init ()
{
  add_action("do_back", "back");
}
int accept_object(object who, object ob)
{
 if((string)ob->query("id") !="baiyu-ling"){
 command("say ��û����۵�����,��ô�ܸ��������«.");
 return 0;
}
else {  
 command("smile");
 command("say �����������«��ͬС��,����·�ϱ�������ȥ,����������۽���.");
 command("say ������ʤ����,����ܷ��ĵð���������!");
 this_player()->set_temp("laojun_fight", 1);
 return 1;
}
}
int accept_fight(object who)
{
 object me;
 me = this_object();
     if (!who->query_temp("laojun_fight")){
     command("say �޵�֮�˲�����������!!\n");
         return 0;
   }

 say("̫���Ͼ�Ц��:�����ϵ���ƴ�������Ϲ�ͷ,��������а�!\n");
  me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));
     who->set_temp("laojun_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}
void player_win(object me, object who)
{
       object hulu;

      hulu=new("/d/33tian/obj/hulu");
      command("sigh");
      say("̫���Ͼ�̾��:С���ɹ�Ȼ�Ƿ�����ǿ,���������������!!\n");
      hulu->move(who);
message_vision("̫���Ͼ���:�������«���վͽ���$N��,·�Ͽɵ�С����.\n",who);
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);

   command("jump");
   say("̫���Ͼ�Ц��:"+msg+"������Ҫ��������,�����ʸ����������«!\n");
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
   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

void die()
{

        if( environment() ) {
message("sound", "\n\n̫���Ͼ�ŭ��,������������������\n\n", environment());
message("sound", "\n˵������������ţ,���Ƴ����ض�ȥ������\n\n", environment());

        }

        destruct(this_object());
}
void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")=="dao" )
     command("say �ã��ã����ɱ�һ�ҡ�\n");
   
  //}

   if( (string)ob->query("family/family_name")=="��ׯ��" )
   {
     if( (int)ob->query("family/generation") > 3   )
     {
        command("say ��»������������ռ������ӣ����ȵ��Ǳ߿����ɡ�\n");
     }
     else 
     {
        if( (int)ob->query("combat_exp") >= 300000 && (int)ob->query_skill("taiyi", 1) >= 120 )
        {
          command("nod ");
          command("say �ã�" + RANK_D->query_respect(ob) + "�����Ǳ��ŵ��˲ţ�\n");
          command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��ҥ�ԡ�ĳ�ˣ���˵"HIW"<<"BLINK+HIW+ob->query("name")+NOR+HIW">>"HIY"����ȡ��"NOR+HIM"���������õ�"HIC"̫���Ͼ�"HIM"��ָ�㣬���ǿ�ϲ�ɺء�\n"NOR,users() );
        }
        else
        {
          command("say �����Ͻ��ǲ�����������Ҫѭ�򽥽���\n");
        }
     }
   }

   else
   {
     command("nod");
     command("say ��λ" + RANK_D->query_respect(ob) + "�����Ž�������֮����֮�֡�һ�������Ϊ�������ӿ����Ĳ�����\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
              ob->set("title",HIW"���ʹ������洫"NOR);
}
int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("33tian/from");

  message_vision("$N����$n��$N�ط���\n",who,me);
  there = "/d/city/kezhan";

  message_vision("$N��������������$n��Զ����ȥ����\n",me,who);
  who->move(there);
  message_vision("�����������һֻ�޴�ķ�������һ����ֻ��$N��������������\n",who);
  
  return 1;
}
string ziyingsword(object me)  
{
        object jian;
   me=this_player();
 //  if((string)me->query("family/family_name")!="��ׯ��") {
 //        message_vision("\n̫���Ͼ��������ǵ��ѣ��⽣Ҳ������...\n", me);
 //        return ("���ȥ��\n");
 //       }
    if(me->query("faith")<500)
          command("say ����ô�������أ�");
     if( me->query("laojun_killjing") != 1 ) 
        {
          me->set("laojun_jing", 1);
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          return ("��˵������ׯ�ۺ�԰����Ϭţ����������Ƚ����������ȥ������\n");
        }
     if( me->query("laojun_killjing") != 1 ) 
        {
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          message_vision("̫���Ͼ���ָһ��.....\n\n", me);
          message_vision("̫���Ͼ��������ڻʹ�!\n", me);
          return ("��Ȼ��ˣ�������ȥ��\n");
        }
     if( me->query("enter") != 1 ) 
        {
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          message_vision("\n̫���Ͼ��������ڻʹ�!�����Ժ����ѽ��\n", me);
          return ("��Ȼ��ˣ�������ȥ��\n");
        }
     if( me->query("laojun_killjingover") != 1 ) 
        {
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          message_vision("\n̫���Ͼ��������ڻʹ�!�����Ժ����ѽ��\n", me);
          return ("��Ȼ��ˣ�������ȥ��\n");
        }

          message_vision("\n̫���Ͼ������úã�����������ѽ�Ҳ���͸����ˡ�\n", me);
          message_vision("̫���Ͼ����������������ҿ�����Ϊ��������Ī�����ĺ�������\n", me);
          message_vision("̫���Ͼ��͸���һ����۫����\n", me);
          jian = new("/d/obj/weapon/sword/zijian.c");
          jian->move(me);
          me->delete("laojun_trye_yes");
          me->delete("laojun_jing");
          me->delete("laojun_killjing");
          me->delete("laojun_killjingover");
          me->delete("laojun_enter");
          return ("��˵����һ�ѽ�������ĸ�ղص�...Ҳ�����������Ǽ٣���\n");
}
