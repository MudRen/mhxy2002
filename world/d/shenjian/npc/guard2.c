//By tianlin@mhxy for 2001.12.6�����Ż�
inherit NPC;
void create()
{
        set_name("�������", ({ "guards"}) );
        set("gender", "����" );
        set("title", "��ɽׯ");
        set("age", 22);
        set("long", "������ɽׯһ����������ĵ��ӡ�\n");
        set("combat_exp", 400000+random(500000));
        set("daoxing", 400000+random(500000));
        set("attitude", "friendly");
        set_skill("unarmed", 150);
	 set_skill("shadowsteps",random(60)+20);
	 set_skill("dodge", random(60)+20);
	 set_skill("qingfeng-jian",random(100)+30);
        set_skill("parry",random(100)+20);
        set_skill("sword",random(100)+40);
	 map_skill("dodge","shadowsteps");
        map_skill("sword","qingfeng-jian");
        map_skill("parry","qingfeng-jian");
        set("force",3500);
        set("mana",3500);
        set("max_mana",3500);
        set("force_factor",random(40)+20);
        set("mana_factor",random(40)+20);
        set("max_force",3500);
        set("chat_chance", 3);
        set("chat_msg", ({
                "�������������ͷ�����Ž�����\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/zcloth")->wear();
        
}

