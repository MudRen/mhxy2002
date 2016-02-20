//created by focus
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("�ַ�����", ({"pufan youzhu","youzhu", "master"}));
       set("long", "СС��ͣ�ȴ����ò���ȭ�ľ���������Զ����ħ���顢�����硣\n");
       set("title", HIG"���ݷ���ѧ" HIR"No.1"NOR);
       set("gender", "����");
       set("age", 20);
       set("class", "lingjie");/*��ʦ����ʦ*/
       set("attitude", "heroic");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ");
       set("per", 30);
       set("int", 30);
       set("max_kee", 80000);
       set("max_gin", 80000);
       set("max_sen", 80000);
       set("force", 100000);
       set("max_force", 50000);
       set("force_factor", 2000);
       set("max_mana", 50000);
       set("mana", 100000);
       set("mana_factor", 200);
       set("combat_exp", 35000000);
        set("daoxing", 80000000);

       set_skill("literate", 260);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("parry", 300);
       set_skill("libieyu", 300);
        set_skill("spells", 300);
        set_skill("kongming-spells", 300);
        set_skill("guangming-shouyin", 300);
        set_skill("guangming-force", 300);
        set_skill("force", 300);
        set_skill("fengtian-steps", 300);
        set_skill("umbrella", 300);
        set_skill("lingfan-san", 300);
        set_skill("yumao", 300);
        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("force", "guangming-force");
        map_skill("parry", "libieyu");
        map_skill("dodge", "fengtian-steps");/*���������Ʋ�*/
        map_skill("yumao", "libieyu");
        map_skill("umbrella", "lingfan-san");
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
        carry_object("/d/lingjie/obj/san");
}

void attempt_apprentice(object ob)
{       
      ob=this_player();
      if( (int)ob->query("family/generation") > 2) {
      command("shake");
      command("say �㻹����ȥ�Ұ�Ҷ��ʦ�ɣ�\n");
      return;      
      }
      if( (string)ob->query("family/family_name")=="���") {
        if ((int)ob->query("combat_exp") < 5000000 ) {
        command("say ���ŵ㱾��Ҳ�������ѧ����" + RANK_D->query_respect(ob) + "������ȥ�����ɡ�\n");
        return;
        }

        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����޳���������������Ϊͽ��\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        return;
      }
      command("shake");
      command("say �������ģ���" + RANK_D->query_respect(ob) + "�ҿɲ����ܣ�Ө�ӻ����ҵ�Ŷ��\n");
      return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "���ɣ�����ϲ������ˣ���\n");
        return 0;
}

