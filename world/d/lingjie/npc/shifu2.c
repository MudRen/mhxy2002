
inherit NPC;
#include <ansi.h>
#define FOOD_D(x)       ("/obj/food/" + x)
int give_food();
int give_water();
string* foods = ({
       FOOD_D("rice"),
       FOOD_D("mantou"),
       FOOD_D("doufu"),
       FOOD_D("baozi"),
       FOOD_D("yuebing"),
       FOOD_D("zongzi"),
       FOOD_D("shanguo"),
       FOOD_D("fan"),
       });
void create()
{
       set_name("����ʦ��", ({ "shifu"}) );
       set("gender", "����" );
       set("age", 50);
       set("long","������緹�õĳ��ӣ����ֵģ��غ���ʵ\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");
       set("inquiry", ([
	"����" : "�����������տ������һ�����������˭�����ң��ٺ٣�",
	"ʳ��" : (: give_food :),
	"food" : (: give_food :),
	"ˮ" : (: give_water :),
	"water" : (: give_water :),
       ]) );
       setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int give_food()
{
       object food, me, ob, *obj;
       int i;
	me = this_object();
	ob = this_player();
	obj = all_inventory(ob);
	for(i=0; i<sizeof(obj); i++)
	if (obj[i]->query("food_remaining")){
	command("say ˭֪���вͣ����������࣡���Ȱ����ϵ�ʳ��Ե���˵�ɡ�");
	return 1;} 
	if ((time()- ob->query_temp("food_give"))<100){command("say �����ող�����Ҫ��ʳ������Ȱ������ϵ�ʳ��Ե���˵�ɡ�");
	return 1;}
	obj = all_inventory(environment(me));
	for(i=0; i<sizeof(obj); i++)
	if (obj[i]->query("food_remaining"))
	{
	   command("say ˭֪���вͣ����������࣡���Ȱѵ��ϵ�ʳ��������Ե��ɡ�");
	   return 1;
	} 

	if (ob->query("age")>30)
	{  
	   command("say ��������ô���ˣ���Ҫ�����ԣ�����Ҳ���ߣ�");
	   return 1;
	}
	else
	{
          command("say ˭֪���вͣ����������࣡���˷��ˡ��� i ���������ϵ�ʳ��� eat ��ʳ�");
          food = new( foods[random(sizeof(foods))] );
          food->move(ob);
          ob->set_temp("food_give",time());
          message_vision("$N����$nһ��Եġ�\n", me, ob);
          return 1;
        }
}
 
int give_water()
{
       object water, me, ob;
       me = this_object();
       ob = this_player();
	if (ob->query("age")>30){
	command("say ��������ô���ˣ���Ҫˮ�ȣ�����Ҳ���ߣ�");
	return 1;
             } 
       if ( objectp(present("cocacola", environment(me)))){ 
	     command("say ˭֪���вͣ����������࣡���Ȱѵ��ϵĿɿڿ��ֺȵ��ɡ�");
             return 1;
             } 
       if (present("cocacola", ob)) { 
	     command("say ���Ȱ����ϵĿɿڿ��ֺȵ��ɡ�");
             return 1;
	     } 
       water = new("/d/lingjie/npc/obj/kekou");
       water->move(ob);
       command("say �� i ���������ϵ�ʳ��� drink ����ˮ��");
       message_vision("$N����һ�пɿڿ��ֽ���$n��\n", me, ob);
       return 1;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || ob->query("age") > 15 ) return;
         
       command("pat "+ob->query("id"));
       command("say �����Ƿ�������������Ҫʳ��"RED"(ask shifu about ʳ��)"NOR"�ͺȵ�"RED"(ask shifu about ˮ)"NOR"��\n");
}
