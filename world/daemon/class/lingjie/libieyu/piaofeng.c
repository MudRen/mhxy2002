//����Ʈ�� From focus 2001.2.18

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{  
   int damage, ap, ap1, dp, dp1, fei, chance;
   string msg;
   object weapon;
   object ob;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("��Ҫ��˭�á�����Ʈ�硹��\n");

   if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷���Ʈ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if((int)me->query_skill("libieyu", 1) < 180 )
     return notify_fail("���������ַ�����Ҫ��������\n");

   if((int)me->query("force") < 1000)
     return notify_fail("��������������޷�ʹ�á�����Ʈ�硹��\n");

   if((int)me->query("mana") < 1000)
     return notify_fail("��ķ����������޷�ʹ�á�����Ʈ�硹��\n");

   if(me->query("family/family_name")!="���")
     return notify_fail("��������ӣ��޷�ʹ�á�����Ʈ�硹��\n");
   
   if((int)me->query("kee") < 500 )
     return notify_fail("�������������޷�ʹ��[����Ʈ��]��\n");

   if((int)me->query("sen") < 500 )
     return notify_fail("�㾫�񲻹����޷�ʹ��[����Ʈ��]��\n");

   if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "yumao")
     return notify_fail("������Ʈ�硹��������ë����ʩչ��\n");

   fei=(int)random((int)me->query("bellicosity")/60)+(int)me->querya("cor")+(int)me->query("cps");
   
   message_vision(HIC"$N��ȻһЦ�����ˡ�����Ť�������󡢳��֡����𡢱�ɢ�����������\n\n" NOR, me, target);
   ap = (int)me->query("combat_exp")+(int)me->query("daoxing");
   ap1= (int)me->query_skill("libieyu")+(int)me->query_skill("yumao")+(int)me->query_skill("dodge");

   dp=((int)target->query("combat_exp"))*4/5+((int)target->query("daoxing"))*4/5;
   dp1 = ((int)target->query_skill("dodge")+(int)target->query_skill("parry")+(int)target->query_skill("unarmed"))*9/10;

   chance=(int)random(((ap/dp)*100)+((ap1/(dp1))*100));
   if(chance > 190)
   {
     message_vision(HIM "����ӭ�磬��ʫ���Σ��������Ʈ�裬�紺�������$n���ˣ������ǲ���˼�ǵĴ����У�\n"NOR + 
                    HIR"�����У��������������$n��ü��\n\n" NOR, me,target);
     me->add("mana",-100);
     me->add("force",-100);
     me->receive_damage("sen",200);
     me->receive_damage("kee",200);

     target->receive_damage("sen",target->query("max_sen")+1,me);
     target->receive_wound("sen", (int)target->query("max_sen")+1, me);
     target->receive_damage("kee",target->query("max_kee")+1,me);
     target->receive_wound("kee", (int)target->query("max_kee")+1, me);
     COMBAT_D->report_status(target);
     target->heart_beat();
}
   else if( chance > 15 ) 
   {
     
     damage=fei*30;
     target->receive_damage("kee",damage);
     target->receive_wound("kee", damage*2/3);
     target->receive_damage("sen",damage);
     target->receive_wound("sen",damage*2/3);
     
     message_vision(HIC"����ķ����У������������$n���ؿ�....\n\n" NOR, me, target);
     
     me->add("mana",-150);
     me->add("force",-150);
     me->receive_damage("sen",100);
     me->receive_damage("kee",100);
     me->start_busy(2+random(2));
}
     else if (chance>random(3)) 
     {
     damage=fei*20+random(fei*10);
     target->receive_damage("kee",damage);
     target->receive_wound("kee",damage/2);     
     
     message_vision(HIB"�������Ʈ�������ķ���$n������ãȻ�У�Ʈ���Ѳ���$nȫ��...\n\n"NOR, me, target);
        
     me->add("mana",-110);
     me->add("force",-110);
     me->receive_damage("sen",80);
     me->receive_damage("kee",80);
     me->start_busy(1+random(2));
     } 
   else
     message_vision(HIW"$n��Ŀ���������֮�䣬���������⡣\n\n"NOR, me, target);
     me->start_busy(2+random(1));
     me->add("mana",-100);
     me->add("force",-100);
     me->receive_damage("sen",100);
     me->receive_damage("kee",100);
     return 1;
}
