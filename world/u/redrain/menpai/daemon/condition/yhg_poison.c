// yhg_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("sen", duration);
	me->receive_damage("sen", duration);
	me->receive_damage("kee", duration);
	me->receive_wound("kee", duration);
	me->set_temp("death_msg","�����ľ�������\n");
	me->apply_condition("yhg_poison", duration);
	if (duration >0 )
	tell_object(me, HIG "��Ȼ����Ŀ����³�һ̲��Ѫ����о��е�֧�ֲ�ס�ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
