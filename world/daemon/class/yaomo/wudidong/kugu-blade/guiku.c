#include <ansi.h>
#include <combat.h>

inherit SSERVER;
void guiku_ok(object);

int perform(object me, object target)
{
        object weapon;
        string msg;
        string str;//ҥ�Եı���
        int damage, max_qi, myqi, mymz,  tamz, mzl;
        string anqi_type,b_unit;


        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("��Ҫ��˭ʹ��"HIY"��"NOR""HIR"���Ѫɢն"HIY"��"NOR"��\n");

        if(!me->is_fighting())
                return notify_fail(HIY"��"NOR""HIR"���Ѫɢն"HIY"��"NOR"ֻ����ս����ʹ�ã�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail("װ�����Ӳ���ʹ�����У�\n");
        
      if((int)me->query_skill("kugu-blade", 1) <80)
            return notify_fail("��Ŀݹǵ��ȼ�̫�\n");

      if((int)me->query_skill("huntian-qigong", 1) <80)
            return notify_fail("��Ļ��������ȼ�̫�\n");

      if (me->query_skill_mapped("force")!="huntian-qigong")
                return notify_fail(HIY"��"NOR""HIR"���Ѫɢն"HIY"��"NOR"������ϻ�����������ʹ�á�\n");

        if((string)me->query("family/family_name")!="�ݿ�ɽ�޵׶�" )
                return notify_fail("͵ѧ�Ĺ���������ã�\n");

      if((int)me->query_skill("blade", 1) <80)
            return notify_fail("��Ե��������̫����!\n");

        if((int)me->query("max_force") < 1200 )
                return notify_fail("�������̫���ˣ�\n");

        if((int)me->query("kee") < (int)me->query("max_kee")/3 )
                return notify_fail("��̫�����ˣ�\n");

                if(me->query_temp("no_guiku"))
                        return notify_fail("��̫���ˣ�������ЪЪ�ɡ�\n");

       if (me->query("force")<500)
           return notify_fail("���������̣��޷�����"HIY"��"NOR""HIR"���Ѫɢն"HIY"��"NOR"��������\n");




           msg =  HIB"\nֻ��$N������������һ����ʹ��"HIY"��"NOR""HIR"���Ѫɢն"HIY"��"HIB"����"+weapon->query("name")+HIB"�������裬
�������񺿰㹥��$n��Ҳ�����Լ��������ж��\n" NOR;



        me->add("force", -100);
        if( random(me->query("combat_exp"))*2 < (int)target->query("combat_exp")/2 ) {
              msg +=   WHT "$nҲ����$N�������ж��ֻ���������ˣ���������Ķ㿪��$N�����й�����\n"NOR;
              message_vision(msg, me, target);
              me->start_busy(1+random(3));
         } else {
                //me->start_busy(random(2));
                target->start_busy(random(2));
                damage = (int)me->query_skill("kugu-blade", 1);
                damage = damage+me->query("force_factor");
                target->receive_damage("kee", damage*2,me);
                target->receive_wound("kee", damage,me);
                me->add("force", -100);
        me->set_temp("no_guiku",1);
                call_out("guiku_ok",3+random(3),me);
                  msg += HIB "����$N��Ȼ������"+weapon->query("name")+HIB"һ���̽���$n���ؿڡ�
���ֻ����$nһ���Һ���"+weapon->query("name")+HIB"����$p���ؿڶԴ�������\n"NOR;

                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+HIM"��"+me->name()+HIM"��"NOR+YEL"�ݿ�ɽ"NOR+HIM"��ѧ"HIY"��"NOR""HIR"���Ѫɢն"HIY"��"HIM"�����ˣ���˵"+target->name()+HIM"�Ǳ�һ������������";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
          me->start_busy(random(2));
          target->start_busy(1+random(2));
        target->kill_ob(me);
          return 1;
}

void guiku_ok(object me)
{ 
if (!me) return;
      me->delete_temp("no_guiku");
}