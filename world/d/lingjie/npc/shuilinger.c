inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("ˮ���", ({ "shui linger", "shuilinger", "linger"}));
        set("title", HIC"�������"NOR);   
        set("long", @LONG
����һ�Դ��������֮����ͨ���ˮ��ɫ��ϲ��
��ˮ����һ���ӽ�ˮ�ߣ�����������γ�һ��
��ɫ�ľ��壬�����������С���Ϊ��ˣ�ˮ�����
�������ı�������ˮ��������㡣�������Խ���
���ˡ�
LONG);
        set("gender", "Ů��");
        set("age", 21);
        set("attitude", "peaceful");
        set("per", 28);
        set("rank_info/self", "ˮ��");
        set("rank_info/rude", "ˮ���");
        set("class", "lingjie");
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 120);
        set("max_mana", 2500);
        set("mana", 2500);
        set("mana_factor", 120);
        set("combat_exp", 1500000);
        set("daoxing", 1000000);

        set_skill("literate", 140);
        set_skill("spells", 140);
        set_skill("kongming-spells", 140);
        set_skill("unarmed", 140);
        set_skill("guangming-shouyin", 140);
        set_skill("dodge", 140);
        set_skill("fengtian-steps", 140);
        set_skill("parry", 140);
        set_skill("force", 140);
        set_skill("guangming-force", 140);
        set_skill("umbrella", 140);
        set_skill("lingfan-san",140);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("���", 2, "����");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/zhehun")->wield();
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="���") {
	if (((int)ob->query("daoxing") < 200000 )) {
	command("say ���У�" + RANK_D->query_respect(ob) + "����й��ף����������±��˲�����\n");
	return;
	}
        command("jump");
	command("say ���գ����ա���"  + RANK_D->query_respect(ob) +
"�������˲�ȴ���ټ���\n");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ����������������硣\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say ����˭���Һ���û����" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}


void die()
{

        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if (ob){
        CHANNEL_D->do_channel(this_object(),"chat",sprintf("�ұ�%sɱ�ˣ����ĵ���Ϊ�ұ��𰡣�",ob->name(1)));
        ::die();}

    
}
