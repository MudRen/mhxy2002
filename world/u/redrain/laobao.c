//by swagger
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���", ({ "lao bao", "lao", "bao" }) );
        set("gender", "Ů��" );
        set("title", HIR"�仨¥"NOR);
        set("age", 40);
        set("long", 
            "�������Ǵ仨¥���ϰ����ˣ������������ˣ�\n��˵���������������ͷ�Ż�����\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 18);
        set("shen_type", 1);

        set_skill("force", 20);
        set("combat_exp", 200);

        set("max_kee", 300);
        set("max_sen", 100);
        set("force", 500);
        set("max_force", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "�����Ҿ���������ϰ��",
            "�仨¥" : "�仨¥�����������µĺ�ȥ����",
            "here" : "��������������µĴ仨¥�ˣ�Ҫ��Ҫ�Ҹ�С��?",
       ]) );

        setup();
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
                "����ż���˵�����������ϣ������ҿ��������ͷ�Ż�����\n",
                "������˵�����������С�㶼���Ҿ�����ѡ�ģ�Ҫ��Ҫ������һ����\n",
        }) );
        carry_object("/obj/loginload/shoes")->wear();
        carry_object("/obj/loginload/skirt")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("wenhou");
                call_out("wenhou", 1, ob);
        }
}

void wenhou(object me)
{
    command("look " + me->query("id"));

    if (me->query("class") =="bonze") {
       command("say �ϣ�" + RANK_D->query_respect(me) 
                +"Ҳ����˴仨¥����");
       command("say ��λ��ʦ���ò������������ԽӴ��㰡��");
       command("grin");
    }
    if (me->query("gender")=="Ů��")
 {
       command("say ��!�������û���мˣ���������??");
       command("kick " + me->query("id"));
    }
    command("say ¥��¥�µĹ����ǿ����������п������ˣ�");
    }

