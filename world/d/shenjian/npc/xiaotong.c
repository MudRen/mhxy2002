// teacher.c

inherit NPC;

void create()
{
        int i,amun;
        string *orderr = ({"����", "����", "�Թ�", "СС", "����",
		"����", "ѻѻ", "����", "ëë"});
        set_name( "л" + orderr[random(8)], ({ "kid", "small kid" }) );
	set("title", "��֪Сͯ");
	set("gender", "����" );
	set("age", random(5)+4);
	set("int", 26);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "yixiao" :),
                 }) );
	set("long",
		"����С, ������ñ��۷���.\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

	set("attitude", "peaceful");
	set("combat_exp", random(50000)+20000);
        set_skill("sword", 30+random(30));
        set_skill("qingfeng-jian", 45+random(10));
        map_skill("sword", "qingfeng-jian");
	setup();
        carry_object(__DIR__"obj/sz")->wield();
}
