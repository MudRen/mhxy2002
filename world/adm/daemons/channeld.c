//by tianlin 2001/5/1
//The sourse code is crack from the DHXY. copyright was keep by DHXY.
//We must respect the wizard's 

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

mapping channels = ([
   "ftp":  ([      "msg_speak": HIM "��FTP��"HIG"%s��"HIG"%s\n" NOR, "wiz_only": 1 ]),
   "sys":   ([   "msg_speak": HIG "��ϵͳ��"HIG"%s��"HIG"%s\n" NOR, "wiz_only": 1 ]),//by tianlin �޸�
   "wiz":   ([   "msg_speak":HIY "��"NOR+WHT"��ʦ"HIY"��"HIY"%s��"HIY"%s\n" NOR,
          	 "msg_emote": HIY "��"NOR+WHT"��ʦ"HIY"��"HIY"%s\n" NOR,
          	 "wiz_only": 1
            ]),
   "gwiz":  ([  "msg_speak": HIG "��������ʦ��%s��"HIG"%s\n" NOR,
                "msg_emote": HIG "��������ʦ��%s\n" NOR,
          	"wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
          	"filter": 1,
          	"intermud_emote": 1 
             ]),
   "xyj":   ([   "msg_speak": HIR "�����μǡ�%s��"HIR"%s\n" NOR,
          "msg_emote": HIR "�����μǡ�%s\n" NOR,
          "intermud": GCHANNEL, "channel": "xyj",
          "filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
          
    //ֻ��mudlib��������A Journey to the West���ܲ�����ͨ
  
   "es":   ([   "msg_speak": HIG "��̶�����ġ�%s��"HIG"%s\n" NOR,
          	"msg_emote": HIG "��̶�����ġ�%s\n" NOR,
          "intermud": GCHANNEL, "channel": "es",
          "filter": 1 ]), 
   //����es2��LPMUD���ܲ�����ͨ
   
   "sldh": ([      "msg_speak": HIC "��ˮ½��᡿"HIC"%s��"HIC"%s\n" NOR,
                   "msg_emote": HIC "��ˮ½��᡿"HIC"%s\n" NOR,
           ]),
      
   "chat": ([      "msg_speak": HIC "�����ġ�%s��"HIC"%s\n" NOR,
                   "msg_emote": HIC "�����ġ�%s\n" NOR,
                   ]),

//by tianlin 2001.7.1��������   
"bill":  ([      "msg_speak": HIC "��������%s��"HIC"%s\n" NOR,
                   "msg_emote": HIC "��������%s\n" NOR,
                    ]),
   //added by vikee           
   "tonggao":   ([   "msg_speak": NOR "��"HIR"ͨ��"NOR"��"HIY"%s��"HIY"%s\n" NOR,
        	    "msg_emote": NOR "��"HIR"ͨ��"NOR"��%s\n" NOR,
   	       "notice_only" : 1,
         ]),
   "rumor":([   "msg_speak": HIM "��ҥ�ԡ�%s��"HIM"%s\n" NOR,
          	"msg_emote": HIM "��ҥ�ԡ�%s\n" NOR,
          "anonymous": "ĳ��"
        ]),
     //this segment code is gettd from dhxy's program
     "jh":   ([     "msg_speak": HIG "������ͬ�ˡ�"+NOR+HIG+"%s��"HIG"%s\n" NOR,
                    "msg_emote": HIG "������ͬ�ˡ�"+NOR+HIG+"%s\n" NOR,
                    "msg_color": NOR+HIG,
                    "intermud": GCHANNEL,
                    "intermud_emote": 1,
                    "channel": "jh",
                    "filter": 1,
                    "omit_address": 0,

        	]),        
    "party":([      "msg_speak": HIG "�����ɡ�%s��"HIG"%s\n" NOR,
                     "msg_emote": HIG "�����ɡ�%s" NOR,
                        "party_only": 1
                ]),
    "lover"	:([ "msg_speak": HIM "���������ࡿ%s��"HIM"%s\n" NOR,
				"msg_emote": HIM "���������ࡿ%s\n" NOR,
				"lover_only":1
		]),
    ]);
string party;
string couple_id;

void create()
{
   seteuid(getuid());  
        set("channel_id", "Ƶ������");
}

varargs int do_channel(object me, string verb, string arg, int emote,int allow_chat)
{
   object *ob, couple;
   string *tuned_ch, who, arg1;
   int time,count,count1,last_chat,len;

        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
     emote = 1;
     verb = verb[0..<2];
   }


   if( !mapp(channels) || undefinedp(channels[verb]) )
     return 0;
//By tianlin@mhxy for 2001.12.15
	 if( !wizardp(me) )
        if( userp(me)) 
        if(me->query("mud_age") < 3600)
           return notify_fail("�Բ��𣬱�վ��֧����������,��1��Сʱ��ʹ�ã�\n");
	if(  !allow_chat ) {  
     time=time();
     if(me->query("channel/chat_block") &&
       (time-me->query("channel/chat_block"))<0 )
        return notify_fail("��Ĺ���Ƶ������ʱ�ر��ˡ�\n");
              
         count=me->query("channel/chat_count");
		// if the channel arg contains too many lines,
		// then count more than once. -- mon 8/16/98
		count1=sizeof(explode(" "+arg,"\n"))/3+1;
		// if arg too long, also counts more.
		count1+=sizeof(arg)/200;
		count+=count1;
		last_chat=me->query("channel/last_chat");
                  if (count>2) {
		  count=0;
		  me->set("channel/last_chat",time);
                if( userp(me)) 
	         if( !wizardp(me) )//������仰Ϊ�˸�wizˢ��,xixi,haaa,ah,ya,hoho,grin
		   if (time==last_chat || count1>2) {
		    me->set("channel/chat_block",time+180);
		    return notify_fail("��Ϊһ�ν���̫�࣬��Ĺ���Ƶ������ʱ�ر��ˡ�\n");
		  } 
//by tianlin@mhxy for 2001.8.22�޸���Ϊ��ؾ��龭���ر�,����cut����仰.
	        } 
		me->set("channel/chat_count",count);  
                
        if ((int)me->query("chblk_es") && verb == "es")
		return notify_fail("�Բ��������������Ƶ�����ر��ˣ�\n");
	if ((int)me->query("chblk_rumor") && verb == "rumor")
		return notify_fail("�Բ������ҥ��Ƶ�����ر��ˣ�\n");
	if ((int)me->query("chblk_chat") && verb == "chat")
		return notify_fail("�Բ����������Ƶ�����ر��ˣ�\n");
	if ((int)me->query("chblk_sldh") && verb == "sldh")
		return notify_fail("�Բ������ˮ½���Ƶ�����ر��ˣ�\n");
	if ((int)me->query("chblk_xyj") && verb == "xyj")
		return notify_fail("�Բ��������������Ƶ�����ر��ˣ�\n");
	if ((int)me->query("chblk_jh") && verb == "jh")
		return notify_fail("�Բ�����Ľ���ͬ��Ƶ�����ر��ˣ�\n");
       if (!stringp(arg) || arg == "") {
		arg = "...";
		if (emote) arg = "�������ֹ����Ĳ�֪����˵Щʲô��";
	}

                if(channels[verb]["wiz_only"] && !wizardp(me)&&userp(me) )
                   return 0; 
                if(channels[verb]["party_only"] && !me->query("family/family_name"))
                   return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");
                if(channels[verb]["notice_only"] && !wizardp(me))
                return notify_fail("ֻ�й���Ա���ܷ�֪ͨ��\n");
                if (verb=="lover"||verb=="lover*") {
                	
		        if (!me->query("couple/id")) 
			      return notify_fail("�����ڻ�û�а��£�Ҫ��˭˵���Ļ��أ���\n");
		        if(!(couple=find_player(me->query("couple/id"))))
			      return notify_fail("��İ���Ŀǰ�������ϡ�\n");
			      couple_id=me->query("id");
	        }  
                if (channels[verb]["party_only"]){
                party = me->query("family/family_name");
                channels[verb]["msg_speak"] = HIG "��"HIW+party+HIG"��%s��%s\n" NOR;
                channels[verb]["msg_emote"] = HIG "��"HIW+party+HIG"��%s\n" NOR;
            }
     
    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("�Բ������Ƶ����֧�� emote ��\n");
        return 1;
    }
     tuned_ch = me->query("channels");
     if( !pointerp(tuned_ch) )
        me->set("channels", ({ verb }) );
     else if( member_array(verb, tuned_ch)==-1 )
        me->set("channels", tuned_ch + ({ verb }) );

     if( emote &&me->is_character()&& !channels[verb]["intermud_emote"]) {
        string vb, emote_arg;

        if( nullp(arg) ) return 0;
        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
          vb = arg;
          emote_arg = "";
        }
   if( arg == me->query_temp("last_channel_msg") )
		return notify_fail("�ù���Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");
     if( channels[verb]["anonymous"] )
           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
               else {
		   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
			int age=me->query("mud_age");
			// prevent login  newbie to flood channels.
			if(!wizardp(me)) {
			    if(age<3600) return notify_fail(
				    "");
			    else if(age<86400) {
				if((int)me->query("sen")<30) return 
				    notify_fail
					("");
				me->add("sen",-5);
			    }
			}

			"/adm/daemons/network/services/gemote_q"->
			send_msg(channels[verb]["channel"], me,
			vb, id, site, channels[verb]["filter"]);
                        return 1;
		      }
                   }
                }

     if( !arg ) return 0;
     }
   }
   if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me)) {
		    if((int)me->query("sen")<50) return
			notify_fail("���Ѿ�û�о���ɢ��ҥ���ˡ�\n");
		    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
		    sprintf("ҥ�ԣ�%s(%s)��", me->name(1),me->query("id")));
		}
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
		who = me->query("name");
		if(me->query("id")) 
		  who=who+"(" + capitalize(me->query("id")) + ")";
             }



   ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );


   len=strlen(arg);
   while(len>1 && arg[len-1]=='\n')
       arg=arg[0..((len--)-2)];

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

   if( emote ) {
     if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;

     message( "channel:" + verb,
        sprintf( channels[verb]["msg_emote"], arg1 ), ob );
   } else
     message( "channel:" + verb,
        sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );
   if( arrayp(channels[verb]["extra_listener"]) ) {
     channels[verb]["extra_listener"] -= ({ 0 });
     if( sizeof(channels[verb]["extra_listener"]) )
        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
   }
   
   if( !undefinedp(channels[verb]["intermud"])
   &&   base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
          	 int age=me->query("mud_age");
            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

      
         if(!wizardp(me)) {
	      if(age<3600) return notify_fail("");
	      else if(age<86400) {
		if((int)me->query("sen")<30) return 
		    notify_fail
			("");
		me->add("sen",-5);
	      }
	    }
          }
     channels[verb]["intermud"]->send_msg(
     channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

   if (userp(me) && !wizardp(me)) {
		if (stringp(me->query_temp("last_channel_msg"))
			&& (strsrch(arg, me->query_temp("last_channel_msg")) >= 0
			|| strsrch(me->query_temp("last_channel_msg"), arg) >= 0))
			
			me->add_temp("channel_repeat", 1);
			
		else me->delete_temp("channel_repeat");
		
               if (me->query_temp("channel_repeat") > 4 ) {
               	       if(verb!="sys")
               	       {
			me->set("chblk_"+verb, 1);
			switch (verb) {
					case "chat": verb = "����"; break;
					case "rumor": verb = "ҥ��"; break;
					case "sldh": verb = "ˮ½���"; break;
					case "es": verb = "��������"; break;
					case "xyj": verb = "��������"; break;
					case "jh": verb = "����ͬ��"; break;
					default: verb = "��̸";
			}
			
			
			do_channel(this_object(), "rumor",
				"���ڽ���̫���£�" + me->name(1) + "("+capitalize(me->query("id"))+")��" + verb + "Ƶ�����ر��ˡ�");
		}}
			
		me->set_temp("last_channel_msg", arg);
		
		if (me->add_temp("channel_count", 1) > 1) {
			me->delete_temp("channel_count");
			if (me->query_temp("last_channel_time") == uptime()) {
				me->set("chblk_"+verb, 1);
				switch (verb) {
					case "chat": verb = "����"; break;
					case "rumor": verb = "ҥ��"; break;
					case "sldh": verb = "ˮ½���"; break;
					case "es": verb = "��������"; break;
					case "xyj": verb = "��������"; break;
					case "jh": verb = "����ͬ��"; break;
					default: verb = "��̸";
				}
				do_channel(this_object(), "rumor",
					"���ڽ���̫��̫�죬" + me->name(1) + "("+capitalize(me->query("id"))+")��" + verb + "Ƶ�����ر��ˡ�");
			}
			me->set_temp("last_channel_time", uptime());
		}
	}

   return 1;
}



int filter_listener(object ppl, mapping ch)
{
   // Don't bother those in the login limbo.
   if( !environment(ppl) ) return 0;
   if( ch["wiz_only"] ) return wizardp(ppl);
   //ֻ�б����ܿ���
   if( ch["party_only"] )  
   {   
        if ( !wizardp(ppl) && party != ppl->query("family/family_name") ) return 0;
   }
   //ֻ�з����ܿ�
   if( ch["lover_only"])
   {
   	if ( !wizardp(ppl) && couple_id !=ppl->query("couple/id") 
   	&& couple_id !=ppl->query("id")  ) return 0;
   }	
   return 1;
}

void register_relay_channel(string channel)
{
   object ob;

   ob = previous_object();
   if( undefinedp(channels[channel]) || !ob) return;
   if( arrayp(channels[channel]["extra_listener"]) ) {
     if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
     channels[channel]["extra_listener"] += ({ ob });
   } else
     channels[channel]["extra_listener"] = ({ ob });
}


