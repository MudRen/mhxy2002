string clean_tower();
inherit NPC;
void create()
{
       set_name("����", ({"oldman", "laozhe"}));
       set("gender", "����");
       set("age", 150);
        set("long", "һλ���˼�,����ȥһ���������������ӡ�\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 25);
	set("str", 25);
       set("combat_exp", 1000000);
  set("daoxing", 5000000);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("spells", 200);
        set_skill("sword",300);
	
        set("force", 2000);
        set("max_force", 3000);
        set("force_factor", 100);
        set("max_kee", 1000);
        set("max_sen", 1500);
        set("max_mana", 5000);
        set("mana", 5000);
set("inquiry", ([
"here" : "�˵ر�������ˡ�\n",
"��ʦ" : (: clean_tower :),
]));

setup();
 
       carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
       carry_object("/d/lingjie/obj/chanyi")->wield();
}

string clean_tower()
{
	object me,obj,env;
	me=this_object();
	obj=this_player();
	env=environment(this_object());

	if( (string)env->query("short")!="������") {
		command("say " + RANK_D->query_respect(obj) + "��ʲô��˼,�Ҳ����ף�\n");
		return "�ٺ١�\n";
	}
	if( env->query("exits/enter") ) {
		command("say ��һ��"  + RANK_D->query_respect(obj) + "�г�Ϣ,�������\n");
		return "����������,��϶������ͷ�صġ� \n";
	}
	command("touchy " + obj->query("id"));
	env->open_down();
	return"��˵�ϻ���,���ȥ�ɡ�\n";
}
�