//By tianlin@mhxy for 2001.12.4�޸�
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{      
       string str;//ҥ�Եı���
	string msg;
	int extra;
       int urkee;
	object weapon;
       urkee=me->query("eff_kee");                 
	extra = me->query_skill("duo-sword",1);
	if ( extra < 210) return notify_fail("��Ķ����������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIB"�۶�������ʮ�彣��"NOR+YEL"ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <200)
return notify_fail("����ķ����������죡\n");
        message_vision(HIR"$N���赭д���ӳ����⣬һ˲�����ʹ������ʮ��ʽ.\nֻ��$N���е�"+ weapon->name()+ HIR "���������������Ǻ�ˮ�����$n�̳���"BLINK+HIC"һ"NOR+HIR"��!\n\n" NOR,me,target);
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
        message_vision(HIC"\n������һ��ȴ���ǻ������磬��Ȼ�գ�ȴ������ת�����Ŧ��"NOR,me,target);
        message_vision(HIR"\nȻ��$N�ʹ̳��˶���ʮ������"HIY"��"HIB"ʮ��"HIY"��"HIR"-------------------------------------------
\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
        message_vision(CYN "$N����һ���̳������еı仯�ѵ���������ѵ��˾�ͷ����ˮ�����ھ���������ȫ�ݽߡ�
$N����Ҳ�ѽ����ˡ����Ǿ�����ʱ��$N���еĽ���Ȼ�������������,��������Ȼȫ����ֹ��
���Ծ�ֹ��û�б仯��û������!��һ�������ģ�ֻ����!ֻ��"NOR+BLINK+BLU"������"NOR+CYN"����������һ�е��սᣬ����
�������ս�!��ˮǬ�ݣ��仯��������սᣬ��������!�����"NOR+BLINK+RED"������ʮ������"NOR+CYN"�����ľ���!�����
����������һ��!��һ����Ȼ�Ѿ���"HIR"��"BLINK+HIW"\tʮ\t��\t"NOR+HIR"��"NOR+CYN"��\n\n"NOR,me,target);
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
if( (int)me->query("bellicosity",1) < 10000 )
  {  msg = HIB "���е����������������ѱ�$N��һ����ȥ,$n���Ϻ�Ȼ¶���ֿ־�֮���ı��顣";
msg +=  "\n$N���۾����ȻҲ¶���ֿ־�֮���ı��飬����Զ��$n���־塣";
msg +=  "\nȻ��$N���������κ��˶��벻�����κ��˶��޷�������¡�$N��Ȼ��ת�˽��棬�����$N�Լ����ʺ�\n\n"NOR;
   message_vision(msg, me, target);
	//	me->receive_wound("kee",urkee+1000);
	//	me->receive_wound("kee",50);
              target->start_busy(3);
              me->start_busy(4);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"��"+me->name()+"����ɽׯ����[1;37m������ʮ�彣��[2;37;0m[1;35m��ɱ����. ʬ�����������˺ۣ�";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
       return 1;
  }
else
  {  msg = HIB "���е����������������ѱ�$N��һ����ȥ,$n���Ϻ�Ȼ¶���ֿ־�֮���ı��顣\n\n"NOR;
    message_vision(msg, me, target);
		target->die();
	//	me->receive_wound("kee",urkee+100);
              me->start_busy(1);
       return 1;
  }
        return 1;
}
