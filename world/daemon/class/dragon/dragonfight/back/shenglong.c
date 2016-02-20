//By tianlin@mhxy for 2002.1.10

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
// #include "/u/tianlin/eff_msg.h";

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	int mydf;
	int ap, dp, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(YEL"��Ҫ��˭ʹ������"HIR"��"HIC"®ɽ������"HIR"��"NOR+YEL"?\n"NOR);

	mydf=(int)me->query_skill("dragonfight",1);
	if(mydf<100) 
		return notify_fail("�����Ϊ��������������������ľ��衣\n");
	mydf=(int)me->query_skill("dragonforce",1);
	if(mydf<100) 
		return notify_fail("�����Ϊ��������������������ľ��衣\n");
	
	if((int)me->query("force")<500) return
	    notify_fail("������������ˡ�\n");

//	msg = CYN "$N���ƻӳ���ն��$n����磬\n";
	mycor=me->query_cor();
	youcps=target->query_cps();
	ob=target->query_temp("weapon");
	str="����";
	if(objectp(ob)) str="���е�"+ob->query("name");
	ap=COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp/=2;	
	pp=COMBAT_D->skill_power(target,"unarmed", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=me->query_str();
	damage_bonus=mystr*(100+me->query("force_factor"))/100;

	if( random(youcps) < 15 || random(ap+dp)>dp) {
		msg  = ""HIB"$NĬ�˱̺���ͨ����һչ����Ȼʹ��"HIC"��®ɽ�����ԡ�"NOR+HIB"��������$n\n\n"NOR;
		msg += "$N����һ��"BLINK+HIC"���޵�������"NOR"��˫��һ���ɨ��ֱ��$n���������ˣ�\n";
		msg += ""HIB"ֻ����$n��ǰ�š�������һ�� ...\n" NOR;
              COMBAT_D->report_status(target);
              msg+="$N����һ������$n�������һȭ������"HIG"������������"NOR"�������ף������ޱȣ�\n" NOR;
	       msg += HIB"$N����һ�£�$n��ͷ��������������һ�����죡\n";
              COMBAT_D->report_status(target);
		msg += "$N���˷�����ͻȻ������ǰ����ָ�繳��һ��"HIW"��Ǳ�����á�"NOR"����׼$n��ͷ��һ��ץ�˹�ȥ��\n";
		msg += HIB"$N����һ�£�$n��ͷ��������������һ�����죡\n";
              COMBAT_D->report_status(target);
		message_vision(msg, me, target);
	//	msg+=COMBAT_D->report_status(target, 0);
              message_vision(HIC"$N���һ���������������������Ծ������ֱ��$n��\n"NOR,me,target);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=me->name()+"��Ȼʹ���˶����ش���[1;36m��®ɽ�����ԡ�[2;37;0m[1;35m��[1;35m�����������������ְԵ���ȭ��֮�¡�";
	                message("channel:rumor",HIM"\n\n��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
	} //else {
	//	msg += "����$p������$P����ͼ�����Խ����\n" NOR;
	//	message_vision(msg, me, target);
	//}
	delay = random(1)+2;
	me->start_busy(delay);
	me->add("force", -300);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));

	return damage;
}


