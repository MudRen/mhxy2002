//modified by vikee
//2000.9
//by tianlin 2001.9.2.�ֲ��޸�
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i,j;
	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�"HIY"��"NOR+HIR"��"NOR+HIW"��"NOR+HIR"��"NOR+HIM"��"NOR"����\n");

        if(!me->is_fighting())
                return notify_fail("��"HIY"��"NOR+HIR"��"NOR+HIW"��"NOR+HIR"��"NOR+HIM"��"NOR"��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail(HIC"�������������\n"NOR);

        if((int)me->query("kee") < 300 )
                return notify_fail(HIR"�����Ѫ���㣬û����ʩ���⹦��\n"NOR);

        if(me->query_temp("no_gthree"))  //�ڴ˴����ñ�־λ 
             return notify_fail("����ʹ���˾Ͳ����ˣ�"); 

        if((int)me->query_skill("zhuihun-sword", 1) < 50)
                return notify_fail("���"HIY"׷�꽣"NOR"���𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("kusang-bang", 1) < 50)
                return notify_fail("���"HIC"��ɥ��"NOR"���𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("���"HIR"�һ��"NOR"���𻹲�����ʹ����һ�л������ѣ�\n");

        weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
	}

	me->delete("env/brief_message");
	target->delete("env/brief_message");
//by tianlin 2001.9.2.�޸�
	message_vision(HIR"$N˫�ֻ�һ��Բ����Ȼ������٣�������������������������"NOR"��"HIY"��"NOR+HIR"��"NOR+HIW"��"NOR+HIR"��"NOR+HIM"��"NOR"��"NOR+HIR"���� !\n"NOR, me);
       message_vision(HIY"$N����:��ħ ���� ��С ���� ������� �� �� �� ��\n"NOR, me);
       me->set("HellZhen", 6);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
       message_vision(HIW"$N����:��а ���� ��˥ ��ħ �񡤹� �� �� �� �� ��\n"NOR, me);
	me->set("HellZhen", 7);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
       message_vision(HIM"$N����:���� �ˡ��� �ˡ��� �ˡ��� �ˡ��� �ˡ� ʽ ʽ �� �ˡ�\n"NOR, me);
	me->set("HellZhen", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete("HellZhen");

       if( i ) me->set("env/brief_message", 1);
       if( j ) target->set("env/brief_message", 1);

	me->receive_damage("kee", 100);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
