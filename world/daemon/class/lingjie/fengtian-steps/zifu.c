//�ϸ�
//created by focus

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int shu, mepo, tarpo;
        
        if(me->is_busy())
                return notify_fail("������û�գ���\n");

        shu = me->query_skill("fengtian-steps",1) ;
        if ( shu < 80) return notify_fail("���[���������Ʋ�]������������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ϸ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query("force") < 400 ) return notify_fail("����������㣬�޷�ʹ���ϸ���\n");
        if((int)me->query("mana") < 400 ) return notify_fail("�㷨�����㣬�޷�ʹ���ϸ���\n");
        if((int)me->query("sen") < 400) return notify_fail("��ľ������㣬�޷�ʹ���ϸ���\n");
        if (me->query("family/family_name")!="���") return notify_fail("��������ӣ�����ʹ���ϸ�! \n");
        if(me->query_temp("zifu_busy")) return notify_fail("����ù��ϸ������µȻ����ð�..\n");
        
        mepo = (int)me->query("combat_exp")+(int)me->query_skill("dodge")+(int)me->query_skill("fengtian-steps");
        mepo = mepo + (int)me->query("mana");
        
        tarpo = (int)target->query("combat_exp")+(int)me->query_skill("dodge");
        tarpo = tarpo + (int)target->query("mana");

        if(random(mepo) > tarpo/2)
 {
        message_vision(
        HIM "\n\n$N���ն��𣬾���һ�ɹɵ��������ƣ���$n�����Ĺ�ס.....\n\n" NOR, me,target);

        target->start_busy(8+random(5));
        me->add("force", -300);
        me->receive_damage("sen", 250);
}
else {
       message_vision(
       HIB "\n$n���о���������ƮȻ�����ȥ......\n" NOR, me, target);

       me->start_busy(random(3));
       me->receive_damage("sen",100);
     }
       me->set_temp("zifu_busy",1);
       call_out("zifu_busy",5+random(3),me);
       return 1;
}

void zifu_busy(object me) {
      if (!me) return;
      me->delete_temp("zifu_busy");
}
