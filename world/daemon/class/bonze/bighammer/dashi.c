#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mydh, hisdh,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("bighammer",1) ;
	if ( extra < 120) return notify_fail("���[������]���������죡\n");
        if(me->query("family/family_name")!="�Ϻ�����ɽ")
                return notify_fail("���Ƿ��ŵ��Ӳ����á������ȡ���\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۴��ƽ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query("force") < 500 ) return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 ) return notify_fail("���޷����о�����\n");
        if((int)me->query("kee") < 200 ) return notify_fail("����Ѫ���㣡\n");
        if(me->query_temp("no_dashi")) return notify_fail("�㻹����Ϣ�ᣬ�Ȼ�����ðɣ�\n");
               me->add("force", -200);
             me->receive_damage("sen", 100);
             me->receive_damage("kee", 100+random(100));
	weapon = target->query_temp("weapon");
	mydh = (int)me->query("daoxing")*(int)me->query("max_mana");
	hisdh= random((int)target->query("daoxing")*((int)target->query("max_mana")+1));
	if(hisdh < mydh*4/5 )	

{
message_vision(HIR "\n$N"NOR+HIR"�����������з�ţ�$n"NOR+HIR"ֻ����һ�־޴��ѹ�����������\n" NOR,me,target);
 if (hisdh<mydh/3)
{
message_vision(HIR "\n$n"NOR+HIR"������ѹ��������Ҫ����һ�㣬��ʹ�ޱȣ��������һ����Ѫ��\n " NOR,me,target);
          damage=random((int)me->query("max_mana")/5);
         	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/2);
	 COMBAT_D->report_status(target);
}
           else if (hisdh<mydh/2)
{
message_vision(HIR "\n$n"NOR+HIR"���������򿹣����������һ����Ѫ��\n " NOR,me,target);
          damage=random((int)me->query("max_mana")/10);
         	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/2);
	 COMBAT_D->report_status(target);
}
           if (weapon)
{
message_vision(HIR "\n$n"NOR+HIR"�ۼ�������ȥ���������б���" NOR, me,target);
     weapon->unequip();
	if( weapon->unequip()) weapon->move(environment(target));
}
message_vision(
HIR "\n$n"NOR+HIR"��$N"NOR+HIR"�ķ𷨸л������ڵ��Ѿ��������Լ�����ս��֮�У�\n\n" NOR, me,target);
            damage=3+extra/20;
            if (damage>8) damage=8;
            target->start_busy(damage);
}
else {
message_vision(
HIB "\n$n"NOR+HIR"�����������ƻ�����ɾ��磡\n" NOR, me, target);
}
        me->start_busy(2);
        me->improve_skill("bighammer", 1, 1);
        me->set_temp("no_dashi",1);
        call_out("dashi_ok",5+random(2),me);
	return 1;
}
void dashi_ok(object me)
{
if (!me) return;
me->delete_temp("no_dashi");
}