//by ephq
inherit SSERVER;
#include <ansi.h>
#include <xue.h>
#include <dianxue.h>


void remove_xue(object tar);
int perform(object me, object target)
{
	string arg,attack_skill,msg;
	int extra, dif, ap, dp, ap1, dp1, pp, app,dpp,t,power;
	object weapon;
	mapping data;

	extra = me->query_skill("dianxue",1) ;

	if ( extra < 75) return notify_fail("���[��Ѩ]���������죬�ϲ�׼���Ѩ����\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||!target->is_character() )
// 	|| target->is_fighting(me))
		return notify_fail("��Ҫ��˭�����С�\n");

        if( target->is_busy() )
		return notify_fail("�Է���æ���أ��αس���֮Σ�أ�\n");

        if((int)me->query("force") < 150 ) return notify_fail("����������㣡\n");
     	if(!valid_perform(me,target)) return 0;
               me->add("force", -100);


     	
        me->receive_damage("sen", 50);

        arg=xue[random(sizeof(xue))];


	data=type(me);
	if( data["type"]=="none" )
	return notify_fail("�����õı������ʺϵ�Ѩ��\n");


	dif=data["dif"]	;

       msg=HIC+"$N��Ϣ����";
       if( dif!=110 ) msg+="������ע"+me->query_temp("weapon")->name()+HIC+",";
       msg+="ȫ���ע�Ķ�ס$n��ȫ��Ѩ����\n"+NOR+MAG+"ͻȻ��";
       if( dif!=110 ) msg+="����"+me->query_temp("weapon")->name()+"��";
       msg+=data["action"]+"$n��"+HBWHT+HIR+arg+NOR+MAG+data["type"]+"ȥ��\n\n"+NOR;

       message_vision(msg,me,target);

       ap=me->query("combat_exp");
       dp=target->query("combat_exp");
       ap1=me->query_skill("force");
       dp1=target->query_skill("force");
       pp=target->query_skill("dodge")+target->query_skill("parry");

       app=ap1*2+extra*40;
       dpp=dp1*2+pp*10;
       if( ((random(app+dpp)*dif/100 > dpp) && random(4)>1) ||( ( random(ap)>(dp*2/3) ) && random(4)>1 ) )
       {
       	msg=WHT+"�����$n��"+HBWHT+HIR+arg+NOR+WHT"��һ����"+data["type"]+"���ˣ���ʱȫ����ԣ��������á�\n"+NOR;
       	t=extra/20;
       	if( t>8 ) t=8;
       	if( t<3) t=3;
       target->start_busy(t+1);
       target->set_temp("dianxue/xue1",arg);
       target->set_temp("xue1/name",me->name());
       power=extra+me->query("force_factor")*10+ap1;
       target->set_temp("xue1/power",power);
       target->start_call_out( (: call_other, __FILE__, "remove_xue", target :), t);
       message_vision(msg,me,target);
       }
       else {
       	msg=HIG+"���ǣ�$n���з���������΢ת�����˿�����ȴ���㲻�����͵Ĺ���һ�С�\n"+NOR;
       message_vision(msg,me,target);
       	me->start_busy(2);
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"));
       	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->fight_ob(target);
        }
	return 1;
}

void remove_xue(object tar)
{
        if(!tar) return;
        if( !tar->query_temp("dianxue/xue1") ) return;
        tell_object(tar, "���"+HBWHT+HIR+tar->query_temp("dianxue/xue1")+NOR+"�������н⿪�ˡ�\n");
        tar->delete_temp("dianxue/xue1");
        tar->stop_busy();
       return;
}
