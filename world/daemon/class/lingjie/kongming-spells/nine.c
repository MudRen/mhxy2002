//�������� created by focus 2001.2.15

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   int damage,ap,dp,att,chance;
   string msg;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("��Ҫ��˭�á��������ԡ���\n");

   if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾������ԣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
   
   if(me->query("family/family_name")!="���")
     return notify_fail("��������ӣ��޷�ʹ��[��������]\n");

   if((int)me->query_skill("kongming-spells", 1) < 100 )
     return notify_fail("��Ŀ����ķ�����Ҫ������\n");

   if((int)me->query("mana") < 600+random((int)me->query("sen") ))
     return notify_fail("��ķ����������޷�ʹ�á��������ԡ���\n");

   if((int)me->query("force") < 600 )
     return notify_fail("��������������޷�ʹ�á��������ԡ���\n");

   if((int)me->query("sen") < 400 )
     return notify_fail("���������ǲ��壡\n");

   if((int)me->query("kee") < 400 )
     return notify_fail("����������������\n");

   message_vision(HIC"$N˫�ַɿ������ǰ����ſ����ֽᣬ[�١��������t�ߡ��ԡ����С��ڡ�ǰ]��ɲʱ������ѣ�$N����һ�������İ׹⣬����$n..��\n\n" NOR, me, target);

   att=(int)me->query("cps")+(int)me->query("ker");
   ap= me->query_skill("spells")+me->query_skill("kongming-spells")+me->query("daoxing")/2;
   ap =  ap*random(ap)/100;
   dp = target->query_skill("dodge")+target->query_skill("spells")+target->query("daoxing")/2;


   chance = (int)(random(ap + dp) * 120 / dp);

   if( chance > 20 ) 
   {
        damage=att*40 ;
        message_vision(HIM"ҫ�۵����������Ļ���$n����$n������Զ����Ѫ߿߿���ն�����\n\n" NOR, me, target);

     me->add("mana",-300);
     me->add("force",-300);
     me->receive_damage("sen",100);
     me->receive_damage("kee",100);
     target->receive_damage("kee",damage);
     target->receive_wound("kee", damage);
     me->start_busy(1+random(2));
     target->start_busy(1);
}
     else if ( chance > 10 ) 
     {
     damage=att*26;
     
     message_vision(HIB"$n�����۵������Χ��˲��$n�о����屻��հ㣬�������һ��Ѫ˿...\n\n"NOR, me, target);
        
     me->add("mana",-150);
     me->add("force",-150);
     me->receive_damage("sen",150);
     me->receive_damage("kee",150);
     target->receive_damage("kee",damage);
     target->receive_wound("kee", damage);
     me->start_busy(1+random(2));
     target->start_busy(1);
     } 
   else
     message_vision(HIW"$n��Ŀ���������֮�䣬���������⡣\n\n"NOR, me, target);
     me->start_busy(2);
     me->add("mana",-100);
     me->add("force",-100);
     me->receive_damage("sen",100);
     me->receive_damage("kee",100);

     return 1;
}
