// LLY@FYSY
//by tianlin@mhxy for 2001.12.1

inherit NPC;

void create()

{

        string *name = ({"����ѩɽ","�����¹�","ڤ��ظ�","�䵱��","������","����","��ɽ��"});
                set_name(name[random(sizeof(name))]+"����", ({ "swordman"}) );

        set("gender", "����");

        set("age", random(20)+20);

        set("long",
                "һ������ɽׯ���Ľ��ͣ�����������л���壬�Ӷ��������£�\n");

	set("combat_exp", 1250000+random(2000000));

        set_skill("sword", 150+random(140));
        set("chat_chance", 5);

        set("chat_msg", ({
        	name()+"̾������ɽׯ�����񽣶���ѽ����\n",
		name()+"�����ҿ���ɽׯҲ��������������\n",     }) );

        set("attitude", "friendly");
        setup();
           carry_object("/obj/cloth")->wear();

        carry_object("/d/shenjian/npc/obj/sword")->wield();
}
