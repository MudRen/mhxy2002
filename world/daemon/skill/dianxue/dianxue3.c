//by ephq

#include <ansi.h>
#include <dianxue.h>
inherit SSERVER;
void remove_xue(object tar);
int perform(object me, object target)
{
	string attack_skill,msg;
	int extra, dif, ap, dp, ap1, dp1, pp, app,dpp,t,power;
	object weapon;
	mapping data;

	extra = me->query_skill("dianxue",1) ;

	if ( extra < 100) return notify_fail("���[��Ѩ]���������죬���ϲ�׼��Ѩ��\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||!target->is_character() )
// 	|| target->is_fighting(me))
		return notify_fail("��Ҫ��˭��Ѩ��\n");

        if( target->query("channel/chat_block")>time()
        || target->query("channel/tell_block")>time() )
		return notify_fail(target->name()+"�Ѿ����ư��ˣ�\n");

        if((int)me->query("force") < 150 ) return notify_fail("����������㣡\n");
     	if(!valid_perform(me,target)) return 0;
               me->add("force", -100);

        me->receive_damage("sen", 50);

//        arg=xue[random(sizeof(xue))];


	data=type(me);
	if( data["type"]=="none" )
	return notify_fail("�����õı������ʺϵ�Ѩ��\n");

	dif=data["dif"]	;

       msg=HIC+"$N��Ϣ����";
       if( dif!=110 ) msg+="������ע"+me->query_temp("weapon")->name()+HIC+",";
       msg+="ȫ���ע�Ķ�ס$n����Ѩ��\n"+NOR+MAG+"ͻȻ��";
       if( dif!=110 ) msg+="����"+me->query_temp("weapon")->name()+"��";
       msg+=data["action"]+"$n����Ѩ"+data["type"]+"ȥ��\n\n"+NOR;

       message_vision(msg,me,target);

       ap=me->query("combat_exp");
       dp=target->query("combat_exp");
       ap1=me->query_skill("force");
       dp1=target->query_skill("force");
       pp=target->query_skill("dodge")+target->query_skill("parry");

       app=ap1*2+extra*40;
       dpp=dp1*2+pp*10;
       if( ((random(app+dpp)*dif/100 > dpp)) ||( ( random(ap+dp)>dp ) ) )
       {
       	msg=WHT+"�����$n����Ѩ��һ����"+data["type"]+"���ˣ���ʱ���齩Ӳ��˵����������\n"+NOR;
        target->set("channel/tell_block",time()+180);
        target->set("channel/chat_block",time()+180);
        target->set_temp("dianxue/xue3","��Ѩ");
       target->set_temp("xue3/name",me->name());
       power=extra+me->query("force_factor")*10+ap1;
       target->set_temp("xue3/power",power);
       target->start_call_out( (: call_other, __FILE__, "remove_xue", target :), 179);
       message_vision(msg,me,target);
       }
       else {
       	msg=HIY+"���ǣ�$n�ƺ�������������һ�У����ݵĶ㿪�ˡ�\n"+NOR;
       message_vision(msg,me,target);
       	me->start_busy(2);
//        COMBAT_D->do_attack(target,me, target->query_temp("weapon"));
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
        if( !tar->query_temp("dianxue/xue3") ) return;
        tell_object(tar, "���"+HBWHT+HIR+"��Ѩ"+NOR+"�������н⿪�ˡ�\n");
        tar->delete("channel/tell_block");
        tar->delete("channel/chat_block");
        tar->delete_temp("dianxue/xue3");
       return;
}