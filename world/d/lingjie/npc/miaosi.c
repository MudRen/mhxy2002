inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("��˼", ({ "miao si", "miaosi", "si"}));
        set("title", HIW"�������"NOR);   
        set("long", @LONG
��������,������������޴����,ȫ���л�
ɫ�Ķ�ë,�ж�ʱ���纣��,ϲ����ѩ���﷭��
��Ϊ������ǰ֧֫������,����˼��״��������
�Խ������ˡ�
LONG);
        set("gender", "Ů��");
        set("age", 35);
        set("attitude", "peaceful");
        set("per", 25);
        set("rank_info/self", "��Ը�");
        set("rank_info/rude", "����");
        set("class", "tianshi");
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 250);
        set("max_mana", 3000);
        set("mana", 3000);
        set("mana_factor", 250);
        set("combat_exp", 2800000);
        set("daoxing", 2000000);

        set_skill("literate", 150);
        set_skill("spells", 180);
        set_skill("kongming-spells", 180);
        set_skill("unarmed", 180);
        set_skill("guangming-shouyin", 180);
        set_skill("dodge", 180);
        set_skill("fengtian-steps", 180);
        set_skill("parry", 170);
        set_skill("force", 180);
        set_skill("guangming-force", 180);
        set_skill("umbrella", 200);
        set_skill("lingfan-san",200);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("���", 1, "����");

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
	if (((int)ob->query("daoxing") < 1000000 )) {
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