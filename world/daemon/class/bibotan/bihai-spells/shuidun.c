//cast function: escape.c �����ڸ����Ӷݡ�

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	int ap, dp, success;
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( me->is_busy())
		return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("�㾫��̫����Լ��о������䡣\n");

	if( (int)me->query_skill("bihai-spells", 1) < 30)
		return notify_fail("��δ��ѧ��ˮ�ݡ�\n");

	ap=me->query_skill("spells")+me->query("max_mana")/10;
	if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

	if(!me->is_fighting() )
	{
		message_vision(HIY"$N���˼����������ӿ��һ��ˮ����$N����ˮ�������ˡ�\n"NOR,me);
		me->add("sen", -me->query("max_sen")/8);
		me->add("mana", -80);
		success=1;
	}
	else
	{
		msg=HIY"$N�ۼ����У�ͻȻ����սȦ�����˼�������...\n"NOR;
		if(random(ap+dp)>dp/2)
		{
			msg+=HIY"���Ű׹�һ��,$N����Ӱ�Ѿ������ˡ�\n"NOR;
			me->add("sen", -me->query("max_sen")/6);
			me->add("mana", -50);
			success=1;
		}
		else msg+=HIY"��$n����Ӱ�ѽ������ϣ���$N����������\n"NOR;
		me->add("mana", -50);
		message_vision(msg, me, target);
	}
	if(success)
	{
//                start=me->query("env/destination");
//                start=me->query("�Ǻ�/"+start);
//                if(!start || !find_object(start))
//                        start=me->query("startroom");
if(!start) start="/d/qujing/bibotan/yujie";
                me->move(start);
		message("vision", HIY+me->name()+"����һ��ˮ�������������ǰ��\n"NOR,
				  environment(me), me);
		tell_object(me, HIY"�����ӰͻȻ������һ��ˮ���С�\n"NOR);
		return 3+random(3);
	}
	return 5+random(5);
}

