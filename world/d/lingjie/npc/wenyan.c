inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("����", ({ "wen yan", "wenyan", "yan"}));
        set("title", HIR"�������"NOR);   
        set("long", @LONG
ȫ���ж�ë,�沿�����Ͻ��л���,һ����ŭ
��ȫ��ת�ɻ��,���л���,��ʱ�����һ���
��,�ж�Ѹ�١��������Ѿ��������ˡ�
LONG);
        set("gender", "����");
        set("age", 26);
        set("attitude", "peaceful");
        set("per", 10);
        set("rank_info/self", "���");
        set("rank_info/rude", "��ɱ");
        set("class", "lingjie");
        set("max_kee", 2500);
        set("max_gin", 2500);
        set("max_sen", 2500);
        set("force", 2800);
        set("max_force", 2800);
        set("force_factor", 200);
        set("max_mana", 2800);
        set("mana", 2800);
        set("mana_factor", 220);
        set("combat_exp", 2200000);
        set("daoxing", 1800000);

        set_skill("literate", 120);
        set_skill("spells", 160);
        set_skill("kongming-spells", 160);
        set_skill("unarmed", 150);
        set_skill("guangming-shouyin", 150);
        set_skill("dodge", 160);
        set_skill("fengtian-steps", 170);
     set_skill("parry", 160);
     set_skill("libieyu", 16);
     set_skill("force", 170);
    set_skill("yumao", 140);
        set_skill("guangming-force", 160);
        set_skill("umbrella", 150);
        set_skill("lingfan-san",150);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "nine" :),
                (: perform_action, "zifu" :),
                (: perform_action, "jiaoyang" :)
        }) );

        create_family("���", 2, "����");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/yinyang")->wield();
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianshi");
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
