#include <ansi.h>

inherit SSERVER;

 int cast(object me, object target)
{
   string msg;
   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
    return notify_fail("��Ҫ��˭ʩչ������\n");
  
  if( me->query("spell_shushan_on") != 1 )
  return notify_fail("�㻹δ������ɽ�ɵ��洫��\n");
  
   if(living(target) )
  return notify_fail(target->name() + "���ں����ѡ�\n"); 

  if((int)me->query("mana") < 10 )
     return notify_fail("��ķ���������\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("���������ǲ��壬����ʩչ�ⷨ����\n");

   me->add("mana", -10);
   me->receive_damage("sen", 10);

   if( random(me->query("max_mana")) < 25 ) 
   {
     write("�ף���һ�κ����顣\n");
     return 1;
   }
  message_vision (HIW "$N����ԣ�������$nһָ�����һ������$n���𣬸�����ʱ����\n" NOR, me, target);
  target->remove_call_out("revive");
  target->revive();
  //target->reincarnate();
  message_vision (HIW "$n�����ϥ���ӵ���һԾ����\n" NOR, me, target);
  return 1;
}