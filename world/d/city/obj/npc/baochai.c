// baochai.c  Ѧ����
#include <ansi.h>
inherit NPC;
string ask_tea();
string ask_poem();
//string clone_npc();
int singing();
void create()
{
       set_name("Ѧ����", ({ "xue baochai", "xue", "baochai" }) );
       set("title", MAG "���벻������������" NOR);
       set("gender", "Ů��" );
       set("shen_type", 1);
       set("age", 17);
       set("str", 20);
       set("con", 40);
       set("int", 50);
       set("dex", 40);
       set("per", 100);
       set("kar", 100);
       set("no_clean_up",1);
       set("long",
HIW"�����ǽ���ʮ����֮һ��Ѧ���Σ�
�����䲻��ȻƷ��˷���
��ò�������˶�ν������������\n"NOR );
       set("combat_exp", 20000);
       set("attitude", "peaceful");
       set("max_qi", 300);
       set("max_jing", 300);
       set("neili", 100);
       set("max_neili", 100);
       set_skill("literate", 500);
       set("inquiry", ([
                   "name" : "СŮ��Ѧ���Ρ�",
                   "here" : "�������ѩ���๫�ľ��������",
                   "fly" : "fly�������๫��������ô�������ⶼ��֪����",
                   "��ѩ" : "��ѩ������������˰�������ô�������ⶼ��֪����",
                   "����" : "���������á�",
                   "������" : "���������á�",
                   "�ؽ�" : "��ȥ�������ðɡ�",
                   "��" : (: ask_tea :), 
                   "tea" : (: ask_tea :), 
                   "����" : "��Ҳ֪�����ᡢ��������������һ�顶����÷��ʡ��ɡ�", 
                   "����" : "��Ҳ֪�����ᡢ��������������һ�顶����÷��ʡ��ɡ�", 
                   "������÷��ʡ�" : (: ask_poem :), 
                   "����÷���" : (: ask_poem :), 
       ]) );
       setup();
       set("chat_chance", 2);
       set("chat_msg", ({
 "Ѧ���δ����ӣ����������ȷ硣\n",
 "Ѧ�����������⣬��������������������������̨�������кޣ�ϲ���ǰ���\n",
 "Ѧ���λع�ͷ�����ʵ�����֪����Ϊ���ᡢ�����𣿣� \n",
       }) );
       carry_object("/u/fly/obj/jinshan")->wield();
       carry_object("/u/fly/obj/qupu");
       carry_object("/u/fly/obj/pipa");
}
void init()
{
        object ob;
                  ::init();
                  if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
   add_action("do_mo", ({"18mo", "kiss", "hug", "lean", "flirt", "interest"}));
   add_action("do_mo", ({"fire", "kick", "smash", "taste", "hehe", "kiss1"}));
   add_action("do_song","song");
}
void greeting(object ob)
{
        object ball;
        if( !ob || environment(ob) != environment() ) return;
        if((string)ob->query("id")=="fly")
                {
                command("wanfu fly");
                say("Ѧ���������ʺ�" + ob->query("name") + "�������˰ɣ����Ҹ�����������\n");
                say("Ѧ���κ�������Ϊ" + ob->query("name") + "����ش��ű���\n");
                if( !objectp(ball = present("xue qiu", ob)) )
                  new("/u/fly/ball")->move(ob);
               }      
        if(ob->query_temp("kill_baochai"))
               {
                message_vision("Ѧ����üͷһ�壺�������֮ͽ�����ˣ�������ȥ��\n",ob);
                message_vision("ֻ�������Ҷ��ܽ�������$N�Ұ����˳�ȥ��\n",ob);
                ob->move("/d/wiz/wizroom");
                ob->receive_damage("qi", 100);
                message_vision(ob->name() + "�����Ұ����˳�����\n",ob);
        }
        if((string)ob->query("id")!="fly")
                say("Ѧ���ε��˸��򸣣���λ" + RANK_D->query_respect(ob)
              + "�������ӭ����������͡�\n");
}
string ask_poem()
{
        object me;
        me=this_player();
        if(me->query_temp("jie") )
            {
             command("angry");
             return "�㲻�Ǹոս������\n";
             }
        if((string)me->query("id")=="fly")
             { 
               command("xixi");
               command("lover fly");
               return "������֪�������ҡ�\n";
             }
        else {
        command("nod");
        command("say ������÷��ʡ������������ʣ��Ҹ�����ǰ�벿������(song)�����²��ְɡ�\n");
        me->set_temp("jie", 1);
        return "���᱾�������������̨\n";
        }
}
int do_song(string arg)
{
     object me = this_player();
      if( !arg ) return 0;
      if( !me->query_temp("jie") ) return 0;
      if(arg == "������һ��δ��ǳ���" || arg == "������һ��δ��г�����") {
                message_vision(CYN"$N�е���" + arg +"\n"NOR,this_player());
                command("sigh " + me->query("id"));
                command("say �������������ڱ����� ������÷��ʡ���������㣬ȴ��Υ������ʦ�ı��⡣\n");
                command("shake " + me->query("id"));
                return 1;
                          }
      if(arg == "���Գ��徻���δ��г���") {
          message_vision(CYN"$N�е������Գ��徻���δ��г�����\n"NOR,this_player());
          command("thumb " + me->query("id"));
          if( me->query_temp("baochai") ) {
           command("hmm " + me->query("id"));
           command("��ϧ���Ѿ�����ˡ�\n");
           return 1;
           }
          if(present("jin shuaijian", me)){
            command("say ��������һ֧��˦������������Ѿ����ˡ�\n");
            command("say �Ҹ���һ�к��������ɡ�\n");
            new("/u/fly/heiyu")->move(me);
            message_vision("Ѧ���ν���$Nһ�к�������ࡣ\n",this_player());
            me->set_temp("baochai", 1);             
            return 1;
            } 
         else {     
          command("say ��֧����͸���������ɡ�\n");
          new("/u/fly/jin-sjian")->move(me);
          message_vision("Ѧ���ν���$Nһ֧��˦����\n",this_player());          
          me->set_temp("baochai", 1);
          return 1;
             }
           }
      else {
           message_vision(CYN"$N�е���" + arg +"\n"NOR,this_player());
           command("angry");
           command("say ����װ������ͱ����ˡ�\n");
           command("disapp " + me->query("id"));
           return 1;
           }
}
