#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 80 )
                return notify_fail("��ķ��������ˣ�����ʹ�û���\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����޷����У�\n");
        message_vision(HIC"$N��Ȼ���һ�����������˹������Ӷ��˼��������������ȥ����\n"NOR, me);

   if(me->is_fighting() ) {
   if(random((int)me->query("max_mana")+10) >((int)target->query("max_mana")+10)/2) {

message_vision(HIC"ֻ����һ��������$N��ʱ�������������ڿ��У��ֳ�Хһ�����򶫺���ȥ��\n"NOR, me);
me->receive_damage("sen", 80);
me->add("mana", -80);
me->move("/d/sea/yujie2");
me->start_busy(1);
   message_vision(HIC"��¡�������У�һ������������צ�Ĵӿն��£��͵�һ���������ɸ����Ρ�\n��ϸһ������Ȼ��$N��\n"NOR,me);
   }
   else
message_vision("ȴΪ$n�ķ����������Ѳ�����\n", me, target);
me->receive_damage("sen", 40);
me->add("mana", -40);
   }
   if(!me->is_fighting() ){

message_vision(HIC"ֻ����һ��������$N��ʱ�������������ڿ��У��ֳ�Хһ�����򶫺���ȥ��\n"NOR, me);
   me->receive_damage("sen", 80);
   me->add("mana", -80);
   me->move("/d/sea/yujie2");
   message_vision(HIC"��¡�������У�һ������������צ�Ĵӿն��£��͵�һ���������ɸ����Ρ�\n��ϸһ������Ȼ��$N��\n"NOR,me);
   me->start_busy(1);
   }
        return 5+random(5);
}

