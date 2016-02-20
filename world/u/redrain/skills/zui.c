//���־�

#include <ansi.h>

inherit SSERVER;
void check_fight(object me);
void remove_effect(object me);


int perform(object me, object target)
{
        object weapon;
        int i,j;
                        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                {if(me->query_temp("zuizj")) {remove_effect(me);return 1;}
                  else  return notify_fail("��Ҫ��˭ʩչ�����־�����\n");}
        
        if(time()-(int)me->query_temp("zuizj_end") < 10) return notify_fail("����������ˣ�\n");

        
        if(me->query_temp("zuizj")) {remove_effect(me);return 1;}
        
            
        if(!me->is_fighting())
                return notify_fail("�����־���ֻ����ս����ʹ�ã�\n");
          
        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        
                   
        if((int)me->query_skill("yinglong-stick", 1) < 100)
                return notify_fail("���Ӧ�����ȼ�������\n");
        
        if((int)me->query_skill("xiantian", 1) < 100)
                return notify_fail("����ķ����𻹲��������ˣ�\n");

        if((int)me->query_skill("feisheng", 1) < 100)
                return notify_fail("��ķ������𻹲��������ˣ�\n");
       
        weapon=me->query_temp("weapon");
        
       
        message_vision(HIC"\n$N�����ڹ��ķ���һ�ɾ���ӿ����ͷ�������������ģ������������ߣ�\n\n��������Ƶ��ǵ�����̤���ԣ��������ţ���һ��"HIW"�����־���"HIC"!\n"NOR,me);
        me->set_temp("zui",0);
        me->set_temp("zuizj",1);
        me->set_temp("zuizj_time",50+random((me->query_skill("force")+me->query_skill("stick"))/8));
        
        call_out("check_fight", 1, me);
        return 1;
}


void check_fight(object me)
{
        object weapon;
        if(!me) return;        
        if( !objectp(weapon=me->query_temp("weapon")) ||
                (weapon->query("apply/skill_type") != "stick" &&
                weapon->query("skill_type") != "stick" ) || 
                me->query_skill_mapped("stick") != "yinglong-stick" ||
                me->query_skill_mapped("force") != "xiantian" ||
                me->query_skill_mapped("spells") != "feisheng" ) 
                remove_effect(me);
        else if(me->query_temp("zuizj_time")<1)
                remove_effect(me);              
        else {  me->add_temp("zuizj_time",-1);
                call_out("check_fight", 1, me);
             }
}



void remove_effect(object me)
{       if(!me) return;
        remove_call_out("check_fight");
        me->delete_temp("zuizj");
        me->delete_temp("zui");
        message_vision(HIC"$N��һҡͷ���Ӿ��������˹�����\n"NOR, me);
        me->set_temp("zuizj_end", time() );
}




