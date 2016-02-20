//modified by vikee 2000.7.29


#include <ansi.h>

inherit NPC;
inherit "/d/dntg/yunlou/npc/yaoguai_reward.c";

string _invocation(object who, int level);
int exp_reward, pot_reward;
int other_kee=0, other_sen=0;

string *death_msg= ({
"$N�ȵ����������һ���������ȥ�ɣ�\n$n�ۼ����Σ�ֻ�û��ɹ����̸�����$N�����С�\n",
"$nһ������$N�Ķ��֣�ֻ�þ͵�һ�������ԭ�Σ����˼���ת������ʵʵ���߿��ˡ�\n",
"$n���һ�����ҷ��ˣ��ҷ��ˣ���Ͷ���������ԹԵط���$N���²����ˡ�\n$N��һ�ӣ�$n���ɴ��⣬ѱ�����߿��ˡ�\n",
"$N�ȵ����������һ���������ȥ�ɣ�\n$n�޿��κΣ�����һ����⣬ֱ������ȥ�ˣ�����\n",
});
string *dirs1 = ({
"/d/city",
"/d/westway",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
"/d/sea", 
"/d/nanhai", 
"/d/eastway",
"/d/ourhome/honglou", 
});

string *dirs2 = ({
"/d/xueshan",
"/d/qujing/wuzhuang", 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
"/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/nuerguo",
"/d/qujing/pingding",
"/d/qujing/pansi",
"/d/qujing/tongtian",
"/d/qujing/qilin",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
"/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
"/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
"/d/penglai",
// "/d/pantao",
});

string *dirs3 = ({
"/d/death",  
"/d/meishan",
"/d/qujing/lingshan",
});

string *names1 = ({
  WHT"̡"NOR,"ta",
  WHT"¹"NOR,"lu",
  WHT"�"NOR,"huan",
  WHT"��"NOR,"gou",
  WHT"��"NOR,"zhu",
  WHT"��"NOR,"hou",
  WHT"��"NOR,"fei",
  WHT"��"NOR,"mang",
});

string *names2 = ({
  WHT"ͷ"NOR,"tou",
  WHT"β"NOR,"wei",
  WHT"��"NOR,"jiao",
  WHT"צ"NOR,"zhua",
  WHT"��"NOR,"zui",
  WHT"��"NOR,"ya",
});

string *names3 = ({
  YEL"��"NOR,"hu",
  YEL"ʨ"NOR,"shi",
  YEL"��"NOR,"bao",
  YEL"��"NOR,"xiong",
  YEL"�"NOR,"pi",
  YEL"��"NOR,"lang",
  YEL"��"NOR,"bei",
  YEL"��"NOR,"chai",
});

string *names4 = ({
	WHT"����"NOR,"huli",
	WHT"����"NOR,"heixiong",
	WHT"����"NOR,"gouxiong",
	WHT"����"NOR,"baixiong",
	WHT"Ы��"NOR,"xiezi",
	WHT"���"NOR,"chanchu",
	WHT"���"NOR,"wugong",
	WHT"����"NOR,"tubie",
	WHT"�ɻ�"NOR,"feihuang",
	WHT"�ȳ�"NOR,"huangchong",
	WHT"�����"NOR,"daqingchong",
	WHT"����"NOR,"chouchong",
	WHT"����"NOR,"tiaozao",
	WHT"ʭ��"NOR,"shizi",
	WHT"�ϻ�"NOR,"laohu",
	WHT"ʨ��"NOR,"shizi",
	WHT"��ʨ"NOR,"huangshi",
	WHT"��ʨ"NOR,"heishi",
	WHT"��ʨ"NOR,"baishi",
	WHT"Ұ��"NOR,"yetu",
	WHT"����"NOR,"huabao",
	WHT"ɽ��"NOR,"shanbao",
	WHT"�ݱ�"NOR,"caobao",
	WHT"ɽ��"NOR,"shanyang",
	WHT"���"NOR,"mahou",
	WHT"⨺�"NOR,"mihou",
	WHT"Գ��"NOR,"yuanhou",
	WHT"����"NOR,"huilang",
	WHT"Ұ��"NOR,"yezhu",
	WHT"֩��"NOR,"zhizhu",
	WHT"��¹"NOR,"malu",
	WHT"��¹"NOR,"bailu",
	WHT"��¹"NOR,"huilu",
	WHT"��¹"NOR,"heilu",
	WHT"ɽ��"NOR,"shanji",
	WHT"Ұ��"NOR,"yeji",
	WHT"����"NOR,"zhiji",
	WHT"���"NOR,"ciwei",
	WHT"������"NOR,"huahuli",
	WHT"�׺���"NOR,"baihuli",
	WHT"�Һ���"NOR,"huihuli",
	WHT"����"NOR,"xingxing",
	WHT"����"NOR,"feifei",
	WHT"����"NOR,"baima",
	WHT"����"NOR,"hongma",
	WHT"����"NOR,"heima",
	WHT"��è"NOR,"baimao",
	WHT"��è"NOR,"huamao",
	WHT"��è"NOR,"heimao",
	WHT"Ұè"NOR,"yemao",
	WHT"Ұ��"NOR,"yema",
	WHT"Ұ¿"NOR,"yelu",
	WHT"����"NOR,"baitu",
	WHT"����"NOR,"huitu",
	WHT"ˮţ"NOR,"shuiniu",
	WHT"��ţ"NOR,"maoniu",
	WHT"Ұţ"NOR,"yeniu",
	WHT"����"NOR,"baishu",
	WHT"����"NOR,"huishu",
	WHT"������"NOR,"heimayi",
	WHT"����"NOR,"mayi",
	WHT"����"NOR,"baiyi",
	WHT"ɽ����"NOR,"shanlaoshu",
	WHT"����"NOR,"huashe",
	WHT"����"NOR,"qingshe",
	WHT"����"NOR,"baishe",
	WHT"�Ұ���"NOR,"huibanshe",
	WHT"����"NOR,"jumang",
	WHT"ˮ��"NOR,"shuishe",
	WHT"����"NOR,"haili",
	WHT"����"NOR,"heli",
});

int yaoguai_type=0;

int random_place(object me, string* dirs);
void _leave();
void leave();

void setname1()
{
        int i,j,k;
	string name, *id;

	i=(random(sizeof(names1)/2))*2;
	j=(random(sizeof(names2)/2))*2;
	k=(random(sizeof(names3)/2))*2;

	name=names1[i]+names2[j]+names3[k];
	id=({names1[i+1]+names2[j+1]+" "+
	    names3[k+1], names3[k+1]});

	set_name(name,id);

	set("race", "Ұ��");
	if (random(2) > 0 ) {
	  set("gender", "����");
	} else {
	  set("gender", "����");
	}
	yaoguai_type=1;
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/2))*2;
    j=random(2);
    
    name=names4[i]+(j?YEL"��"NOR:YEL"��"NOR);
    id=({names4[i+1]+" "+(j?"jing":"guai"),
	    (j?"jing":"guai")});

    set("race", "Ұ��");
    set("gender",(j?"����":"����"));
    set_name(name,id);
    yaoguai_type=2;
}

int cast_chance(int level) 
{
    return 5+level/2;
}

void create()
{
        if(random(2)==0)
	    setname1();
	else
	    setname2();

	set("chat_chance", 5);
	set("chat_msg", ({
	     (: random_move :)
	}) );

	set("chat_chance_combat", 5);

	set("age", 20+random(80));
	set("class", "yao");
	set("combat_exp", 3000);
	set("attitude", "heroism");
	set_skill("unarmed", 10);
	set_skill("jinghun-zhang", 10);
	map_skill("unarmed", "jinghun-zhang");
	set_skill("dodge", 10);
	set_skill("ghost-steps", 10);
	map_skill("dodge", "ghost-steps");
	set_temp("apply/armor", 25);
	
	set("limbs", ({
	       "ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
	       "�ұ�", "��צ", "��צ", "����", "С��", "ǰ��", "����",
	       "ǰצ", "��צ" }) );

        setup();
}

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
        object me=this_object();
	object weapon;

	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j+random(15));
	me->set_skill("lunhui-zhang", j+random(15));
	me->set_skill("lotusmove", j+random(15));
	me->set_skill("buddhism", j+random(15));
	me->set_skill("jienan-zhi", j+random(15));
	me->set_skill("lotusforce", j+random(15));
	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");

//	set("chat_chance_combat", 10+2*level);
	set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
	}) );

	weapon=new("/d/obj/weapon/staff/budd_staff");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}

void copy_status(object me,object ob, int lv)
{
        int j, lvl;
        object qm=new("/d/changan/npc/qianmian.c");
	int base=20;

	lvl=lv+base-2;

        if(qm) {
            mapping skill=ob->query_skills();
            int i=sizeof(skill);
            int *level, max_level;
	    int max_sen, max_kee;

	    if(i>0) {
		level=values(skill);
		max_level=level[0];
		while(i--) { // find out victim's maximum level
		    if(level[i]>max_level)
			max_level=level[i];
		}
	        max_level=max_level*lvl/base;

	    } else max_level=1;

	    qm->copy_status(this_object(), ob, lvl);
            destruct(qm);

	    // skill level will be set to the maximum level
	    // of the player.
	    set_skills(max_level, lv);
	    
	    max_sen=query("max_sen")/2;
	    max_kee=query("max_kee")/2;
	    add("eff_sen",max_sen);
	    add("eff_kee",max_kee);
	    add("sen",max_sen);
	    add("kee",max_kee);
	    add("max_sen",max_sen);
	    add("max_kee",max_kee);

	} else { // sth goes wrong.
	    leave();
	    return;
	}

	if((query("daoxing")+query("combat_exp"))/2
		>1000000)
	  add("force",query("force")); // double force.
	                               // because players have fabao.
	                             // mana is doubled when copying.
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query("max_mana")/30+1);
}

int random_place(object me, string* dirs)
{
        int  i, j, k;
        object  newob;
        mixed*  file, exit;

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        if( !sizeof(file) )             return 1;

	for(k=0;k<30;k++) { // try 20 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
		       newob->query("no_magic") ||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;

               if(me->move(newob)) {
		   message_vision("$N���˹�����\n",me);
		   return 1;
	       }
	     }
	   }
	}

        return 0;
}

void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if(me->is_fighting() || me->is_busy())
	return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
		  "����һ�Σ����һ������ɢȥ�ˡ�\n" NOR,environment());
        destruct(this_object());
      }
      return;
}

string invocation(object who, int level)
{
        object me=this_object();

        copy_status(me,who, level-2);
	
	return _invocation(who, level);
}

string _invocation(object who, int level)
{       object me=this_object(), env;
        string *dirs; 
        int exp, i, lvl;
	string where, long, guainame;
	
	dirs=dirs1;

        set("owner", who->query("id"));
        set("owner_ob", who);

	if(yaoguai_type==1) {
        long="һͷ"+name()+"����������"+
	  chinese_number((query("daoxing")/1000/10)*10)+
	  "������С���";
        if(random(2)==0) {
	  set("long",long+"ͨ��͸��һ˿������\n");
        } else {
	  set("long",long+"���������������ˡ�\n");
        }
	} else if(yaoguai_type==2) {
	    int dx=query("daoxing");
	    long="һֻ"+query("name")[0..<3]+
		"����"+({"��ɽ��","������","Ұ��",
			"��ԭ��","Ұ����","��ɽ��",
			"ç����","çԭ��","�����",
			})[random(9)]+
	        "��ȡ"+({"����","���","����"})[random(3)]+
		    "������������Щ���С�\n";
            set("long",long);
	    
	    if(dx>=10000000)
		long=HBYEL HIW" �� �� "NOR;
	    else if(dx>=1000000)
		long=HBRED HIW" ǧ �� "NOR;
	    else if(dx>=100000)
		long=HBBLU HIW" �� �� "NOR;
	    else if(dx>10000)
		long=HIR"ʮ��"NOR;
	    else
		long=HIY"СС"NOR;
	    
	    set("title",long);
	}

	lvl=level;
	
	// choose npc type.
	i=random(1000);
	if(i<10) {
	    set("type","aggressive");
	} else if(i<20) {
	    set("type","blocker");
	} else if(i<220) {
	    set("type","aggressive_on_owner");
	} else 
	    set("type","normal");
	
	if(random(10)==0) {
	    set("env/wimpy",40);
	    if(lvl<9) lvl=lvl+1; // as more difficult to kill.
	} else {
	    set("env/wimpy",1);
	}

	// determine reward
	exp=(who->query("combat_exp")+
		who->query("daoxing"))/2;
	if(exp<30000) {
	    exp_reward=500+exp/60;
	    pot_reward=200+exp/300;
	} else if(exp<300000) {
	    exp_reward=1000+exp/600;
	    pot_reward=300+exp/6000;
	    dirs=dirs+dirs2;
	} else if(exp<3000000) {
	    exp_reward=1500+exp/6000;
	    pot_reward=350+exp/60000;
	    dirs=dirs+dirs2;
	} else {
	    exp_reward=2000;
	    pot_reward=400;
	    dirs=dirs+dirs2+dirs3;
	}

	pot_reward=pot_reward*(lvl+1)/10;
	exp_reward=exp_reward*(lvl+1)/10;

	me->set("stay_time", time()+1800);

	if(!random_place(me, dirs)) {
	    leave();
	    return 0;
	}
	
	env=environment(me);
	guainame=me->query("name")+"("+me->query("id")+")";
	where=guainame;
	if(env)
	  where+="��"+MISC_D->find_place(env);
	return where;
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)
  {
    message_vision ("$Nһ���ۣ�����㶫����������ˣ�����\n", me);
    return 1;
  }
  who->set_temp("mieyao/allow_to_go", 1);
  message_vision ("$N�ٺٺټ�����Ц���������ˣ������"
	  +"�ɱ������ٿ����㣡\n",me);
  return 1;
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
		env->query("no_magic"))) {
	random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>t) {
	remove_call_out("_leave");
	call_out("_leave",300);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
    type=query("type");
    switch (type) {
	case "aggressive": {
	    object leader=query_leader();
	    int exp, myexp;
	    if(leader && present(leader, environment(me))) {
		if(!is_fighting()) kill_ob(leader);
		break;
	    }
	    exp=(who->query("combat_exp")+
		    who->query("daoxing"))/2;
	    myexp=(query("combat_exp")+
		    query("daoxing"))/2;
	    if(exp>myexp*3 || exp<myexp)
		break;

	    set_leader(who);
	    message_vision("$N����$n������ֱ����ˮ���ٺ٣�����\n",
		    this_object(), who);
	    kill_ob(who);
	    break;
	}
	case "aggressive_on_owner":
	    if(query("owner")==this_player()->
		    query("id")) {
		message_vision("$N����$n�����һ���������������������⣡\n",
			this_object(), who);
		kill_ob(this_player());
		this_player()->kill_ob(this_object());
	    }
	    break;
	case "blocker": {
	    add_action("do_block","",1);
	    break;
	}
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
	    verb!="fly" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    if(who->query_temp("mieyao/allow_to_go")) {
	who->delete_temp("mieyao/allow_to_go");
	who->delete_temp("mieyao/leave_time");
	return 0;
    }
    t=who->query_temp("mieyao/leave_time");
    if(t>0 && time()>t) {
	who->delete_temp("mieyao/leave_time");
	message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
	return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("mieyao/leave_time",t);
	message_vision("$N�͵�����������$n��ǰ�������е���\n"+
		"          ��ɽ���ҿ������������ԣ�\n"+
		"          Ҫ���·����������·�ƣ�\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"һ��ץס���㣡\n");
    return 1;
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void die()
{
        string owner;
    string skill;
        object owner_ob;
	object me=this_object();
	string str,msg;
	int max_kee, max_sen, ratio, exp_r, pot_r;

        owner = query("owner");

        if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
	    if(environment(owner_ob)==environment() && living(owner_ob)) {
   message_vision(death_msg[random(sizeof(death_msg))],owner_ob,this_object());


	    } else {
		message_vision("$N���ˡ�\n",this_object());
	    }
		    owner_ob->set("mieyao/done",1);
		    
		    max_kee=query("max_kee");
		    max_sen=query("max_sen");
		    ratio=100*(max_kee-other_kee)/max_kee;
		    if(ratio<0) ratio=0;
		    ratio=ratio*(max_sen-other_sen)/max_sen;
		    if(ratio<0) ratio=0;

		    exp_r=exp_reward*ratio/100;
		    pot_r=pot_reward*ratio/100;
		    owner_ob->add("combat_exp",exp_r);
		    owner_ob->add("potential",pot_r);
		    
		    str=" got "+exp_r+"/"+exp_reward+" exp "+
			pot_r+"/"+pot_reward+" pot in level "+
			owner_ob->query_temp("mieyao/level")+
			".\n";
       if (owner_ob->query_temp("mieyao/level")==9 && ratio>50) {
          skill=give_reward(owner_ob);
         str+= "and rewarded 1 lvl of "+skill+".\n";
   	if (skill != "none"){
    message("shout",HIY"��"HIW"ն����ħ"HIY"��"HIY"�(Li jing):" HIR+ owner_ob->query("name")+HIM"Э����ͥն����ħ�й�,��ʴ�۴�"HIY+ to_chinese(skill)+HIM"һ����\n"NOR,users()); 
// CHANNEL_D->do_channel(me,"rumor",msg);
    }



   }

		    MONITOR_D->report_system_object_msg(owner_ob, str);

		   tell_object(owner_ob, HIY"��õ���"HIR+chinese_number(exp_r)
			    +"��"HIY"��ѧ�����"HIR+chinese_number(pot_r)+
			    "��"HIY"Ǳ�ܣ�\n"NOR);

     
        } else {
	    message_vision("$N���ˡ�\n",this_object());
	}

	destruct(this_object());

}

varargs int receive_wound(string type, int damage, object who)
{
    string owner=query("owner");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "kee": other_kee+=damage; break;
		case "sen": other_sen+=damage; break;
	    }
	}
    }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
    string owner=query("owner");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "kee": other_kee+=damage; break;
		case "sen": other_sen+=damage; break;
	    }
	}
    }
    return ::receive_damage(type, damage, who);
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
	        string owner=query("owner");
	
	if(opponent->query("id")==owner 
			&& userp(opponent)
			&& !living(opponent)
			&& environment()==environment(opponent)) {
		    call_out("leave",1);
		    return 0;
		}

		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}
