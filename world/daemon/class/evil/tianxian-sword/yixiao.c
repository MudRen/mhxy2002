// created by ken   2001.3.9
#include <ansi.h>

inherit SSERVER;

void free(object target);
int perform(object me, object target)
{
       object weapon;
       int ap, ap1, ap2, dp, dp1, dp2, kaee, kkee, damage;
       if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("�����˭�ý���һЦ��\n");

        if(!me->is_fighting())
                return notify_fail("��ɲ��ǿ���Ц��.\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("������������ˡ�\n");

        if((int)me->query("mana") < 1000 )
                return notify_fail("��ķ������㣡\n");
        if((int)me->query("force") < 1500 )
                return notify_fail("�������������\n");

        if((int)me->query("max_mana") < 1000 )
                return notify_fail("��ķ������㣡\n");

        if( (int)me->query_skill("tianxian-sword", 1) < 150)
                return notify_fail("������ɽ�����Ϊ�в��������޷�ʩչ��ô�������书��\n");
        if( (int)me->query_skill("evil-force", 1) < 150)
                return notify_fail("���ħ����򲻵���С���߻���ħ�ˡ�\n");
        if( (int)me->query_skill("sword", 1) < 150)
                return notify_fail("��Ľ���������ǳ�����Ǳ�����Ϊ�á�\n");

  message_vision(HIW "$N��Цһ����"+(me->query_temp("weapon"))->name()+"����һ�����磬�����Ļ���$n��\n\n" NOR,me,target,);
       ap = (int)me->query("combat_exp");
       ap1 = 
   (int)me->query_skill("sword")+(int)me->query_skill("evil-force")+(int)me->query_skill("tianxian-sword");  
       ap2 = me->query("mana")+me->query("force") ;
       dp = (int)target->query("combat_exp");
       dp1 = target->query("mana")+target->query("force") ;
       dp2 = (int)target->query_skill("parry")+(int)target->query_skill("dodge");

       if (random(ap+dp) > dp)
   {
                message_vision(HIW "ֻ������һ�����һ����û��������$n���⾪��һ���Ŵ��ˣ����ѱ�"+(me->query_temp("weapon"))->name()+"�ó��Ľ�â���������\n"
NOR,me,target,);

             me->add("force",-500);
             me->add("mana",-500);
             damage=random(100+100+ap1+ap2);
             if(damage<1) damage=random(ap1);
             if(damage>1200) damage=random(1400);
             if(target->query("force")<500) {target->set("force",0);}
             else {target->add("force",-random(500));}
             target->receive_wound("kee", damage, me);
//           target->receive_wound("sen", damage, me);
//           ���˾���
             COMBAT_D->report_status(target);
             me->start_busy(random(3));

}
         else {
             message_vision(BLU "$nƾ�������ѧ,���ڳŹ���$N���⾪�춯�ص�һʽ��ѧ,ȴҲ���Ǳ�������\n" NOR,me,target,);  
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             me->start_busy(3);
        }
        return 1;
}