//By tianlin@mhxy for 2002.1.3

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;//ҥ�Եı���
	 object weapon=me->query_temp("weapon");                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С� "CYN"�� "RED"�� "YEL"Ц"NOR" ����\n");

        if(!me->is_fighting())
                return notify_fail("��"CYN"��"RED"��"YEL"Ц"NOR"��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("kee") < 500 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("kugu-blade", 1) < 60)
                return notify_fail("��Ŀݹǵ�����Ϊ�����\n");
	if(me->query_temp("last_xiao")+5>time())
		return notify_fail("���ж�ʹ�Ͳ����ˡ�\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	if (! present(target,environment(me))) return 1;
       message_vision(HIB"\n$NĬ�˻���������ͻȻ��ʹ�����޽���������"+weapon->name()+NOR+HIB"ֱȡ$n��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIC"\n$N������ʽ���ϣ�����һЦ�������յ���צ��һ������ֱ��$n��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+HIM"��"+me->name()+HIM"��"NOR+YEL"�ݿ�ɽ"NOR+HIM"��ѧ"HIR"������Ц��"HIM"�����ˣ���˵"+target->name()+HIM"�������ϻ�����΢Ц��";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        me->receive_damage("kee", 50);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("last_xiao",time());
        return 1;
}

