#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
void wusi_ok(object); 
int perform(object me, object target) 
{ 
        object weapon; 
                 
        if( !target ) target = offensive_target(me); 

        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
return notify_fail("��Ҫ��˭ʩչ��һ�С���˽�޵С���\n"); 

        if(!me->is_fighting()) 
return notify_fail("����˽�޵С�ֻ����ս����ʹ�ã�\n"); 
if((string)me->query("family/family_name") != "������" )
return notify_fail("��Ǿþӹٳ�����������˽��η�ĺ��⣿\n");

 if((int)me->query("max_force") < 300 ) 
                return notify_fail("�������������\n"); 

if((int)me->query_skill("wusi-mace", 1) < 60) 
return notify_fail("�����˽ﵷ����𻹲�����ʹ����һ�л������ѣ�\n"); 

if(me->query_temp("no_wusi"))
return notify_fail("����ʹ���˾Ͳ����ˣ�"); 
        me->delete("env/brief_message"); 
target->delete("env/brief_message"); 

message_vision(HIY"\n$Nһ�������о��ι�������Ϊ����һ��ǰ��δ�е�ѹ����$n������\n"NOR,me,target); 

me->set_temp("WSM_perform", 8); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

me->delete_temp("WSM_perform"); 

        me->add("force", -100); 
me->set_temp("no_wusi",1); 
call_out("wusi_ok",2+random(4),me); 


        if( !target->is_fighting(me) ) { 
                if( living(target) ) { 
                        if( userp(target) ) target->fight_ob(me); 
                        else target->kill_ob(me); 
                } 
        } 

        return 1; 
} 

void wusi_ok(object me) 
{ if (!me) return; 
 me->delete_temp("no_wusi"); 
}          

