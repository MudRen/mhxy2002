//creat by focus
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
    int extra;
        object weapon;
        object ob;
    string msg;
 //       extra=me->query_skill("bingpo-blade",1);
 //   if(me->query("family/family_name")!="��ѩɽ")
   //             return notify_fail("���ѩɽ���ӣ������ÿ�ħ���裡\n");

    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á���ħ���衹��\n");
    if( (int)me->query_skill("bingpo-blade",1) < 120)
    return notify_fail("����ǵ���̫�ͣ��޷�ʹ�á���ħ���衹��\n");
    
    if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        ||      (string)ob->query("material") != "ice" )
                return notify_fail("���������һ�ѱ����ĵ�����ʩչ����ħ���衹��\n");
   
        if( (int)me->query("force") < 100 )
    return notify_fail("�������������\n");
    me->add("force", -120);
    
    if (me->query_temp("BPD_perform_busy")) return notify_fail("�����õ�̫��̫�ľͲ����ˡ�\n");
    me->delete("env/brief_message");
        target->delete("env/brief_message");
    
    message_vision(HIR"$N���һ��������ٿ����շ�����˲����������,"+
    HIW"ƥ��Ҳ�Ƶĵ��⻷�Ʒ��ӣ��γ�һ�����ģ�͸���Ĺ�֮���Σ�$nֻ����������ֹͣ�ˣ�\n"NOR,me,target);
                   
         target->start_busy(2+random(2));
        me->set_temp("BPD_perform", 6);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->set_temp("BPD_perform", 5);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->set_temp("BPD_perform", 3);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
       

        
        me->delete_temp("BPD_perform");
        me->recive_damage("kee",100);
        me->recive_damage("sen",100);
        me->add("force",-200);
        
        if (! target->is_fighting(me))
          {
            if ( living(target))
              {
                 if( userp(target) ) target->fight_ob(me);
                     else target->kill_ob (me);
              }
           }
        me->start_busy(2+random(2));
        
    return 1;
}
