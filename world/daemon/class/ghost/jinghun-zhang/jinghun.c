//By tianlin@mhxy for 2001.12.31����
//��pfm����û���κ�bug
//����˵�Է����˺��ڵظ���������,������ʹ��pfm�뿪�˵�,���ñ����,�ȵ�.....
//��pfmû����������ʱ���õ�����,��Ϊ����6����,�����軹�ܺ��õ�,�ⲻ��ʲô������
//�벻Ҫ������������лл!
//������˷��ִ�����bug���Ÿ�����tianlin-mhxy@163.comлл��

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;//ҥ�Եı���
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(HIY"��Ҫ��˭ʩչ��һ��"HIC"��"HIB"����"HIR"����"HIC"��"HIY"��\n"NOR);

        if(!me->is_fighting())
                return notify_fail(""HIC"��"HIB"����"HIR"����"HIC+HIY"��ֻ����ս����ʹ�ã�\n"NOR);

        if( (int)me->query_temp("jinghun") ) 
        return notify_fail(HIW"����һ���л�û����ȫ����,������ʹ�á�\n"NOR);

        if((int)me->query("max_force") < 500 )
                return notify_fail(YEL"���������򻹲��У�\n"NOR);

        if((int)me->query("force") < 500 )
 	         return notify_fail(CYN"����������㣡\n"NOR);

        if((int)me->query("kee") < 500 )
                return notify_fail(HIR"�����Ѫ���㣬û����ʩ���⹦��\n"NOR);

        if((int)me->query("sen") < 500 )
                return notify_fail(HIC"��ľ����㣬û����ʩ���⹦��\n"NOR);

        if((int)me->query_skill("jinghun-zhang", 1) < 100)
                return notify_fail("��ľ����Ƽ��𻹲�����ʹ�ò�����������ǵİ���֮����\n");
	 if(me->query_temp("last_jinghun")+8>time())
	         return notify_fail(HIB"����"HIR"����"NOR+CYN"�˾����书,��ʹ�Ͳ����ˡ�\n"NOR);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

	 if (! present(target,environment(me))) return 1;
        message_vision(HBBLU+HIR"\n$N������Σ�����������ʵ�ģ���$n������·��ȥ��$N����$n˫�ȣ�\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBRED+HIW"\n$N˫��΢�֣����ֱ�����һ��һ����һ�ƣ�$nһ���ҽд���$n�İٻ�Ѩ��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+CYN+target->name()+HIM"��"NOR+YEL+me->name()+HIM"��ڤ���ѧ"HIC"��"HIR"����"HIB"����"HIC"��"HIM"��ɱ����,��˵"NOR+CYN+target->name()+HIM"�������仹�־���һ�У�";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        me->set_temp("jinghun", 1);
        call_out("remove_jinghun",3,me);
        me->start_busy(1);
        target->start_busy(1);
        me->set_temp("no_move",1);
        call_out("remove_no_move",3,me);
        remove_call_out("perform");
        call_out("perform2", 3, me, target);    
        return 1;
}

int perform2(object me, object target)
{
        string str;//ҥ�Եı���
        object weapon;
        if(!living(target) || !target || environment(me)->query("no_fight")
           ){
           message_vision(CYN"$N�Ķ����Ѿ�������ս����,��ݲ���������ʹ�þ���!\n"NOR,me);
                return 1;
                }
	if( environment(target) != environment(me) ) {
		tell_object(me, BLINK+HIR"��Ķ����Ѿ��뿪�����ˡ�\n"NOR);
		return 1;
	}
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("�㷢���Լ������Ѿ������õ���,��������������\n");     
        message_vision(HBBLU+HIY"\n$N������$nͷ�����������һ��������צ��������������$n�沿ץȥ��\n"NOR,me,target);
        message_vision(BLINK+HIC"\n\t\t\t\t��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBRED+HIC"\n$N��˫�����������µ����أ�˫���͵İγ����ſ�һ����һ�ɱ���������$nӭ�������\n"NOR,me,target);
        message_vision(BLINK+HIY"\n\t\t\t\t��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBBLU+HIC"\n$N���Ӷ�ҡ���ţ��漴���������$N��˫�ֺ��ƺ�צץ��$n��������\n"NOR,me,target);
        message_vision(BLINK+HIR"\n\t\t\t\t��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HBBLU+HIR"\n$N������$n�Ұ��������漴������$n������$n���������ۿ���Ҫ���У�$N������һ����\n"NOR,me,target);
        message_vision(BLINK+HIB"\n\t\t\t\t��\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+CYN+target->name()+HIM"��"NOR+YEL+me->name()+HIM"��ڤ���ѧ"HIC"��"HIR"����"HIB"����"HIC"��"HIM"��ɱ����,��˵"NOR+CYN+target->name()+HIM"�������仹�־���һ�У�";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
                me->start_busy(1+random(2));
	         me->receive_damage("kee", 50);
	         me->receive_damage("sen", 50);
                target->start_busy(1+random(2));
                me->delete_temp("jinghun");
                me->set_temp("last_jinghun",time());
        return 1;
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
void remove_jinghun(object me) {
  if (me) me->delete_temp("jinghun");
}

