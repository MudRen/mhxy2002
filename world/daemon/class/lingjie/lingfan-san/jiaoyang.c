// link 2001.2.19
//By tianlin@mhxy for 2002.1.18����rumorϵͳ
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit SSERVER;
int perform(object me, object target)
{
        string str;
        object weapon,ob;
        int skill, damage, ap, dp, kar;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("�������ƻ�ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "umbrella")
                return notify_fail("�������ƻ𡹱�����ɡ����ʩչ��\n");

        if( (int)me->query_skill("lingfan-san", 1) < 90 )
                return notify_fail("��ġ���ᦾ���ɡ��������죬����ʹ�á������ƻ𡹡�\n");
        if( (int)me->query("force") < 600  ) 
                return notify_fail("�������������\n");
        if(!wizardp(me) && me->query("family/family_name")!="���")
                return notify_fail("��������ӣ��޷�ʹ�á������ƻ𡹡�\n");


        skill = me->query_skill("lingfan-san");
        weapon = me->query_temp("weapon");
        msg = MAG "$N��Хһ��,ʹ������ᦾ���ɡ���еľ����������ƻ����е�"+weapon->name()+MAG"��ħ���ɨ��$n��\n"NOR;
        message_vision(msg, me, target);

        me->add("force", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();
        damage=weapon->query("weapon_prop/damage");
        ap = me->query("combat_exp") + skill * 100 + me->query("daoxing") + me->query("con") * 1000; 
        dp = target->query("combat_exp") + target->query_skill("parry") * 100 + target->query("daoxing") 
             + target->query("kar") * 1000; 
        kar = me->query("kar");
        
        if(ap > dp) {
          msg = HIY"�񽿡�\n"NOR;
          message_vision(msg, me, target);
          target->add("kee", -damage);
          target->add("eff_kee", -damage/2);
          COMBAT_D->report_status(target, 0);
        }
        if(ap > dp) {
          msg = HIR"������\n"NOR;
          message_vision(msg, me, target);
          if(random(1) == 0) target->add("kee", -damage);
          else target->add("kee", -damage*2);
          COMBAT_D->report_status(target, 0);
          me->improve_skill("lingfan-san", 1, 1);
        }
        if(ap > dp) {
          msg = HIY"���ơ�\n"NOR;
          message_vision(msg, me, target);
          if(random(5) == 0) target->add("kee", -damage);
          else target->add("kee", -damage*3);
          COMBAT_D->report_status(target, 0);
          me->improve_skill("lingfan-san", 1, 1);
        }
        if(ap > dp) {
          msg = HIR"����\n"NOR;
          message_vision(msg, me, target);
          if(random(10) == 0) target->add("kee", -damage);
          else target->add("kee", -damage*4);
          COMBAT_D->report_status(target, 0);
          me->improve_skill("lingfan-san", 1, 1);
        }
        if( me->is_fighting() ) me->start_busy(random(2)+1);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"��"+me->name()+"��������[1;37m�������ƻ�[2;37;0m[1;35m��ɱ����. ʬ���Ѿ�������Ŀ��";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        return random(3)+5;
}
