// tanyunshou.c
// by mhsj@gslxz /2001/7/25

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	int damage,ob,victim,who;
	string msg,dsc;

	object thing,*inv;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("̽����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		
	if( (int)me->query_skill("sougu-zhua",1)<10)
	return notify_fail("����ѹ�צ������죬����ʹ�á�̽���֡���\n");
	if( (int)me->query_skill("yanxing-steps",1)<10)
	return notify_fail("������в����������ݣ�����ʹ�á�̽���֡���\n");
	if( (int)me->query("force",1)<50)
	return notify_fail("����������̫��������ʹ�á�̽���֡���\n");

//	victim = present(who, environment(me));
			
	msg = CYN "$NͻȻ����һչ��ʹ����̽���֡���$n������ȥ��\n"NOR;

	if(random(me->query_skill("dodge"))>target->query_skill("dodge")/2)
	{
	me->start_busy(3);
		target->start_busy(random(3));
		
	me->add("force",-random(10));
	inv=all_inventory(target);
	if(!sizeof(inv))	{
		msg +=CYN"$n���Ͽտ���Ҳ��$NʲôҲû��̽������\n"NOR;
	}
	else	{
		thing=inv[random(sizeof(inv))];
		thing->move(me);
	msg +=CYN"$N���ֿտգ���$n���ϵõ�"+thing->query("unit")+thing->query("name")+"��\n"NOR;
	message("channel:chat",HIM"���о����ԡ�ĳ�ˣ�"+"��˵ "HIY+me->query("name")+HIM"ʹ�������"HIW"��̽���֡�"HIM"�� "
HIY+target->query("name")+HIM" ����͵���� "HIW"һ"+ thing->query("unit")+ thing->name()+" \n"NOR,users());
}
	} else 
	{
		me->start_busy(1);
	msg += CYN"����$p������$P����ͼ������һ�����˿�ȥ��\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
