//by tianlin 2001/5/1
// fingerd.c
//By tianlin@mhxy for 2002.3.10���±���
#include <net/dns.h>
#include <ansi.h>

void create() { seteuid( getuid() ); }
string *exclude =({});
string age_string(int time)
{
	int month, day, hour, min, sec;

	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?chinese_number(month) + "��":"") + (day?chinese_number(day) + "��":"") + 
	(hour?chinese_number(hour) + "Сʱ":"") + chinese_number(min) + "����";
}

string finger_all()
{
	object *ob;
	string msg, fip;
	int i;

	ob = users();
	msg = "";
	if ( !wizardp(this_player()) )  // player finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-14s%-14s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				query_idle(ob[i]) + "s");
		}
		return "[1;36m��[2;37;0m [36m�λ�����[2;37;0m \n" + 
		"[1;33m------------------------------------[2;37;0m\n"
		+ "[1;37m����[2;37;0m          [1;36m�ʺ�[2;37;0m          [1;35m����[2;37;0m\n" +
		"[1;33m------------------------------------[2;37;0m\n"
		+ msg +
		"[1;33m------------------------------------[2;37;0m\n";
	} else  	// wizard finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-10s%-4s%-14s%-7s%s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				ob[i]->query_encoding()?"B5":"GB",
				 chinese_number(ob[i]->query("age")), 
				query_idle(ob[i]) + "s", query_ip_name(ob[i]));
		}
		return "[1;36m��[2;37;0m [36m�λ�����[2;37;0m \n" + 
"[1;33m-----------------------------------------------------------[2;37;0m\n"
+ "[1;37m����[2;37;0m          �ʺ�          [1;36m����[2;37;0m          [1;35m����[2;37;0m   [1;32m����[2;37;0m\n" +
"[1;33m-----------------------------------------------------------[2;37;0m\n"
+ msg +
"[1;33m-----------------------------------------------------------[2;37;0m\n";
	}
}
	
string finger_user(string name)
{
	object ob, body;
	string msg, mud;
	int public_email,public_webpage,public_icq;

	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_gfinger_q(mud, name, this_player(1));
		return "��·ָ��͹��̿�����ҪһЩʱ�䣬���Ժ�\n";
	}

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) {
	  destruct(ob);
	  return "û�������ҡ�\n";
        }	
	
	if ((!this_player() || !wizardp(this_player())) )  // player finger
	// !this_player() is used for inter-mud finger.
	// in that case, this_player() is not defined, so treat as player.
	// mon 8/27/97
	{
	
		if( objectp(body = find_player(name)) && geteuid(body)==name )
		{
			public_email = body->query("env/pub_email")?1:0;
			public_webpage = body->query("env/pub_webpage")?1:0;
			public_icq = body->query("env/pub_icq")?1:0;
		} else 
		{
			body = LOGIN_D->make_body(ob);
			if( !body || !body->restore() ) {
			  destruct(body);
			  destruct(ob);
			  return "û�������ҡ�\n";
                        }
			public_email = body->query("env/public")?1:0;
			public_webpage = body->query("env/pub_webpage")?1:0;
			public_icq = body->query("env/pub_icq")?1:0;
			destruct(body);
		}		
		if(this_player()==body)
		  msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
			"�����ʼ���ַ��\t%s\n������ҳ��ַ��\t%s\n[ICQ/OICQ]���룺%s\n�ϴ����ߵ�ַ��\t%s( %s )\n\n%s\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_chinese_status(name),
			ob->query("email"),
			ob->query("webpage"),
			ob->query("icq"),
			ob->query("last_from"),
			ctime(ob->query("last_on")),
			stringp(ob->query("profile"))?(ob->query("profile")):"",
		);
		else 
		msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n�����ʼ���ַ��\t%s\n������ҳ��ַ��\t%s\n[ICQ/OICQ]���룺%s\n�ϴ����ߣ�\t%s\n\n%s\n",
			ob->query("id"),
			ob->query("name"),
member_array(ob->query("id"),exclude)==-1?SECURITY_D->get_chinese_status(name):"(immortal)",
			public_email?ob->query("email"):"��������",
			public_webpage?ob->query("webpage"):"��������",
			public_icq?ob->query("icq"):"��������",
			ctime(ob->query("last_on")),
			stringp(ob->query("profile"))?(ob->query("profile")):"",
		);
		// !body->query("env/invisibility") added by snowcat
		if( objectp(body = find_player(name)) 
			&& geteuid(body)==name 
			&& interactive(body)
			&& (!wizardp(body) || 
				!body->query("env/invisibility")) ) {
		    // can only query_idle on an interactive player.
		        int idle=query_idle(body);

			msg += sprintf("%sĿǰ��������",body->name(1));
			if(idle>59) 
			    msg+=sprintf("���ѷ��� %d ���ӡ�\n", idle);
			else 
			    msg+="�С�\n";
		}
	} else  	// wizard finger
	{
		msg =  sprintf("\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
			"�����ʼ���ַ��\t%s\n������ҳ��ַ��\t%s\n[ICQ/OICQ]���룺%s\n�ϴ����ߵ�ַ��\t%s( %s )\n\n%s\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("webpage"),
			ob->query("icq"),
			ob->query("last_from"),
			ctime(ob->query("last_on")),
			stringp(ob->query("profile"))?(ob->query("profile")):"",
		);
		// !body->query("env/invisibility") added by snowcat, removed by mon
		if( objectp(body = find_player(name)) 
			&& interactive(body)
			&& geteuid(body)==name ) {
			msg += sprintf(
				"%s��%s��Ŀǰ���ڴ� %s ���ߣ��ѷ��� %d ���ӡ�\n", 
				body->name(1),
				age_string( (int)body->query("mud_age")),
				query_ip_name(body), query_idle(body));
		}
	}	
	
	destruct(ob);
	return msg;
}

//this function is not used.  remote finger still use finger_user.
//mon 3/7/98
varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) {
	        destruct(ob);
		return chinese_flag ? "û�������ҡ�\n" : "No such user.\n";
        }
	if( chinese_flag ) msg =  sprintf(
		"\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\nȨ�޵ȼ���\t%s\n"
		"�����ʼ���ַ��\t%s\n�ϴ����ߵ�ַ��\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "Ŀǰ�������ϡ�\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	if(ob->restore()) return ob;
	else {
	  destruct(ob);
	  return 0;
        }
}
varargs string tianlin_finger_user(string name, int chinese_flag)
{
    object ob, body;
    string msg;

    ob = new(LOGIN_OB);
    ob->set("id", name);
    if( !ob->restore() ) {
        destruct(ob);
        return chinese_flag ? "û�������ҡ�\n" : "No such user.\n";
    }
    msg =  sprintf(
      "\nӢ�Ĵ��ţ�\t%s\n��    ����\t%s\n"
      "Ȩ�޵ȼ���      "CYN"��ͨ���"NOR"\n"
      "�����ʼ���ַ��  ��������\n"
      "������ҳ��ַ��  ��������\n"
      "[ICQ/OICQ]���룺��������\n"
     "�ϴ����ߣ�    \t%s\n\n",
      ob->query("id"),
      ob->query("name"),
      ctime(ob->query("last_on"))
    );
    if( body = find_player(name) ) {
        if( !this_player() || this_player()->visible(body) )
            msg +=     ("\n" + ob->query("name") + "Ŀǰ�������ϡ�\n");
    }

    destruct(ob);
    return msg;
}


