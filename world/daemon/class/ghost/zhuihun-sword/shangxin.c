//Cracked by Roath
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int mysen,tarsen,myspi,tarspi,myskill,tarskill,chance;
        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name") != "���޵ظ�" )
                return notify_fail("����˲��˱��˵��ģ�\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"+HIR"�������񽣡�"NOR+"��\n");
    
        if(!me->is_fighting())
                return notify_fail(HIR"�������񽣡�"NOR+"ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("zhuihun-sword", 1) < 100)
                return notify_fail("���׷�꽣���𻹲��������ܻ��������Σ�\n");

        if((int)me->query("renru") !=1)
                return notify_fail("�㻹û������"+WHT"������"NOR+"��Ҫ�죡\n");

        if((int)me->query("shanzijing") !=1)
                return notify_fail("�㻹ûѧ��"+WHT"ɽ�־�"NOR+"��\n");
        myskill= (int)me->query_skill("zhuihun-sword",1);
        tarskill=(int)target->query_skill("dodge",1);  
        mysen=(int)me->query("sen");
        tarsen=(int)target->query("sen");   
        myspi=(int)target->query("spi");
        tarspi=(int)target->query("spi");

        weapon=me->query_temp("weapon");
      message_vision(HIB"$N�Ϻ�һ����������Ӣ��Ϊ������������ŮΪ����������һ��\n\n"NOR+ HIB"  ��������"+HIR"������������>>\n"+HIR"             ����      ��      С      ����"NOR+HIB"��\n\n"NOR,me);
      message_vision(HIB"$N���е�"+weapon->name()+HIB"��Ϊһ֧�񲻿ɵ��ļ������ȥ������$n"NOR+HIB"���ķ���\n" NOR,me,target);        
      if (random(myskill*myspi)>random(tarskill*tarspi/2))
     {
      message_vision(HIB"�����һ������$n"NOR+HIB"��ǰ�أ���͸��$n"NOR+HIB"���ġ�\n"NOR,me,target);
      target->receive_damage("kee", mysen*2/3, me);
      target->receive_wound("kee", mysen*2/3, me);
       target->receive_damage("sen", mysen*2/3, me);
      COMBAT_D->report_status(target);
      me->receive_damage("kee", 100);
      me->add("force", -100);
      me->start_busy(1+random(2));
      return 1;
      }
      else
      {
       message_vision(HIC"û�뵽$n"+HIC"����ͻ��������һ�����������Ӷ��д�������$N����һ����\n"NOR,me,target);
       me->start_busy(2+random(3));
       return 1;
      }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }      
    //    return 1;
}
