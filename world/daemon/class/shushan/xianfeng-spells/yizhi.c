//Ǭ��һ�� for shushan by LitChi 5/30/2001

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int damage, ap, dp, s_num, chance;
   object coin, coin2;
   int amount = 10000;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("��Ҫ��˭ʩ��Ǭ��һ������\n");

   if((int)me->query_skill("xianfeng-spells", 1) < 200 )
     return notify_fail("����ɷ���������򲻹���������ʹ�á�Ǭ��һ������\n");

   if((int)me->query("mana") < 500+(int)me->query("mana_factor") )
     return notify_fail("��ķ�����������Ǭ��һ��������ûʲô���ã�\n");

   if((int)me->query("force") < 400 )
     return notify_fail("��������������޷�����Ǭ��һ�������ӳ�����\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("���������ǲ��壡\n");

   if( !objectp(coin = present("coin", me)) )
     return notify_fail("���Ѿ�û��Ǯ�ˣ����ʹ��Ǭ��һ����\n");
   
   if(coin->query_amount() < amount) {
        amount = coin->query_amount();
        destruct(coin);
   }
   else {
        coin->set_amount((int)coin->query_amount()-amount );   
   }	
   
   me->add("mana", -200-(int)me->query("mana_factor"));
   me->add("force", -100);
   me->receive_damage("sen", 10);

   if( random(me->query("max_mana")) < 50 ) 
   {
     write("��һ�κ����顣\n");
     return 1;
   }
   s_num = (int)(random(amount));
   if(s_num < 0) s_num = 0;
   msg = HIC "$N����һ�ӣ�ֻ��һƬͭǮ��$nѸ�ٵķ�ȥ��\n" NOR;

   ap = me->query_skill("spells");
   ap =  ap * ap * ap / 100;
   dp = target->query("combat_exp")* 4 /5;
   chance = (int)(random(ap + dp) * 100 / dp);
        
        if((int)me->query("mana_factor")/100 > 0) 
           damage = (int)(random(me->query_skill("spells")/20)) + (int)me->query("mana_factor")/100;    
        else if((int)(random(me->query_skill("spells")/20)) > 0)
           damage = (int)(random(me->query_skill("spells")/20));  
        else damage = 1;

   if( chance > 88 ) 
   {
        damage = (int)(s_num * damage * 10);
        damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
        msg += HIC "���$n����"+chinese_number(s_num)+"��ͭǮ��\n" NOR;
        target->receive_wound("kee", damage, me);
     }
     else if ( chance > 55 ) 
     {
        damage = (int)(s_num * damage);        
        if(damage < 0) damage = 1;
        msg += HIC "���$n��"+chinese_number(s_num)+"��ͭǮ���ˣ�\n" NOR;
        target->receive_wound("kee", damage, target);
     } 
   else
     msg += "���Ǳ�$nȫ�㿪�ˡ�\n";

   message_vision(msg, me, target);

   if( !target->is_fighting(me) ) 
   {
     if( living(target) ) 
     {
        if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(random(2));
   return random(20)+10;
}

