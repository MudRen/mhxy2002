// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int damage,dui,ap,dp,hai,ap1,dp1;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۹�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if((int)me->query_skill("xiaofeng-sword", 1) < 60 )
     return notify_fail("���[������½�]����Ҫ��������\n");

   if((int)me->query("force") < 400)
     return notify_fail("��������������޷�ʹ�á�������硹��\n");

   if((int)me->query("mana") < 400)
     return notify_fail("��ķ����������޷�ʹ�á�������硹��\n");

   if(me->query("family/family_name")!="��ׯ��")
     return notify_fail("�����ׯ���ӣ��޷�ʹ�á�������硹��\n");
   
   if((int)me->query("kee") < 400 )
     return notify_fail("�������������޷�ʹ��[�������]��\n");

   if((int)me->query("sen") < 400 )
     return notify_fail("�㾫�񲻹����޷�ʹ��[�������]��\n");

	weapon = me->query_temp("weapon");
	hai= (int)me->query("kar");

        ap=(int)(me->query_skill("sword")/10)+(int)(me->query_skill("dodge")/10)+(int)me->query("spi");
        dp=(int)(target->query_skill("parry")/10)+(int)(target->query_skill("dodge")/10);
        ap1=(int)((me->query("combat_exp")/100)*ap);
        dp1=(int)((target->query("combat_exp")/100)*dp) + 1;
   
        dui=(int)(random(ap1/dp1)*100); 

   if (dui>60) {
	msg = HIC"$N���е�"+ weapon->name() + HIC"����������ǣ�һ���׹�����������$n\n"NOR;
        message_vision(msg, me, target);
        damage=hai*50;
	target->receive_damage("kee",damage);
	me->receive_damage("sen",50);
        me->add("force",-150);
        me->add("mana",-150);
	me->start_busy(1+random(2));
        target->start_busy(random(2));
}
  else if(dui>40) {

	msg = HIM"$N���е�"+ weapon->name() + HIM"����һ�����ߣ�����$n���ؿ�..\n"NOR;
        message_vision(msg, me, target);
        damage=hai*30;
	target->receive_damage("kee",damage);
	me->receive_damage("sen",50);
        me->add("force",-150);
        me->add("mana",-150);
	me->start_busy(random(2));
        target->start_busy(random(2));
}
   else
        msg = HIB"$n�����շ����ѵ�����\n"NOR;

        message_vision(msg, me, target);
        me->start_busy(2);
        me->receive_damage("sen",100);
        me->add("mana",-100);
        me->set_temp("lx_busy",1);
        call_out("remove_effect",3+random(5),me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("lx_busy");
}