//concentrate.c ������
//created by foc,23-08-01
//˵���������������������������ã�������ɣ�


#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int effect;
    if(!target) target = me;
    if(target != me) return notify_fail("������û�취���������ˡ�\n");
    if(me->is_ghost() || me->is_ghost())
      return notify_fail("������û�취ʹ�ü�������\n");
    if((int)me->query_skill("segokee",1)<20)
    return notify_fail("���ʥ����������ǿ��\n");
    if((int)me->query("combat_exp")<1000000 || (int)me->query("daoxing")<700000)
    return notify_fail("�������ڵ���Ϊ���²��С�\n");
    if((int)me->query("kee")<100 || (int)me->query("sen")<100)
    return notify_fail("�������ڵ�״̬�������ü�������\n");
    if(me->query_temp("concentrated"))
    return notify_fail("������̫�࣬�ɾͲ����ˡ�\n");
    else
{
    effect=(int)me->query_skill("segokee",1)*10;
    message_vision(HIY "$N�ų�ʥ�����������γ���һ���޴�����������ܵ���\nȻ�������ϼ�����$N������֮�С�\n" NOR,me);
    me->add("force",effect);
    me->add("mana",effect);
    if(me->is_fighting()) me->start_busy(random(3));
    me->set_temp("concentrated",1);
    call_out("remove_effect",10,me);
}
    return 1;
}

void remove_effect(object me)
{
    if(me->query_temp("concentrated"))
      me->delete_temp("concentrated");
    else return 0;
}
