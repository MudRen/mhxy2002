// mhsj@gslxz /2001/7/25
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        string classname;
        classname = me->query("family/family_name");
        if(classname!="���")
                return notify_fail(WHT"ֻ������ĵ��Ӳ��ܹ�ʹ��"RED"[�ѹǶ���צ]"NOR+WHT"��\n"NOR);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(RED"���ѹǶ���צ��"WHT"ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if (me->query_temp("weapon")||me->query_temp("second_weapon"))
                return notify_fail("���ֲ���ʹ��[�ѹǶ���צ].\n");
                
        if( (int)me->query_skill("sougu-zhua", 1) < 100 )
                return notify_fail("����ѹ�צ������죬����ʹ�á��ѹǶ���צ����\n");
                                        
        if( (int)me->query("force", 1) < 500 )
                return notify_fail("����������̫��������ʹ�á��ѹǶ���צ����\n");
                        
        msg = CYN"ֻ��$N�����������˵�˫���ϣ�����$n"NOR+CYN"��������һ��,\n$n"NOR+CYN"��ʧɫ����$N������"NOR+RED"[�ѹǶ���צ]"CYN"�Ż��ˡ�\n"NOR;

        if(random(me->query_skill("force")) >target->query_skill("force")/5)
        {
                target->start_busy((int)me->query_skill("six_finger")/40 +1);
                
                damage = 100+(int)me->query_skill("tianpeng-force", 1);
                damage = damage +  (int)me->query_skill("xbuddhism", 1);
                damage = damage +  (int)me->query_skill("sougu-zhua", 1);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/1);
                me->add("force", -500);
                msg += RED"һ˲�䣬����Ѫ����$n"RED"���ϳ��֣���Ѫ������ӿ��������\n"NOR;
                me->start_busy(1);

        } else 
        {
                target->start_busy(1+random(1));
                msg += CYN"$n"NOR+CYN"��ʱ��æ���ң��Ǳ�������\n"NOR;
                me->add("force", -200);
                me->start_busy(1);
        }
        message_vision(msg, me, target);

        return 1;
}

