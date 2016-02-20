// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
//string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name(HIW"������"NOR, ({"master dadi", "dadi", "master"}));
       set("long", "�й���ǧ�괫��������̹ſ����������ƹ������е��似��\n");
       set("title", HIC"���ʥ��"NOR);
       set("gender", "����");
       set("age", 100);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "���");
       set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 145);
        set("max_mana", 3000);
        set("mana", 6000);
        set("mana_factor", 150);
        set("combat_exp", 2000000);
        set("daoxing", 10000000);


        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);
        set_skill("feisheng", 280);
        set_skill("literate", 200);
        set_skill("sword", 280);
        set_skill("wuying", 300);
        set_skill("fumobashi", 280);  
        set_skill("mizongbu", 270);
        set_skill("dodge", 280);  
        set_skill("force", 280); 
        set_skill("xiantian", 280);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        set("chat_chance_combat", 60);
/*           set("inquiry", ([
                "��ɽ":    (: expell_me :),
                "leave":   (: expell_me :),
 ]) );     */

	create_family("��ʥ��", 1, "����");
	
        setup();
        //carry_object("/d/wusheng/obj/armor")->wear();
        //carry_object("/d/wusheng/obj/cloth")->wear();
        //carry_object("/d/wusheng/obj/pifeng")->wear();
        //carry_object("/d/wusheng/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ʥ��") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ���ǽ�ħ����֮�����صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "�����޳����Ϸ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("feisheng", 1) < 140 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���ҷ�������ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-1000);
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
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="��ʥ��") {
    tell_room(environment(me),"������˵��.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("�Ϸ�֪������˵Щʲô��");
}




int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "wusheng");
}
/*string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="��ʥ��") {
                me->set_temp("betray", 1);
                return ("������ʥ�Ź棬ȴ���ܷ������Ը��(agree)?");
        }
        return ("ȥ���ʱ��ŵ��Ӱɣ���������֪����");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/wusheng", 1);
	        this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                if( this_player()->query_skill("xiantian") )
		  this_player()->delete_skill("xiantian");
                if( this_player()->query_skill("fumobashi") )
		  this_player()->delete_skill("fumobashi");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->save();
                command("say ����ȥ�ɣ�\n");
                return 1;
                }
        return 0;
}
*/
