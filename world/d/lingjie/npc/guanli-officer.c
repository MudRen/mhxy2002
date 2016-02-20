// link

#include <ansi.h>

inherit NPC;

void reset_balance(object me);


void create()
{
        set_name("������Ա", ({ "officer" }) );
        set("title", RED "һ������" NOR);
        set("gender", "����" );
        set("age", 22);
        set("richness",50000000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 30);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long","���Ǹ���������ѧϰ����ü���̬�ȶԴ��˿Ͷ������˿�Ͷ�ߵķ����Ĺ�����Ա��\n");
        set("combat_exp", 2000000);
        set("daoxing", 1000000);
        set("attitude", "friendly");
        set("max_atman", 1000);
        set("atman", 1000);
        set("atman_factor", 33);
        set("max_force", 1600);
        set("force", 1000);
        set("force_factor", 180);
        set("max_mana", 1800);
        set("mana", 1000);
        set("mana_factor", 200);
        set("chat_chance", 3 );
        set("chat_msg", ({
                (: exert_function, "heal" :),
        }) );
        set_skill("unarmed", 150);
        set_skill("dodge", 120);
        set_skill("force", 120);
        set_skill("guangming-force", 120);
        set_skill("guangming-shouyin", 120);
        set_skill("fengtian-steps", 120);
        map_skill("force", "guangming-force");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        set("inquiry", ([
                "����" : "������Ⱥ�����å������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥ�����å������������Ӱ��ȥ���٣�\n",
        ]) );
        setup();
        carry_object("d/obj/cloth/linen")->wear();
        add_money("gold", 15);
}

void reset_balance(object me)
{
    int myexp;
    int allowed, removed_gold;
    string myid;
    string NPCNAME=this_object()->name();

    if(!me) return;

    myexp=me->query("combat_exp")/1000;
    myid=me->query("id");

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
        me->set("balance_old", me->query("balance"));
        me->set("balance", allowed);
        removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
        log_file("MONEY_RESET", ctime( time() )+"�������ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
        tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
                "���⡢���治֪��ô˵�Ǻã�����\n"NOR);
        tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
                "���հ�����������ǰ���참���������ϵĻƽ���·������\n"NOR);
        tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
                "���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫����ң�ˣ�����\n"NOR);
    }
    return;
}

void init()
{
	::init();
        add_action("do_loan","loan");
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("fool");

        ob=present("hufa");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/lingjie/npc/hufa");
                ob->move(environment());
        }
        message_vision("\n��Ȼ��������������绤������$N��һ������ʲô������������å��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
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
