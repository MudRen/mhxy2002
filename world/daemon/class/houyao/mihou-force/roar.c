// roar.c ��Ȼ������

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;
        
//        if(!me->is_fighting())
  //              return notify_fail("�����־���ֻ����ս���в���ʹ��!\n");
//        if( (string)me->query("family/family_name") !="ˮ����" )
  //                return notify_fail("ֻ��ˮ�������Ӳ���ʹ�á����־���!\n");

        if( (int)me->query("force") < 150 )
                return notify_fail("����һ�����������һ����\n");


        skill = me->query_skill("force");

        me->add("force", -150);
        me->receive_damage("kee", 10);

        me->start_busy(3);
        message_vision(
        MAG "$NͻȻ��������,����һ��,������һ����Х.ɲ�Ǽ�,��ر�ɫ,�����!\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;
 		if( interactive(ob[i]) ) continue;

                if( !ob[i]->is_killing(me) )
                        ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) )
                        me->fight_ob(ob[i]);

              damage = 20*skill/(int)me->query("per") - (int)ob[i]->query("max_force") / 20 ; 

                if( damage > 0 ) {
                       ob[i]->receive_damage("sen", damage,me);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                 ob[i]->receive_wound("sen", damage,me);
                tell_object(ob[i], "���Ȼ����һ�����������������������Ư�Ʋ�����\n");
                        ob[i]->set_temp("last_damage_from",me);
                }

        }

        return 1;
}

