// һ�����

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg,start;
        int ap, dp, success;
        target = offensive_target(me);

//      if( me->is_busy())
//              return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

        if( (int)me->query("mana") < 100 )
                return notify_fail("��ķ��������ˣ�\n");
        
        if(me->query("family/family_name")!="���")
                return notify_fail("��������ӣ�����������Ű�..\n");

        if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
                return notify_fail("�㾫��̫����Լ��о������䡣\n");

        if( (int)me->query_skill("kongming-spells", 1) < 20)
             return notify_fail("�㻹��������һ����⡣\n");

        ap=me->query_skill("spells")+me->query("max_mana")/10;
        if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

        if(!me->is_fighting() )
        {
          message_vision(HIC"ֻ��$N����һ�Σ�����һ����⣬��Ȼ�����ˡ�\n"NOR,me);
                me->add("sen", -me->query("max_sen")/10);
                me->add("mana", -50);
                success=1;
        }
        else
        {
message_vision(HIC"ֻ��$N����һ�Σ�����һ����⡣\n"NOR, me);
                if(random(ap+dp)>dp/2)
                {
message_vision(HIC"����Ȼ������ֻ����$n����������ԭ�ء�\n"NOR,me,target);
                        me->add("sen", -me->query("max_sen")/8);
                        me->add("mana", -50);
                        success=1;
                }
else message_vision(HIC"��$n�ۼ��ֿ죬���λζ��У�����$N��ǰ��\n"NOR,me,target);
                me->add("mana", -50);
        }
        if(success)
        {
start="/d/lingjie/shengdian";
                me->move(start);
message("vision",HIW+me->name()+"�����һ�ۣ�����������\n"NOR,environment(me),me),

tell_object(me, HIC"��������һ�֣���Ӱ�����ֳ����Ρ�\n"NOR);
                return 3+random(3);
        }
        return 3+random(5);

}
