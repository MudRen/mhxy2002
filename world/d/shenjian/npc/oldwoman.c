// LLY@FYSY
inherit NPC;
int impart();
void create()
{
        set_name("�ϸ���", ({ "oldwoman" }) );
        set("gender", "Ů��" );
        set("age", 49);
	set("str",40);
        set("long",
                "һ��˥�϶��㲵ĸ��ˣ�ĬĬ�����ڹµ���,�ݷ��ڵȴ�,�·���������������һ�б����Ϳ��ѡ�\n");
	set("combat_exp", 5000000);
        set("chat_chance", 15);
        set("chat_msg", ({
                "�ϸ��˺�Ȼ�ʣ���������û�л�������\n",
                "�ϸ���˵������֪��������һ��������ģ���˵�ǲ���?\n",
	        }) );
        set("inquiry", ([
                "����" : (: impart :),
                "aji" : (: impart :)

        ]));


        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/ncloth")->wear();

}

int impart()
{
	object me;
	me = this_player();
	message_vision("$N��$n˵���������С���ͽа�����\n",this_object(),me);
	        if(!me->query("m_success/����"))
        {
                me->set("m_success/����",1);
                me->add("score",50);

        }

	return 1;
}

int accept_object(object me, object obj, string arg)
{   string name;
	if(obj->query("for_sjwoman"))
	{
	me->set_temp("for_shenjian",1);
        message_vision("$N˥��ƣ����۾������������.\n",this_object(),me);
        command("say ���Ȼ���������ˣ��ӽ��쿪ʼ�����л����������ɽׯ�����ˣ�\n");
        name = (string) this_player()->query("name");
	name = "л"+name[2..];
	this_player()->set("name",name);
	this_player()->save();
        return 1;
	}
	return 0;
}