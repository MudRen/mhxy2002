// npc: /d/city/npc/wei.c
// Dec.12.1997 by Venus
#include <ansi.h>;
inherit NPC;
void create()
{
        set_name(MAG"Τ����"NOR, ({ HIR"wei chunfang"NOR,  "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Ů��" );
        set("title", HIG"����Ժ"HIW"�ϰ���"NOR);
//      set("nickname", "¹����");
        set("age", 42);
        set("long",
            "Τ�����ǵ���¹������컨���ܶ���ΤС�����������"
            "����ϣ��������̴档\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 125000);
        set("daoxing", 125000);

        set("max_kee", 300);
        set("max_sen", 100);
        set("force", 500);
        set("max_force", 500);
        set("mana", 500);
        set("max_mana", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name"   : "�����Ҿ���Τ������",
            "ΤС��" : "�����ҵĹԶ��ӣ����þ����㡣",
            "����Ժ" : "��������Ժ���ǳ�������ͷһ�ݵ�������ȥ����",
            "here"   : "��������Ժ���ǳ�������ͷһ�ݵ�������ȥ����",
        ]) );

        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "Τ���������˵�������������ұ��µúܣ�ÿ���кü������ˡ�\n",
                "Τ����ŭ������������裬Ҫ����ɲ����ë���ӵ�����Ժ����������
��ɨ�����˳�ȥ��\n",
                "Τ��������˵������һ˫�۾���߯�����ģ������Ǹ����\n",
        }) );
//        carry_object("/d/city/obj/flower_shoe")->wear();

 //       carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell", "sell");
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="����" && file_name(environment(this_object()))=="/d/changan/lichunyuan") {
       command("say �㵱��������������������裬���������ɲػض��ӣ�
���ǲ���̫�࣡\n");
       command("kick " + me->query("id"));
       message("vision", me->name() +"��Τ����һ���߳����⡣\n",
                environment(me), ({me}));
       me->move("/d/changan/wside5");
       message("vision", me->name() +
"���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������\n",environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say �ϣ�" + RANK_D->query_respect(me)
                +"Ҳ�������������Ժ����");
       command("say �뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ���һ�����
�����Ӿ͹�����������ҡ�");
    }
    if (me->query("gender")=="Ů��") {
       command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͬ��");
       command("sigh");
       command("say ��ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź��㡣");
    }
    command("say ¥��¥�µĹ����ǣ��������ˣ�");
    }
    return ;
}


int do_sell(string arg)
{
	object ob, myenv;
	int balance;
	object *inv;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!userp(ob))
		return notify_fail("����ֻ���ˡ���������Ҫ����ʲô������\n");
	// if( query_ip_name(this_player()) == query_ip_name(ob))
//		return notify_fail("�Լ����Լ���ʵ���Ƿ����е��ˡ�\n");
	if (ob->query_condition("prostitute") > 1)
		return notify_fail("�����Ѿ�����������ˡ��㻹����ƭǮ��\n");

	ob->set("balance", ob->query("per") * 80000);
	command("rumor "HIY+ob->query("name")+HIM"������������Ժ�ˣ����಻�٣�����"HIW +
		CHINESE_D->chinese_number(ob->query("balance")) + NOR+YEL"��ͭ���ġ�\n"NOR);

	message_vision("$N��" + ob->query("name") + "����Τ������\n", this_player());
	MONEY_D->pay_player(this_player(), balance * 70 / 10000);
	myenv = environment (this_player());
	tell_room(myenv,"Τ�������Ĵ�Ц������Ҫ�����ˡ�\n");
	ob->move("/d/changan/lichunyuan2");
       ob->set("startroom","/d/changan/lichunyuan2");
	ob->apply_condition("prostitute", 50);
	ob->set_temp("selled");
	ob->set("class", "prostitute");
	ob->set("title",HIY"����Ժ�������"NOR);
       ob->save();
	this_player()->add("balance",1800000);//���Ĺ̶���Ǯ
	this_player()->set("title",HIR"������Ů���˷���"NOR);
       this_player()->save();
return 1;
}
