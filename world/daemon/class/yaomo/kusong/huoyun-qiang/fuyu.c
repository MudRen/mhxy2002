#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("huoyun-qiang", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����귭�ơ���\n");

        if(!me->is_fighting())
                return notify_fail("�����귭�ơ�ֻ����ս����ʹ�ã�\n");
                
		   if(me->query("family/family_name")!="���ƶ�")
           return notify_fail("�����귭�ơ�ֻ�л��ƶ����˲ſ����ã�\n");
	                
	if(me->query_temp("busy_fuyu")+4>time())
		return notify_fail("��ո�ʹ�������귭�ơ�,��ЪһЪ�ɡ�\n");

        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="spear")
                return notify_fail("�����귭�ơ�Ҫ��ǹ���ܷ���������\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 300 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("��ľ����㣬û����ʩչ���귭�ƣ�\n");

        if(myskill < 40)
                return notify_fail("��Ļ���ǹ�����𻹲�����\n");
        else 
            if(myskill <100){
                times = 3;        
                number = "��";}
        else
            if (myskill <130){
                times = 4;
                number = "��";}
        else
            if(myskill <160 ){
                times = 5;
                number = "��";}
        else
            if(myskill <190 ){
                times = 6;
                number = "��";}
        else
            if(myskill <220 ){
                times = 7;
                number = "��";}
        else
            if(myskill <250 ){
                times = 8;
                number = "��";}
        else
            if(myskill <270 ){
                times = 9;
                number = "��";}
        else
            {
                times = 10;
                number = "ʮ";}


        me->delete("env/brief_message");
	target->delete("env/brief_message");
	damage = me->query_str() + random(me->query_skill("huoyun-qiang")) + random(me->query_kar());

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20);
       // me->add("force", -(times*50+50));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && times>5)
	{

                target->receive_damage("sen",damage,me);
                target->receive_wound("sen", random(damage), me);
                target->receive_damage("kee",damage+1,me);
                target->receive_wound("kee", random(damage), me);
                  			
		COMBAT_D->report_status(target, 0);
	}
        me->set_temp("busy_fuyu",time());
        me->set_temp("no_move",1);
        call_out("remove_no_move",2,me);
        return 1;
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}


