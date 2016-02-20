//By tianlin@mhxy for 2002.1.10���¸ı�

inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_mieyao();
string ask_cancel();
string ask_for_leave();
#include <ansi.h>
void create()
{
        set_name(HIG"������"NOR, ({ "tie zhenzhen", "tie", "zhenzhen", "zhen"}) );
        set("gender", "Ů��" );
        set("age", 21);
        set("agi",30);
        set("str", 60);
        set("per", 21);
        set("int",30);
        set("nickname",HIR"һ��"HIW"��ѩ"NOR);
        set("attitude","friendly");
        set("max_force", 3000);
        set("force", 3000);
        set("force_factor", 200);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_atman", 3000);
	 set("max_kee",2000);
        set("max_gin",2000);
        set("max_sen",2000);
        set("chat_chance", 30);
        set("long",
"������л��������Ҵ���ӣ���ý�����洫��\n"
        );
        create_family("��ɽׯ",2,"���Ŵ����");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "jianqizongheng" :),
        }) );
       set("inquiry", ([
           "ɱħ": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
           "ְλ": (: rank_me :),
           "leave" : (: ask_for_leave :),
]));
       set("combat_exp", 2300000);
       set("daoxing", 2300000);
       set_skill("literate", 120);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("force", 140);
       set_skill("parry", 165);
       set_skill("sword", 185);
       set_skill("spells", 145);
       set_skill("blade", 125);
       set_skill("lianhuan-zhang", 155);
       set_skill("duo-sword", 185);
       set_skill("qingfeng-jian", 185);
       set_skill("cloudforce", 135);
       set_skill("shadowsteps", 145);
       set_skill("xueying-xianfa", 130);
       set_skill("shenji-blade", 150);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "qingfeng-jian");
       map_skill("parry", "duo-sword");
       map_skill("dodge", "shadowsteps");
       map_skill("blade", "shenji-blade");
        setup();
       // carry_object(__DIR__"obj/deitysword")->wield();
      //  carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="��ɽׯ") {
if (((int)ob->query("combat_exp") < 200000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���ջ�Ҫ�ڽ����϶������ϰ��\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", HIW"��ɽׯ"HIG"������"HIY"���´����"NOR);
	   ob->set("class", "shenjian");
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
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}

void re_rank(object who)
{
    int faith=who->query("faith");
    if(who->query("class")!="taoist")return;
    if(faith<=100){
        if(who->query("gender")=="Ů��")
           who->set("title",HIW"��ɽׯ"BLINK+HIM"��Ů����"NOR);
        else who->set("title",HIW"��ɽׯ"BLINK+HIR"�󻤷�"NOR);
        return;
     }else if(faith<=300){
        who->set("title",HIW"��ɽׯ"BLINK+HIG"�һ���"NOR);
        return;
     }else if(faith<=600){
        who->set("title",HIW"��ɽׯ"BLINK+HIY"����"NOR);
        return;
    }else if(faith<=1000){
        who->set("title",HIW"��ɽׯ"BLINK+HIC"����"NOR);
        return;
    }else if(faith<=1800){
        who->set("title",HIW"��ɽׯ"BLINK+BLK"��ƶ"NOR);
        return;
    }else if(faith<=3000){
        who->set("title",HIW"��ɽׯ"BLINK+HIC"����"NOR);
        return;
    }else if(faith<=6000){
        who->set("title",HIW"��ɽׯ"BLINK+HIG"����"NOR);
        return;
    }else who->set("title",HIW"��ɽׯ"BLINK+HBRED+HIW"��ħ"NOR);
    return;
}
void init()
{
        add_action("do_agree", "agree");
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "����")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "��ɽׯ"){
                if( exp <= 100000 ){
                        me->set("title", HBRED+WHT"�� �� ɽ ׯ"NOR+HIY"�轣���ᶽ"NOR);
                 } else if(exp < 1000000 ){
                        me->set("title", HBRED+WHT"�� �� ɽ ׯ"NOR+HIM"�λ�ʹ��"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", HBRED+WHT"�� �� ɽ ׯ"NOR+HIR"�񵶽�ħ"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", HBRED+WHT"�� �� ɽ ׯ"NOR+HIB"��꽣ƶ"NOR);
                } else {
                        me->set("title", HBRED+WHT"�� �� ɽ ׯ"NOR+HIC"������"NOR);
                }

                tell_object(me, "л�������˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"л�����"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""NOR+me->query("title")+HIC"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}

string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="��ɽׯ") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("��������,�ι�����?\n");
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
string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "��ɽׯ" ) {
                command("say �����ִ��Ҫ��ׯ�����ȴ�м��仰˵��");
                me->set_temp("betray/sj", 1);
                return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)��");
        }

        return ("���֪��\n");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray/sj")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                command("say ����������ɽׯ��Ե������ׯȥ�ɣ�");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shenjian", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*60/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*60/100);
                if( this_player()->query_skill("duo-sword") )
                    this_player()->delete_skill("duo-sword");
                if( this_player()->query_skill("xueying-xianfa") )
                    this_player()->delete_skill("xueying-xianfa");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                command("rumor "HBRED+HIW"��ɽׯ"NOR+HIG"����ͨ����"HIC+this_player()->query("name")+HIY"���ٲ�����"HBRED+HIW"��ɽׯ"NOR+HIY"�����ˣ�"NOR);
                return 1;
        }
}
