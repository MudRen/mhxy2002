// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// waiter.c

inherit F_VENDOR_SALE;
void create()
{
        set_name("�̴�ɩ", ({ "cai dasao", "cai", "dasao", "da sao" }) );
        set("title", "�Ͱ���");
        set("gender", "Ů��" );
        set("age",32);
        set("long", "�̴�ɩ������Ц����,���ﻹ��ͣ�İ�Ū���߲ˡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("per",25);
        set("vendor_goods", ([
        "guaguoshucai" : "/d/obj/food/sucai",
         "guaguoshucai" : "/d/obj/food/sucai",
   ]));
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
   add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
   say("�̴�ɩ˵������λ" + RANK_D->query_respect(ob)
     +"������㿴����㿴,���ʵĹϹ��߲�.\n");
}
