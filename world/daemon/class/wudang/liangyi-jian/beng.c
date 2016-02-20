//by nina
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{
        int mypot,tapot;
        object weapon, weapon2;
        string msg;
        me->clean_up_enemy();
        target = me->select_opponent(); 
        if( !me->is_fighting() )
                return notify_fail("���ǽ����ġ������־�ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("force") < 500 )
                return notify_fail("�������������\n");

        if(me->query("family/family_name") != "����ɽ���Ƕ�" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á������־�?\n");

        
        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û���ñ��У����ò��ˡ������־���\n");

        if( (int)me->query_skill("liangyi-jian",1) < 100 )
                return notify_fail("������ǽ����������ң��޷�ʹ�á������־���\n");

        msg = HIC "$N��ס���Σ�����������ʹ�����ǽ����еġ������־�\n" NOR;
        message_vision(msg, me);

        mypot=(int)me->query_skill("sword");
        mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

        if ( random( mypot + tapot ) > tapot ) 
                {
                        msg = HIW"$nֻ���û��ھ�ʹ������";
                        msg += weapon2->name();
                        msg += "��ʱ����ס���ַ��˳�ȥ��\n" NOR;
                        me->add("force", -200);
                        target->start_busy(4);
                        weapon2->move(environment(me));
                }

        else    {
                        me->add("force",-100);
                        msg = HIY"����$n������$N����ͼ���������ϼӾ�����" + weapon2->name() + "��������һ����\n˫�����е�����һ��,�������ķ���һ�����죡\n"NOR;
                        me->start_busy(2);
                }
        message_vision(msg, me, target);
        return 1;
}