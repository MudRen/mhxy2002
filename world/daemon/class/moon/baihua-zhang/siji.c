// by nina
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extra;
        object weapon;

        if(me->is_busy(1))
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("baihua-zhang",1) *2;

        if ( extra < 150) return notify_fail("��İٻ��ƻ��������죡\n");

        if(me->query_temp("last_siji")+5>time())
                return notify_fail("��ո�ʹ���������ļ���,��ЪһЪ�ɡ�\n");

        if(me->query("family/family_name") != "�¹�")
                return notify_fail("�������ļ������¹�����֮�ܣ�\n");

        if( (int)me->query("force",1) < 1000 )
                return notify_fail("�����������������ʹ�á������ļ�����\n");
        
        if( (int)me->query_skill("moonforce", 1) < 150 )
                return notify_fail("���Բ���ķ�������죬����ʹ�á������ļ������\n");
        
        if( (int)me->query_skill("moondance", 1) < 150 )
                return notify_fail("������������費����죬����ʹ�á������ļ������\n");
     
        if( (int)me->query_skill("snowsword", 1) < 150 )
                return notify_fail("��ķ��ѩ�轣��������죬����ʹ�á������ļ������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷����ļ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");                me->add_temp("apply/attack",extra/10);
        weapon = me->query_temp("weapon");
        msg = HIR  "$Nʹ���ٻ����еĲ��������۷����ļ��ݣ�һ��������ʽ��$n������\n" NOR;
        message_vision(msg,me,target);
        msg = HIG  "\n~~~ �ٻ�ӭ�� ~~~~ ��" NOR;
        message_vision(msg,me,target);
        msg = HIG "$N˫�Ʒ���, ����ƬƬ����,����������ľ���,�������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "������ƬƬ�ɻ�,$n����ǰ�����˴��̵Ĵ�����ɫ..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIB "$N���Ʒ������Ļ������Ի�,�Ե�Ŀ�����...,�����Ű���һ���ҽ�, һ��������$N������ӿ������\n" NOR,target);
        target->receive_wound("sen",extra);
        me->receive_heal("sen",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,��Ŀ��Ϣ,��Ϊ�������Ի�...\n" NOR,target);
        }
        msg = HIC  "\n~~~ ������� ~~~~ ��" NOR;
        message_vision(msg,me,target);
        msg = HIC "$N��̽��һ��, ����һ�������Ļ���, ǡ������΢��, ����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "�����������΢��,$n����ǰ�����˰�쵵��ļ���ɫ..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIR "$N���Ʒ������Ļ������Ի�,�Ե�������ã...�� ���������ص�һ���ƺߣ�һ��Ѫ���Ӷ�����ӿ������\n" NOR,target);
        target->receive_wound("kee",extra);
        me->receive_heal("kee",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,ת����ȥ,��Ϊ�������Ի�...\n" NOR,target);
        }
        msg = HIY  "\n~~~ ������� ~~~~ ��" NOR; 
        message_vision(msg,me,target);
        msg = HIY "$N�ڿ�Ծ��, ���б�ò���, ������Ӱ, ��и�ɻ��Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "�����Ų��������,$n����ǰ�����˽�Ƶ��＾��ɫ..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIC "$N���Ʒ������Ļ������Ի�,�Ե������ɢ....��������Ұ�ް�ĳ�Х�� һ��������$N������ӿ������\n" NOR,target);
        target->receive_wound("sen",extra);
        me->receive_heal("sen",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,��������,��Ϊ�������Ի�...\n" NOR,target);
        }
        msg = HIW  "\n~~~ Ʈѩ���� ~~~~ ��" NOR; 
        message_vision(msg,me,target); 
        msg = HIW "$N���˵���, ˫���Ƴ�,�����������ƬƬ��ѩ,��$n�����޾������У�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "�����ŷ׷ɵ�ѩ��,$n����ǰ�����˲�ã�Ķ�����ɫ..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( MAG "$N���Ʒ������Ļ������Ի�,�Եû�����....������������ײ��������һ��������$N������ӿ������\n" NOR,target);
        target->receive_wound("kee",extra);
        me->receive_heal("kee",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N�ƺ���͸����һ��,פ������,��Ϊ�������Ի�...\n" NOR,target);
        }
        me->start_busy(1+random(3));
        me->add("force",-300);
        me->add_temp("apply/attack",-extra/10);
        me->set_temp("last_siji",time());

        return 1;
}
