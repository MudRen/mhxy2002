#include <ansi.h>
inherit NPC;
int ask_ge();
int ask_la();
int ask_long();
int ask_sex();

void create()
{
	set_name("����ʦ",({"meirong shi","meirong","shi"}));
	set("title",HIR"���˿���"NOR);
	set("nickname",HIC"����ר��"NOR);
	set("long",
		"\n����һ��������Ӣ������,��ɷ��\n"
		"�������λ����ε�����ʦ,ר�Ÿ������ò���ѵ���ҽ������ݷ���\n"
		"���ݿ��Ǹ�����Ŷ,��˵��˫��ƤҪ100gold,��Ƥ300gold,¡��500gold,\n"
		"���ڱ�����,���ڳ�ǰ����,������1000gold��\n");
	set("gender","����");
	set("age",21);
	set("per",40);
	set("str",30);
	set("int",40);
	set("attitude", "friendly");
	
	set("max_kee",10000);
	set("kee",10000);
	set("max_sen",10000);
	set("sen",10000);
	set("max_force",50000);
	set("force",50000);
	set("max_mana",50000);
	set("mana",50000);
	set("combat_exp",100000000);
    set("daoxing",100000000);
  set("force_factor", 200);
  set("mana_factor", 200);

	set_skill("blade",500);
	set_skill("dodge",500);
	set_skill("parry",500);
	set_skill("unarmed",500);
	set_skill("dragonfight",500);
	set_skill("kugu-blade",500);

	map_skill("dodge","kugu-blade");
	map_skill("parry","kugu-blade");
	map_skill("blade","kugu-blade");
	map_skill("unarmed","dragonfight");

	set("inquiry", ([
		"��˫��Ƥ":(: ask_ge :),
		"¡��":(: ask_long :),
		"��Ƥ":(: ask_la :),
		"����":(: ask_sex :),
	]) );
set("chat_chance_combat", 80);

	set("chat_msg_combat", ({
		"\n����ʦҡͷ̾�����۵��������������������������Ǻο���?\n",
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat ��λ" + RANK_D->query_respect(this_player())+",������ԩ�޳𣬺α����?\n") :),		
(: perform_action, "blade.pozhan" :),
(: perform_action, "blade.kugu" :),
                (: exert_function, "recover" :),                          
	}) );
	setup();

 carry_object("/u/tianlin/obj/qiang")->wield();
  carry_object("/u/tianlin/obj/leaf")->wear();
}

void init()
{
  add_action("do_ok", "ok");
  add_action("do_sure", "sure");
  add_action("do_nod","nod");
  add_action("do_yes","yes");
}

int ask_ge()
{        
	object me=this_player();
        command("say ��ȷ��Ҫ���𣿣�ok��Ҫ��Ļ��ܷ�100gold���һ�����
Ǯׯ�ʺ���۳���\n");
        me->set("ge",time()+60);
        return 1;
        }
int ask_long()
{        
	object me=this_player();
        command("say ����¡�أ��ð�¡���ܷ�500gold���һ�����
Ǯׯ�ʺ���۳�����sure)\n");
        me->set("long",time()+60);
        return 1;
}
int ask_la()
{        
	object me=this_player();
        command("say ����Ƥ����Ƥ�ܷ�300gold�������
Ǯׯ�ʺ���۳���ȷ����(nod)\n");
        me->set("la",time()+60);
        return 1;
        }
int ask_sex()
{        
	object me=this_player();
        command("say ����Ǵ�����ѽ���ܷ�1000gold�����ɣ���������
�����Ļ�����yes)�һ�����Ǯׯ�ʺ���۳���\n");
        me->set("sex",time()+60);
        return 1;
        }

int do_ok()
{
	object me = this_player();
	if (me->query("ge")>(int)time())
{	 
	if (me->query("bmw_ge")=="done"){
//	command("hit"+ me->query("id"));
	tell_object(me,"����˫��Ƥ��,��Ҫ��,�ѵ�����������Ƥ? \n");
	return 1;
	}
	if (me->query("per")>=25){
	command("shake " + me->query("id"));
	tell_object(me,"�㱾������˫��Ƥ,����ʲô? \n");
	return 1;
	}
 if (me->query("balance")<1000000){
//         command("slap " + me->query("id"));
         tell_object(me,"��⵰,�����Բ���,��������! \n");
         return 1;
         }
	else {
		me->set("bmw_ge","done");
		me->add("per",1);
me->save();
                me->add("balance",-1000000);
                command("ok " + me->query("id"));
                message("channel:chat",HIY+"���������ġ�����˵ "+me->query("name")+" ���������ĸ���˫��Ƥ��\n"+NOR,users());
		        me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}else { message_vision("ʲô\n");return 1;}return 1;
}
int do_sure()
{
	object me = this_player();
		if (me->query("long")>(int)time())
{
	
	if (me->query("gender")!="Ů��"){
//	command("slap " + me->query("id"));
	tell_object(me,"���̬ѽ���еĻ���¡�أ�������\n");
	message("channel:chat",HIY+"���������ġ���"+me->query("name")+" �������Ÿ���̬����Ȼ�ܵ�������������¡�أ�\n"+NOR,users());
	return 1;
	}	 
	if (me->query("bmw_long")=="done"){
//	command("hammer " + me->query("id"));
	tell_object(me,"����ز���¡�ĺ�����һ�����ˣ���¡? \n");
	return 1;
	}
	if (me->query("per")>=25){
	command("heihei " );
	tell_object(me,"����ز��Ѿ���С��! \n");
	return 1;
	}
 if (me->query("balance")<5000000){
  //      command("slap " + me->query("id"));
         tell_object(me,"��⵰,�����Բ���,����¡��! \n");
         return 1;
         }
	else {
		me->set("bmw_long","done");
		me->add("per",2);
me->save();
                me->add("balance",-5000000);
                command("ok " + me->query("id"));
               message("channel:chat",HIY+"���������ġ�����˵ "+me->query("name")+" ��������������һ��¡����������Χ������XX�磡\n"+NOR,users()); 
	        	me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}
else { message_vision("ʲô\n");return 1;}return 1;
}
int do_nod()
{
	object me = this_player();
	 	if (me->query("la")>(int)time())
{
	if (me->query("bmw_la")=="done"){
//	command("sigh " + me->query("id"));
	tell_object(me,"������Ƥ�����岻�ã���ҪΪ�����ݶ��������壡 \n");
	return 1;
	}
	if (me->query("per")>=25){
//	command("pat " + me->query("id"));
	tell_object(me,"���Ƥ���ܺã��������ˣ����������ɹ����ˣ�\n");
	return 1;
	}
 if (me->query("balance")<3000000){
  //       command("kick " + me->query("id"));
         tell_object(me,"��⵰,�����Բ���,��������! \n");
         return 1;
         }
	else {
		me->set("bmw_la","done");
		me->add("per",1);
me->save();
                me->add("balance",-3000000);
                command("nod " + me->query("id"));
                message("channel:chat",HIY+"���������ġ�����˵ "+me->query("name")+" �������������˸�Ƥ�����������ˣ�\n"+NOR,users());
	        	me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}
else { message_vision("ʲô\n");return 1;}return 1;
}
int do_yes()
{
	object me = this_player();
       if (me->query("sex")>(int)time())
   {    
	if (me->query("bmw_sex")=="done"){
//	command("sigh " + me->query("id"));
	tell_object(me,"�������ǲ�����ë��ѽ�������������������ѽ������Ҹ㣡 \n");
	return 1;
	}

 if (me->query("balance")<10000000){
  //       command("kick " + me->query("id"));
         tell_object(me,"��⵰,�����Բ���,��������! \n");
         return 1;
         }
	else {
		me->set("bmw_sex","done");
		
    if(me->query("gender")=="Ů��") me->set( "gender", "����" );
    else me->set( "gender", "Ů��" );
                me->add("balance",-10000000);
				me->add("per",-3);
                command("nod " + me->query("id"));
                message("channel:chat",HIY+"���������ġ�����˵ "+me->query("name")+" �������������˸�����������\n"+NOR,users());
		        me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}    
else { message_vision("ʲô\n");return 1;}return 1;
}

   
