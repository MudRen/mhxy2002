//fumo by greenwc
//fomo by yushu�޸�
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
              int i,j,e,damage,damagea;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");

        if((int)me->query("max_force") < 200 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("force") < 100 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("xianfeng-spells", 1) < 50)
                return notify_fail("����ɷ��������ȼ�����������ʹ����һ�У�\n");
        i=(int)me->query_skill("sword");
              j=(int)target->query_skill("dodge");
              e=i+j+i/2;
        if(i<75)        
        return notify_fail("��Ľ������𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIC"\n$N����Ĭ�������ھ�������"+weapon->name()+NOR+HIC"��ʱ��ϼ�����䣬һ�С�������ħ��ֱն$n��\n\n"NOR,me,target);
        if (random(e)>j)
        {       
        damage = i+random((int) me->query("max_force"))/30;
        damagea = i+random((int) me->query("max_force"))/50;
         target->receive_damage("kee",damage*2);
         target->receive_damage("sen",damagea*2);
        me->receive_damage("sen", 100);
        me->add("force", -100);
        me->receive_damage("kee", 100);
        COMBAT_D->report_status(target);
        COMBAT_D->report_sen_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
             }      
          me->start_busy(2);
        return 1;
}