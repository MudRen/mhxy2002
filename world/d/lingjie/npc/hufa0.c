//hufa2


#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��绤��", ({ "hufa","hu", "fa" }));
        set("title", HIR "�������ػ���" NOR);
        set("gender", "����");
        set("age", random(20) + 20);
        set("str", 50);
        set("con", 30);
        set("spi", 40);
        set("dex", 40);
        set("int", 40);
        set("long", "���������ݣ�ɱ�����ڣ����������ӵı���������\n");
        set("combat_exp", 500000);
        set("daoxing", 250000);
        set("class", "hufa");
        set("attitude", "herosim");
        set_skill("unarmed", 110);
        set_skill("force", 110);
        set_skill("umbrella", 110);
        set_skill("dodge", 110);
        set_skill("parry", 110);
        set_skill("lingfan-san", 110);
        set_skill("fengtian-steps", 110);
        map_skill("umbrella", "lingfan-san");
        map_skill("parry", "lingfan-san");
        map_skill("dodge", "fengtian-steps");
        map_skill("unarmed", "guangming-shouyin");
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("force", 2000); 
        set("max_force", 1500);
        set("force_factor", 40);
        set("max_mana", 1500);
        set("mana", 2000);
        set("mana_factor", 30);
        setup();
        carry_object("/d/lingjie/obj/hufa")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}


void copy_status(object me,object ob)
{
	me->set_skill("unarmed", (int)ob->query_skill("unarmed", 1));
	me->set_skill("dodge", (int)ob->query_skill("dodge", 1));
	me->set_skill("parry", (int)ob->query_skill("parry", 1));
        me->set_skill("umbrella", (int)ob->query_skill("umbrella", 1));
	me->set_skill("lingfan-san", (int)ob->query_skill("lingfan-san", 1) + 20);
	me->set_skill("fengtian-steps", (int)ob->query_skill("fengtian-steps", 1)+ 20);
        me->set_skill("guangming-shouyin", (int)ob->query_skill("guangming-shouyin", 1)+ 20);
        me->set("combat_exp",ob->query("combat_exp"));
	me->set("daoxing",ob->query("daoxing"));
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIC"����˫�ֱ�ȭ��΢һ����ת����ƶ�ȥ��\n"NOR, environment(),  this_object());
        destruct(this_object());
}

void invocation(object who)
{       int i;
        object *enemy;

	object me=this_object();
        copy_status(me,who);
        message("vision",HIC"�����һ���߲���Ʈ�����ƹ������ֳ�һ��������\n\n"NOR, environment(),  this_object());
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }

}

