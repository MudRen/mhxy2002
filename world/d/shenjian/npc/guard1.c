//By tianlin@mhxy for 2001.12.6�����Ż�

inherit NPC;
void create()
{
        set_name("�������", ({ "guards"}) );
        set("gender", "����" );
        set("title", "��ɽׯ");
        set("age", 22);
        set("long", "������ɽׯһ����������ĵ��ӡ�\n");
        set("combat_exp", 500000+random(200000));
        set("daoxing", 500000+random(200000));
        set("attitude", "friendly");
        set_skill("unarmed", 150);
	 set_skill("shadowsteps",random(100)+80);
	 set_skill("dodge", random(100)+80);
	 set_skill("qingfeng-jian",random(60)+20);
        set_skill("parry",random(100)+80);
        set_skill("sword",random(60)+20);
	 map_skill("dodge","shadowsteps");
        map_skill("sword","qingfeng-jian");
        map_skill("parry","qingfeng-jian");
        set("force",2500);
        set("mana",2500);
        set("max_mana",2500);
        set("mana_factor",random(30)+20);
        set("force_factor",random(30)+20);
        set("max_force",500);
        set("chat_chance", 3);
        set("chat_msg", ({
                "�������������ͷ���������̹���\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/zcloth")->wear();
        
}

