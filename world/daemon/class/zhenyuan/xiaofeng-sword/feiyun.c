//feiyun.c
//created by focus
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
        string *style_xiaofeng = ({
HIG "�ɽ�����$N����ᵯ����$w��ֱ��$n��$l��" NOR,
HIG "�ƽ�����$N����$w�������ƣ�Ʈ��$n��$l��" NOR,
HIG "ʯ������$N����$w������ǧ�����$n��$l��" NOR,
HIG "Ȫ������$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��" NOR
});
        string *style_zouxiao= ({
HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��" NOR,
HIR "������������$N�����һ������������$w��Х��������$n��$l��" NOR,
HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��" NOR
});
        string *style_mix= ({
HIG "�ɽ�����$N����ᵯ����$w��ֱ��$n��$l��" NOR,
HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��" NOR,
HIG "�ƽ�����$N����$w�������ƣ�Ʈ��$n��$l��" NOR,
HIR "������������$N�����һ������������$w��Х��������$n��$l��" NOR,
HIG "ʯ������$N����$w������ǧ�����$n��$l��" NOR,
HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��" NOR,
HIG "Ȫ������$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��" NOR
});

	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۷���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
   if((int)me->query_skill("xiaofeng-sword", 1) < 120 )
     return notify_fail("���[������½�]����Ҫ��������\n");

   if((int)me->query("force") < 400)
     return notify_fail("��������������޷�ʹ�á�������������\n");

   if((int)me->query("mana") < 400)
     return notify_fail("��ķ����������޷�ʹ�á�������������\n");

   if(me->query("family/family_name")!="��ׯ��")
     return notify_fail("�����ׯ���ӣ��޷�ʹ�á�������������\n");
   
   if((int)me->query("kee") < 400 )
     return notify_fail("�������������޷�ʹ��[��������]��\n");

   if((int)me->query("sen") < 400 )
     return notify_fail("�㾫�񲻹����޷�ʹ��[��������]��\n");

        if(me->query_temp("feiyun_busy")) 
               return notify_fail("����ù��������������µȻ����ð�..\n");

	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("zouxiao")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "sword"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("sword") != "xiaofeng-sword") {FLAG=0; continue;}
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;

        if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("sword");
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/3);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/3);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->kill_ob(target);
	for(i=0;i<sizeof(style_mix);i++)
	if(i%2) COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
	else    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/3);
        me->receive_damage("kee",200);
        me->add_temp("apply/damage",-(extra_you+extra_me)/2);
        me->add("force",-400);
        you->add_temp("apply/attack",-(skl_you+skl_me)/3);
        you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/5);
        me->add_temp("apply/damage",extra_me/3);
        for(i=0;i<sizeof(style_xiaofeng);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_xiaofeng[i]);
        me->add_temp("apply/attack",-skl_me/5);
        me->add_temp("apply/damage",-extra_me/3);
        me->receive_damage("kee",150);
        me->add("force",-300);
	}	
	me->set_temp("feiyun_busy",1);
        call_out("remove_effect",5,me);
	return 1;
}
void remove_effect(object me) {
if (!me) return;
me->delete_temp("feiyun_busy");
}