// ill_liji.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "���������Ųλ�����Ŷ��ӵ����Ҳ������������ǵ��������ˡ�\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ķ������ܼ��ˣ�ֱ���ϲ�����\n" NOR );
      message("vision", me->name() + "���Ŷ��ӵ����Ҳ����������ǵ��������ˡ�\n",
            environment(me), me);
   }
   me->receive_wound("kee", 2);
   me->receive_damage("kee", 2);
   me->apply_condition("ill_liji", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
