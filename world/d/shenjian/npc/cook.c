// worker.c


inherit NPC;


void create()

{

        set_name("��ʦ", ({ "cook" }) );

        set("gender", "����" );

        set("age", 42);

        set("long", "����һ�����ֵĵĳ�ʦ. \n");


       set("combat_exp", 100000);

        set("attitude", "heroism");

        set_skill("unarmed", 30);

        set_skill("parry", 30);

	set_skill("dodge", 30);

	set_skill("sword",30);

        set("chat_chance", 35);

        set("chat_msg",
        ({
 "��ʦ��������˸��ˡ�\n",
              }) );


	setup();

	add_money("silver", 300);

        carry_object(__DIR__"obj/zcloth")->wear();}
