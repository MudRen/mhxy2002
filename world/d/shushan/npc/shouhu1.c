//shushan2 by yushu@SHXY 2000.12 
inherit NPC;
void create()
{
       set_name("��ɽ����", ({"shouwei dizi", "dizi"}));
       set("title", "��������");
       set("long","��ɽ���ɵĽ�������\n");
       set("gender", "����");
       set("age", 28);
	set("str", 25);
       set("attitude", "aggressive");
       set_skill("sword",140);
       set_skill("parry",140);
	set_skill("dodge",140);
	set_skill("fumozhang",140);
       set_skill("unarmed",140);
       set_skill("force",140);
       set_skill("shushan-force",140);
       set_skill("spells",140);
       set_skill("xianfeng-spells",140);
 	set_skill("songhe-sword",140);
	set_skill("zuixian-steps",140);
	map_skill("dodge", "zuixian-steps");
	map_skill("sword", "songhe-sword");
	map_skill("parry", "songhe-sword");
	map_skill("unarmed", "fumozhang");
	map_skill("force", "shushan-force");
	map_skill("spells", "xianfeng-spells");
       set("max_kee",1000);
	set("bellicosity", 5000);
       set("max_sen",1000);
       set("force",2000);
       set("max_force",1000);
       set("mana",2000);
       set("max_mana",1000);
       set("mana_factor", 100);
       set("force_factor", 100);
       set("combat_exp", 300000);
       set("daoxing", 200000); 
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "wanjian" :),
                (: cast_spell, "fu" :),
}) );

       setup();
       carry_object("/d/obj/weapon/sword/qinghong")->wield();
       carry_object("/d/obj/armor/yinjia")->wear();
       add_money("silver", 50);
       }
       void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "��ɽ���Ӻȵ������������ˣ��ô���ɽ���أ�������ˣ�\n");
}
