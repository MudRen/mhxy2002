#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;
    int skill;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
        return notify_fail(RED"װ��ǹ����ʹ�á���ǹ����\n"NOR);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail(HIW"��ֻ����ս����ʹ�á�\n"NOR);

    if ((int)me->query_skill("huoyun-qiang", 1) < 60 )
        return notify_fail(WHT"�����ǹ��������죬ʹ��������ǹ����\n"NOR);

      if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail(HIC"��һ��ʽ������ϻ�ħ�ķ�����ʹ�á�\n"HIC);
if(me->is_busy())
return notify_fail("��������æ�ţ���\n");

      if (me->query_skill_mapped("spells")!="pingtian-dafa")
                return notify_fail(HIC"��һ��ʽ�������ƽ��󷨲���ʹ�á�\n"NOR);

    if ((int)me->query_skill("huomoforce", 1) < 60 )
        return notify_fail(RED"��Ļ�ħ�ķ���򲻹���ʹ��������ǹ����\n"NOR);
    if ((int)me->query("max_force") < 600)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("force") < 600)
    {
        return notify_fail(HIC"�������������㣬���ܼ���ʹ�á���ǹ����\n"NOR);
    }
       skill = me->query_skill("huoyun-qiang",1);

message_vision(RED"\n$N��Ȼ���һ��: "BLINK+HIR"����ǹ�� \n"NOR,me,target);

    msg = RED "$N���ֳ�ǹ,ǹ�������һ����һ��Ѫ�齦��ǹͷ��������ǹ���ұ۴̳���һƬѪ��
��ס����Ѫ��ǹӰ��"+NOR"$n"+RED"�����Х��ȥ��\n"NOR;

   if((int)me->query_int()  > (int)target->query_int()/3 +random(5) ) {
damage=me->query_skill("huomoforce")/2 + me->query_skill("spear")/2 + me->
query_skill("huoyun-qiang")/2 + me->query("max_force")/2;
//           damage = skill - ((int)target->query("max_force")/50);
           if( damage > 0 ) {
msg += "$n"+CYN"��æ������ã���Ѫǹ֮�⼲����ֻ����ǰһ��Ѫ�죬ǹ��������£���Ѫ�ɽ��������󺿣�\n"NOR;
          me->add("force", -250); //ʹ��һ�μ�������ǰֵ250�� 
          me->start_busy(random(5));//�漴����5�����ڵ�busy
          target->receive_wound("kee", damage/2);//������Ѫ���˺� :P
     }
        }
else
msg += WHT"����"+NOR"$n"+WHT"������ã����Ų�æ�������$N��Ѫǹ��\n"NOR;
        me->start_busy(1);//�����е�Ŀ��Ҳ��1��busy  
  
      message_vision(msg, me, target);
        target->kill_ob(me);

        return 1;
}

 
 

  
