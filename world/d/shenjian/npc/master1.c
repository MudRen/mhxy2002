// LLY@FYSY
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("л����", ({ "master xie", "master", "xie", "xie wangsun"}) );
        set("nickname", YEL "ĺɫ��Ϧ" NOR);
        set("gender", "����" );
        set("age", 51);
        set("agi",30);
        set("str", 60);
        set("per", 35);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 200);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("long",
"����˲������⡣���Ǹ������ˣ�Ҳ������껹��Щ�����������Ѱߣ���ɫ����
¶�������ƣ�롣�����ú����أ�һ����������Ь���ࡣ�������������������
�ţ����������������վ�����������Ϊ��̫ƽ����ƽ���þ�����������ĺɫ
��������ſ�����������������Ҳ���翴����Ϧĺɫһ��������ֻ��о�����ƽ��
�����������������������һ��㾪��Ϳ־壬������ͣ�����ƽ�׵��ˣ�������
����Ȼ����̫�ϣ�������������ȴ�ѵ��˻ƻ裬�����������Ļƻ��ƽ��������
�������Ѳ�����ʲ��������ĵ��¡�\n"
        );
        create_family("��ɽׯ", 4, "ǰ��ׯ��");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jianqizongheng" :)
        }) );
        set("chat_msg_combat", ({
 "л����ƽ����˵����ÿ���˶������Լ������ˡ�\n�����ˣ����ǲ��ң���Թ���ϱ��ˣ�������Щ��������Ҳ���������ˣ�\n", "л���������̾Ϣ��˵��������ս���壿�������Ѿ��������,����������ʮ���졣\nл����ָ��ľ�����úڲ����ŵĶ�����һ�������ķ����Ķ�����\n"
	     }) );

        set("combat_exp", 2300000);
        set("daoxing", 1300000);
        set_skill("parry",200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("literate", 120);
        set_skill("unarmed",180);
        set_skill("shadowsteps",240);
        set_skill("qingfeng-jian",300);
        set_skill("cloudforce",200);
        set_skill("sword",200);
        map_skill("dodge", "shadowsteps");
        map_skill("force", "cloudforce");
        map_skill("parry","softsword");
        map_skill("sword", "softsword");    
        setup();
        carry_object(__DIR__"obj/deitysword")->wield();
        carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object me)
{
        if(me->query_temp("won_master_xie"))
        {
        command("say һ����Ҫѧ������Ӧ�ó������⣬������̫�������������������
�����κ�һ�������������������\n");
        command("recruit " + me->query("id") );
                return;
        }
        else
        {
        command("sigh");
        command("say ��ɽׯ�������ѽ��\n");
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}

void re_rank(object student)
{
                student->set("title","����");
                return ;
}

