// LLY@FYSY 
// worker.c


inherit NPC;


void create()

{

        set_name("л��", ({ "xiewu" }) );

        set("gender", "����" );
        set("title", "��ɽׯ�ʷ�����");


       set("age", 32);

        set("long", "����һ�����ֵ�����������ׯ��л�Ҵ��ջС��л�˵ĸ�硣\n�Դ�л�ƹ�����ʷ��󣬾������������ʷ���. \n");


       set("combat_exp", 1000000);

        set("attitude", "friendly");

        set_skill("unarmed", 130);

        set_skill("parry", 130);

	set_skill("dodge", 130);

	set_skill("sword",130);

        set("chat_chance", 15);

        set("chat_msg",
        ({
 "л����˸����������������еĺ��̳���������\n", 
             "л����˴����̣������ֹ���ʲô��\n", 
        }) );


	setup();

	   carry_object(__DIR__"obj/zcloth")->wear();
}
