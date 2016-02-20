// LLY@FYSY // waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("л��", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 19);
	set("long",
		"����л�ˣ��������ջ��С��������æµ��������ȴ��ʱ�ֹ���ʲô��\n");
	set("combat_exp", 650000);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	setup();
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
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
			say( "л��˵������λ" + RANK_D->query_respect(ob)
				+ "��ס����\n");
			break;
		case 1:
			say( "л����ë��Ĩ��Ĩ�֣������ֹ�������λ" + RANK_D->query_respect(ob)
				+ "ҲҪȥ������ү�Ƚ��𣿡�\n");
			break;
		case 2:
			say( "л��С��˵������λ" + RANK_D->query_respect(ob)
				+ "����������ȥ�޻ص��ˡ�\n");
			break;
		case 3:
			say( "��С��˵������λ" + RANK_D->query_respect(ob)
				+ "��Ҫ����������ס�ꣿ\n");
			break;
	}
}
