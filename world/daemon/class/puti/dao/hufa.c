// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// invocation.c

inherit SSERVER;

int cast(object me, object target)
{   
        int invocation_time;
        object soldier;

        if( !me->is_fighting() )
                return notify_fail("����û����Ҫɱ�㣡\n");
   
    if((string)me->query("family/family_name")!="����ɽ���Ƕ�")
                return notify_fail("�㲻�Ƿ���ɽ�ĵ��ӣ�����ɽ�Ļ����ǲ�����������ġ�\n");
        if(me->query("combat_exp")>500000)
                return notify_fail("����书�����Ա��������ǲ�����������ġ�\n");
        invocation_time=100-(int)me->query_skill("spells");
        if(invocation_time<40) invocation_time=40;
        if((time()-me->query("last_invocation"))<invocation_time)
       return notify_fail("��սй����������Ƕ�����з��ˣ�\n");

        if( (int)me->query("mana") < 50 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 40 )
                return notify_fail("��ľ����޷����У�\n");

        message_vision("$N�૵����˼������\n", me);

        me->add("mana", -50);
        me->receive_damage("sen", 40);

        seteuid(getuid());
        soldier = new("/d/lingtai/npc/hufa");
        soldier->move(environment(me));
        soldier->invocation(me);
        me->set("last_invocation",time());
        me->start_busy(2+random(2));

        return 8+random(5);
}
