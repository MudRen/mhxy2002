// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭���⡸"HIB"����"NOR+YEL"����"NOR"����\n");

        if(!me->is_fighting())
        return notify_fail("��"HIB"����"NOR+YEL"����"NOR"��ֻ����ս����ʵ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

   if((int)me->query("force") < 500 )
     return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("kugu-blade",1) < 100)
        return notify_fail("��Ŀݹǵ���û����\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIB"
$N��������ʹ����"HIW"���ݹǵ������������"HIB"��������ݵ�һ�У�ֱ����$n
��ʱ����������ع�Ҳɭɭ���������������$N�ޱȷ����ĵ��⽣Ӱ֮��$n
��ʱ�������Ʈҡ֮�䣬$Nǿ��ĵ�����$n����������������ʮ���Ǳ���
"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 


        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

me->start_busy(1+random(2));
}