// zhike.c ֪��

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("֪�͵���", ({ "zhike daozhang", "lingxu daozhang", "lingxu", "zhike" }));
        set("long",
                "���������飬���䵱ɽ��֪�͵�����\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("no_get", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_kee", 300);
        set("max_sen", 200);
        set("force", 1300);
        set("max_force", 1300);
        set("mana", 1300);
        set("max_mana", 1300);

        set("combat_exp", 115000);
        set("daoxing", 1101000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("wudang-jian", 20);
        set_skill("taoism", 20);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 3, "����");
        set("chat_chance",2);
        set("chat_msg", ({
            "֪�͵���˵�������䵱�����˽ܣ����ʢ�������µ��˶������ݾ��㡣\n",
            "֪�͵���˵�������������䵱�����Ż����ҵ�һ��Ҫ��������(volunteer)������˿��и����\n"
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_volunteer","volunteer");
}

void greeting(object ob)
{
        mapping myfam;

        myfam = (mapping)ob->query("family");
        if(!myfam || myfam["family_name"] != "�䵱��")
              say ("֪�͵���Ц�����˵����λ"+RANK_D->query_respect(ob) + "����ӭ���䵱���������ȱ��裬ЪЪ�Ȱɡ�\n");
        else
              say ("֪�͵���Ц�����˵����λ"+RANK_D->query_respect(ob) + "��һ·�����ˡ�\n");
        return;
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
}

int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

        if (me->query_temp("in_guard")) 
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");
        ob = users();
        for (i=sizeof(ob); i>0; i--)
        {
                if (ob[i-1]->query_temp("in_guard"))
                return notify_fail("֪�͵�������˵���Ѿ�������ɽ���ˣ���һ�������ɡ�\n");
        }
        tell_room(environment(me),me->query("name")+"��ʼ���䵱ɽ��ֵ�ء�\n");
	me->set("guard", HIG"ɽ������"NOR);
        me->set_temp("in_guard","1"); 
        me->save();
        remove_call_out("end_guard");
        call_out("end_guard", 150, me);
        remove_call_out("clone_meng");
        call_out("clone_meng", 30, me);
        return 1;
}
void clone_meng(object me)
{
        object ob;
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
        ob=new("/d/wudang1/npc/mengmian.c");
        ob->move("/d/wudang1/xuanyuegate");
        call_out("clone_meng", 100, me);
}
void end_guard(object me)
{
        me->delete("guard");
        me->add("guarded",1);
        me->add("combat_exp",10);
        me->add("potential",5);
        if ((int)me->query("potential")-(int)me->query("learned_points")>10000)
           me->set("potential",(int)me->query("learned_points")+10000);
        me->delete_temp("in_guard"); 
        me->save();
        remove_call_out("clone_meng");
        tell_room(environment(me),me->query("name")+"���䵱ɽ��ֵ����������\n");
        tell_object(me,"�����䵱ɽ��ֵ����������\n");
}
void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++)
            me[i]->delete_temp("in_guard"); 

        ::die();
}
