//By tianlin@mhxy for 2001.12.5
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{      
	int ap, dp;
	string msg;
	int extra;
	object weapon;                 
	extra = me->query_skill("duo-sword",1);
	if ( extra < 200) return notify_fail("��Ķ��������������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIR"�۶���ʮ�Ľ���"HIB"ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <200)
return notify_fail("����ķ����������죡\n");
        message_vision(HIR"$N���赭д���ӳ����⣬һ˲�����ʹ������ʮ��ʽ�����е�"+ weapon->name()+ HIR "���������������Ǻ�ˮ�����$n�̳���"BLINK+HIC"һ"NOR+HIR"��!\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIW"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIC"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIB"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIY"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIG"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        message_vision(HIR"------>>>>>>��"HIC"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIY"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIB"��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIC"ʮ"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIW"ʮһ"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIM"ʮ��"HIR"��<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>��"HIC"ʮ��"HIR"��<<<<<<------" NOR,me,target);
        message_vision(CYN"\n$N�ĵ�ʮ�����̳������еı仯�����������������ˮ�ѵ���ͷ������Ҳ���ˣ�������\n\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"��Ȼ����ȴ�����ڱ䣬$N��Ȼһ���ӳ��������߼ʣ������·���"NOR,me,target);
        message_vision(HIC"\n������һ��ȴ���ǻ������磬��Ȼ�գ�ȴ������ת�����Ŧ��" NOR,me,target);
        message_vision(HIR"\nȻ��$N�ʹ̳��˶���ʮ������"HIY"��"HIB"ʮ��"HIY"��"HIR"-------------------------------------------
\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);            
        
        msg = RED "\n$N�Ľ�����ɱ�������أ��������쵺���ܲ�����һ���̳�����Ȼ��ͽ��������ƶ������ˣ��ֳ������⡣";
msg +=  "\n��һ���̳������еı仯������ѵ���������ѵ��˾�ͷ����ˮ�����ھ���������ȫ�ݽ�.\n$N����Ҳ�ѽ��ˡ�\n\n" NOR; 
        if(target->query("disable_type") ==HIW "<������>" NOR)
	return notify_fail(HIY"�������޷��ö���ʮ��ʽ�Ľ��Ʊ��ȶԷ���\n"NOR);
	ap = me->query_skill("sword");
	ap = ( ap * ap /100 * ap/40 ) * (int)me->query("sen") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
	msg +="$n��$N�Ľ������ȣ��������ã�\n";
		target->set_temp("disable_inputs",1);
		target->set("disable_type",HIW "<������>" NOR);
		target->start_busy(2);
		target->set_temp("is_unconcious",1);
        	seteuid(ROOT_UID);
		target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),
		random((int)me->query_skill("sword")/30)+((int)me->query_skill("sword")/30));
	} else
		msg += "����$n��������$N�Ľ��ơ�\n";

	message_vision(msg+NOR, me, target);

        me->start_busy(3);
	return 1;
}
void remove_frozen(object me)
{
   me->delete("disable_type");
   me->delete_temp("disable_inputs");
   me->delete_temp("is_unconcious");
  if(!me->is_ghost())
	message_vision(HIR "\n\n$Nһ������������һ��,�ɳ����������֮�У���\n\n" NOR, me);
}


