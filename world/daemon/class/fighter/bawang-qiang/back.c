// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
  string msg=" ";
        object weapon;
  int damage, ap, dp, point;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        return notify_fail("��Ҫ��˭ʩչ������ǹ����\n");


        if(!me->is_fighting())
             return notify_fail("������ǹ��ֻ����ս����ʹ�ã�\n");

    if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");

  if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

      if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

  i=(int)me->query_skill("bawang-qiang",1)+(int)me->query_kar();

    if( i < 20)
            return notify_fail("��İ���ǹ���𻹲�����ʹ����һ���˼����׾ͻῴ������\n");

msg=(HIY"\n$N����ͷ���Լ�����ת����ǹ���ܣ�һ���ܻ�һ�ߴ�У����������үү�����㶷�ˣ�\n\n"NOR);

        ap = me->query_skill("bawang-qiang");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_force") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_force") / 10 +
random((int)target->query("eff_sen") / 5);
         damage +=(int)me->query("force_factor")-random((int)target->query("force_factor"));
                if( damage > 0 ) {
     damage +=random((damage*(int)me->query_skill("bawang-qiang"))/100);
  msg += HIR "$n���һ���������ߣ�˵�շ����׷��\n$N��$n�ϵ���ͻȻ���״��һ��������ǹ��\n$n�ߺ������ã��ϵ��ˡ���ȴû�ж㿪������һ���������ˡ�\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("bawang-qiang", 1, 1);
                }
       else {
 msg += HIR "$n�����Ц��С�������������ֻ���ƭ�ң�\n$n˵�շ�����ǰ����$N����ʱ�����˽�����\n���$Nȴû�ϵ����б�ʶ�ƣ���������һ�����ˡ�\n" NOR;
        COMBAT_D->do_attack(target, me, target->query_temp("weapon"));

 /*    damage -= (int)target->query("force_factor");
     damage -=random((-damage*(int)target->query_skill("dodge"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/4, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
                        me->improve_skill("bingpo-blade", 1, 1);
*/
       }
             }
   else
   msg +=HIC "$n���һ���������ߣ�˵�շ����׷��\n$N��$n�ϵ���ͻȻ���״��һ��������ǹ��\n$n�ߺ������ã��ϵ��ˡ����Ƿ�����˹�ȥ��\n"NOR;

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->kill_ob(target);
        }
point=me->query("force_factor")+150;
me->add("force",-point);
me->add("sen",random(100));

        me->start_busy(1+random(3));
        return 1;
}
