// yun_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 17);
	me->receive_damage("sen", 20);
	me->apply_condition("yun_poison", duration-1);
      if( duration < 1 )
	tell_object(me, WHT "���������һƬ��������������������\n" NOR );
	else
	tell_object(me, YEL "��ֻ������ǰһ�ڣ�������ת����ʱ����������\n" NOR );
	me->unconcious();
	if( duration < 1 ) 
		return 0;
	return 1;
}
