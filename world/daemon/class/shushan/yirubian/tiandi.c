#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void snake_ok(object);
int perform(object me, object target)
{
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ͬ������\n");
        if(!me->is_fighting())
                return notify_fail("�����ͬ����ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");
          if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("yirubian", 1) < 100)
                return notify_fail("�������޲���������ʹ����һ�л������ѣ�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIR"\n$N���е�"+weapon->query("name")+HIR"���·����������ޱȱ��˵���������$n��ȥ\n"NOR,me,target);
me->set_temp("SS_perform", 7);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->delete_temp("SS_perform");
        me->receive_damage("sen", 50);
me->add("force", -50);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}
void snake_ok(object me)
{ if (!me) return;
      me->delete_temp("no_snake");
}