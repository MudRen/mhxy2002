//by tianlin 2001.5.1
//�������Լ�������ĸ�perform,��Щ�����Ҵӱ�����ϳ�������.xixi
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;
	object weapon=me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��"HIY"����"NOR+HIC"����"NOR"��ֻ����ս���в���ʹ�á�\n");

	if( (int)me->query_skill("skyriver-rake", 1) < 40 ) 
	return notify_fail(HIB"�����Ӱҷ����𻹲�������!\n"NOR);

          if(me->query("family/family_name") != "����˧��" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"���Ѿ�������ļٶ�����!\n");

	message_vision(RED"$N����"RED+weapon->name()+RED"��$n����һ���ٶ�����
\n"NOR,me, target);

	mypot=(int)me->query_skill("rake");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

	time=(int)me->query_skill("skyriver-rake", 1) /5;
	if ( time > 15 ) time = 15;
	if ( time < 5  ) time = 5;

	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIC"$Nһʱ�ż���"BLINK+HIW"����"NOR+HIC".���ǽ���һ�����ȣ���һ��ʯͷ�����ˣ�\n"NOR,target);
		target->start_busy(time);
	}else {
	message_vision(HIY"����$N���������ͼ������Ĺ��ƺ�����ᣡ\n"NOR,target,
me);
                me->start_busy(1+random(3));
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}

