#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{

        int d=me->query_skill("lotusmove",1)/2;
        int j=me->query_skill("cibei-dao", 1)/2;
     int i=me->query_skill("jienan-zhi", 1)/2;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ӱָֻ�ܶ�ս���еĶ���ʹ�á�\n");                

        if( (int)me->query_skill("lotusforce", 1) < 100 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�õ�Ӱָ��\n");    
        if( (int)me->query_skill("cibei-dao", 1) < 100 )
                return notify_fail("��ĵ�����δ���ɣ�����ʹ�õ�Ӱָ��\n");        
        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "cibei-dao")
                return notify_fail("������û�е����޷�ʹ�õ�Ӱָ��\n");
        if((int)me->query_skill("jienan-zhi", 1) < 100 )
                return notify_fail("���ָ����δ���ɣ�����ʹ�õ�Ӱָ��\n");  
        if(me->query_skill_mapped("force") != "lotusforce")
                return notify_fail("����ڹ�������̨�ķ����޷�ʹ�õ�Ӱ
ָ��\n");

                if(me->query_temp("no_yingzhi"))
                        return notify_fail("������ʹ�Ͳ����ˣ�\n");
        if(me->query_skill_mapped("parry") != "cibei-dao")
           if(me->query_skill_mapped("parry") != "cibei-dao")
                return notify_fail("����мܹ��򲻶ԣ��޷�ʹ�õ�Ӱָ��\n");
        if((int)me->query("force") < 300 )
                return notify_fail("�������������㣬����ʹ�õ�ָ��\n");      
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�õ�Ӱָ��\n");
        if((int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("����˼��񶷲�����죬�����ڵ����м���ʹ�õ�Ӱָ��\n");     
        message_vision(HIR"\n$N���һ��ʹ����Ӱָ��ָ�浶�ߣ������м���������ָ��һ����$n��\n"NOR, me,target);
       me->add("force", -200); 
     me->add("sen", -50);
        me->add_temp("apply/dodge", d); 
  me->add_temp("apply/attack", (i+j)/1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        me->add_temp("apply/unarmed", i/1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
     me->add_temp("apply/unarmed", -i/1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
  me->add_temp("apply/attack", -((i+j)/1)); 
   me->add_temp("apply/dodge", -d);
me->set_temp("no_yingzhi",1);
                call_out("yingzhi_ok",2+random(2),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

void yingzhi_ok(object me)
{ if (!me) return;
      me->delete_temp("no_yingzhi");
}         