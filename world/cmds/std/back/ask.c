// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
//xkiller 2001.1.20 �����˼���Ԥ������Ļش� (�μ���/adm/daemons/inquiryd.c) 
//ע������뷨��������2000���������������ǿ����ǵģ��Ǻ�~~~~
#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�ɻ�ؿ���$N��ҡ��ҡͷ��\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵�����ţ��������ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n�����������\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic 
			+ "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("[1;37m���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�[2;37;0m\n",
			me, ob);
		return 1;
	}

	// by snowcat jan 23 1998
	  if ( msg = QUEST->quest_ask (me, ob, topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	}

	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} else

	if(topic=="news")
		{
		string str;
		str=read_file("/log/NEWS");
		message_vision( CYN "$N������˵�ͷ˵��,���������˵��"+str+"" NOR, ob);
		return 1;
	       }	
	if(topic=="all")
		{
		message_vision( CYN "$N��������˵��:"+query_inquiry(ob)+"!\n" NOR, ob);
		return 1;
		}
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
} 
      	
//��npc���϶�ȡinquiry
string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		for(i=0;i<sizeof(indexs);i++)
			{
				str=indexs[i]+" "+str;
				}
		str="�й��� "HIB+str+NOR CYN"������,�Һܸ��˸�����!";
		return str;
		}
	return "ʵ���ǶԲ���,��ʲôҲ��֪��ѽ!";
	}
int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
Ԥ���ѯ������:
	here
	name
	news
	all
HELP
   );
   return 1;
}

