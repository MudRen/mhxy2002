inherit NPC;

void create()
{
        set_name("����", ({ "farmer" }) );
        set("gender", "����" );
        set("age", 25+random(20));
        set("long", "�㿴��һλ��ɫ��ڵĴ���\n");
        set("combat_exp", 1500000+random(800000));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "����е���ɱ���ģ�ɱ���ģ�\n",
                "����е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("gold", 50);
}
