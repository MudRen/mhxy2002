//By angela@mhxy 2001.12.29
// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	message_vision(
	HIW"$N����������������ķ����������ɣ�����������Ƶİ���\n" NOR, me );

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
	me->add("force", -30);

	return 1;
}
