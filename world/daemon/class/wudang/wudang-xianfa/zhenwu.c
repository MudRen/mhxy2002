//By tianlin@mhxy for 2001.12.13
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        object weapon;
        int i,j,k,u,damage;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(""YEL"��Ҫ��˭ʹ��"WHT"�����߾���\n"NOR);
		if(me->query("family/family_name")!="�䵱��")
                return notify_fail("���䵱�ɲ����á������߾��󡹣�\n");
        if((int)me->query("max_mana") < 700 )
                return notify_fail("��ķ���̫��ˡ�\n");
        if((int)me->query("mana") < 300 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if((int)me->query_skill("wudang-xianfa", 1) < 100)
        	return notify_fail("����䵱�ɷ��ȼ�����������ʹ����һ�У�\n");
	k=(int)me->query_skill("sword");
       j=(int)target->query_skill("dodge");
                  if(k<50)        
                return notify_fail("��Ľ������𻹲�����ʹ����һ�л������ѣ�\n");
u=1+k/50;
if (u>6) u=6;
me->delete("env/brief_message");
	target->delete("env/brief_message");
message_vision(BRED+WHT"\n$N��������һ����"NOR,me,target);
message_vision("\n\n\t"BRED+HIW"��"NOR"\n\t\t"BBLU+HIY"��"NOR"\n\t\t\t"BBLU+HIW"��"NOR"\n\t\t\t\t"HBRED+HIY"��"NOR"\n\t\t\t\t\t"HBRED+HIC"��"NOR"\n"NOR,me,target);
message_vision(HIW"ֻ��$NĬĬ�������佣����ķ�Ҫ��,�·�$n����ǧ�����������.\n"NOR+HIC"��ֱ���������ܼ�!"NOR,me,target);
for (i=0;i<=u;i++)
{
if (random(k+j)>j) {
           message_vision(CYN"\n$nһ��������������һ��.\n"NOR,me,target);
damage=100+random(100);
target->receive_damage("kee",damage);
target->receive_wound("kee",damage/3);
	    COMBAT_D->report_status(target);
me->receive_damage("sen", 10);
me->add("mana", -20);
}
             else {
           message_vision(YEL"\n$n�����������ò����ױܿ���һ�ֽ���\n"NOR,me,target);
me->receive_damage("sen", 10);
me->add("mana", -20);
}
}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
       me->start_busy(1+random(1));
       target->start_busy(1+random(2));
       return 2+random(3);
}
