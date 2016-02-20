inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("ʤ��", ({ "sheng qi", "shengqi", "qi"}));
        set("title", HIY"�������"NOR);   
        set("long", @LONG
ȫ���ǳ�ë,��������֮ë�Զ�,˫�����,����
�غ�,���Գ�β����������ҷ�����ּ䡣���Խ���
Ϊ���С�
LONG);
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("per", 20);
        set("rank_info/self", "����");
        set("rank_info/rude", "��");
        set("class", "lingjie");
        set("max_kee", 1500);
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("force", 2700);
        set("max_force", 2700);
        set("force_factor", 150);
        set("max_mana", 2800);
        set("mana", 2800);
        set("mana_factor", 160);
        set("combat_exp", 2000000);
        set("daoxing", 1500000);

        set_skill("literate", 150);
        set_skill("spells", 155);
        set_skill("kongming-spells", 155);
        set_skill("unarmed", 150);
        set_skill("guangming-shouyin", 150);
        set_skill("dodge", 160);
        set_skill("fengtian-steps", 160);
        set_skill("parry", 160);
        set_skill("force", 150);
        set_skill("guangming-force", 150);
        set_skill("umbrella", 160);
        set_skill("lingfan-san",160);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("���", 2, "����");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/yinyang")->wield();
        
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