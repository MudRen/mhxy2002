// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// pk_counter.c
// by mon. 9/22/97

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        object env=environment(me);
//        object room=load_object("/d/wiz/punish");
  //      object room2=load_object("/d/city/kezhan");

   if(env) {
//         if(env->query("short")=="����")
          me->apply_condition("no_pk_time", duration - 1);
  /*        else
         {
        tell_object(me,"��Ȼһ�����紵����ֻ�������޳��������������ܰ���\n");
        me->move("/d/wiz/punish");
         }
   */         }
   if( duration < 1 ) 
   {
/*           if(env->query("short")=="����")
                {
                 me->move("/d/city/kezhan");
                 tell_object(me,"���޳�����һЦ���´�С�ĵ㣡\n");
                 return 0;
                }
  */     return 0;
    }
   return CND_CONTINUE;
}
