#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "ͻȻ�е�һ�����䡣\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ��̹ǵ��溮Ϯ�������еı��Ǻ��������ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",
            environment(me), me);
   }
       me->receive_damage("kee",50);
        me->add("kee",-110);
      me->apply_condition("bp_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
