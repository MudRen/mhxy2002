#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, force;

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("��ȫ���ڲ�����������������\n");
        if( !me->is_fighting() )
                return notify_fail("��תǬ��ֻ����ս����ʹ�á�\n");
        if( me->query("family/family_name")!="��ʥ��")
                return notify_fail("������ʥ�ŵĲ����á���תǬ������\n");
        if( (int)me->query("force") < 400 )
                return notify_fail("�������������\n");
	if( (int)me->query("kee") < 200)
		return notify_fail("������������ˡ�\n");
 if( (int)me->query_skill("xiantian", 1) < 50)
                return notify_fail("�������Ǭ������Ϊ��������ʹ����һ�л������ѣ�\n");
                
        skill = me->query_skill("force");
	force = me->query("max_force");
        me->add("force", -350);
        me->receive_damage("kee", 150);

   me->start_busy(3);
	message_vision(HIR "\n$N������ϣ���������˫�ֶ���һָ�������������������ڼ��ã�\n��ʱ���ذ��������޹⣬��صߵ���\n��һ����������ġ���תǬ������\n\n"
NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

 damage = (skill + force) * 1 - ((int)ob[i]->query("max_force") / 1);
                if( damage > 0 ) {
                        ob[i]->receive_damage("sen", damage, me);
                        if( (int)ob[i]->query("force") < skill * 2 )
                        ob[i]->receive_wound("sen", damage/10, me);
                        tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
                }
		COMBAT_D->report_sen_status(ob[i]);		
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}

