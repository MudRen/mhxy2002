// By tianlin 2001.5.1
//By tianlin@mhxy for 2002.2.25�����޸�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>
void create()
{
        set_name("��ȸ����������", ({"kongque mingwang", "kongque", "mingwang", "wang", "pusa"}));
        set("title", HBRED+HIW"��ѩɽ"HIY"��ɽ��ʦ"NOR);
        set("gender", "����" );
        set("age", 90);
        set("per", 30);
        set("str", 30);
        set("long", "��λ��ȸ�����Ǵ�����ʦ��,�书�����ޱ�,������ԶԶʤ������������\n�ر��������ϵ���ѽ�,���������ѵõİѱ���,��˵������ѽ������ƵĿ���,\n��˵�����������Ǹ���ȸ����ѧ��Ľ������.\n");
        set("class", "yaomo");
        set("combat_exp", 11800000);
        set("daoxing", 3456000);

        set("attitude", "peaceful");
        create_family("��ѩɽ", 1, "��ʦ");
        set("rank_info/respect", "����");
        set_skill("unarmed", 285);
        set_skill("cuixin-zhang", 285);
        set_skill("dodge", 285);
        set_skill("xiaoyaoyou", 285);
        set_skill("parry", 285);
        set_skill("sword", 285);
        set_skill("bainiao-jian", 285);
        set_skill("blade", 285);
        set_skill("bingpo-blade", 285);
        set_skill("throwing", 285);
        set_skill("force", 285);   
        set_skill("ningxie-force", 285);
        set_skill("literate", 180);
        set_skill("spells", 285);
        set_skill("dengxian-dafa", 285);
        set_skill("yingzhaogong", 285);
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 3500);
        set("max_sen", 3500);
        set("force", 8500);
        set("max_force", 4800);
        set("mana", 3000);
        set("max_mana", 4000);  
        set("force_factor", 200);//��������,������������enforce��,����enchant�Ͱ�,�������������и���ɱ������.snicker
        set("mana_factor", 10);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "juanbi" :),
                (: cast_spell, "jieti" :),//��ֹplayerɱ��,������ڴ�д��,��ȸ�������Ƴ����ǽ�����.snicker By tianlin 2001.5.1
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng" :),

       }) );
            setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("d/xueshan/obj/ningbi-jian")->wield();
}

void attempt_apprentice(object ob)
{
                int size = sizeof(obstacles);
        string *names = keys(obstacles);
        int i;
        for (i = 0; i < size; i++)
        if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
        {
           command("shake");
           command("say ��λ" + RANK_D->query_respect(ob) + "��δ���������ѹأ������������������ѧ��\n");
           return;
        }

        if( (string)ob->query("family/family_name")=="��ѩɽ" ){
                if( (int)ob->query("family/generation") > 3   ){
                        command("say û���Ĵ󻤷����Ƽ����������ѿ��ǡ�\n");
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1500000 ){
                                command("nod ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ��������п�Ϊ��\n");
                                command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"��ҥ�ԡ�ĳ�ˣ�"BLINK+HIR+ob->query("name")+NOR+HIM"��������ĥ��,����Ѱ�ÿ�ȸ������\n"NOR,users() );
                        }
                        else {
                                command("say �㻹���ȵ������������������ɡ�\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "���ڱ��ſ�û��һ��������¡�\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
              ob->set("title",HBWHT+HIG"��ȸ�������º���ʹ"NOR);
}

