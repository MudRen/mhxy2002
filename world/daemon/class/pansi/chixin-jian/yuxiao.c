//by swagger skyer
//by 03/01/2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg , str;
 int extra,lvl,lv;
 int i;
 object weapon;
 
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
        return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 if (me->query_temp("fenghuang_busy")) return notify_fail("���ϵ��һ���������!\n");
                    if( (int)me->query("force") <= 1000 )
        return notify_fail("����������������ʹ��������\n");

 extra = me->query_skill("chixin-jian",1) / 2;
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg = HIW  "������Ʈ����һ�ֵ���������......\n\n                           ɲ�Ǽ�,�ۺ�ɫ��"HIM""BLINK"�һ�"NOR""HIW"Ʈ����$N��$n����Χ!" NOR;
        message_vision(msg, me, target);
 msg =  HIC "\n\n$N���齣��,üĿ��������ǧ��Թ����"HIR"���ҵ������У�ֻ�г�ޣ�ֻ��ɱ�˺ͱ�ɱ��"HIC"��\n" NOR;
        message_vision(msg, me, target);
 msg =  HIC "\n$N����δ��,�����м�͸��һ˿ɱ����"HIC"��\n" NOR;
        message_vision(msg, me, target);
 msg =  HIW"\n                ��"HIM"�� �� �� ��  "HIC""BLINK"��"NOR""HIM"  �� �� �� ��"HIM"��\n" NOR;
        message_vision(msg, me, target);
lvl=extra/20;
if(lvl>4) lvl =4;
for(i=0;i<=lvl;i++)
 {
 msg = HIY "$N�̳�һ����\n" NOR;
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
 message_vision(msg,me,target);
           if (target->query("eff_kee")<0 || !living(target) )  
                       {str="��˵"+target->name()+"��"+me->name()+"����˿����ѧ"HIY"�������"HIM"��ȥ�����޵ظ���"+target->name()+"����ǰ���ϻ������������ᣡ"NOR;
             message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
}
}
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->add("force", -200);
 msg =  HIY "\n$N����һ�գ�����̾�����������"HIM""BLINK"�һ�"NOR""HIY"����......����......��\n" NOR;
        message_vision(msg, me, target);
me->start_busy(1);
 me->set_temp("fenghuang_busy",1);
 call_out("remove_effect",3+random(8),me);
return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("fenghuang_busy");
}


