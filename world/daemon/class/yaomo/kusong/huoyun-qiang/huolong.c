// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("huoyun-qiang",100) ;
        if ( extra < 50) return notify_fail("��Ļ���ǹ���������죡\n");
                
     if(me->query("family/family_name")!="���ƶ�")
           return notify_fail("���ۻ������ݡ�ֻ�л��ƶ����˲ſ����ã�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۻ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp * 2 && weapon)        
        {
        message_vision(
HIW "\n\n$Nʹ��һʽ����ǹ�е� �ۻ�������� ��ǹ����һ���������ס$n���еı���,"+ 
weapon->name()+  "���ֶ��ɣ�\n\n" NOR, me,target);
        if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR+ "\n\n$Nʹ��һʽ����ǹ�е� �ۻ�������� �����е�"+(me->query_temp("weapon"))->name()+"�������ֱҧ$n��$l��\n\n"+ NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        }
        return 1;
}