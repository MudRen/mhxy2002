// by gslxz@mhsj 2001/11/21 (�Ż�)
// laozhang.c

#include <ansi.h>
inherit NPC;
string expell_me(object me);

void create()
{
	set_name("����", ({ "lao zhang", "zhang", "lao" }));
	set("long", 
		"��������Ĺܼҡ�\n");
          set("title", YEL"����ܼ�"NOR);
	set("gender", "����");
       set("class", "xian");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 16);

	set("str", 20);

	set("combat_exp", 815763);
	set("daoxing", 500000);
	set("max_force", 1500);
       set("force", 1500);
       set("max_mana", 1500);
       set("mana", 1500);

	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("spells", 160);
	set_skill("tianpeng-force", 160);
	set_skill("xbuddhism", 160);
	set_skill("sougu-zhua", 160);
	set_skill("rake", 160);
	set_skill("yanxing-steps", 160);
	set_skill("skyriver-rake", 160);
	set_skill("unarmed", 160);	
	set_skill("parry", 160);
	set_skill("literate", 130);
	map_skill("rake", "skyriver-rake");
	map_skill("parry", "sougu-zhua");
	map_skill("unarmed", "sougu-zhua");
	map_skill("force", "tianpeng-force");
	map_skill("spells", "xbuddhism");
	map_skill("dodge", "yanxing-steps");

	create_family("���", 3, "����");
        set("inquiry", ([
		"�뿪": (: expell_me :),
		"leave": (: expell_me :),
]) );

	setup();
	
           carry_object("/d/tianpeng/obj/gangpa")->wield();
           carry_object("/d/tianpeng/obj/choupao")->wear();
}
void attempt_apprentice(object ob)
{
             if (((int)ob->query("kar") < 29 )) {
	command("say ��" + RANK_D->query_respect(ob) +
                          "�ĸ�Ե�������ܰ��������\n");
	return;
	}

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�������������������\n");
	 message("shout", WHT "��"HIC"������Ϣ"NOR+WHT"����"+ WHT"����ֶ���һ������"+YEL""+this_player()->name()+WHT"�����������ǿ�ˡ�\n"NOR,users());
 command("recruit " + ob->query("id") );
        return;
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="���") {
                me->set_temp("betray", 1);
                command("say �����Ҳ���������ɣ����й����������Ź棡");
                return ("����Ҫ�뿪�������ȴ�����Ź�ͷ������Ը��(agree)?");
        }
        return ("С�϶���֪��");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{               if (this_player()->query("family/family_name") == "���" )
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/tianpeng", 1);
                command("say ������������ݲ����㣬�㻹���߰ɣ�");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("xbuddhism") )
                    this_player()->delete_skill("xbuddhism");
                if( this_player()->query_skill("skyriver-rake") )
                    this_player()->delete_skill("skyriver-rake");
                if( this_player()->query_skill("sougu-zhua") )
                    this_player()->delete_skill("sougu-zhua");
this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("kar",15);
                this_player()->set("per",25);
                this_player()->set("title", "��ͨ����");
                this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
                }
        return 0;}
                else return notify_fail("ʲô��\n");
}int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
               ob->set("class","xian");
                ob->set("per",11);
                ob->set("kar",40);
}
�
