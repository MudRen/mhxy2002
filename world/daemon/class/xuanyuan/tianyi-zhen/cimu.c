//By tianlin@mhxy for 2002.1.20

#include <ansi.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;
int perform(object me, object target)
{
    string str;//ҥ�Եı���
    int damage,p;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail(HIR"����Ŀ��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("tianyi-zhen", 1) < 80 )
        return notify_fail(WHT"����һ���벻����죬ʹ��������Ŀ����\n"NOR);
    if ((int)me->query("max_force")<400)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("force")<200)
    {
        return notify_fail(HIC"����������������û�ܽ�����Ŀ��ʹ�꣡\n"NOR);
    }
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "needle")
       msg = HIC "$N������ָ��£���ֱ۱�����Ѹ���쳣�ִ�$n˫Ŀ��\n"NOR;
    else
       msg = HIC "$N��������һ�񣬽���һ�㱩�����ִ�$n����˫Ŀ��\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
    {
        me->start_busy(1);
        target->start_busy(random(4));
        damage = (int)me->query_skill("tianyi-zhen", 1) + (int)me->query_skill("needle", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("kee", damage);
        target->receive_wound("kee", damage);
        msg += HIC"$nֻ��������һ�㣬˫Ŀһ���ʹ����ǰһ�ڣ���ʲôҲ������
�ˣ���ʱ����ʹ��������\n"NOR;
        p = (int)target->query("kee")*100/(int)target->query("max_kee");
        msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target); 
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=GRN+target->name()+HIM"��"HIY+me->name()+HIM"��"NOR+MAG"��ԯ��Ĺ"NOR+HIW"��ѧ"HIR"��"HIW"��Ŀ�޺�"HIR"��"HIM"ɱ����, ��˵"GRN+target->name()+HIM"��������˫Ŀ����Ѫ��ֹ!";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        me->add("force", -damage/5);
	me->set_temp("zhen/cimu", 1);
	target->set_temp("block_msg/all",1);
	call_out("cimu_end", (int) 2+random(6), me, target);
    } else
    {
        me->start_busy(2);
        msg += HIY"$p�鼱������̧��Ҳ$P���۴�ȥ���ȵ�$P�ؽ�Ծ����\n"NOR;
        message_vision(msg, me, target); 
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

void cimu_end(object me, object target)
{      
       if(!living(target)) 
       return;
	target->enable_commands();
	message_vision("$NĨ��Ĩ����"HIR"��Ѫ"NOR"�������ܿ����ˡ�\n", target);
	target->set_temp("block_msg/all", 0);
	me->delete_temp("zhen/cimu");

	return;
}
