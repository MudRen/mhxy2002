// link

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("����ʦ��", ({ "shifu" }) );
	set("gender", "����" );
	set("age", 42);
	set("long",
		"��λ��ʦ����æ�Ÿ�������װ����æ����Ǯ��\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",10);
	set("vendor_goods", ([
                __DIR__"obj/rice" : 40,
                __DIR__"obj/baishi" : 20,
                __DIR__"obj/fruitbread" : 20,
                __DIR__"obj/turkey" : 30,
                __DIR__"obj/vege" : 40,
                __DIR__"obj/midvege" : 10,
                __DIR__"obj/leg" : 10,
	]) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
	setup();
	carry_object("d/obj/cloth/linen")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("get_card", "newcard");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
message_vision("$N��$n˵�����ֵܣ�Ҫʲô���ˣ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$nһ�ۣ���һɨ����Ĳˣ�ί���ص�������������е㷢���ˡ�����\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����Ķ�$n˵�������ֵܣ�Ҫ��Ҫ�췹�������롰newcard��ָ��Ϳ����ˣ���\n",this_object(),ob);
			break;
		case 3:
message_vision("$N����Ķ�$n˵�������ֵܣ�Ҫ��Ҫ����ķ�����ֵ��ȥ���������Ϳ����ˣ���\n",this_object(),ob);
			break;

	}
}
int get_card()
{
	object me=this_player();
	object card;
	if (me->query("get_time")) return notify_fail("��ʦ��üͷһ�壬˵�������㲻���Ѿ���һ�ŷ������𣿣���ô��Ҫ�������˷�Ǯ����\n");
	if (me->query("deposit")<100) return notify_fail("��ʦ��üͷһ�壬˵��������Ĵ��̫���ˣ�Ҫ����100��Ǯ���У���\n");
	card=new("/d/liwu/obj/goldcard");
	card->move(me);
	me->set("deposit",me->query("deposit")*90/100);
	me->set("get_time",time());
	message_vision(CYN"��ʦ����ȡ��$N10%�������ѣ���һ����"+chinese_number(me->query("deposit")/100)+"\nԪǮ�ķ�������$N���С�\n"NOR,me);
	return 1;
}