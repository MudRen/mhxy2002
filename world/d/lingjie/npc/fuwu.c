// fuwu.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����Ա", ({ "waiter", "fuwuyuan", "fuwu", "yuan"}) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ����Ա����ǰ�ܺ��æ�š�\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "���Ҳ��ң�С�Ľ���ң�����ڱ����ϳ���ġ�",
		"here" : "�����ǹ���ѽ���͹�����Ȼ��֪����",
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int accept_object(object who, object ob)
{
	object fuwuyuan;

	if (ob->query("money_id")) {
		if (!objectp(fuwuyuan = present("waiter2", environment()))) {
			fuwuyuan = new(__DIR__"fuwu2");
			fuwuyuan->move(environment());
		}
		tell_object(who, "����Ա�������Ҵ���ȥ���ʡ���\n");
		tell_object(who, "����ŷ���Ա������̨ǰ����Ǯ��������Ա��\n");
		return fuwuyuan->accept_object(who, ob);
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("����Ա��$N��Ц��������װǻ���������������ְ��װͰ���ͼ�Է�����Ǯ�ļһ��Ҽ����ˣ�ʡʡ�ɡ���\n", ob);
	message_vision("$N�������ƣ������ⷬ������˼��ôȫ����˵���ˣ���\n", ob);
}

void greeting(object ob) 
{ 
           string time,respect;  
    
             time = NATURE_D->room_event(); // ����
             respect=RANK_D->query_respect(ob); 
     
              if( !ob || environment(ob) != environment() ) return; 
               
              switch(time) {  // ʹ��switch �жϵ�ǰʱ��                         
                      case "event_sunrise": // ����
                              message_vision(CYN"$NЦ�Ŷ�$n˵��������λ" + respect 
                      + "����������簡������ո�Ӫҵ����ӭ���١���\n"NOR, this_object(),ob);  
                              break; 
 
                      case "event_noon":   // ����
                              message_vision(CYN"$N�ܹ�����$n˵��������λ" + respect 
                      + "���ù��緹���𣿿���������\n"NOR, this_object(),ob);  
                              break; 

                     case "event_evening": // ����
                              message_vision(CYN"$NЦ�����ض�$n˵��������λ" + respect 
                      + "�������ˣ�����������ЪЪ�ɣ������ư������۵ġ���\n"NOR, this_object(),ob);  
                             break; 

                     case "event_midnight": // ��ҹ
                             message_vision(CYN"$N����˯���߳��������Ժ����ض�$n˵��������λ" + respect 
                     + "�����治�ɰ��������Ѿ������ˣ����������������ɡ���\n"NOR, this_object(),ob); 
                             ob->move("/d/huafu/xjjicun");        
                             break; 
                     default : 
			     break;
             }  

} 


void unconcious()
{
	say( "����Ա��һ�������Ҳ����ˣ������Ӱ࣡��\n");
	say( "����ӹ�̨���������һ������Ա����˵����û���⣬�����Ұɡ���\n");
	say( "ǰһ���Ʊ�������ֵ��뿪�ˡ�\n");
	reincarnate();
	set("eff_kee", query("max_kee"));
	set("kee", query("max_kee"));
	set("eff_gin", query("max_gin"));
	set("gin", query("max_gin"));
}

void die()
{
	unconcious();
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
