// keelv.c ��һ���ķ���
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // ���ֵ�����
        string msg;
        int i,attack_time,skill,damage;
        me=this_player();
        skill = me->query_skill("canxin-jian",1);
//      target=this_object();
//      ob=target->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character() )                return notify_fail("����һ���ķ��项ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("canxin-jian", 1) < 200 )
                return notify_fail(HIW"���޷�������������һ���ķ��项��\n"NOR);

        if ( me->query("force") < 400)
                return notify_fail(HIW"������������������޷�ʹ������һ���ķ��项��\n"NOR);
        me->add("force", -200);


        msg = HIW "$N������̾,ʹ���ˡ���һ���ķ��项,�����д������־���,��������,���ֿɰ���һ�ֲ���һ����\n";

  if((me->query_skill("sword")*me->query("int") ) > ((int)target->query_skill("force")*target->query("int")))
        {
 
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += "\n"HIW "�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n\n" NOR;
                        me->start_busy(3);
                        damage = 700 + random(skill);
                        target->receive_damage("kee", damage);
                        target->start_busy(3);
        message_vision(msg, me, target);
                } else
                {
                          msg += "\n"HIW"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n" NOR;
                          msg += "\n"YEL"��һ��,������$n�����"+ob->query("name")+"��\n\n"NOR;

                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", YEL"���˵�"NOR + ob->query("name"));
                        ob->set("long", "һ"+ob->query("unit")+ob->query("name")+"��\n");
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        damage = 700 + random(skill / 2);
                        target->receive_damage("kee", damage);
                        me->start_busy(2);
                        target->start_busy(2);

        message_vision(msg, me, target);

                } 

        }
else
        {
                msg += HIW"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!\n"NOR"\n"HIY"���$n������������ע���ܿռ�,������$N�Ľ��⡣\n" NOR;
                me->start_busy(random(2));
                message_vision(msg, me, target);

        } 
                
}
