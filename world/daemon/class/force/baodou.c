//by tianlin 2001.8.1

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("force",1);

	if( skill > 250 ) {
		skill=250;
	}

        if( target != me ) 
		return notify_fail(""HIC"����"NOR"ֻ�ܸ��Լ�ʹ�á�\n");

   //     if( (int)me->query("force") < skill*2 )     
	//	return notify_fail("�������������\n");
        if((int)me->query("bellicosity") < 1000 )
                return notify_fail(HIY"���"NOR+HIR"ɱ��"NOR+HIY"�����Է����Լ���"HIC"������"NOR+HIY"��\n"NOR);
        if( (int)me->query_temp("baodou") ) 
		return notify_fail(HIC"���Ѿ���"BLINK+HIR"����"NOR+HIC"���ˡ�\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIC "
               "BLINK+HIR"."NOR+HIC" 
               |
           \   *  
          "BLINK+HIR"."NOR+HIC"  "NOR+HIY"* * *"NOR+HIC" "BLINK+HIR"."NOR+HIC"
         -=*  POP! *=-              
         "BLINK+HIR"."NOR+HIC"  "BLINK+HIR"."NOR+HIC""NOR+HIY"* * *"NOR+HIC"  "BLINK+HIR"."NOR+HIC"
              *  "BLINK+HIR".\
                                 
               "NOR+HIC"|"NOR""BLINK+HIR"."NOR+RED"\n $N����ȫ�������,"NOR+HIW"��"NOR+RED"��һ����$N����$N��������һƬ��⣬$N�о��Լ�ǿ׳�˺ܶ�!    \n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);
          me->add_temp("apply/damage", 200);
        me->add("bellicosity",- 1000);
        me->set_temp("baodou", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(1);//�趨��ս���е�busy��Ŀ,�������Ҹ�busy����Ϊ1

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
	me->add_temp("apply/strength", - amount);
        me->delete_temp("baodou");
          me->add_temp("apply/damage", - 200);
        me->add("bellicosity", amount*2 );
	// mon 3/1/98. move this to after powerup is done.
        tell_object(me, HIY"���"NOR+HIC"������"NOR+HIY"�Ѿ�������ϡ�\n"NOR);
}

