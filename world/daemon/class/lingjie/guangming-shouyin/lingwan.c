//link 2001.2.20
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("�����衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("guangming-force", 1) < 150 )
   return notify_fail("��Ĺ����ķ���򲻹���ʹ���������衹��\n");

    if( (int)me->query_skill("guangming-shouyin", 1) < 150 )
   return notify_fail("��Ĺ�����ӡ��������������ʹ�����衹��\n");

    if( (int)me->query_skill("fengtian-steps", 1) < 150 )
   return notify_fail("��ķ��������Ʋ���������������ʹ�����衹��\n");

    if( (int)me->query_skill("lingfan-san", 1) < 150 )
   return notify_fail("����������ɡ��������������ʹ�����衹��\n");

    if( (int)me->query_skill("libieyu", 1) < 150 )
   return notify_fail("�������𲻹�����������ʹ�����衹��\n");

    if( (int)me->query_skill("kongming-spells", 1) < 150 )
   return notify_fail("��Ŀ����鷨��������������ʹ�����衹��\n");

    if( (int)me->query("force") < 1000 )
   return notify_fail("���������Ϊ�������ߡ�\n");

    if(me->query("family/family_name")!="���")
                return notify_fail("��������ӣ��޷�ʹ�á����衹��\n");


    msg = HIW "
$N��ȫ��ÿ�����������ӿ������֮һ����Ϊ�������������ֱ��У���\n"NOR+HIC"
�ۿ����������ۣ����Ե�����ȴԽ��Խ�죬�����ľ�����$N�����������������ֱ�Ǹ�Ȼ���죬
��Ȼͬʱ��Ȼ�ı��ѿ����������ִ�������ʵ��һ��Ĺ���˺�ѿռ�����$n�񱼶�ȥ����\n"NOR;  
   if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2) { 
   me->start_busy(3);
   damage = ((int)me->query_skill("guangming-shouyin", 1))*2.5+(int)me->query_skill("guangming-force",1);
   damage = damage/2 + random(damage);
   target->receive_damage("kee", damage);
   target->receive_wound("kee", damage/random(5));
   me->add("force", -600);
   msg += HIR"
�������֮�£�$n���ϱ�$N����һ����ھ�˲�����ɣ����ɹ����Ȼ�Ļ�����$n�����ϡ�\n"NOR;
    } else
    {
       me->start_busy(2);
       msg += HIY"����$p������$P����ͼ�����������һ��,����Ҳ����һ���亹��\n"NOR;
    }
 message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
