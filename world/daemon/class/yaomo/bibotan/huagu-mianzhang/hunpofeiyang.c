// By tianlin 2001.5.1
// hunpofeiyang.c ���Ƿ���
 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	
	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting() )
	    	return notify_fail("�����Ƿ��ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 500 )
		return notify_fail("��������������ߣ�\n");

	if( (int)me->query_skill("unarmed") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�û��Ƿ��\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 60)
		return notify_fail("�㻯�����Ƶ���Ϊ����������ʹ�û��Ƿ���! \n");
	 
	msg = HIY "$N���һ����ʹ���������Ƶľ���[5m[1;37m�����Ƿ��[2;37;0m[1;33m��˫ȭ������������$n��ȥ��\n"NOR;
             message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	
	me->start_busy(2);
	return 1;
}
