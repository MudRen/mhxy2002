//��������
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        
        if( (int)me->query_skill("guangming-force",1) < 20)
                return notify_fail("��Ĺ����ķ�����Ҫ��һ������ߡ�\n");
        
        if( me->query("family/family_name")!="���")
                return notify_fail("���������ӣ��޷�ʹ�ù�������");

        if( (int)me->query("force") < 250 )
                return notify_fail("�������������\n");

        if( (int)me->query("mana") < 250 )
                return notify_fail("��ķ���������\n");

        message_vision(HIC"$N��ϥ������˫�ֿ۾�--���������ģ�ֱ���Ķ���һ��������������ס$N...\n"NOR,me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->receive_curing("sen", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -100);
        me->add("spells", -100);

        return 1;
}