//created by focus
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("��Ҷ����ʦ", ({"master baye","baye", "master"}));
       set("long", "������ͬʱ��������̫��ʱ������������磬�ǹ���ݱ�ް�Ҷ������\n");
       set("title", HIW"���ʦ��"NOR);
       set("gender", "����");
       set("age", 300);
       set("class", "lingjie");/*��ʦ����ʦ*/
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ");
       set("per", 30);
       set("int", 30);
       set("max_kee", 8000);
       set("max_gin", 8000);
       set("max_sen", 8000);
       set("force", 10000);
       set("max_force", 5000);
       set("force_factor", 200);
       set("max_mana", 5000);
       set("mana", 10000);
       set("mana_factor", 200);
       set("combat_exp", 3000000);
        set("daoxing", 10000000);

       set_skill("literate", 160);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("libieyu", 200);/*�����*/
        set_skill("spells", 200);
        set_skill("kongming-spells", 200);/*������*/
        set_skill("guangming-shouyin", 200);/*��������ӡ*/
        set_skill("guangming-force", 200);/*�����ķ�*/
        set_skill("force", 200);
        set_skill("fengtian-steps", 200);
        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("force", "guangming-force");
        map_skill("parry", "libieyu");
        map_skill("dodge", "fengtian-steps");/*���������Ʋ�*/
        map_skill("yumao", "libieyu");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "nine" :),/*�󰵺�����*/
                (: perform_action, "zifu" :),/*���������Ʋ���(pfm for dodge)*/
                (: perform_action, "piaofeng" :)/*����Ʈ��*/
        }) );

create_family("���", 1, "��");
setup();

        carry_object("/d/lingjie/obj/yuyi")->wear();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/baiyu")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="���") {
        if ((int)ob->query("daoxing") < 320000 ) {
        command("say �������ע�����У�" + RANK_D->query_respect(ob) + "������Ŭ����\n");
        return;
        }

        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����޳���������������Ϊͽ��\n");
        command("sigh");
        return;
        }

        if ((int)ob->query_int() < 38) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("kongming-spells", 1) < 180 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "���ҿ����䷨��ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say �Ϸ��շ������ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "ɱ��̫�أ��ֻ������ѣ�\n");
        return 0;
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

