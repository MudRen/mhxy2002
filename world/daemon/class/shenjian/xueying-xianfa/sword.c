//By tianlin@mhxy for 2002.1.17

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
       string str;//ҥ�Եı���
        int success_adj, damage_adj;

        success_adj = 110;//ȫ������
        damage_adj = 110;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����"HIW"��"HIR"��"HIW"��"NOR"��\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("��ķ����������޷�������\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("���޷����о�����������Լ��ˣ�\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("����û��Ӧ������һ�ΰɣ�\n");
                return 1;
        }
       message_vision(HIC"\n$N����$n"NOR+HIC"���һ��:"BLINK+HIR"����"NOR+HIC"��\n"NOR,me,target);
       message_vision(HIR"\n      ��   ��   ��   ��   ��   ��   ��   ��\n\n\t"HIB"��   ��   ��   ��   ��   ��   ��\n\n"HIR"      ��   ��   ��   ��   ��   ��   ��   ��\n\n"NOR,me,target);
	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIY "$N"NOR+HIY"�������������죬�����л���һ���ʺ磬\n$N"NOR+HIY"���ɵ�һ㶣�ɲ�Ǽ䣬�ǲʺ��ֻ��һ��,\n������������ɫ���ˣ���$N"NOR+HIY"�����ǽ�����������Ƣ��\n��ɫ�Ѷ�ȥ$n"NOR+HIY"����־��$n"NOR+HIY"�ε��뵽�ˣ�\n����Ǵ�˵�е�"HIW"��"HIC"��"HIW"��"HIY"��\n" NOR,
			//initial message
		HIY "ֻ����ѽ����Ĳ�����$n"NOR+HIY"�����ϣ�\n" NOR, 
			//success message
		HIY "����$n"NOR+HIY"��������һ�������˹�ȥ��\n" NOR, 
			//fail message
		HIY "����$N"NOR+HIY"һ����С�ģ���û�г�ȥȴ�����Լ��Ľ��ϣ�\n" NOR, 
			//backfire initial message
		HIY "ֻ����ѽ����Ĳ�����$n"NOR+HIY"�����ϣ�\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+YEL+target->name()+HIM"��"NOR+CYN+me->name()+HIM"��"HBRED+HIW"��ɽׯ"NOR+HIY"��ѧ"HIC"��"HIW"��"HIR"��"HIW"��"HIC"��"NOR+HIM"��ȥ��"HIB"���޵ظ�"HIM"����˵"NOR+YEL+target->name()+HIM"�Ǳ��򽣴��Ķ�����";
                        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
                       }
        me->start_busy(2+random(3));
        return 3+random(6);
}


