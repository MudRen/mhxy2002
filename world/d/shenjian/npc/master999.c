// LLY@FYSY
#include <ansi.h>

inherit NPC;
int send_letter();

//int wieldsword();
void create()

{
        
        set_name("л����", ({ "master xie", "xie xiaofeng", "master","xie"  }) );

        set("long",
"л��������ѧ��,ʮ���꽣��,ʮ����ܻ�����,һ�����ϸ�����ὣ��������˫
��������������,��������Ľ����ݶ����,����һ����ծ����\n");
        
        set("nickname", HIG"����"NOR);
        set("attitude", "heroism");
        create_family("��ɽׯ",1,"ׯ��");
        set("str", 50);
        set("cor", 40);
        set("cps", 40);
	 set("agi",40);
	 set("int",40);
        set("combat_exp", 8000000);
        set("daoxing", 4000000);
	 
        set("max_force", 5600);
        set("force", 5600);
        set("max_mana", 6000);
        set("mana", 6000);
        set("force_factor", 100);
        set("inquiry", ([
		"apprentice" : (: send_letter :),
	        "��ʦ" : (: send_letter :), ]));
        set("chat_chance_combat", 15);

        set("chat_msg_combat", ({
 "л����̾������ɽׯ���ڻ�����\n",

"л����������գ���̾��һ������\n",
	     }) );

                set("chat_chance", 15);

                 set("chat_msg_combat", ({
           //     (: wieldsword  :),
        }) );
        set_temp("apply/damage",500);
	 set_skill("sword",280);
	 set_skill("force",300);
        set_skill("parry",300);
        set_skill("dodge",300);
        set_skill("unarmed",300);
	 set_skill("cloudforce",290);
        set_skill("literate",170);
	 set_skill("qingfeng-jian",300);
        set_skill("shadowsteps",300);
	map_skill("dodge","shadowsteps");
	map_skill("force","cloudforce");
	map_skill("sword","qingfeng-jian");
        setup();

        carry_object(__DIR__"obj/letter");
        carry_object(__DIR__"obj/3childe-sword");
        carry_object(__DIR__"obj/sjcloth")->wear();

      //  carry_object(__DIR__"obj/ajiskin")->wear();
}
void attempt_apprentice(object me)
{
        if(me->query_temp("for_shenjian"))
	{
	command("haha");
        command("remove skinmask");
        command("say �ðɣ���Ȼ����������ɽׯ֮�ˣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("shake");
        command("say �����Ц�ģ��������ʸ�����Ϊͽ��\n");
	}
	}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}
 
void init()
{add_action("do_look","look");

        }

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if ( exp <= 512000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ɽׯ��ʥ");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��ɽׯ����");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ɽׯ���");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ɽׯ��ɷ");
                return ;
        } else
                student->set("title","��ɽׯ����");
                return ;

}

int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
        command("say �ã���Ӯ���ҾͿ���ȥ��ɽׯ����ѧϰ������Ľ����ˣ�\n");
        return 1;
        }
        else
        {
        command("fear");
        command("say ������֪���Ƕ��֣����ǲ��ñ��ˡ�");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say ���ڽ����ϵ����軹�������������ɣ�\n");
}
void lose_enemy(object winner)
{
command("say ��Ľ����Ѿ�����֮�ϣ�����ȥ��ɽׯ����ѧϰ������Ľ����ˣ���\n");
winner->set_temp("won_master_xie",1);
}


int do_look(string arg)
{
if (arg == "aji" )
{
write("��������һ��������ӵ����꺺��,ƽʱ��Ҷ������С�û�õİ�������\n");
write("��������Լ��ʮ���ꡣ\n");
write("�书��������������С�ɣ������ƺ����ᡣ\n");
return 1;
}
return 0;
}
int send_letter()
{
        object letter,me;

	me = this_player();
	say("л����˵������λ" + RANK_D->query_respect(me) +
		"������������Ϊʦ���͵�����֮��������ɽׯ��\n��Ը��Ļ��ͽ����Ž�����ɽׯ��ԺС¥֮�ˡ�\n");
	if( letter = present("letter", this_object())) {
	
	       letter->move(me);
		message_vision(HIY "$N��һ���Ž�����$n���ֿ�ʼ�ɻ��ˡ�\n" NOR, this_object(), me );
	}
        return 1;
}
/*int wieldsword()
{
command("wield sword");
perform_action("sword.yixiao");
command("unwield sword");
return 1;
} */
