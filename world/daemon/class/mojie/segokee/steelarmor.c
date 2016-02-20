//steelarmor.c ���ֶ���
//created by foc,01-7-01
//�ص�˵������ս��������

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
    int defence, time, str;
    if(me->query_temp("keearmor"))
    return notify_fail("������Ѿ��������˼���״̬��û�취������ˡ�\n");
    if((int)me->query_skill("segokee",1)<10)
    return notify_fail("���ʥ������ûǿ������ʵ�ﻯΪ���׵ĳ̶ȡ�\n");
    if((int)me->query("max_force")<600 || (int)me->query("force")<500)
    return notify_fail("�����������\n");
    if((int)me->query("daoxing")<800000)
    return notify_fail("�����Ϊ�������������ó�����Ҳ�����ж���Ч����\n");
    if( target != me )
    return notify_fail("ʥ�����ķ���Ч���޷�ת�޸����ˡ�\n");
    if(me->is_ghost())
    return notify_fail("�㶼�Ѿ��ǹ��ˣ������ڸ�ʲôѽ��\n");
    else
{
    message_vision(HIY "$N���һ����ȫ���ʥ�����͵ط��˳��������ܵĿռ��ƺ���\nŤ���ˣ�$N��������Լ����������ɫ������������$N��\n��һ�����γ���һ����ɫ�����ף�\n" NOR,me);
    defence=(int)me->query_skill("segokee",1)*5;
    time=(int)me->query_skill("segokee",1)*12;
    if(defence >=200) defence=200;
    if(time >=180 ) time=180;
    me->add_temp("apply/armor", defence);
    me->add_temp("apply/armor_vs_force",defence);
    me->add_temp("apply/attack",defence*25);
    me->add_temp("apply/dodge",defence);
    me->add_temp("apply/parry",defence);
    me->add_temp("force_factor",defence);
    me->add_temp("mana_factor",defence);
    me->set_temp("keearmor",1);
    if(me->is_fighting())
    me->start_busy(3);
    me->add("force",-200);
    call_out("remove_effect",time,me);
}
    return 1;
}

void remove_effect(object me, int defence )
{
    defence=(int)me->query_skill("segokee",1)*5;
    if(defence >=200) defence=200;
    message_vision(HIY "$N���ϵ����ֶ����Զ��⿪�����±����������̬��\n�ص���$N�������С�\n" NOR,me);
    me->add_temp("apply/armor",-defence);
    me->add_temp("apply/armor_vs_force",-defence);
    me->add_temp("apply/attack",-defence*25);
    me->add_temp("apply/dodge",-defence);
    me->add_temp("apply/parry",-defence);
    me->add_temp("force_factor",-defence);
    me->add_temp("mana_factor",-defence);
    me->delete_temp("keearmor");
}
