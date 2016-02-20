
#include <ansi.h>

inherit NPC;
int ask_gongzuo(); 
void create()
{
	set_name("����Ա", ({ "fw yuan","yuan" }));
	set("gender", "����");
	set("age", 45);
	set("str", 27);
	set("long", "������ò�Ͱ���Ц�Ǻǵġ����������Ҫ����ϴ��\n");
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
	 set("inquiry",  ([
	"����" : (: ask_gongzuo :), 
	"panzi" : (: ask_gongzuo :), 
	"plate" : (: ask_gongzuo :), 
                ]));
	setup();
}
void init()
{	
	object ob;
	if( interactive(ob = this_player())&&ob->query_temp("����/ϴ����")){
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
                      + "�����ǲ�����ϴ���ӣ�"WHT"��ask yuan about panzi��"CYN"��\n"NOR, this_object(),ob);  
                              break; 
                      case 1:
                              message_vision(CYN"$N�ܹ�����$n˵��������λ" + respect 
                      + "��ϴ���Ӿ�����Ҫ��"WHT"��ask yuan about panzi��"CYN"����\n"NOR, this_object(),ob);  
                              break; 
                     default : 
			     break;
             }  

} 

int ask_gongzuo() 
{ 
object me,ob; 
int i=random(10);
me = this_player(); 
if(!me->query_temp("����/ϴ����")) 
{
tell_object(me,"�㻹����ȥ������Ա�ܹܴ���к��ɡ�\n"); 
return 1;
}
if( me->query_temp("����/������")> 0) 
{
tell_object(me,"����Ա�ɻ󲻽�Ķ���˵�����Ҳ��Ǹ��������������ѵ��㶪��������\n "); 
return 1;
}
ob = new(__DIR__"obj/zangpanzi"); 
ob->set_amount(i);
ob->move(me); 
me->set_temp("����/������", 1); 
message_vision("����Ա����$Nһ�������ӡ�\n",me); 
tell_object(me,"����Ա�����㣺���ðɣ����ȥ����ϴ�ϸɾ���Щ���Ӱɡ���\n "); 
return 1;
} 