// snowsword perform
//by fly
//by tianlin 2001.7.1�޸�
#include <ansi.h>
#include <combat.h>
#include "/u/tianlin/eff_msg.h";
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int i, j, z;
        object weapon;
        j = me->query_skill("snowsword", 1);
        z = me->query_skill("baihua-zhang", 1);
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("�������ѩ��ֻ����ս���жԶ���ʹ�á�\n");
        if (!weapon || weapon->query("skill_type") != "sword"
             )
                return notify_fail("�������ʹ�ý�ʱ����ʹ[�����ѩ����\n");
        if(me->query_skill("snowsword", 1) < 120 )
                return notify_fail("��ķ��ѩ�轣����������죬ʹ�����������ѩ��������\n");
        if(me->query_skill("baihua-zhang", 1) < 120 )
                return notify_fail("��İٻ��Ƶȼ���������죬ʹ�����������ѩ��������\n");
        if(me->query_skill("unarmed", 1) < 120 )
                return notify_fail("����Ʒ���������죬ʹ�����������ѩ��������\n");
        if( (int)me->query_skill("force") < 150 )
                return notify_fail("����ڹ��ȼ�������ʹ�����������ѩ��������\n");
        if( (int)me->query_str() < 50)
                return notify_fail("�������������ǿ����ʹ�����������ѩ��������\n");
        if( (int)me->query("max_force") < 1500 )
                return notify_fail("����������̫����ʹ�����������ѩ����\n");      
        if( (int)me->query("force") < 500 )
                return notify_fail("����������̫����ʹ�����������ѩ����\n");      
//   if (!this_player()->query_temp("moon_tian")&&!wizardp(me))
//                            return notify_fail("û������ĸ��ָ�㣬���Լ��������?..\n");
        msg = HIM "$Nʹ���¹�����֮�ܡ������ѩ�������ж�ʱ������أ�������ѩ�裡\n" NOR;
        //me->add_temp("apply/strength", z);
      //  me->add_temp("apply/attack", (j+z)/5); 
        if(weapon->query("id") == "snowsword"){
     //     me->set_temp("moon_pfm", 1);
    //    me->add_temp("apply/dodge", 350);
         // me->add_temp("apply/damage", 350);
          msg = HIR"\n$N���з��ѩ�轣�����������Ƴ�������⣬������$N����Ϊ�����ƽ������ֱָ$n��\n\n"NOR;
          }

  // if((string)me->query("id")=="tianlin") 
          {
     //     me->set_temp("moon_pfm_fly", 1);
     //     me->set_temp("moon_pfm", 1);
     //   me->add_temp("apply/dodge", 350);
  //        me->add_temp("apply/damage", 350);
        msg = HIM "\n\n$Nʹ����ңɽׯ�������ѩ�������ж�ʱ������أ�������ѩ��,��ʤ�¹���" NOR;
          msg += HBBLU"\n$N�������ѩ�轣���������ڵ�һ��֮��,$n�����Ļ�ʧ�ң�\n"NOR;
     //   me->add("force", 1000);
       }

        if(weapon->query("id") == "tianlin"){
    //      me->set_temp("moon_pfm", 1);
       // me->add_temp("apply/dodge", 350);
          //me->add_temp("apply/damage", 350);
          msg = HIR"\n$N��������˫��һ������һ�����֣�ֻ��������⣬������$N����Ϊ�����ƽ������ֱָ$n��\n\n"NOR;
          }
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
      //  if(me->query_temp("moon_pfm_fly"))
message_vision(HBGRN"\n$NǱ�˵�һ��,�ھ�Ʈ�����������һ����������֮����"NOR,me);
//        weapon->unequip(); 
      //  me->delete_temp("weapon");
        me->reset_action();
        COMBAT_D->do_attack(me, target);
      //  if(me->query_temp("moon_pfm_fly"))
message_vision(HBYEL"\n$NǱ�˵�һ��,������Ʈ��,�쳣�鶯,΢�����,�ҽ�������"NOR,me);
//        weapon->wield();
        me->set_temp("weapon",weapon);
        me->reset_action();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
       // if(me->query_temp("moon_pfm_fly"))
message_vision(HBRED"\n$NǱ�˵�һ��,�ھ��ᴩ����,ȭ��������������ף����������"NOR,me);
//        weapon->unequip();
        me->delete_temp("weapon");
        me->reset_action();
        COMBAT_D->do_attack(me, target);
      //  if(me->query_temp("moon_pfm"))
                {
       // me->add_temp("apply/dodge", -350);
         // me->add_temp("apply/damage", -350);
        //if(me->query_temp("moon_pfm_fly"))
message_vision(HBMAG"\n$NǱ�˵�һ��,������Ʈ��,�쳣�鶯,΢�����,�ҽ�������"NOR,me);
                }
//        weapon->wield();
        me->set_temp("weapon",weapon);
        me->reset_action();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
      //  me->delete_temp("moon_pfm");
        me->add("force", -100);
        //me->add_temp("apply/strength", -z);
      //  me->add_temp("apply/attack", -(j+z)/5);
        me->start_busy(1+random(3));

        return 1;
}
