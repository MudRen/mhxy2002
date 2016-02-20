//created by focus
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("��������", ({"jiangshi mingwang","jiangshi", "mingwang"}));
       set("long", "��Ҷ��ʦ�Ķ������֮һ\n");
       set("title", HIB"����"NOR);
       set("gender", "����");
       set("age", 100);
       set("class", "lingjie");/*��ʦ����ʦ*/
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("per", 26);
       set("int", 30);
       set("max_kee", 2000);
       set("max_gin", 1000);
       set("max_sen", 2000);
       set("force", 4000);
       set("max_force", 3000);
       set("force_factor", 100);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
        set("daoxing", 1000000);

       set_skill("literate", 120);
       set_skill("umbrella", 120);
       set_skill("lingfan-san", 120);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
        set_skill("spells", 120);
        set_skill("kongming-spells", 120);
        set_skill("guangming-shouyin", 120);
        set_skill("guangming-force", 120);
        set_skill("force", 120);
        set_skill("fengtian-steps", 120);
        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");
        map_skill("dodge", "fengtian-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "fengtianfu" :),
                (: perform_action, "lieshi" :),
}) );
create_family("���", 1, "��");
setup();

        carry_object("/d/lingjie/obj/yuyi")->wear();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/hufa")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="���") {
        if ((int)ob->query("daoxing") < 120000 ) {
        command("say �������ע�����У�" + RANK_D->query_respect(ob) + "������Ŭ����\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����޳���������������Ϊͽ��\n");
        command("sigh");
        return;
        }
*/
/*        if ((int)ob->query_int() < 30) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }*/

        if( (int)ob->query_skill("kongming-spells", 1) < 60 ) {
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

