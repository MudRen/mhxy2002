// by happ@YSZZ 

inherit NPC;

void create()
{
       set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("gender", "����");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set_skill("unarmed", 10);

       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);

}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy","buy");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        say( name()+"Ц�����˵������λ" +RANK_D->query_respect(ob)
                                + "���ǿ�ս��������Ȥ�ˣ���һֻ�ɣ�\n");
}

int do_list()
{
        write("����Թ���������Щ������\n");
        write("�ǿ�ս����(zhandou ji)        ��ʮ���ƽ�\n");
        return 1;
}

int do_buy(string arg)
{
        object ob = this_player();
        object gold;

        object hen = new(__DIR__"hen");

        gold = present("gold_money",ob);

        if( present("zhandou ji",ob) )
                return notify_fail("�㲻�����ǿ�ս������\n");

                
        if( !gold)
                return notify_fail("������û�н��ӡ�\n");

        if( gold->query_amount() < 10 )
                return notify_fail("���Ǯ������\n");
        if( !arg || arg !="zhandou ji")
                return notify_fail("��Ҫ��ʲô?\n");
        hen->set("owner",ob->query("id") );
        hen->init_data(ob);
        hen->move(ob);
        write("����С������һ���ǿ�ս������\n");
        gold->add_amount(-10);
        return 1;
}
        
        
