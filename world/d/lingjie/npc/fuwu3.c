//fwzong.c����Ա�ܹ�
//by jjgod
#include <ansi.h>

inherit NPC;
int do_gongzuo() ;
int accept_object(object me, object ob) ;
void create()
{
	set_name("����Ա�ܹ�", ({"zong guan", "zongguan","guan"}));
	set("gender", "����");
	set("age", 45);
	set("str", 27);
	set("long", "������ò�Ͱ���Ц�Ǻǵġ����������Ҫ��������job����\n");
	set("combat_exp", 700000);
	set("attitude", "friendly");
	set_skill("unarmed", 120);
	set_skill("force", 130);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	set("kee", 2000);
	set("max_kee", 2000);
	set("force", 2500); 
	set("max_force", 2500);
	 set("inquiry", 
                ([
                  "����" : (: do_gongzuo :),
	"job" : (: do_gongzuo :),
                ]));
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
void greeting(object ob) 
{ 
           string respect=RANK_D->query_respect(ob); 
     
              if( !ob || environment(ob) != environment() ) return; 
              switch(random(1)) {
                      case 0:
                              message_vision(CYN"$NЦ�Ŷ�$n˵��������λ" + respect 
                      + "�����ǲ�����ϴ���ӣ���\n"NOR, this_object(),ob);  
                              break; 
                      case 1:
                              message_vision(CYN"$N�ܹ�����$n˵��������λ" + respect 
                      + "��ϴ���Ӿ�����Ҫ��"WHT"��ask guan about job��"CYN"����\n"NOR, this_object(),ob);  
                              break; 
                     default : 
			     break;
             }  

} 
int do_gongzuo() 
{ 
object me= this_player();
if( me->query_temp("����/ϴ����")>0) 
{ 
tell_object(me,"����Ա�ܹ��������ͷ��˵��������ȥϴ���Ӱɡ���\n"); 
return 1; 
} 
message_vision(CYN"�ܹܶ�$N˵�����⼸����˶࣡����ϴ���������ţ�\n���ȥ���̨�ҷ���ԱҪ��������ϴ�ɡ�\n"NOR,me); 
me->set_temp("����/ϴ����",1); 
return 1; 
} 
int accept_object(object me, object ob) 
{ 
object ob2,ob3;
int i=ob->query_amount();
me=this_player();
if (me->query_temp("����/ϴ����")<1) 
{
command("say ��û������Ҫ�������ɡ�\n"); 
return 1;
}
if( (string) ob->query("name") != "ϴ�õ�����"){
command("say ����ϴ�õ����ӣ��㲻�ǿ���Ц�ɣ�\n"); 
return 1;
}
else
message_vision(CYN"�ܹܶ�$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me); 
ob2 = new("/obj/money/silver");
ob2->set_amount(i);
ob2->move(me);
message_vision(CYN"�ܹܸ���$N"+chinese_number(i)+"ԪǮ��\n"NOR,me); 
me->add("combat_exp",50); 
me->delete_temp("����/ϴ����"); 
me->delete_temp("����/������"); 
call_out("destroying", 1, this_object(), ob); 
return 1;
}