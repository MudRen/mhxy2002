//zixiaxianzi.c 2001 by lestat

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_mieyao();
string ask_cancel();
string avenge();
string give_zui(object me);
void create()
{
       set_name(MAG"��ϼ����"NOR, ({"qingxia xianzi", "qingxia", "xianzi","master"}));
       set("long", "������ϼ���ӵ��������,���������������ϼ��������һ�õ�о�������ϼ����˼��
�½翪ɽ����,��׷���˴���\n");
       set("title", HIY"�����о"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "С����");
       set("cor", 30);
       set("per", 21);
       set("max_kee", 4000);
       set("max_gin", 1000);
       set("max_sen", 4000);
       set("force", 4000);
       set("max_force", 2500);
       set("force_factor", 100);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
        set("daoxing", 10000000);
       set_skill("literate", 120);
       set_skill("unarmed", 160);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 180);
       set_skill("spells", 170);
       set_skill("whip", 180);
   set_skill("pansi-dafa", 180);
   set_skill("lanhua-shou", 180);
   set_skill("jiuyin-xinjing", 180);
   set_skill("qingxia-jian", 200);
   set_skill("yueying-wubu", 180);
   set_skill("yinsuo-jinling", 180);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
   set("inquiry", ([
          "����" : (: avenge :),
//		  "��������" : (: give_zui :),
           "����": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
		   "ְλ": (: rank_me :),
]));
   set("no_zui", 0);
create_family("��˿��", 1, "��");
setup();

     //   carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
          carry_object("/d/pansi/obj/key"); 
        carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
add_action("do_yes", "yes");
}
string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="��˿��")
        return ("�㲻�Ǳ��ɵ��ӣ��������Һθɣ�");
    if(who->query("faith")<1000)
        return ("���ڱ���������������������Ŭ�����С�");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("����δ����Ѷ");
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("��������������һ��");
    command("say �������ȥΪ�㱧��");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"ֻ����ϼ���������һָ��\n");
    tell_room(where,"����������ڣ���ȥ��"+killer->query("name")+"ץ����\n");
    tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")+"ץ���ˡ�\n");
    killer->move(where);
    tell_room(where,killer->query("name")+"���ӿ�������������\n");
    command("say ���ϣ�����ɱ������˿������");
    this_object()->kill_ob(killer);
    return("��������");
} 
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "����")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "��˿��"){
                if( exp <= 100000 ){
                        me->set("title", MAG"��˿��"CYN"Ѳ��С��"NOR);
                 } else if(exp < 1000000 ){
                        me->set("title", MAG"��˿��"CYN"ϼ��ʹ��"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", MAG"��˿��"CYN"�һ�������ʹ"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", MAG"��˿��"CYN"��о����"NOR);
                } else {
                        me->set("title", MAG"��˿��"CYN"�����ʥ"NOR);
                }

                tell_object(me, "��ϼ���Ӷ���˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"��ϼ���Ӷ�"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""+me->query("title")+"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{
   /*if ( !((string)ob->query("gender")=="Ů��")){
      command("shake");
          command("say ������˿��ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
      return;
   }*/

   if ( (string)ob->query("family/family_name")=="��˿��") {
   if (((int)ob->query("daoxing") < 500000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������˿��������\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "��˿����ϼ���Ӵ���");
	   ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="��˿��") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("��������,�ι�����?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="��˿��")
     return notify_fail(this_object()->query("name")+"˵�����ֲ��������µ��ӣ����Ҹ�ʲô��\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say ��Ȼ��ˣ������˰ɣ�������û��������񣬵���Щ�ͷ���\n");
	who->add("faith",-5);
        message_vision("$N���ҳ϶��½��ˣ�\n",who);
     }
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}
