// Super Warp of Sun Yang 
// all code design 3/18/1997 bye phoebus
#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_CLEAN_UP;
inherit F_COMMAND;
string inputstr,verb;

void create()
{
       seteuid(getuid());

       set("long",@LONG
   ����������ϲ�������ñ���װ.
LONG
       );
       set("unit","��");
       set("no_get",1);
       set("no_drop",0);
       set("no_steal",1);
       set("no_give",1);
       set("material", "cloth");
       set("armor_prop/armor", 1500);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
      set_name(HIC"���Ű���" NOR, ({"loveme","love"}));
       add_action("full","fill"); 
       add_action("hun","nofill");
       add_action("wave","yao");  
       add_action ("whereis", "whereis"); 
       add_action ("pk_mob", "pk");       
      add_action ("do_give", "gei");     
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_die","chuqiao");
        add_action ("do_reincarnate","qshs");
       add_action ("do_disable_player","feng");
        add_action ("do_enable_player","jiefeng");
        add_action ("super_die","superdie");
          add_action ("do_gan","gan");
       add_action ("do_halt","qj");
       add_action ("do_killer","jizhu");
       add_action ("do_ban","ban");
       add_action ("do_rm","del");
       add_action ("do_move","move");
       add_action ("do_snoops","snoops");
       add_action ("do_command","command");
       add_action ("do_closecommand","closecmd");
       add_action ("do_opencommand","opencmd");
       this_player()->set_temp("heat",1);
}

int whereis(string arg)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("ĳ�˶�����£��������Ϻ���û�����ѽ����\n");
    }
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("��������Ʈ��䡣\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str)
{
  int max;
  object me;

       if (!geteuid()) seteuid (getuid());
       if(!str)
       me=this_player();
       else   {
       me = LOGIN_D->find_body(str);
       if (!me) return notify_fail ("ĳ��˵�����������: �Ҳ���"+str+"\n");
       }
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
// yxjh cmds
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_shen");
  me->set("eff_shen",max);
  me->set("shen",max);

  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
//  message_vision( sprintf("$N������մ󺰣���Զ������\n"),
//                  this_player());

  return 1;
}
int hun(string str)
{
  int min;
  object me;

  if (!geteuid()) seteuid (getuid()); 
  me = LOGIN_D->find_body(str);
  if(!str)
    return notify_fail ("ĳ��˵���������Լ���Ѫ�����ðɣ�");
  else
    if (!me) return notify_fail ("ĳ��˵: 
��Ѫ�������: �Ҳ���"+str+"\n");
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_sen");
  me->set("eff_sen",min);
  me->set("sen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);
 // yxjh
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_shen");
  me->set("eff_shen",min);
  me->set("shen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);  
  me->clear_condition();
//  message_vision( sprintf("$N��������һ�������˹�ȥ����ʱ������ȫ��û����...\n"),
//                  this_player());

  return 1;

}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <����Ǯ> <Ǯ������>\nע�������ȱ���������Ǯ��");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("ĳ��˵�������û�У�ҡ��ƨѽ��\n");
        if( amount < 1 )
                return notify_fail("�Ǻǣ�����û�С�\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf(HIY "$Nʹ�����ͱ��˵Ŀڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n" NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                       this_player());
               return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("ĳ��˵��������˭ PK ˭��\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�Ҳ��� "+st1+" �������.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�Ҳ��� "+st2+" �������.\n");

       message_vision(HIR ""+ob1->name()+"����"+ob2->name()+"���һ����������������\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  if (str!=NULL_VALUE) return notify_fail("usage:gei <id>\n");
  me = this_player();
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
     return 0;
  wiz = wizhood (me);
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 1)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("ĳ��˵�����ҿ����Ǳ�����ɣ���\n");
    return 1;
  }

  ob = present ("wiz cloak", me);
  if (!ob) write ("��û������������\n");
  who = find_player(whos);
  if (!who) write ("û������ˡ�\n");
  if (ob && who) {
    ob->move (who);
    message_vision (HIY "$N��$nһ�����������������ŷɼס���\n" NOR, me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("ĳ��˵������ û��"+str+"��\n");
  }
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
//  write("Ok.\n");
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("ĳ��˵���㲻�ܰ����Լ�Ū�Σ�\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("ĳ��˵������ û��"+str+"��\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
//  write("Ok.\n");
  return 1;
}

int do_die (string str)
{
  object ob;
  if (!str) return notify_fail("usage: chuqiao <oneself id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("û�����ʣ�û����ˡ�\n");
  message_vision( sprintf(HIY "" NOR),
         this_player());
  tell_room(environment(ob),""+                    
       (string)ob->query("")+"" , ob);
  tell_object(ob,"");  
  ob->die();
//  message_vision( sprintf( HIY "ֻ��$N���ֶ������һָ����У����������ʡ�, һ�Ѿ޽�������лص���$N���Ľ����\n" NOR),
//         this_player());
//  write("Ok.\n");
  return 1;
}

int do_reincarnate (string str)
{
  object ob;
  if (!str) return notify_fail("usage: qshs <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  if (ob->is_ghost()) 
           tell_object(ob,"�������ȫ������...\n");
       else 
           return notify_fail("��...����˺����ǻ�ģ�\n");
  tell_object(ob,"�����ϣ����ǹ�!��Ҫ���㸴��ұ����ϴε�һ�С�\n");
  tell_room(environment(ob),"һ�����ͻȻ��������£�������"+
       (string)ob->query("name")+"����Χ��\n", ob);
  tell_object(ob,"ͻȻһ����������������𣬡������....��������\n��ʼ���ٲ��ǻ���ˡ�����ͻȻ�е�һ�����...\n");
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,"�ܺã����ָ����ˣ�\n");
  write("Ok.\n");
  return 1;    
}

int do_disable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  tell_object(ob,"");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "" NOR);      
//  write("Ok.\n");
  return 1;    
}

int do_enable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
//  tell_object(ob,"�����������˵��������ټ��ټ�ܡ������ָֻ���...\n");
//  write("Ok.\n");
  return 1;
}

  int do_gan (string str)
{
  object ob;
  seteuid(ROOT_UID);
  if (!str) return notify_fail("usage: gan <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("û�ҵ�����ˡ�\n");     
  if (ob->query("name")=="ĳ��") {
       tell_object(ob,this_player()->query("id") + "����մ�Ҫ������ߣ�\n");
       return notify_fail(HIY "����ĳ�˶�����ߣ�\n" NOR);   
       }  
  tell_object(ob,"���ñ����������㣺ʵ�ڲ�����˼����������ȥ��...\n");
  destruct(ob);
  if(ob) write("���޷�������˸��ߡ�\n");
        else write("Ok.\n");
  return 1;    
}

void super_die ()
{
//       if ( this_player()->query("name")!="ĳ��" );
//       CHANNEL_D->do_channel( this_object(),"rumor",
//       sprintf(HIY "�������ۿ���" + this_player()->query("name") + "��ĳ�˵ı���ɱ�����е��ˡ�" + NOR));
//  return notify_fail("Σ�չ��ܣ���ʱ�����ţ�\n");
       users()->die();
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail("usage: quanjia <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("�����޴��ˣ�\n");       
  if( !ob->is_fighting() )
       return notify_fail("�������ڲ�û�д��С�\n");        
  tell_room(environment(ob),HIY "����к�Ȼ��������������Ӱ��\n������Ķ�"+                    
       (string)ob->query("name")+"˵�����������˴������ˣ��ҿ���λ"+RANK_D->query_respect(ob)+"�������˰ɣ���\n" NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),HIC "�ţ�"+                    
       (string)ob->query("name")+"˵��������˵�Ķԣ��Ҳ����ٴ��ˡ���\n" NOR, ob);
  tell_room(environment(ob), "..."+                    
       (string)ob->query("name")+"�����ܵ����٣����������ˣ�\n", ob);
  return 1;    
}

int do_killer(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("ĳ��˵��������˭��˭���?\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("jizhu <ob1> with <ob2>\n");
       if (!ob1 = LOGIN_D->find_body(st1))
          return notify_fail("�Ҳ��� "+st1+" �������.\n");

        if (!ob2 = LOGIN_D->find_body(st2))
          return notify_fail("�Ҳ��� "+st2+" �������.\n");
       ob1->set_temp("looking_for_trouble", 0);
       ob2->set_temp("looking_for_trouble", 0);
       ob1->kill_ob(ob2);
       write(HIC "ĳ��˵��������������\n" NOR);
       return 1;
}

int do_ban(string str)
{
        object ob1;
        string st1,st2;

        if (!str || str=="") return notify_fail ("��Ҫװ��˭��˵����\n");
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail ("ban <id> say <message>\n");
       if (!ob1=present(st1,environment(this_player())))
               return notify_fail("�������û��"+st1+"�ɡ�\n");
       message("sound", HIG + ob1->name() + "˵����" + HIG +  st2 + "\n" NOR,
       environment(ob1), ob1);
       return 1;
}
int do_rm(string file)
{
        object me=this_player();
//        seteuid(ROOT_UID);
//	seteuid(geteuid(me));
    if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	if( rm(file) )
		write("Ok.\n");
	else
		write("��û��ɾ�����������Ȩ����\n");
	return 1;

}
int do_move(string arg)
{
        object me=this_player();
	int goto_inventory = 0;
	object obj;
	string msg;

	if( !arg ) return notify_fail(HIC "��Ҫȥ���\n" NOR);

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail(HIC "��Ҫȥ���\n" NOR);

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("������û�л������� goto��\n");

	me->move(obj);

	return 1;
}

int do_snoops(string arg)
{
        object me=this_player();
	object ob;
	object obj;
	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write(HIR "��Ƶ����ʾ�������������ڼ���" + ob->query("name") + "���յ���ѶϢ����\n" NOR);
		return 1;

	} else if( arg=="none" ) {
//		if( objectp(ob = query_snooping(me))
//		&&	wiz_level(ob) >= wiz_level(me) )
		snoop(me);
		write(HIG "������ֹͣ�������˵�ѶϢ��\n" NOR);
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
        if( wiz_level(me) < wiz_level(ob) )
//	if( wizhood(me) != "(admin)"
//	&&	wiz_level(me) < wiz_level(ob) )
		return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");

	if( me==ob ) return notify_fail("���� snoop none ���������\n");
		
	snoop(me, ob);
	write(HIM "������Ƶ�����������ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n" NOR);
	if (me->query("id")!="phoebus") {
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) ���� %s �� %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );

	}
	if( find_player("phoebus")) {
		obj = find_player("phoebus");
		tell_object(obj, HIY + "��Ƶ������" + HIW + me->query("name") + "��ʼ����"+ ob->query("name") + "���յ���ѶϢ��\n" + NOR);
	}
	return 1;
}

int do_command(string arg)
{
	int res;
	object ob;
	string who, cmd, verb, path;
        object me=this_player();
	// No indirect mode for this command.
	if( me != this_player(1) ) return 0;

	if( !wizardp(me) ) return 0;

	if( !arg || arg=="" || sscanf(arg, "%s do %s", who, cmd)!=2 )
		return notify_fail("What do you want what is who to do?\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
	if( !ob || !ob->is_character())
		return notify_fail("Here no this person�C\n");

	if( sscanf(cmd, "%s %*s", verb) != 2 ) verb = cmd;

	stringp(path = ob->find_command(verb));

	if( wizardp(ob) && wiz_level(me) <= wiz_level(ob) )
		return notify_fail("You can not command him�C\n");
	write("You command " + ob->name() + "to do: " + cmd + "\n");
//        seteuid(export_uid(ob));
//	seteuid(getuid());
	res = ob->force_me(cmd);
        if (!res) return notify_fail("No! Cannot found this command!\n");
	return 1;
}

int do_closecommand(string arg)
{
	string who, cmd, verb;
        object me=this_player(),ob;
	if( me != this_player(1) ) return 0;

	if( !wizardp(me) ) return 0;

	if( !arg || arg=="" || sscanf(arg, "%s %s", who, cmd)!=2 )
		return notify_fail("Close who command and which command?\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
	if( !ob || !ob->is_character())
		return notify_fail("Here no this person�C\n");
        ob->set_alias(cmd, "�");
        ob->set_alias("alias","set");
	return 1;
}
int do_opencommand(string arg)
{
	string who, cmd, verb;
        object me=this_player(),ob;
	if( me != this_player(1) ) return 0;

	if( !wizardp(me) ) return 0;

	if( !arg || arg=="" || sscanf(arg, "%s %s", who, cmd)!=2 )
		return notify_fail("Open who command and which command?\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
	if( !ob || !ob->is_character())
		return notify_fail("Here no this person�C\n");
        ob->set_alias(cmd,0);
//        ob->set_alias("alias",0);
	return 1;
}

/*int query_autoload()

{
  if (wizardp(this_player()))
    return 1;
  else return 0;
*/
