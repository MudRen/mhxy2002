// link

inherit NPC;
int give_soup();
void create()
{
        set_name("����", ({ "mengpo", "meng"}) );
        set("gender", "Ů��" );
        set("age", 220);
        set("long", 
"��˵����׷���ϰ鵽���֮�������������䣬�������ã�
���������׼���������������⣬��Ϊ�������������𣩺ã�����������Ϊ����
����������һ��������ʹ����ȴ�����Ŀ�ʹ���������ŵ������һ�պù�һ�ա�
Ͷ�����˶����ڴ���һ��������µ�����֮·��
\n");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        set_temp("apply/astral_vision",1);
        set("chat_chance", 8);
        set("chat_msg", ({
                "���Ŷ���˵�������������˲��ٿ�ɣ��������ɣ���\n",
                "����˵�������ӣ���ȥǰ��һ��ɣ���\n",
        }) );
        set("inquiry", ([
                "������" : (: give_soup:),
                "soup" : (: give_soup:)

        ]));
        setup();
        add_money("gold", 5);
        carry_object("d/obj/cloth/yuanxiang")->wear();
}

int give_soup()
{
        object obj;
if( !query("given"))
        {
message_vision("$N���������ַ�Ҩ��һ�����ݸ�$n��\n",this_object(),this_player());
command("say �������������ȣ����������ȥ��ȥ�ĵط���\n");
obj = new(__DIR__"obj/tang");
obj->move(this_player());
if(!random(10))set("given",1);
        }
else
command("say ���ϣ��ո����⣬����ţ��Ҿ�ȥ�ٰ�һ����\n");
        return 1;
}

void reset()
{
delete("given");
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
