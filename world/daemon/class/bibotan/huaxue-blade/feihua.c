//writted by redrain 2002-3-8
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("huaxue-blade", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���̶�ɻ�����\n");

        if(!me->is_fighting())
                return notify_fail("����̶�ɻ���ֻ����ս����ʹ�ã�\n");
                
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="blade")
                return notify_fail("����̶�ɻ���Ҫ��ǹ���ܷ���������\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 1000 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("��ľ����㣬û����ʩչ��̶�ɻ���\n");

        if(myskill < 120)
                return notify_fail("��Ļ�Ѫ�������𻹲�����\n");
        else 
            if(myskill <130){
                times = 3;        
                number = "��";}
            else
                if (myskill <140){
                    times = 4;
                    number = "��";}
                      else{ 
                           times = 5;
                           number = "��";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");
	damage = me->query_str() + random(me->query_skill("zhuanlong-force"));

message_vision(HIC"\n$Nһ����Х��"+ weapon->query("name")+ HIR"Ѫ��"HIC"һ����һʽ"HIR"����̶�ɻ���"HIC"�������$n������"HIB""+number+""HIC"����\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20);
        me->add("force", -(times*50));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && times>4)
	{

                target->receive_damage("sen",damage,me);
                target->receive_wound("sen", random(damage), me);
                target->receive_damage("kee",damage+1,me);
                target->receive_wound("kee", random(damage), me);
                  			
message_vision(HIR"\n$nһ㶣��ѱ�$N��"+ weapon->query("name")+ HIR"������Ŀȫ�ǣ�\n" NOR,me,target);
		COMBAT_D->report_status(target, 0);
	}
        me->start_busy(2);
        return 1;
}

