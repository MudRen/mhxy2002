// By tianlin 2001.5.1
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("huagu-mianzhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�����Ļ�ϡ�ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����Ļ�ϡ�ֻ�ܿ���ʹ�á�\n");		
       
	 if( (int)me->query("force") < 700 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("force",1) < 110 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á����Ļ�ϡ���\n");
	
	weapon = me->query_temp("weapon");

        msg = HIW "$N���λ�ת��ŭ��һ����ͬʱʹ�����������еľ��裬һ��"NOR+BLINK"[1;30m�����Ļ�ϡ�"NOR+HIW"��������$n��" NOR;
        	         message_vision(msg, me, target);                
	 msg =  HIW  "�������" NOR;
        message_vision(msg, me, target);
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "�ݳ�����" NOR;
        message_vision(msg, me, target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��ʧ����" NOR;
        message_vision(msg, me, target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "��������" NOR;
        message_vision(msg, me, target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "�˷ξ���" NOR;
        message_vision(msg, me, target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "���ľ���" NOR;
        message_vision(msg, me, target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "���㱾���" NOR;
        message_vision(msg, me, target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("force", -700);
        me->start_busy(3);

        return 1;
}

