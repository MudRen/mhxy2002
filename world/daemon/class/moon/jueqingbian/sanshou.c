//By tianlin@Mhxy for 2001.12.30
 
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int j;
       string msg;
      int ap;
        if( !target ) target = offensive_target(me);
j = (int)me->query_skill("jueqingbian",1);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����������֡���\n");

        if(!me->is_fighting(target) )
                return notify_fail("�����������֡�ֻ����ս����ʹ��\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("�������������\n");

   if((int)me->query("force") < 500 )
     return notify_fail("����������㣡\n");

        if((int)me->query("sen") <50 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("jueqingbian",1) <120)
        return notify_fail("��ľ���޼��𻹲���ʩչ��һ�С����������֡�!!\n");
if((int)me->query_skill("moondance",1) <100)
        return notify_fail("�������������ȼ�����!!\n");
if((int)me->query_skill("moonforce",1)<100)
        return notify_fail("���԰���ķ��ȼ�̫��!!\n");
        if((int)me->query_skill("moonshentong",1) <120)
        return notify_fail("����¹��ɷ��ȼ�����!!\n");
      if( (string)me->query("gender") !="Ů��")
       return notify_fail("���Ϊ����֮��,����֪��Ů���ҵ���˼??\n");
  if(me->query("family/family_name") != "�¹�" )
return notify_fail("���������Ե,���򲻵��޷��ľ���!!\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

        ap = 2 + random(1);
     msg = HIC
"\n��������Ϊ����?ֱ������������!$N����һ�����,�޷���Ȼ����鶯�쳣!\n" NOR;
    message_vision(msg, me, target);

        if( (int)me->query_skill("jueqingbian",1) > 180)
{
        message_vision(HIW"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
        me->set_temp("JQB_perform", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
        me->set_temp("JQB_perform", 13);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIW"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
        me->set_temp("JQB_perform", 14);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
        me->set_temp("JQB_perform", 15);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIW"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
        me->set_temp("JQB_perform", 16);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
        me->set_temp("JQB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->start_busy(ap);
       } else {
      if( (int)me->query_skill("jueqingbian",1) > 150)
{
       message_vision(HIW"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 12);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(HIY"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 13);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(HIR"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 14);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(HIG"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 15);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->start_busy(2);
} else {
       message_vision(YEL"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 12);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(CYN"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 13);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(MAG"ˢ��һ��,$n����о���һ��΢��Ӷ��ߴ���\n"NOR,me,target);
       me->set_temp("JQB_perform", 14);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       me->start_busy(1);
}
}
        me->delete_temp("QJB_perform");
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        return 1;
}

