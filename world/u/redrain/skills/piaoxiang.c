//Ѫ��Ʈ��
// by swagger
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������Ʈ�㡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("baihua-sword", 1) < 100 )
		return notify_fail("��Ľ���������죬����ʹ�á�\n");
	                        
           if (me->query_temp("piao_busy")) 
                        return notify_fail("����������У����û���Σ��!\n");

	if( (int)me->query_skill("zhuanlong-force", 1) < 100 )
		return notify_fail("����ڹ���Ϊ�����ߡ�\n");
			
	if( (int)me->query("force") < 1000 )
		return notify_fail("����������̫��������ʹ�á�����Ʈ�㡹��\n");
			
       msg = HIW "\n$Nһ����Х�����˵��Χ��$n��ת�����г�����������������Ľ���!\n        
"HIC"$n�پ������ۻ����ң��·����������ػ���֮��......"NOR"
"HIC"ȴ��$NͻȻ����һ�٣��˽���һ������һ˿���������㣬����$n......\n"NOR;        
	if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
	damage = (int)me->query_skill("baihua-sword", 1) + me->query("force_factor");
		target->receive_damage("kee", damage*3/2+random(100));
		target->receive_wound("kee", damage/4);
		 msg += HIM"\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n"NOR;
                message_vision(msg,me,target);
                me->add("force", -250 - me->query("force_factor"));
                target->start_busy(1);
//                          me->start_busy(random(2));
		COMBAT_D->report_status(target);

	} else 
	{
		msg += HIM"\n����$n�͵������һԾ,������$N�Ĺ�����Χ��\n"NOR;
                message_vision(msg,me,target);
		me->add("force", -150 - me->query("force_factor"));
                me->start_busy(2);
	}

	if(userp(target)) target->fight_ob(me);
 me->set_temp("piao_busy",1);
 call_out("remove_effect",5+random(5),me);
	return 1;
}
void remove_effect(object me) {
 string msg;
  if (!me) return;
  me->delete_temp("piao_busy");
}