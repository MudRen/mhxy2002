//����������ӡ
//created by focus 2001.2.10
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,att,damage;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�в���������ӡ��\n");

        if(!me->is_fighting())
                return notify_fail("����������ӡֻ����ս����ʹ�ã�\n");
        
        if(me->query("family/family_name")!= "���")
                return notify_fail("���������飬����ʹ�ò���������ӡ��\n");

        if((int)me->query("force") < 600 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("guangming-shouyin", 1) < 50)
                return notify_fail("��Ĳ���������ӡ���𻹲�����ʹ����һ�л������ѣ�\n");
 
        if(me->query_temp("shouyin_busy")) return notify_fail("����̹����Ա����䣬���ǵȻ����̰�..\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        
        message_vision(HIW"\n$N�ĳ����Ա����䣬����Ĭ�̣����������ħ�ڣ������δϢҮ�������ο����ϰ���\n"NOR+
                       HIM"����Ϊ���ո���ϰ����������ڣ����ջ���������������������Ժ����������������\n"NOR+
                       HIC"�������˭����...\n"NOR, me);

        ap=(int)me->query("combat_exp")+(int)me->query_skill("unarmed")+(int)me->query_skill("guangming-shouyin")/3;
        dp=(int)target->query("combat_exp")+(int)me->query_skill("parry");
        att=(int)me->query("spi")+random((int)me->query_skill("spells")/10);

        if (random(ap)>dp*2/5)
{
        damage=random(att*30);

        message_vision(MAG"$N�����ڵ�����������ս�ġ�������֡���̥�ؽ�ġ���������������ڡ���\n"+"�����ġ�ǧ�ָ���ӡ������$n...\n"NOR+HIR"��$n������Զ.....\n"NOR,me,target);

        me->start_busy(2);
        target->receive_damage("kee",damage);
        target->receive_wound("kee",damage*2/3);
        target->start_busy(random(2));
        me->receive_damage("kee",100);
        me->add("force",-200);
//        me->set_temp("pfm_shouyin",1);
}
        else 
{
        message_vision(HIW"\n$n��֮�£����������������ѳ���ӡ�İ�Χ��ȴҲ����һ���亹\n"NOR,me,target);
        me->start_busy(1+random(3));
        target->start_busy(random(2));
}

      me->set_temp("shouyin_busy",1);
      call_out("remove_effect",4+random(3),me);
return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("shouyin_busy");
}
