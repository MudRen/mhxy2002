//by elva@mhxy and tianlin@mhxy 2001.9.30

inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_me();
string ask_for_leave();
#include <ansi.h>

void create()
{
	set_name("��Զ��", ({ "song yuanqiao", "song" }));
	set("nickname", "[1;37m�䵱[1;31m����[2;37;0m");
	set("long", 
		"������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
		"��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
		"���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
	set("gender", "����");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "wudang");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 3000);
	set("max_sen", 3000);
	set("force", 5000);
	set("max_force", 2000);
	set("mana", 5000);
	set("max_mana", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("daoxing", 1110000);

	set_skill("force",130);
set_skill("wudang-force", 150);
	set_skill("dodge", 130);
        set_skill("wudang-xianfa", 130);
        set_skill("spells", 130);
	set_skill("tiyunzong", 130);
	set_skill("unarmed", 120);
	set_skill("taiji-quan", 120);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("taiji-jian", 140);
	set_skill("wudang-jian", 130);
	set_skill("literate", 110);

	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 2, "����");
        set("inquiry", ([
              "leave" : (: ask_for_leave :),
              "ְλ": (: rank_me :),
		"�ؼ�" : (: ask_me :),
                ]) );
create_family("�䵱��", 2, "����");
setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang1/obj/greyrobe")->wear();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "�䵱������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "�䵱��"){
                if( exp <= 100000 ){
                        me->set("title", HIY"�䵱��"NOR+HIR"��ɽ��ͯ"NOR);
                  } else if(exp <= 1000000 ){
                        me->set("title", HIY"�䵱��"NOR+HIR"��������"NOR);
                  } else if(exp <= 2000000 ){
                        me->set("title", HIY"�䵱��"NOR+HIR"������ʿ"NOR);
                  } else if(exp <= 3000000 ){
                        me->set("title", HIY"�䵱��"NOR+HIR"��ң����"NOR);
                } else {
                        me->set("title", HIY"�䵱��"NOR+HIR"��������"NOR);
                }

                tell_object(me, "��Զ�Ŷ���˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"��Զ�Ŷ�"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""NOR+me->query("title")+NOR+HIC"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{

        if( (string)ob->query("family/family_name")=="�䵱��" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say �����" + RANK_D->query_rude(ob) + "������ǲ���үү���ˣ�\n");
                }
                else if( (int)ob->query("family/generation") ==3  ){
                        command("hoho ");
                        command("say �ðɣ�ƶ�����������ˡ�");
                        command("recruit " + ob->query("id") );
                        message("system", HIY"���䵱���ֶ���һ������  "+this_player()->name()+HIW"
                 �䵱�ɵ�������ǿ�ˡ�\n"NOR,users());
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
                ob->set("class", "wudang");
                ob->set("title", "[1;33m�䵱��[1;37m��[1;36m��[1;37m������[2;37;0m");
}
void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "�䵱��" ) {
                command("say �����ִ����ɽ��ƶ��ȴ�м��仰˵��");
                me->set_temp("betray", 1);
                return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)��");
        }

        return ("���಻֪��\n");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                command("say ���������䵱����Ե�������ɽ�ɣ�");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/moon", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("wudang-force") )
                    this_player()->delete_skill("taiji-jian");
                if( this_player()->query_skill("wudang-jian") )
                    this_player()->delete_skill("taiji-quan");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
        }
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/d/wudang1/obj/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�̫��ʮ��ʽ����\n");
	return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}
