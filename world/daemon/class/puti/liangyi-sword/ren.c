// ren.c  ���ǽ��������ͬ�ʡ�
//by tianlin 2001.8.10�޸�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    object weapon;
    string msg;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʲô��Ц��ûװ��������ʹ"HIC"�����ͬ�ʡ�"NOR"��\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail(""HIC"�����ͬ�ʡ�"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("liangyi-sword", 1) < 60 )
        return notify_fail("�����ǽ���������죬ʹ����"HIC"�����ͬ�ʡ�"NOR"��\n");
    if ((int)me->query_skill("wuxiangforce", 1) < 90 )
        return notify_fail("���С���๦��򲻹���ʹ����"HIC"�����ͬ�ʡ�"NOR"��\n");
    if ((int)me->query("max_force")<400)
        return notify_fail("��������Ϊ���㣬�޷�����������\n");
    if ((int)me->query("force")<200)
    {
        return notify_fail("����������������û�ܽ������ͬ�ʡ�ʹ�꣡\n");
    } 
    message_vision(HIC "$N���г�����âԾ�������Ⱪ������������ƺ������Ҵ���$N�ĵ��ˣ�\n"NOR,me);
    message_vision(HIC"����������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR,me);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      if(!target->is_fighting(me)) target->fight_ob(me);
	me->start_busy(1);
    return 1;
}
