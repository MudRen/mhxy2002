// seller.c

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("С��", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/suburb/xkx/shaolin/obj/map",
		"/d/suburb/xkx/shaolin/obj/guide",
		"/d/suburb/xkx/village/npc/obj/stick",
		"/d/suburb/xkx/village/npc/obj/shoes",
                "/d/suburb/xkx/village/npc/obj/bottle",
	}) );
	setup();
        carry_object("/d/obj/clone/misc/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

