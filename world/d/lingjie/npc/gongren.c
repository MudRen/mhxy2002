
inherit NPC;

void create()
{
        set_name("԰�ֹ���", ({ "gongren", "ren"}) );
        set("gender", "����" );
        set("age", 35);
        set("long", "����һλ����ͨͨ��԰�ֹ��ˡ�\n");
        set("combat_exp", 5000+random(5000));
	set("class","lingjie");
        set_skill("unarmed", 50+random(30));
        set_skill("dodge", 50+random(30));
        set("chat_chance", 20);
        set("chat_msg", ({
                "԰�ֹ���ҡͷ���Ե�˵����������ɽҲ����������壮����\n",
                (: random_move :),

        }) );
	
	setup();
	add_money("silver", 50+random(20));
        carry_object("/d/obj/cloth/linen")->wear();
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
	if (ob){
        CHANNEL_D->do_channel(this_object(),"chat",sprintf("�ұ�%sɱ�ˣ����ĵ���Ϊ�ұ��𰡣�",ob->name(1)));
        ::die();}
}