//By tianlin@mhxy for 2001.10.8
//���±�д
#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "�����","�����","ɵB","�Ҳ�","����","������˯","�л��û��","û���᣿","��",
                      "�٣�","��!","fuck","FUCK","Fuck","���","��û�л��","����?","shit","SHIT","Shit",
                      "�����̵�","����������","�����","��үү��","��û�д�����","cao","CAO","Cao",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������","û���أ�",
                      "�����","��ƨwiz","��wiz","��wiz","��wiz","������","Nnd","ȥ����",
                      "������","�����","������","�ƣգã�","F u c k","f u c k","nnd","NND","SB",
                      "Sb","shabi","SHABI","MCB","danzi","����","����","���",
                      "ţ��","��ƨ","��ʺ","���ү","������","����","6mang","���","С��","caobi",
                      "����","������","����ʦ","ʲô��վ","�������衡�ɡ�ѩ",});

void punish(object);

int give_quest();

void create()
{
        set_name("��ظ", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"�����"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 112);//no rongmao description.

        set("long", "���˲�֪��ץ����ɣ���������׼�������ʲô���¡�\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        set("inquiry", ([
		"ץ��"	:	(: give_quest :),
	]));        
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( clonep() ) CHANNEL_D->register_relay_channel("sldh");
        if( clonep() ) CHANNEL_D->register_relay_channel("party");
        if( clonep() ) CHANNEL_D->register_relay_channel("bill");
        carry_object("/d/lingtai/obj/xiangpao")->wear();

}

void relay_channel(object ob, string channel, string msg)
{

        int i;
        if( !userp(ob) || (channel == "sys") ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
        	msg=replace_string(msg, " ", "");
        	msg=replace_string(msg, "��", "");
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    call_out("punish",1,ob);
                    return;
                    }
        }
}

void punish(object ob)
{
        int i;
        string criname,result;
        int howlong;
      if(ob->is_fighting()||ob->is_busy())
    {
    call_out("punish", 1, ob); return; }
        command_function("chat ������ظһ��ŭ�ȣ�"+ob->query("name")+" ���������ܲ����ˡ�");
        message_vision(HIC"���з���һ�����ӣ�һ�¾���ס$N�Ĳ��ӡ�\n"NOR+CYN"$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, ob);
        criname = ob->query("name") + "("+ob->query("id")+")";
        howlong=20;//��������Զ�����ʱ��,60=60����
                    
                    
        ob->set("qiushi/howlong",howlong);
        ob->set("qiushi/temp",result);
        ob->move("/d/wiz/qiushi");
        message_vision(CYN"��ظ��$N���������ҿڳ����Ի���ڴ˵�����ʵʵ���Ҷ��š�\n", ob);
        message_vision(CYN"˵�ţ�����һ�ɣ�$N�����ڵ��ϡ�\n"NOR, ob);
        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ���˵ "HIR+criname+HIM" �ڹ���Ƶ��ʹ�ô����������ظ����"NOR+BLINK+HIW"20"NOR+HIM"���ӡ�\n"NOR, users());
}
int give_quest()
{
	object who, seal;
	mapping room;
	
	who=this_player();
            if((time()-who->query("catch_ghost/last_time"))<0)
	{
		command("say ���ڻ���Ƚ�̫ƽ������ȥЪ�˰ɡ�");
		return 1;
	}
	seal=new("/d/newjob/zhuagui/seal");
	seal->set("master", who);
      do{ room=LOCATION_D->random_location(); } while(!strlen(room["long"]));
	seal->set("file_name", room["file"]);
	seal->set("desc", room["long"]);
	seal->move(who);
	who->set("catch_ghost/last_time", time());
	command("nod");
	message_vision("$N��$n˵�������ŷ����㣬�㿴������д�ķ���ȥץ��ɡ�\n", 
	this_object(), who);
	return 1;
}

int accept_object(object who, object ob)
{
	int reward, times;
	string msg;

	if(!ob->query("finished")||
		this_player()!=ob->query("master"))
		return 0;
	command("nod");
	message_vision("$N��$n˵�����ܺã�\n", this_object(), who);
	times=who->query_temp("catch_ghost");
	reward=800+random(200)*times+200*times;
	msg=HIG"��������"NOR;
	switch(random(3))
	{
		case 0:
			this_player()->add("combat_exp", reward/7);
			this_player()->add("catch_ghost/cache/wuxue", reward/7);
			msg+=HIY+chinese_number(reward/7)+HIG"����ѧ"HIG"��\n"NOR;
			break;
		case 1:
			this_player()->add("daoxing", reward/7);
			this_player()->add("catch_ghost/cache/dx", reward/7);
			msg+=HIY+COMBAT_D->chinese_daoxing(reward/7)+HIG"����"HIG"��\n"NOR;
			break;
		default:
			this_player()->add("office_number", reward/500);
			this_player()->add("catch_ghost/cache/off", reward/500);
			msg+=HIY+chinese_number(reward/500)+HIG"���ְ"HIG"��\n"NOR;
	}
	this_player()->add_temp("catch_ghost", 1);
	if(who->query_temp("catch_ghost")>9)
		who->set_temp("catch_ghost", 0);
                message("channel:chat",    HIG"��"HIY"��ظץ��"HIG"������˵ "HIW+this_player()->query("name")+HIG" ["HIR"ץ��"HIG"]"HIG+msg+HIG""NOR,users());
       tell_object(this_player(), HIG"��"NOR+msg);
        return 1;
}

