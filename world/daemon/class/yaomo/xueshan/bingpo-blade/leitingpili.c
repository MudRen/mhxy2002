// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int d=me->query_skill("xiaoyaoyou",1)/1;
        int j=me->query_skill("bingpo-blade",1)/1;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");                

        if( (int)me->query_skill("ningxie-force", 1) < 100 )
                return notify_fail("����ڹ����������죬����ʹ������������\n");    
        if( (int)me->query_skill("bingpo-blade", 1) < 100 )
                return notify_fail("��ĵ�������������������ʹ������������\n");
        if(me->query_skill_mapped("force") != "ningxie-force")
                return notify_fail("����ڹ�������Ϸ������У�\n");

                if(me->query_temp("no_leitingpili"))
                        return notify_fail("���в��ܾ�����! \n");
        if((int)me->query("force") < 400 )
                return notify_fail("��������������,����������������\n");      
        weapon = me->query_temp("weapon");
        extra = me->query_skill("bingpo-blade",100);
        me->add_temp("apply/attack", (d+j)/1);  
        me->add_temp("apply/damage", (j)/1);
        me->add("force", -200);
        me->add_temp("apply/dodge", d);
        message_vision(HIR  "$N���е�"+ weapon->name() +HIR"�ó����쵶�ƣ�"+weapon->name() +HIR"���Ƶ��ƣ�����������Ļ���$n��\n" NOR,me, target);//by tianlin 2001.8.9.ȱ��\n,�Ѽ���
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -(d+j)/1);
        me->add_temp("apply/damage", -(j)/1);
        me->add_temp("apply/dodge", -d);
        me->set_temp("no_leitingpili",1);
                call_out("leitingpili_ok",2+random(2),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

void leitingpili_ok(object me)
{ if (!me) return;
      me->delete_temp("no_leitingpili");
}