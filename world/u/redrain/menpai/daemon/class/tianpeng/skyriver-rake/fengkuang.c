// by gslxz@mhsj 2001/9/6
// fengkuang.c �����һ�١�
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string str;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"��Ҫ��˭ʩչ��"HIR"[���һ��]"NOR WHT"��\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIR"[���һ��]"NOR WHT"ֻ����ս����ʹ�ã�\n"NOR);

        if((int)me->query("force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("skyriver-rake", 1) < 150)
                return notify_fail("�������ٷ����𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("tianpeng-force", 1) < 150)
                return notify_fail("��������ķ����𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");

        message_vision("\nֻ��$Nʹ�����������"HIR"[���һ��]"NOR"������" YEL"��ɱ��ʽ"NOR"\n", me);


        me->set_temp("fengkuang_per", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"BLINK HIY"            ��      һ      ʽ\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"BLINK HIY"            ��      ��      ʽ\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"BLINK HIY"            ��      ��      ʽ\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("fengkuang_per");

        me->receive_damage("kee", 50);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
         if( !userp(target) ){
               if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0) )  
                       { str=target->name()+HIM"��"+me->name()+HIM"���������"HIW"�����һ�١�"HIM"ɱ���ˣ���˵ʬ�����Ѿ��鲼¶�ǵ��ٺۣ�";
//	                 message("channel:rumor",HIM"���������С�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
}else{               if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0) )  
                       {str=target->name()+HIM"��"+me->name()+HIM"���������"HIW"�����һ�١�"HIM"ɱ���ˣ���˵ʬ�����Ѿ��鲼¶�ǵ��ٺۣ�";
                message("channel:rumor",HIM"���������С�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
}

        me->start_busy(2);
        return 1;
}

