// sun wukong.c
// By tianlin 2001.5.8
// 加入lingtai设为lingtai的终极boss,skills均为300级.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name("孙悟空", ({"sun wukong","sun", "wukong"}));
       set("long", "一个身不足五尺，瘦瘦干干，满身黄毛的猢狲。\n");
       set("title", HIR"齐天大圣"NOR);
       set("gender", "男性");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "祖师爷");
       set("per", 26);
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 150);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 3456000);

       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("parry", 285);
	set_skill("stick", 285);
	set_skill("sword", 285);
	set_skill("liangyi-sword", 285);
	set_skill("spells", 285);
	set_skill("dao", 285);
	set_skill("puti-zhi", 285);
	set_skill("wuxiangforce", 285);
	set_skill("force", 285);
	set_skill("qianjun-bang", 285);
	set_skill("jindouyun", 285);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"stick","qiankun" :),
        (: perform_action,"stick", "pili" :),
        }) );

create_family("方寸山三星洞", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/jiasha")->wear();
        carry_object("/d/obj/weapon/stick/jingubang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="方寸山三星洞") {
	if ((int)ob->query("daoxing") < 1000000 ) {
  	command("say 这位" + RANK_D->query_respect(ob) + "我看你的道行还差的远呢,拜我起码也要有一千年的道行啊!\n");
	return;
	}
	if ((int)ob->query_str() < 25) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的臂力太差劲了,你还是去找别人吧.\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("qianjun-bang", 1) < 180 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的千均棒法太差了,你还是再练练吧.\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "跟俺老孙,你绝对不会后悔.");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 本座不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
	   ob->set("title", RED"齐天大圣亲传弟子"NOR);
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n孙悟空大喝一声:岂有此理竟不把俺老孙放在眼里.\n\n", environment());
        command("pa wukong");
        message("sound", "\n孙悟空一怒之下,飞回了花果山!\n\n", environment());
        }

        destruct(this_object());
}

�

