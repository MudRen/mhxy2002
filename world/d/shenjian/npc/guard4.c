// LLY@FYSY
inherit NPC;
void create()
{
        set_name("����ͳ��", ({ "guards"}) );
        set("gender", "����" );
        set("title", "��ɽׯ");
        set("age", 32);
        set("long", "������ɽׯһ������ֵ�ڵ�������\n");
        set("combat_exp", 1000000+random(1000000));
        set("daoxing", 1000000+random(1000000));
        set("attitude", "friendly");
        set_skill("unarmed", 180);
	 set_skill("shadowsteps",random(100)+100);
	 set_skill("dodge", random(100)+100);
	 set_skill("qingfeng-jian",random(100)+100);
        set_skill("parry",random(100)+100);
        set_skill("sword",random(100)+100);
	 map_skill("dodge","shadowsteps");
        map_skill("sword","qingfeng-jian");
        map_skill("parry","qingfeng-jian");
        set("force",4500);
        set("force_factor",random(50)+40);
        set("max_force",5000);
        set("mana",4500);
        set("mana_factor",random(60)+40);
        set("max_mana",5000);
        set("chat_chance", 3);
        set("chat_msg", ({
                "����ͳ���Ĵ�����Ĺ۲��š�\n",
        	     }) );
	
	setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/zcloth")->wear();
        
}

