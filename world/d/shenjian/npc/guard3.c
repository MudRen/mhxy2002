//By tianlin@mhxy for 2001.12.6�����Ż�

inherit NPC;
void create()
{
        set_name("����", ({ "guards"}) );
        set("gender", "����" );
        set("title", "��ɽׯ");
        set("age", 22);
        set("long", "������ɽׯһ������ֵ�ڵ�������\n");
        set("combat_exp", 800000+random(800000));
        set("daoxing", 800000+random(800000));
        set("attitude", "friendly");
        set_skill("unarmed", 150);
	 set_skill("shadowsteps",random(100)+70);
	 set_skill("dodge", random(100)+70);
	 set_skill("qingfeng-jian",random(100)+70);
        set_skill("parry",random(100)+70);
        set_skill("sword",random(100)+70);
	 map_skill("dodge","shadowsteps");
        map_skill("sword","qingfeng-jian");
        map_skill("parry","qingfeng-jian");
        set("force",4500);
        set("force_factor",random(40)+30);
        set("max_force",5000);
        set("mana",4500);
        set("mana_factor",random(40)+30);
        set("max_mana",5000);
        set("chat_chance", 3);
        set("chat_msg", ({
                "���������������ص�Ѳ���š�\n",
        	      (: random_move :),  }) );
	
	 setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/zcloth")->wear();
        
}

