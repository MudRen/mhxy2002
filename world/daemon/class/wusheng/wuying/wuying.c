//��ȥ������ wuying.c
// write by piao 2001-10-04;
// add by xiuxiu 2002-1-18
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void wuying_ok(object); 
inherit SSERVER; 

void remove_effect(object me, int a_amount, int d_amount);
int perform(object me, object target)
{
        object weapon,ob;
        string str;
        int skill;
        int extra;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��"HIW"������Ӱ"NOR"��ֻ����ս����ʹ�á�\n");
if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
              return notify_fail(" ��ʹ�õ��������ԣ��޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if((int)me->query("sen") < 800 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if( (int)me->query_skill("wuying", 1) < 180 )
return notify_fail("�����Ӱ��������죬�޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if( (int)me->query("force") < 1000  ) 
                return notify_fail("�������������\n");
        if( (int)me->query("max_force") < 3000  ) 
                return notify_fail("����������㣬�޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if((int)me->query("combat_exp") < 1000000 )
                return notify_fail("����ѧ���鲻�������򲻵���"HIW"������Ӱ"NOR"����\n");
        if( me->query("force_factor") > 50)
                return notify_fail("��"HIW"������Ӱ"NOR"���������в������������̫�����ܽ������飿\n");
        if(me->query_temp("no_wuying"))
              return notify_fail("��ո�ʹ����"HIW"������Ӱ"NOR"��,��ЪһЪ�ɡ�\n");
        skill = me->query_skill("wuying");
        extra = me->query_skill("wuying",1) / 10;
        extra += me->query_skill("wuying",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIC "\n$N����ͻ�䣬һ��"HIW"��������Ӱ��"HIC"˲������ֳ�������Ӱ��������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);
        me->set_temp("WYJ_perform", 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("WYJ_perform", 2); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("WYJ_perform", 3); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

message_vision(HIW" ��������  ��������  ��������  ��������  ��������\n"NOR,me,target); 
message_vision(HIW" �� "HIR"��"HIW" ��  �� "HIY"ȥ"HIW" ��  �� "HIG"��"HIW" ��  �� "HIB"��"HIW" ��  �� "HIM"��"HIW" ��\n"NOR,me,target); 
message_vision(HIW" ��������  ��������  ��������  ��������  ��������\n"NOR,me,target);
        me->set_temp("WYJ_perform", 4); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("WYJ_perform", 5); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        if( (int)me->query_skill("wuying", 1) > 179 ){
message_vision(HIR"      ���־���\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 199 ){
message_vision(HIY"            ȥ�־���\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 249 ){
message_vision(HIG"                 ���־���\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 299 ){
message_vision(HIB"                        ���־���\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 349 ){
message_vision(HIM"                           ���־���\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
                    if (target->query("eff_kee")<0 || !living(target))
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"����ʥ�ž�ѧ��"HIW"������Ӱ"HIM"��ɱ���ˡ���˵ʬ����ǧ���ٿף�";
        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
                       }
        me->start_busy(3);
         me->add("force", -1000);
        me->set_temp("no_wuying",1);
        me->receive_damage("sen", 50+random(50));
        call_out("wuying_ok",5+random(3),me); 
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);

        return 1;
}
void wuying_ok(object me)
{
if (!me) return; 
      me->delete_temp("no_wuying"); 
}
