inherit F_VENDOR_SALE;

string heal_me(object me);

void create()
{
	reload("yangzhongshun");
        set_name("���ϰ�", ({"yinlao ban", "yin", "boss"}));
        set("title", "[37mҩ���ϰ�[2;37;0m");
        set("gender", "����");
        set("age", 18);
        set("long",
"����һ�������۾��������ϰ�,���Ĳ�����Ŀ,�����Ǽ�Ʒ�еļ�Ʒ��\n");
        set("kee", 300); 
        set("max_kee", 300);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("inquiry", ([
                "����": (: heal_me :),
                "����": (: heal_me :),
                "��ҩ": (: heal_me :),
        ]) );

        set("vendor_goods", ([
		"taogan": "/d/obj/drug/fake-tao",
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
        ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 5);
}


string heal_me(object ob)
{
        int ratio;
        object me;
        me = this_player();
        ratio = (int)me->query("eff_kee") * 100 /
(int)me->query("max_kee");
        if( ratio >= 100 )
                return "��λ" + RANK_D->query_respect(me) +
"������������ɫ�ܺð������������˵����ӡ�";
        if( ratio >= 95 )
                return
"Ŷ....�ҿ���....ֻ��ЩƤ��С�ˣ��������ҩ��ȥ����û���ˡ�";

}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


}


