// LLY@FYSY 
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("л�ƹ�", ({ "xie zhang gui", "xie", "master" }) );
        set("gender", "����" );
        create_family("��ɽׯ", 5, "����");
        set("age", 42);
        set("long", "�������ɽׯл�ƹ񣬴��һ�����л������\n��ɽׯ���˶�ʹ�������Ǿ�˵л�����õ�ȴ��һ�׶������ֵĵ�����\n");
        set("combat_exp", 360000+random(40000));
        set("daoxing", 360000+random(40000));
        set("attitude", "friendly");
        set("max_force", 1800);
        set("force", 1800);
        set("force_factor", 25);
        set("max_mana", 1800);
        set("mana", 1800);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jichulianhuan" :),
		        }) );
        set_skill("blade",150);
        set_skill("parry",110);
        set_skill("force",120);
        set_skill("xueying-xianfa",130);
        set_skill("literate",120);
        set_skill("spells",120);
        set_skill("sword",80);
        set_skill("cloudforce",140);
        set_skill("dodge", 130);
        set_skill("shenji-blade",150);
        set_skill("shadowsteps",150);
        map_skill("force","cloudforce");
        map_skill("spells","xueying-xianfa");
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shadowsteps");
        setup();
        carry_object(__DIR__"obj/qingcloth")->wear();
	 carry_object(__DIR__"obj/blade")->wield();
        }

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}
void re_rank(object student)
{
                student->set("title","��ɽׯ��ϵ����");
                return ;
}

