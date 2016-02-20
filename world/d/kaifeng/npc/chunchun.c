//by tianlin 2001.7.30
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_for_leave();
#include <ansi.h>

void create()
{
       set_name("����", ({"chun chun", "chunchun", "master"}));
       set("long",
"�����ǿ������һ�����ĸ��֣�\n");
       set("title", MAG"С����"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class", "kaifeng");
       set("attitude", "friendly");
       set("rank_info/respect", "Ư��");
       set("per", 30);
	set("int", 30);
	set("str", 730);
       set("max_kee", 19500);
       set("max_gin", 19500);
       set("max_sen", 19500);
       set("force", 1500);
       set("max_force", 1700);
       set("force_factor", 80);
       set("max_mana", 2000);
       set("mana", 3000);
       set("mana_factor", 120);
       set("combat_exp", 1200000);
  set("daoxing", 1100000);


        set("eff_dx", 70000);
        set("nkgain", 260);

  set_skill("unarmed", 142);
  set_skill("dodge", 127);
  set_skill("parry", 130);
  set_skill("rake", 150);
  set_skill("force", 120);
  set_skill("spells", 130);
  set_skill("fofa", 130);
  set_skill("literate", 160);
  set_skill("tianpeng-zhang", 120);
  set_skill("bajie-force", 140);
  set_skill("chaos-steps", 120);
  set_skill("skyriver-rake", 120);
  map_skill("force", "bajie-force");
  map_skill("spells", "fofa");
  map_skill("rake", "skyriver-rake");
  map_skill("unarmed", "tianpeng-zhang");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "chaos-steps");
        set("inquiry", ([
         "leave" : (: ask_for_leave :),
         "ְλ": (: rank_me :),
                ]) );
create_family("����˧��", 2, "����");
setup();

  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "����˧������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "����˧��"){
                if( exp <= 100000 ){
                        me->set("title", HIY"����˧��"WHT"��Ů"NOR);
                  } else if(exp <= 1000000 ){
                        me->set("title", HIY"����˧��"WHT"�����輧"NOR);
                  } else if(exp <= 2000000 ){
                        me->set("title", HIY"����˧��"WHT"Ʈ������"NOR);
                  } else if(exp <= 3000000 ){
                        me->set("title", HIY"����˧��"WHT"��ңʥŮ"NOR);
                } else {
                        me->set("title", HIY"����˧��"WHT"����ʥĸ"NOR);
                }

                tell_object(me, "��������˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"������"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""+me->query("title")+"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{

        if( (string)ob->query("family/family_name")=="����˧��" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ҹ��������ˣ�\n");
                }
                else if( (int)ob->query("family/generation") ==3  ){
                        command("blush ");
                        command("say �����" + RANK_D->query_rude(ob) + "����������Ը�ģ��ɲ�������ǽ��...\n");
                        command("recruit " + ob->query("id") );
                        message("system", HIY"������˧���ֶ���һ������  "+this_player()->name()+HIW"
                 ����˧����������ǿ�ˡ�\n"NOR,users());
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 200000 ){
                                command(":) ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "��Ȼ�������¾͵ø����������ɲ���͵����\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say �㻹���ұ��������Űɡ�\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "���㻹���ұ����������ɡ�\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}
void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "����˧��" ) {
                command("say �����ִ����ǣ����ȴ�м��仰˵��");
                me->set_temp("betray/tp", 1);
                return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)��");
        }

        return ("���֪��\n");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray/tp")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                command("say ������������˧����Ե�������ǰ�ȥ�ɣ�");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/tianpeng", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("fofa") )
                    this_player()->delete_skill("fofa");
                if( this_player()->query_skill("skyriver-rake") )
                    this_player()->delete_skill("skyriver-rake");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
        }
}
