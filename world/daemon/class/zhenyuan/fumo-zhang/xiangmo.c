//������ʽ by hawks 2000.12
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void pili_ok(object);
int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����ħ��ʽ����\n");
      

        if(!me->is_fighting())
                return notify_fail("����ħ��ʽ��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("staff",1)<120)
                return notify_fail("��Ļ����ȷ����𲻹�!\n");
if((int)me->query_skill("fumo-zhang",1)<100)
                return notify_fail("��ķ�ħ�ȼ��𻹲�����ʹ����һ�л������ѣ�\n");
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("��ħ��ʽ���������Ԫ�񹦲���ʹ�á�\n");
        if((int)me->query_skill("zhenyuan-force",1)<100)
                return notify_fail("�����Ԫ�񹦼��𻹲������޷�ʹ����һ��!\n");
                

                if(me->query_temp("no_xiangmo"))
                        return notify_fail("��ո��ù�����ħ��ʽ���ˣ�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");

message_vision(HIY"\n$N�ӿ����Σ��������$nչ������������\n"NOR,me,target);
        me->set_temp("FMZ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("FMZ_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("FMZ_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         me->set_temp("FMZ_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("FMZ_perform");

        me->receive_damage("sen", 140);
        me->add("force", -140);
me->start_busy(random(3));
        me->set_temp("no_xiangmo",1);
                call_out("xiangmo_ok",5+random(3),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

void xiangmo_ok(object me)
{ if (!me) return;
      me->delete_temp("no_xiangmo");
}