//by tianlin@mhxy for 2002.1.13

inherit NPC;
void create()
{
	 string *order=({"����", "����", "����", "׳��"});
        set_name((order[random(4)]) +"ׯ��", ({ "guards"}) );
        set("gender", "����" );
        set("title", "��ɽׯ");
        set("age", 22+random(10));
        set("long", "������ɽׯ��һ��ׯ����\n");
        set("combat_exp", 30000+random(30000));
        set("daoxing", 50000+random(25000));
        set("attitude", "friendly");
        set_skill("unarmed", 50);
	 set_skill("shadowsteps",random(50)+50);
	 set_skill("dodge", random(50)+50);
	 set_skill("qingfeng-jian",random(50)+50);
        set_skill("parry",random(50)+50);
        set_skill("sword",random(50)+50);
	 map_skill("dodge","shadowsteps");
        map_skill("sword","qingfeng-jian");
        map_skill("parry","qingfeng-jian");
        set("force",3000);
        set("force_factor",random(20)+20);
        set("max_force",1600);
        set("mana",3000);
        set("mana_factor",random(20)+20);
        set("max_mana",1600);
        set("chat_chance", 4);
        set("chat_msg", ({
                "ׯ�����������Ƶ�Ц��Ц��\n",
		(: random_move :),
        }) );
	
	 setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/zcloth")->wear();
        
}

