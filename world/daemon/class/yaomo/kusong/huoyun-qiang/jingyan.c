
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill;
        object weapon;
 	skill = me->query_skill("huoyun-qiang",1);
if( (string)me->query("class") !="bonze")
       return notify_fail("��֪����ô����,�������������ǹ��!!\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 	return notify_fail("����ֻ����ս���жԶ���ʹ�ã�\n");
 	if (skill< 100 ) 
 	return notify_fail("��Ļ���ǹ���ȼ�������\n");
        if (me->query("force")<800 )
              return notify_fail(" �����������,���ʩչ���о�ѧ? \n");
        weapon = me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "spear")
 		return notify_fail("����ʹ�õı������ԣ�\n");
 	me->add_temp("apply/attack",skill);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 	me->add_temp("apply/attack",-skill);
 	me->add("force",-200);
 	me->start_busy(1);
 	return 1;
}
