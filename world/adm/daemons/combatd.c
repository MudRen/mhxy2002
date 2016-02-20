// combatd.c
//by tianlin@mhxy 2001.5.1 for pansi and shushan NK
//by tianlin@mhxy 2001.8.10 �������±༭��һ��

#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/cmds/std/valid_kill.h"

inherit F_DBASE;

int victim_lose(object killer,object victim,string killerid);
void victim_penalty(object victim);
int nk_gain(object killer, object victim);
string chinese_daoxing(int gain);

int check_family(string fam);

//this mapping indicates whether this family class is
//xian or yao.
mapping family=(["����ɽ���Ƕ�":1,
                 "�Ϻ�����ɽ":1,
                 "����˧��":1,//By tianlin@mhxy for 2001.7.2
                 "������":1,
                 "��ׯ��":1,
                 "�䵱��":1,//By tianlin@mhxy for 2001.9.27
		   "��ʥ��":1,//���޸Ĺ�
                 "��ɽ��":1,//�Ѹ���
                 "������":1,//By tianlin@mhxy for 2001.12.13.��1����Ѯ�������
                 "��ɽׯ":1,//By tianlin@mhxy for 2001.12.13.
                 "���޵ظ�":0,
                 "��ս�":0,
                 "�¹�":0,
                 "���":0,
                 "��������":0,
		   "����":0,
                 "�ƻ���":0,//��2001.11��ǰ�������
                 "��˿��":-1,
                 "��ѩɽ":-1,
                 "ħ��":-1,
                 "���ƶ�":-1,//moyun-shou��ǿ,���޸ļ���pfm 2��
                 "��ԯ��Ĺ":-1,//�޸����
                 "����ɽ�Ž���":-1,//�ݲ�����
                 "�ݿ�ɽ�޵׶�":-1,
                 "��ʯɽ�̲�̶":-1, 
]);

string *guard_msg = ({
	CYN "$N"NOR+CYN"ע����$n"NOR+CYN"���ж�����ͼѰ�һ�����֡�\n" NOR,
	CYN "$N"NOR+CYN"������$n"NOR+CYN"��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N"NOR+CYN"�������ƶ��Ų�����Ҫ�ҳ�$n"NOR+CYN"��������\n" NOR,
	CYN "$N"NOR+CYN"Ŀ��ת���ض���$n"NOR+CYN"�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
	CYN "$N"NOR+CYN"�������ƶ��ŽŲ����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N"NOR+HIW"��$n"NOR+HIW"������������ۺ죬���̴���������\n" NOR,
	HIW "$N"NOR+HIW"����$n"NOR+HIW"��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N"NOR+HIW"��$n"NOR+HIW"һ���棬������˵�ʹ���������\n" NOR,
	HIW "$N"NOR+HIW"һ��Ƴ��$n"NOR+HIW"�����ߡ���һ�����˹�����\n" NOR,
	HIW "$N"NOR+HIW"һ����$n"NOR+HIW"�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N"NOR+HIW"�ȵ�����$n"NOR+HIW"�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N"NOR+HIW"�ȵ�����$n"NOR+HIW"�����У���\n" NOR,});

string *winner_msg = ({
	CYN "\n$N"NOR+CYN"������Ц��˵���������ˣ�\n\n" NOR,
	CYN "\n$N"NOR+CYN"˫��һ����Ц��˵�������ã�\n\n" NOR,
	CYN "\n$N"NOR+CYN"ʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	CYN "\n$n"NOR+CYN"��ɫ΢�䣬˵��������������\n\n" NOR,
	CYN "\n$n"NOR+CYN"������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
	CYN "\n$n"NOR+CYN"���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "ս������");
	set("id", "combatd");
	
//	if(!MISC_D->check_date()) {shutdown(-1);return;}
}

string damage_msg(int damage, string type)
{
	string str;

//	return "��� " + damage + " ��" + type + "��\n";

	if( damage == 0 ) return "���û������κ��˺���\n";

	switch( type ) {
	case "����":
	case "ץ��":
	case "����":
		if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
		else if( damage < 40 ) return "���"MAG"���͡�"NOR"��һ������һ���˿ڣ�\n";
		else if( damage < 80 ) return "���"MAG"���͡�"NOR"��һ������һ��"HIR"Ѫ����"NOR"���˿ڣ�\n";
		else if( damage < 160 ) return "���"MAG"���͡�"NOR"��һ������һ���ֳ�������˿ڣ�����$N����"HIR"��Ѫ��\n"NOR;
		else return "���ֻ����$nһ���Һ���$p��$l������һ������ǵĿ����˿ڣ�\n";
		break;
	case "����":
	case "����":
		if( damage < 10 ) return "���ֻ����$n��Ƥ�����������������Ӷ���ࡣ\n";
		else if( damage < 20 ) return "�����$n$l����һ��ϸ����Ѫ�ۡ�\n";
		else if( damage < 40 ) return "���"CYN"���ۡ�"NOR"һ������һ��"HIR"Ѫ����"NOR"���˿ڣ�\n";
		else if( damage < 80 ) return "���ֻ��"CYN"���ۡ�"NOR"��һ����$n��$l������Ѫ��Ȫӿ��ʹ��$pҧ���гݣ�\n";
		else if( damage < 160 ) return "���"CYN"���ۡ�"NOR"��һ������һ���ֳ�������˿ڣ�����$N����"HIR"��Ѫ��\n"NOR;
		else return WHT"���ֻ����$nһ���Һ���$p��$l������һ������ǵĿ����˿ڣ�\n"NOR;
		break;
	case "ǹ��":
	case "����":
		if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
		else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
		else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˲���\n";
		else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
		else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ�\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ�������һ������$n��Ƥ��������һ��׺ۡ�\n";
		else if( damage < 20 ) return "�����$p��$l���¼���Ѫ�ۡ�\n";
		else if( damage < 40 ) return "���һ�������У�$n��$l��ʱ���ּ���Ѫ�ף�\n";
		else if( damage < 80 ) return "���һ�������У�$n����Ѫ����ע��\n";
		else if( damage < 120 ) return "���"MAG"���꡹"NOR"��һ����$n��ʱ��Ѫ�ɽ���\n";
		else if( damage < 160 ) return "�����һ��"MAG"���꡹"NOR"��һ����$n�����û�����Ѫ��\n";
		else return "���"MAG"���꡹"NOR"���ص����У�$n������ǧ���׿ף�Ѫ���Ĵ���ɣ�\n";
		break;
	case "����":
	case "ȭ��":
	case "����":
		if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
		else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
		else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
		else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
		else if( damage < 120 ) return "���"WHT"���项"NOR"��һ����$n����������\n";
		else if( damage < 160 ) return "�����һ��"WHT"���项"NOR"��һ�����$n�����˺ü�������һ��ˤ����\n";
		else if( damage < 240 ) return "������صػ��У�$n"WHT"���项"NOR"��һ���³�һ��"HIR"��Ѫ��\n"NOR;
		else return "���ֻ����"WHT"���项"NOR"��һ�����죬$n��һ�����ݰ���˳�ȥ��\n";
		break;
	case "ײ��":
	case "����":
		if( damage < 10 ) return "���ֻ����������������ڸ�$nɦ��һ������\n";
		else if( damage < 20 ) return "�����$p��$l�ҳ�һ��С������\n";
		else if( damage < 40 ) return "����Ҹ����ţ�$n��$l��ʱ����һ���ϸߣ�\n";
		else if( damage < 80 ) return "����Ҹ����ţ�$n�ƺ�һ����Ȼ���˲�С�Ŀ���\n";
		else if( damage < 120 ) return "���"WHT"���项"NOR"��һ����$n�۵����������ˣ�\n";
		else if( damage < 160 ) return "�����һ��"RED"���䡹"NOR"��һ���ҵ�$n��ð���ǣ���һ��ˤ����\n";
		else if( damage < 240 ) return "������ص����У�$n��ǰһ�ڣ����ۡ���һ���³�һ����Ѫ��\n";
		else return "���ֻ����"RED"���䡹"NOR"��һ�����죬$n���ҵ�Ѫ��ģ�����Ҳ��̶ã�\n";
		break;
	case "����":
	case "����":
		if( damage < 20 ) return "�����$n����һ�����ţ����ڸ�$nɦ��һ������\n";
		else if( damage < 40 ) return "���$n����һ�Σ����˵�С����\n";
		else if( damage < 80 ) return "���$n��Ϣһ�ϣ���Ȼ�е����������\n";
		else if( damage < 120 ) return "���$n����һ���ʹ�����������˲��ᣡ\n";
		else if( damage < 160 ) return "���"HIY"���ˡ�"NOR"��һ��$nֻ������ǰһ�ڣ�˫��������ֹ��\n";
		else return RED+BBLU"���ֻ����"HIY"���ˡ�"NOR+RED+BBLU"��һ�����죬$n"HIW"���ۡ�"NOR+RED+BBLU"��һ���³�һ��"HIR"��Ѫ"NOR+RED+BBLU"����������������λ��\n"NOR;
		break;
		case "����":
		case "����":
		if( damage < 10 ) return "���ֻ����$n��Ƥ�����������������Ӷ���ࡣ\n";
		else if( damage < 20 ) return "�����$n$l���һ����΢���Ϻۡ�\n";
		else if( damage < 40 ) return "���"HIC"��ž��"NOR"��һ����$n$l���һ��������"HIR"Ѫ�ۣ�\n"NOR;
		else if( damage < 80 ) return "���ֻ��"HIC"��ž��"NOR"��һ����$n��$l�����Ƥ��������ʹ��$pҧ���гݣ�\n";
		else if( damage < 160 ) return "���"HIC"��ž��"NOR"��һ�����죡��һ�º�������ֻ���$nƤ��������"HIR"Ѫ���ɽ���\n"NOR;
		else return "���ֻ����$nһ���Һ���$w���صس�����$p��$l��$n��ʱѪ���ɣ�ʮ�����˾�����\n";
		break;
	default:
		if( !type ) type = "�˺�";
		if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
		else if( damage < 20 ) str = "��������΢��";
		else if( damage < 30 ) str = "������һ��";
		else if( damage < 50 ) str = "������һ������";
		else if( damage < 80 ) str = "��������Ϊ���ص�";
		else if( damage < 120 ) str = "�������൱���ص�";
		else if( damage < 170 ) str = "������ʮ�����ص�";
		else if( damage < 230 ) str = "�����ɼ������ص�";
		else str =  "�����ɷǳ����µ�����";
		return str + type + "��\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
	if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
	if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
	if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
	if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧���Ų�����ȥ��" NOR;
	if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
	if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
	return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
	if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
	if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
	if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧���Ų�����ȥ��" NOR;
	if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
	if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

//report_shen messages
string sen_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "������ͷ�����ѣ�һ��Ҳ���Ժ���" NOR;
	if( ratio > 90 ) return HIG "�������Լ����Դ����ƺ��е㲻̫�þ���" NOR;
	if( ratio > 80 ) return HIY "��������Щ�Ժ��ˡ�" NOR;
	if( ratio > 60 ) return HIY "��ȷ�е��Ժ��ˣ�������ó������ϱ���" NOR;
	if( ratio > 40 ) return HIR "���۷�ֱ���ڽ����ѣ����ǿ�ʼ���ҡ�" NOR;
	if( ratio > 20 ) return HIR "���Ժ�����ҡҡ�λΣ��Ѿ��治�������ϱ��ˡ�" NOR;
	if( ratio > 10 ) return RED "�����Ѿ����ڼ��Ȼ����С�" NOR;
	return RED "�����Ѿ���ȫ��ʧ����ʱ���п��ܱ�����ȥ��" NOR;
}

varargs void report_status(object ob, int effective)
{
	if( effective ) 
		message_vision( "( $N" + eff_status_msg(
			       (int)ob->query("eff_kee") * 100 /(1+(int)ob->query("max_kee")) ) 
			       + " )\n", ob);
	else
		message_vision( "( $N" + status_msg(
			       (int)ob->query("kee") * 100/(1+(int)ob->query("max_kee")) ) 
			       + " )\n", ob);
}

varargs void report_sen_status(object ob, int effective)
{
	
	message_vision( "( $N" + sen_status_msg(
		(int)ob->query("sen") * 100 /(1+(int)ob->query("max_sen")) ) 
		+ " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power;

	if( !living(ob) ) return 0;

	level = ob->query_skill(skill);

	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
			level += ob->query_temp("apply/defense");
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;

	power = (level*level*level) / 3;
	if( (status = ob->query("max_sen")) > 0 )  {
		if ( power > 100000 )
		   power = power / status * (int)ob->query("sen");
        else
		   power = power * (int)ob->query("sen") / status;
	}

	power +=  ob->query("combat_exp");

	return power;
}
/*
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do1_attack(object me, object victim,object who)     //���ǵ�ִ��
{
int myda,vda;
int one,two,three;
int ap,dp;
one=me->query("soilder");
two=victim->query("soilder");
three=victim->query("defendance");
message_vision("$N�����г���һ�ӡ������Ͼۣ�ӿ���Ǳߣ�һ�߼���������Խ��ǽ��һ�߾���������\n",me);
message_vision("$Nֻ����ǽ�������ɣ���ʯ�������ص����״򲻶���ˮ�ò�����\n",me);
ap=one*me->query("train_level");
dp=two*(victim->query("train_level")+three);
if((ap<=0)&&(dp>0))
{
message("vision",HIY+"�����ַ�ϭ��:"+NOR+HIC+me->query("name")+"��"+
victim->query("short")+"�Ľ����޹�������"+who->query("name")+"����ʤ��.\n"NOR,users());
tell_object(who,"�㱣���˳��У��õ���һ��ĵ��н�����\n");
who->add("combat_exp",1000);
me->set("soilder",0);
me->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}
if((ap>0)&&(dp<=0) )
{
message("vision",HIY+"�����ַ�ϭ��:"+NOR+HIC+me->query("name")+"��ռ��"+
victim->query("short")+" ,"+who->query("name")+"����ʧ��.\n"NOR,users());
victim->set("owner",me->query("id"));
victim->set("soilder",0);
victim->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}
if(ap < dp )
{
message_vision("$N�����Ƶ����ο�����һ���ҵ��ⲫ֮��$n�Ĺ��ƻ���������\n",who,me);
myda=(dp-ap)/1000;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"����ƴ���ֿ�����������:"+chinese_number(myda)+"������\n");
me->add("soilder",-myda);
tell_object(who,"����ƴ����������������:"+chinese_number(myda/2)+"������\n");
victim->add("soilder",-myda/5);
}else
if(ap < 5*dp)
{
message_vision("$N�����Ƶ�����ǿ����һ���ҵ��ⲫ֮��$n�����ò�������\n",who,me);
myda=(ap-dp)*dp/(ap*1000);
vda=(ap-dp)*ap/(dp*1000);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"����ƴ���ֿ�����������:"+chinese_number(myda)+"������\n");
me->add("soilder",-myda);
tell_object(who,"����ƴ����������������:"+chinese_number(vda)+"������\n");
victim->add("soilder",-vda);
victim->add("defendance",-1);
if(victim->query("defendance")<0) victim->set("defendance",0);
}else 
{
message_vision("$N��������Ȼ��ǿ����һ���ҵ��ⲫ֮��$n���ǽ���ռ�����ơ�\n",who,me);
myda=(ap-dp)*dp/(ap*2000);
vda=(ap-dp)*ap/(dp*500);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;

tell_object(me,"���˵ֿ���������������:"+chinese_number(myda)+"������\n");
me->add("soilder",-myda);
tell_object(who,"����ƴ����������������:"+chinese_number(vda)+"������\n");
victim->add("soilder",-vda);
victim->add("defendance",-2);
if(victim->query("defendance")<0) victim->set("defendance",0);
}
}
*/
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
// cloud��2000,9������ŭ��ֵ�����Ըı�ս���г��е��˺��ȣ��Լ�����Ƶ��
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
   mapping my, your, action, victim_action;
   string limb, *limbs, result;
   string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
   mixed foo;
   int ap, dp, pp;
   int damage, damage_bonus, defense_factor;
   int wounded = 0;
   //int cost;
   int mod_val;
   
   my = me->query_entire_dbase();
   your = victim->query_entire_dbase();

   //
   // (1) Find out what action the offenser will take.
   //
   action = me->query("actions");
   if( !mapp(action) ) {
     me->reset_action();
     action = me->query("actions");
     if( !mapp(action) ) {
        CHANNEL_D->do_channel( this_object(), "sys",
          sprintf("%s(%s): bad action = %O",
             me->name(1), me->query("id"), me->query("actions", 1)));
        return 0;
     }
   }
   result = "\n" + action["action"] + "��\n";

   //
   // (2) Prepare AP, DP for checking if hit.
   //
   if( objectp(weapon) )   {
            if( weapon->query("use_apply_skill") )
                attack_skill = weapon->query("apply/skill_type");
            else
                attack_skill = weapon->query("skill_type");
        }
   else             attack_skill = "unarmed";

   limbs = victim->query("limbs");
   limb = limbs[random(sizeof(limbs))];

   ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
   //�����������������û�кܴ�ķ�ŭֵ���п��ܻ�����׺ݣ����������������
   if( me->query("anger")>30 )//��ŭʱ
   if( me->query("anger")>90 || random(5)>3 )
   {
       me->set_temp("anger_attack",random(100));//˵����������������������
	   ap = (ap*me->query("anger")*me->query("anger_attack"))/10000 + ap;
	   me->set("anger",0);//���������ˣ�ŭ����ʧ
   }
   
   if( ap < 1) ap = 1;
   
   dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
    dodge_skill = victim->query_skill_mapped("dodge");
   mod_val = 0;
   if( dodge_skill )  {
       victim_action = SKILL_D(dodge_skill)->query_action();
      if( victim_action && victim_action["dodge_power"] )
         mod_val = victim_action["dodge_power"];
   }
   //˵����������������������
   if( victim->query_temp("anger_attack") )
   {
	   dp = (dp*(100+random(victim->query("cps"))-victim->query_temp("anger_attack")))/100;
	   victim->delete_temp("anger_attack");
   }

   if( dp < 1 ) dp = 1;
   if( victim->is_busy() ) dp /= 3;

        if( userp(me))
        {
                        if( my["force_factor"] && (my["force"] >
                        my["force_factor"]) )
                                        my["force"] -= my["force_factor"];
                        else
                                        my["force_factor"] = 0;
        }

   if( action["dodge"] )  mod_val += action["dodge"];
   if( dp > 1000000 )
       mod_val = dp / 100 * (100 + mod_val);
    else 
      mod_val = (100 + mod_val) * dp / 100;
   if( mod_val < 1 ) mod_val = 1;
   if( mod_val > ((ap + dp)/100*80)) mod_val = (ap + dp)/100*80;

   //
   // (3) Fight!
   //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
   //     AP and DP are greater than zero, so we always have chance to hit
   //     or be hit.
   //  
   if( random(ap + dp) < mod_val ) {      // Does the victim dodge this hit?

     if( !dodge_skill ) {
        dodge_skill = "dodge"; 
           result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
     }
     else   {
           if( victim_action && victim_action["dodge_action"] )
          result += victim_action["dodge_action"];
     else
          result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
     }

     if( dp < ap && (!userp(victim) || !userp(me)) 
     &&     random(sizeof(victim->query_enemy())) < 4
     &&   random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 ) {
        your["combat_exp"] += 1;
        victim->improve_skill("dodge", 1);
     }

     // This is for NPC only. NPC have chance to get exp when fail to hit.
     if( (ap < dp) && !userp(me) ) {
        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
        me->improve_skill(attack_skill, random(my["int"]));
     }
     damage = RESULT_DODGE;

   } else {

     //
     //   (4) Check if the victim can parry this attack.
     //
     if( victim->query_temp("weapon") ) {
        pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        if( !weapon ) pp *= 2;
        parry_skill = victim->query_skill_mapped("parry");
     } else {
      pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
        parry_skill = victim->query_skill_mapped("unarmed");
        if( weapon ) pp /= 2;
     }

     if( victim->is_busy() ) pp /= 3;
     if( pp < 1 ) pp = 1;
     mod_val = 0;
        if( action["parry"] )       mod_val = action["parry"];
     if( pp > 1000000 )
        mod_val = pp / 100 * (100 + mod_val);
     else
        mod_val = (100 + mod_val) * pp / 100;
     if(mod_val < 1)  mod_val = 1;
     if( mod_val > ((ap + dp)/100*80)) mod_val = (ap + dp)/100*80;

     if( random(ap + pp)< mod_val ) {

        //parry_skill = victim->query_skill_mapped("parry");
        if( !parry_skill ) parry_skill = "parry";
        // change to SKILL_D(parry_skill) after added parry msg to those
        // martial arts that can parry.
        // because of number of local variable limit, here use
        // dodge_skill
        dodge_skill = SKILL_D(parry_skill)->query_parry_msg(weapon);
        if( dodge_skill )     result += dodge_skill;
        else
            result += SKILL_D("parry")->query_parry_msg(weapon);

        if( pp < ap && (!userp(victim) || !userp(me)) 
        &&     random(sizeof(victim->query_enemy())) < 4
        &&   random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 ) {
          your["combat_exp"] += 1;
          victim->improve_skill("parry", 1);
        }
        damage = RESULT_PARRY;

     } else {

        //
        //   (5) We hit the victim and the victim failed to parry
        //

        damage = me->query_skill(attack_skill) / 4;
        damage += me->query_temp("apply/damage");
        damage = (damage + random(damage)) / 2;
        if( action["damage"] )
          damage += action["damage"] * damage / 100;

        damage_bonus = me->query_str();

        // Let force skill take effect.
        if( my["force_factor"] && (my["force"] > my["force_factor"]) ) {
          if( force_skill = me->query_skill_mapped("force") ) {
             foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
             if( stringp(foo) ) result += foo;
             else if( intp(foo) ) damage_bonus += foo;
          }
        }

        if( action["force"] )
          damage_bonus += action["force"] * damage_bonus / 100;

        if( martial_skill = me->query_skill_mapped(attack_skill) ) {
          foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
          if( stringp(foo) ) result += foo;
          else if(intp(foo) ) damage_bonus += foo;
        }

        // Let weapon or monster have their special damage.
        if( weapon ) {
          foo = weapon->hit_ob(me, victim, damage_bonus);
          if( stringp(foo) ) result += foo;
          else if(intp(foo) ) damage_bonus += foo;
        } else {
          foo = me->hit_ob(me, victim, damage_bonus);
          if( stringp(foo) ) result += foo;
          else if(intp(foo) ) damage_bonus += foo * 3 / 4;
        }

        if( damage_bonus > 0 )
          damage += (damage_bonus + random(damage_bonus))/2;
        if( damage < 0 ) damage = 0;


        // Let combat exp take effect
        defense_factor = your["combat_exp"];
        while( random(defense_factor) > my["combat_exp"] ) {
          damage -= damage / 3;
          defense_factor /= 2;
        }

        //
        //   (6) Inflict the damage.
        //

        damage = victim->receive_damage("kee", damage, me );


        if( (me->is_killing(victim) || weapon)
        && random(damage) > (int)victim->query_temp("apply/armor") ) {
          // We are sure that damage is greater than victim's armor here.
          victim->receive_wound("kee",
             damage - (int)victim->query_temp("apply/armor"), me);
          wounded = 1;
        }
          
        result += damage_msg(damage, action["damage_type"]);

		//�����ܵ��˺���victim������ŭ����ŭֵ�����˺���С����
        if( damage > victim->query("max_kee")/5)
			victim->add("anger",10+random(10));
		else
              victim->add("anger",1+random(10));
		tell_object(victim,"���ŭ�������ˣ�\n");
		if( victim->query("anger")>100 ) victim->set("anger",100);

        //
        //   (7) Give experience
        //

        if( !userp(me) || !userp(victim) ) {
          if( (ap < dp)
          &&   (random(my["sen"]*100/my["max_sen"] + my["int"]*my["cps"]) > 150) ) {
             my["combat_exp"] += 1;
             if( my["potential"] - my["learned_points"] < 100 )
               my["potential"] += 1;
             me->improve_skill(attack_skill, 1);
          }
          if( random(your["max_kee"] + your["kee"]) < damage ) {
             your["combat_exp"] += 1;
             if( your["potential"] - your["learned_points"] < 100 )
               your["potential"] += 1;
          }
        }
     }
   } 

   result = replace_string( result, "$l", limb );
   if( objectp(weapon) )
     result = replace_string( result, "$w", weapon->name() );
   else if( stringp(action["weapon"]) )
     result = replace_string( result, "$w", action["weapon"] );
   if( objectp(victim->query_temp("weapon")) )
     result = replace_string( result, "$W", 
       victim->query_temp("weapon")->name() );

   if ((damage != RESULT_DODGE) && (damage != RESULT_PARRY) )
     message_vision(result, me, victim );
   else
     if ( (string)me->query("env/brief_message") != "YES" 
       && (string)victim->query("env/brief_message") != "YES" ) 
        message_vision(result, me, victim );

   if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
     if( damage > 0 )
        tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d��Mod��%d���˺�����%d\n" NOR,
          ap, dp, pp, mod_val, damage));
     else
        tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d��Mod��%d\n" NOR,
          ap, dp, pp, mod_val));
   }
   if( wizardp(victim) && (string)victim->query("env/combat")=="verbose" ) {
     if( damage > 0 )
        tell_object(victim, sprintf( GRN "AP��%d��DP��%d��PP��%d��Mod��%d���˺�����%d\n" NOR,
          ap, dp, pp, mod_val, damage));
     else
        tell_object(victim, sprintf( GRN "AP��%d��DP��%d��PP��%d��Mod��%d\n" NOR,
          ap, dp, pp, mod_val));
   }

   if( damage > 0 ) {
     report_status(victim, wounded);
     if( victim->is_busy() ) victim->interrupt_me(me);
     if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) ) {
       // fight until one side's kee is < 50%
       if( victim->query("kee") < victim->query("max_kee") * 50 / 100)  {
         //�����ˣ�ŭ��ʧ
		 me->set("anger",0);
		 victim->delete_temp("anger_attack");
		 victim->set("anger",0);
		 me->delete_temp("anger_attack");

		 me->remove_enemy(victim);
         victim->remove_enemy(me);
         message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
          }
     }
   }

   if( functionp(action["post_action"]) )
     evaluate( action["post_action"], me, victim, weapon, damage);

   if( damage > 0 && attack_type != TYPE_QUICK &&
    me->query_temp("perf_quick") && me->is_fighting(victim) )   {
        if( me->query_temp("weapon") &&
        me->query_temp("perf_quick/"+me->query_temp("weapon")->query("skill_type")) )  {
           if( me->query_temp("perf_quick/msg") )
               message_vision(CYN + me->query_temp("perf_quick/msg") +NOR, me, victim);
           else
               message_vision(CYN + "$N"NOR+CYN"���Ʋ����ˣ���$n"NOR+CYN"չ������������"+NOR, me, victim);
           do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
           return 1;
        }
    }

   // See if the victim can make a riposte.
   if( attack_type==TYPE_REGULAR
   &&   damage < 1
   &&   victim->query_temp("guarding") ) {
     victim->set_temp("guarding", 0);
     if( random(my["cps"]) < 5 ) {
        message_vision("$Nһ�����У�¶����������\n", me);
        do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
     } else {
        message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
        do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
     }
   }
}
varargs int shibai(object me, object victim,object who)
{
message("vision",HIY+"�����ַ�ϭ��"+NOR+HIC+me->query("name")+"��"+
victim->query("short")+"�Ľ����޹�������"+who->query("name")+"����ʤ��.\n"NOR,users());
//tell_object(who,"�㱣���˳��У��õ���һ��ĵ��н�����\n");
//who->add("combat_exp",1000);
me->set("soilder",0);
me->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}

varargs int chenggong(object me, object victim,object who)
{
message("vision",HIY+"�����ַ�ϭ��"+NOR+HIC+me->query("name")+"��ռ��"+
victim->query("short")+" ,"+who->query("name")+"����ʧ��.\n"NOR,users());
victim->set("owner",me->query("id"));
victim->set("owner_name",me->query("name"));
victim->set("soilder",0);
victim->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}

varargs int do1_attack(object me, object victim,object who)     //���ǵ�ִ��
{
int myda,vda;
int one,two,three;
int ap,dp;
one=me->query("soilder");
two=victim->query("soilder");
three=victim->query("defendance");
message_vision("$N�����г���һ�ӡ������Ͼۣ�ӿ���Ǳߣ�һ�߼���������Խ��ǽ��һ�߾���������\n",me);
message_vision("$Nֻ����ǽ�������ɣ���ʯ�������ص����״򲻶���ˮ�ò�����\n",me);
ap=one*me->query("train_level");
dp=two*(victim->query("train_level")+three);
if((ap<=0)&&(dp>0))
{
  shibai(me,victim,who);
  return 1;
}
if((ap>0)&&(dp<=0))
{
   chenggong(me,victim,who);
   return 1;
}
if(ap < dp )
{
message_vision("$N�����Ƶ����ο�����һ���ҵ��ⲫ֮��$n�Ĺ��ƻ���������\n",who,me);
myda=(dp-ap)/1000;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"����ƴ���ֿ�����������:"+chinese_number(myda)+"������\n");
me->add("soilder",-myda);
if(me->query("soilder") < 0) { me->set("soilder",0); shibai(me,victim,who); return 1;}
tell_object(who,"����ƴ����������������:"+chinese_number(myda/2)+"������\n");
victim->add("soilder",-myda/5);
if(victim->query("soilder") < 0) { victim->set("soilder",0); chenggong(me,victim,who); return 1;}
}else
if(ap < 5*dp)
{
message_vision("$N�����Ƶ�����ǿ����һ���ҵ��ⲫ֮��$n�����ò�������\n",who,me);
myda=(ap-dp)*dp/(ap*1000);
vda=(ap-dp)*ap/(dp*1000);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"����ƴ���ֿ�����������:"+chinese_number(myda)+"������\n");
me->add("soilder",-myda);
if(me->query("soilder") < 0) { me->set("soilder",0); shibai(me,victim,who); return 1;}
tell_object(who,"����ƴ����������������:"+chinese_number(vda)+"������\n");
victim->add("soilder",-vda);
if(victim->query("soilder") < 0) { victim->set("soilder",0); chenggong(me,victim,who); return 1;}
victim->add("defendance",-1);
if(victim->query("defendance")<0) victim->set("defendance",0);
}else 
{
message_vision("$N��������Ȼ��ǿ����һ���ҵ��ⲫ֮��$n���ǽ���ռ�����ơ�\n",who,me);
myda=(ap-dp)*dp/(ap*2000);
vda=(ap-dp)*ap/(dp*500);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"���˵ֿ���������������:"+chinese_number(myda)+"������\n");
me->add("soilder",-myda);
if(me->query("soilder") < 0) { me->set("soilder",0); shibai(me,victim,who); return 1;}
tell_object(who,"����ƴ����������������:"+chinese_number(vda)+"������\n");
victim->add("soilder",-vda);
if(victim->query("soilder") < 0) { victim->set("soilder",0); chenggong(me,victim,who); return 1;}
victim->add("defendance",-2);
if(victim->query("defendance")<0) victim->set("defendance",0);
}
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
	object ob;

	if( !living(me) ) return;
	if( me->query_temp("netdead") )  return;
  	if( victim->query_temp("netdead") )   {
   	    if( member_array( me, victim->query_netdead_enemy() ) == -1 )
		return;     // can't start fight if the victim is already netdead
 	}

	if( !me->visible(victim)
	&& (random(100 + (int)me->query_skill("perception")) < 100) )
		return;
   /*    if(me->query("attacking")){                 //���ǿ�ʼ��
      ob=find_player(victim->query("owner"));
      do1_attack(me,victim,ob);
            } */
	// If victim is busy or unconcious, always take the chance to make an attack.
	// added: if victim is in "no_move", similar to "is_busy".
	if( victim->is_busy() || (victim->query_temp("no_move")) || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

	// Else, see if we are brave enough to make an aggressive action.
	} else if( random( (int)victim->query("cps") * 3 ) < ((int)me->query("cor") + (int)me->query("bellicosity") / 50) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") ) {
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		return;
	} else return;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int bellicosity;

	if( !me ) return;// Are we still exist( not becoming a corpse )?
	me->set_temp("looking_for_trouble", 0);
	if( !obj ) return;

	if( wizardp(obj) ) return;	

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	bellicosity = (int)me->query("bellicosity");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if(	(int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

	if( bellicosity > (int)me->query("score") 
	&&	!wizardp(obj) ) {

	    // auto kill, mark my_killer_list. -- mon 9/23/98
	    if(userp(me) && userp(obj)) {
        	set_my_killer_list(me, obj);
	    }

	    message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
		+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
	    me->kill_ob(obj);
	} else {
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
			+ "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
//	obj->fight_ob(me);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event, string msg)
{
	switch(event) {
		case "dead":
			message_vision("\n$N���ˡ�\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
			break;
		case "revive":
			message_vision("\n$N���������۾��������˹�����\n\n", ob);
			break;
                case "death_rumor":
			CHANNEL_D->do_channel(this_object(),"rumor",msg);
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	int bls,exp, pot, score,level;
	string vmark,killmsg,rkmsg;
	int gain,gain1,lose;
	string str,killerid;
	object weapon;
	// Call the mudlib killer apply.
	killer->killed_enemy(victim);

	if( userp(victim) ) { // victim is user.
	    
	    string *my_killer_list;
	    int init_killer;
	    int no_pk;

	   killer->add("PKS", 1);
	   killer->add("PKD", 1);
	   
	   killerid=killer->query("id");
           //����������¼��������������  by LitChi
          victim->set("kill/killer_name",killer->query("name"));
//By tianlin@mhxy for 2002.1.23�޸�litchi����ʱ�����pker id.
          victim->set("kill/killer_id",killer->query("id"));
          victim->set("kill/killer_date",BJTIME_D->chinese_time(1, time()) ); 

	   // mon 8/4/98
	   // to see whether the killer has init the kill on me.
	   // if yes, then this is PK. (init_killer!=-1)
	   // if no, (means the victim init the kill and got killed),
	   // then treat this as normal death. (init_killer==-1)
	   my_killer_list=victim->query_temp("my_killer_list");
	   victim->delete_temp("my_killer_list");

	   if(!my_killer_list) init_killer=-1;
	   else init_killer=member_array(killerid, my_killer_list);
		
	   no_pk=killer->query_condition("no_pk_time");
	   if(no_pk>10) init_killer=1; // killed by a player who
	   // has PK record, then this is PK.
           // regardless who init it.

///////////////////////////////////////////////////////////////////////
killmsg=killer->query_temp("kill_msg");
    if(killmsg)
    {
	switch (killmsg)
	{
		case "slash":
	 	{	rkmsg="ն";	}
		break;
		case "slice":
	 	{	rkmsg="��";	}
		break;
		case "chop":
	 	{	rkmsg="��";	}
		break;
		case "hack":
	 	{	rkmsg="��";	}
		break;
		case "thruse":
	 	{	rkmsg="��";	}
		break;
		case "pierce":
	 	{	rkmsg="��";	}
		break;
		case "wave":
	 	{	rkmsg="��";	}
		break;
		case "whip":
	 	{	rkmsg="��";	}
		break;
		case "impale":
	 	{	rkmsg="��";	}
		break;
		case "rake":
	 	{	rkmsg="��";	}
		break;
		case "bash":
	 	{	rkmsg="��";	}
		break;
		case "crush":
	 	{	rkmsg="��";	}
		break;
		case "slam":
	 	{	rkmsg="��";	}
		break;
		case "throw":
	 	{	rkmsg="��";	}
		break;
		case "shoot":
	 	{	rkmsg="��";	}
		break;
//now start cast :
//		case "cast_qiankun":	//�ǹ����� transfer , chuqiao, qiankun, yinshen
//		{	rkmsg="";	}
//		break;
		case "cast_zhenhuo":
		{	rkmsg="̫�����";		}
		break;
		case "cast_baxian":
		{	rkmsg="���ɴ���";		}
		break;
		case "cast_bighammer":
		{	rkmsg="������ħ��";		}
		break;
		case "cast_jingang":
		{	rkmsg="�ٻ����";		}
		break;
		case "cast_jinguzhou":
		{	rkmsg="������";		}
		break;
		case "cast_thunder":
		{	rkmsg="������";		}
		break;
		case "cast_invocation":
		{	rkmsg="�ٻ��콫";		}
		break;
		case "cast_fenshen":
		{	rkmsg="������";		}
		break;
		case "cast_dingshen":
		{	rkmsg="����";		}
		break;
		case "cast_light":
		{	rkmsg="�����";		}
		break;
		case "cast_jieti"://escape, tudun, suliao, huanying
		{	rkmsg="��ħ�����";		}
		break;
		case "cast_sanmei":
		{	rkmsg="��ζ���";		}

		break;
		case "cast_zhuang":
		{	rkmsg="ƽ���";		}
		break;
		case "cast_arrow":
		{	rkmsg="�������";		}
		break;
		case "cast_shiyue":// mihun huimeng
		{	rkmsg="ʴ����";		}
		break;
		case "cast_qingwang":
		{	rkmsg="����";		}
		break;
		case "cast_hufa":
		{	rkmsg="�ٻ�����";		}
		break;
		case "cast_freez":
		{	rkmsg="ѩ�����";		}
		break;
		case "cast_jiushen":
		{       rkmsg="����";       }
		break;
		case "cast_jianshen":
		{       rkmsg="����";       }
		break;
		case "cast_tuntian":
		{       rkmsg="ħ������";       }
		break;
		case "cast_gouhun"://miwu
		{	rkmsg="������";		}
		break;
		case "cast_animate":
		{	rkmsg="������";		}
		break;
		case "cast_fu":
		{	rkmsg="��ʦ����";		}
		break;
		case "cast_wuzhishan":
		{	rkmsg="��ָɽ";		}
		break;
		case "cast_sanmei":
		{	rkmsg="�������";		}
		break;
		case "cast_yading":
		{	rkmsg="����ѹ��";		}
		break;
/*		case "cast_":
		{	rkmsg="";		}
		break;
*/
// now start perform msg
		case "perform_sanban":
		{	rkmsg="�޵����師";		}
		break;
		case "perform_haotan":
		{	rkmsg="�����̾";		}
		break;
		case "perform_hongyan":
		{	rkmsg="���հ׷�";		}
		break;	
		case "perform_zplw":
		{	rkmsg="�������";		}
		break;	
		case "perform_daoda":
		{	rkmsg="����һ��";		}
		break;	
		case "perform_daoluan":
		{	rkmsg="��������";		}
		break;	
        	case "perform_huadie":
		{	rkmsg="��    ��";		}
		break;
		case "perform_mantian":
		{	rkmsg="��ϼ����";		}
		break;
		case "perform_wang":
		{	rkmsg="���޵���";		}
		break;
		case "perform_kai":
		{	rkmsg="����ٵ�";		}
		break;
		case "perform_meihua":
		{	rkmsg="÷������";		}
		break;
		case "perform_lei":
		{	rkmsg="����ŭ��";		}
		break;
		case "perform_zhua":
		{	rkmsg="�޳�צ";		}
		break;
		case "perform_ldlh":
		{	rkmsg="�����ֻ�";		}
		break;
		case "perform_lunhui":
		{	rkmsg="����";		}
		break;
		case "perform_pudu":
		{	rkmsg="�ȹ��ն�";		}
		break;
		case "perform_xlfh":
		{	rkmsg="��������";		}
		break;
		case "perform_storm":
		{	rkmsg="��������";		}
		break;
		case "perform_diyu":
		{	rkmsg="�������";		}
		break;
		case "perform_pili":
		{	rkmsg="��������";		}
		break;
		case "perform_qiankun":
		{	rkmsg="Ǭ��һ��";		}
		break;
		case "perform_pozhan":
		{	rkmsg="�����ٳ�";		}
		break;
		case "perform_zhangxinlei":
		{	rkmsg="������";		}
		break;
		case "perform_flower":
		{	rkmsg="��Ůɢ��";	}
		break;
		case "perform_diezhang":
		{	rkmsg="����";		}
		break;
		case "perform_huifeng":
		{	rkmsg="�ط�";		}
		break;
		case "perform_wuxue":
		{	rkmsg="��ѩ";		}
		break;
		case "perform_sheshen":
		{	rkmsg="����";		}
		break;
		case "perform_three":
		{	rkmsg="���ˡ���";	}
		break;
		case "perform_chaofeng":
		{	rkmsg="���񳯷�";	}
		break;
		case "perform_feijian":
		{	rkmsg="����Ͷ��";	}
		break;
		case "perform_yaowu":
		{	rkmsg="�������";	}
		break;
		case "perform_fumo":
		{	rkmsg="������ħ";	}
		break;
		case "perform_jinsheng":
		{	rkmsg="��������";	}
		break;
		case "perform_wanjian":
		{	rkmsg="�򽣾�";	}
		break;
		case "perform_duanshui":
		{	rkmsg="��ˮ�޺�";	}
		break;
		case "perform_feilong":
		{	rkmsg="����̽����";	}
		break;
		case "perform_buhui":
		{	rkmsg="����";	}
		break;
		case "perform_fengchan":
		{	rkmsg="��������";	}
		break;
		case "perform_ji":
		{	rkmsg="��ǹ";	}
		break;
	        case "perform_huohun":
		{	rkmsg="���";	}
		break;
	       case "perform_lihuo":
		{	rkmsg="�������";	}
		break;
	       case "perform_shenli":
		{	rkmsg="����";	}
		break;
	       case "perform_leidong":
		{	rkmsg="�׶�����";	}
		break;
	       case "perform_break":
		{	rkmsg="��Ԫһ��";	}
		break;
	       case "perform_fengbo":
		{	rkmsg="�޾��粨";	}
		break;
	       case "perform_juejian":
		{	rkmsg="�������";	}
		break;
	       case "perform_jianzhang":
		{	rkmsg="����";	}
		break;
	       case "perform_jianmang":
		{	rkmsg="��ý�â";	}
		break;
	    case "perform_jianqi":
		{	rkmsg="��ý���";	}
		break;
	    case "perform_luanwu":
		{	rkmsg="Ⱥħ����";	}
		break;
	    case "perform_tiandi":
		{	rkmsg="���ͬ��";	}
		break;
	    case "perform_zouxiao":
		{	rkmsg="���ﴫ��";	}
		break;
	    case "perform_damoyange":
		{	rkmsg="��Į���";	}
		break;
/*		case "perform_":
		{	rkmsg="";		}
		break;
*/
		
//now start exert .........// �ǹ����� recover refresh transfer regenerate heal lifeheal
		case "exert_sheqi":
		{	rkmsg="����";		}
		break;
		case "exert_roar":
		{	rkmsg="����";		}
		break;
		
		case "special_msg"://����Ĺ���
		{	rkmsg=killer->query_temp("special_msg");	
			killer->delete_temp("special_msg");
		}
		break;
	}
      }//if(killmsg)
	



           if(userp(killer) && init_killer!=-1) { // killer is user.
//           if(userp(killer))  // killer is user.
	     killer->apply_condition("no_pk_time",240+no_pk);
	       //limit on how many one can pk in a row.
             lose=victim_lose(killer,victim,killerid);
	     gain=lose*8/10;
	     if(gain<0) gain=0;
	     victim->delete_temp("last_fainted_from");
	     /*
	     if(killerid==victim->query("kill/last_killer")) {
	       //discourage repeated killing same player.
	       gain1=victim->query("kill/last_lose")/2;
               if(gain>gain1) {
	         gain=gain1;
               }
             }
	     */
	     if(lose>100)
	       killer->delete("kill/last_killer");
	     //any one can kill this killer to
	     //get maximum dx benefit.
	     //including the one who last killed 
	     //this killer.
	     //here check lose>100, so one can't
	     //pk a newbie to erase the last_killer flag.
	     killer->add("kill/pkgain",gain);
	     killer->add("daoxing",gain);

	     victim->set("kill/last_killer",killerid);
	     //the victim is protected for repeated
	     //killing by the same killer.
	     victim->set("kill/last_lose",gain);
	     //actually last_lose is what the killer gains,
	     //not really the victim lose.
	     //victim loss is in /death/combat_exp_loss
//	     victim->add("kill/pklose",lose);
//	     victim->add("daoxing",-lose);
             
	     victim_penalty(victim);

             str=chinese_daoxing(gain);
             if(strlen(str)>1) {
               str=killer->name(1)+"�õ�"+str+"���У�";
             } 

//      add by dragon for PK rumor
//by tianlin �޸���һ����ɫ

			weapon=killer->query_temp("kill_weapon");
			if(weapon && rkmsg)
			{			
	     		str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"��"HIY+weapon->name()+HIM+rkmsg+"���ˡ�"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			} else {
			if(rkmsg && !weapon)
			{
			str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"��һ��"+HIW"��"+rkmsg+"��"+HIM"��ȥ����������"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			}else if(weapon && !rkmsg){
			str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"��"HIY+weapon->name()+HIM"��ȥ�˼���������"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
					   }else {
			str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"ɱ���ˡ�"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
						  }
			
				
			
	     	}
	     	bls=10;
		killer->delete_temp("kill_weapon");
		killer->delete_temp("kill_msg");
           } else {    // killer is not user or killer didn't init the kill.
	       int i;
	       string last_faint;
	       object fainter;
	       // mon 8/1/98
	       // check who fainted the victim.
	       // if it was a player faint the victim,
	       // give the player credit for pk :)
	       last_faint=victim->query_temp("last_fainted_from");
	       if(last_faint) {
		   fainter=find_player(last_faint);
		   if(fainter && userp(fainter)) {
	             if(!my_killer_list) init_killer=-1;
	             else init_killer=
			 member_array(last_faint, my_killer_list);

		     if(init_killer!=-1) {
                       fainter->apply_condition("no_pk_time",240+
	                 fainter->query_condition("no_pk_time"));
		       log_file("death","["+ctime(time())+"] "+
			       victim->query("id")+" was fainted by "+
			       fainter->query("id")+" and killed by "+
			       killer->query("id")+".\n");
		     }
		   }
	       }

               victim_penalty(victim);

	       bls = 10;
//	       CHANNEL_D->do_channel(this_object(), "rumor",
//		  sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(1)));
/////////////////for NK rumor
//by tianlin 2001.8.15		
			weapon=killer->query_temp("kill_weapon");
			if(weapon && rkmsg)
			{			
	     		str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"��"HIY+weapon->name()+HIM+rkmsg+"���ˡ�";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			} else {
			if(rkmsg && !weapon)
			{
			str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"��һ��"+HIW"��"+rkmsg+"��"+HIM"��ȥ�����޵ظ���";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			}else if(weapon && !rkmsg){
			str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"��"HIY+weapon->name()+HIM"��ȥ�����޵ظ���";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
					   }else {
			str=victim->name(1)+"��[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m��"+killer->name(1)+"ɱ���ˡ�";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
						  }
if ( userp(killer) && !killer->query_temp("kill_killer")) {
                                CHANNEL_D->do_channel(this_object(), "rumor",
                                sprintf("%s���ٸ�ͨ���ˡ�", killer->name(0)));
                        
        } 
			if(victim->query("PKD")>9)
			{			
	     		str=HIR+"ɱ�˷�"+HIM+victim->name(1)+"��"+HIW+
	         	MISC_D->find_place(environment(killer))+HIM+"��"+killer->name(1)+HIM+"�͵�����"+HIM+"��"+killer->name(1)+"�õ���Ӧ�еĽ�����";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
                           killer->add("daoxing",5000);
                           victim->set("PKD",0);
	}
			if(killer->query("PKD")>9)
			{			
	     		str=victim->name(1)+"��"+HIW+
	         	MISC_D->find_place(environment(killer))+HIM+"��"HIR"ɱ�˷�"HIM+killer->name(1)+HIM+"ɱ����"+HIM+"��"+killer->name(1)+"����ʴ�ۼ��ٵ���ʮ������Ϊ������";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
                           killer->add("daoxing",-15000);
                           victim->set("PKD",0);
	}	
	     	}
           }
	} else {  //NPC is the victim.
	  if(userp(killer)) {
                int reward;

		reward=nk_gain(killer, victim);

		// nk_reward is defined as needed for each NPC
		// this allows individual NPC to customize NK reward.
		// mon 12/24/99
		if((int)victim->nk_reward(killer, reward)>0) {
		    // this NPC has its own reward.
		} else if(reward>0) {
		  string msg;
                  killer->add("kill/nkgain",reward);
		  killer->add("daoxing",reward);
                  str=chinese_daoxing(reward);
                  tell_object(killer,"\n��õ���"+str+"���С�\n");
		  msg=sprintf("%s(%d)ɱ����%s(%d)���õ�%d����С�", 
		    killer->query("id"),(killer->query("daoxing")+
			killer->query("combat_exp"))/2, 
		    victim->query("id"),(victim->query("daoxing")+
			victim->query("combat_exp"))/2,reward);
		  log_file("npc_kill","["+ctime(time())+"] "+msg+"\n");
		  CHANNEL_D->do_channel(this_object(), "sys",msg);
		}
	  }
	  killer->add("MKS", 1);
	  bls = 1;
	}

        if(!userp(killer) &&
	   ((killer->query("daoxing")+killer->query("combat_exp"))/10>
	    (victim->query("daoxing")+victim->query("combat_exp"))) ) bls=0;
        //mon 2/15/98
	//can't use newbie to kill NPC to increase NPC's bls.

	// NPC got 10 times of bellicosity than user.
	killer->add("bellicosity", bls * (userp(killer)? 1: 10));

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

        if(userp(killer)) killer->save();
	if(userp(victim)) victim->save();
}
//��ɱ������Ҳ����趨
void victim_penalty(object victim)
{
        int i;

	// by snowcat 2/21/1998 for death/*
	int combat_exp_loss = (int)victim->query("combat_exp") / 40;
	int dx_loss = (int)victim->query("daoxing") / 40;

        victim->clear_condition();
        // Give the death penalty to the dying user.
        victim->set("bellicosity", 0);

	i=victim->query_condition("no_pk_time");
	if(i>240) victim->apply_condition("no_pk_time",i-80);

        victim->set("death/mud_age",victim->query("mud_age"));
        victim->set("death/combat_exp_loss",combat_exp_loss);
        victim->set("death/dx_loss",dx_loss);
	log_file("death",victim->query("id")+
	  " lost "+combat_exp_loss+" exp points and "
	  + dx_loss+ " dx points.\n");

	victim->add("combat_exp", -combat_exp_loss);
	victim->add("daoxing", -dx_loss);
       victim->add("death/die",1);
	victim->delete("vendetta");
	if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
	if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
  ((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );//��������qn�����趨Ϊ2��֮1
        if(random(100)>(int)victim->query("kar")) {
          victim->set("death/skill_loss",1);
  	  victim->skill_death_penalty();
	}
	 else
//	  victim->set("death/skill_loss",0);

        victim->save();
}

int nk_gain(object killer, object victim)
{
	    string fam, fam1;
	    int cla, eff_dx, eff1, eff2, dx, reward, nkgain;

	    // some NPC has no rewards.
	    // mon 3/9/99
	    if(victim->query("no_nk_reward")) return 0;

            //can't kill NPCs which were fainted by
	    //other players to get daoxing.
            if(victim->query_temp("last_fainted_from")
               && victim->query_temp("last_fainted_from")!=
               killer->query("id")) return 0;

            fam=killer->query("family/family_name");

	    if(fam && !undefinedp(family[fam])) {//player must have a
	                                         //family.
              cla=family[fam];
              eff_dx=victim->query("eff_dx");
	      nkgain=victim->query("nkgain");

              //can't kill NPCs of the same menpai as the player
	      //to get daoxing.
	      fam1=victim->query("family/family_name");
	      if(fam1 && fam==fam1)
	        return 0;

              if(eff_dx!=0 && cla*eff_dx>0)
	        return 0;
		//for NPC being set eff_dx, only 
		//if cla*eff_dx<=0 (not all in xian or all in yao)
		//can gain daoxing.

              //For NPC which has not been set eff_dx,
	      //the default is everyone can kill them to get
	      //dx reward, however, the default value is low.
	      if(!eff_dx) { 
	        //default value for eff_dx and nkgain.
		//the default nkgain is low.
		//If want to increase the value for certain NPC,
		//then need to set its eff_dx and nkgain.

                int dxn=0;

		eff_dx=(victim->query("daoxing")+
			victim->query("combat_exp"))/2;
                if(eff_dx>20000)
		  dxn=eff_dx/3;
		else if(eff_dx>5000)
		  dxn=eff_dx/2;
                else 
		  dxn=eff_dx;
		  //make it easier for newbie.
                eff_dx=dxn;
              }

	      if(!nkgain) {
	        int effdx=eff_dx;

		if(effdx<0) effdx=-effdx;

		if(effdx>667000) 
		  nkgain=600;
                else if(effdx>333000)
		  nkgain=500;
                else if(effdx>100000)
		  nkgain=400;
                else if(effdx>33000)
		  nkgain=300;
                else if(effdx>17000)
		  nkgain=200;
                else if(effdx>5000)
		  nkgain=150;
                else if(effdx>2000)
		  nkgain=100;
                else if(effdx>500)
		  nkgain=50;
                else nkgain=25;

		nkgain=nkgain+20;
	      }

                if(eff_dx<0) eff_dx=-eff_dx;
                eff1=eff_dx/8;
		eff2=eff_dx/4;
		dx=(killer->query("daoxing")+
			killer->query("combat_exp"))/2;
		if(dx>eff_dx) reward=0;
		else if(dx>eff2) reward=nkgain;
		else if(dx>eff1) reward=10*(dx-eff1)/(eff2-eff1)*
		  nkgain/10;
                else reward=0;

		if(cla==0 || (cla!=0 && !fam1)) reward=reward*2/3;
		//cla==0: people not xian and not yao. e.g. longgong, moon.
		//cla!=0: people either xian or yao. if they kill
		//        no family NPC, dx reward reduse.

		return reward;
             
            }
	    return 0;
}

int victim_lose(object killer,object victim,string killerid) 
{            int lose,exp_k,exp_v;
             int lose1;

             if((wizardp(victim)&&!wizardp(killer))
	        ||(!wizardp(victim)&&wizardp(killer)))
		return 0;

             if(victim->query_temp("last_fainted_from")
               && victim->query_temp("last_fainted_from")!=
               killerid) {
               lose=0;
             } else {
               exp_k=killer->query("daoxing");
               exp_v=victim->query("daoxing");
               if (exp_k>exp_v) {
                 lose=10*exp_v/(exp_k+1)*(4000+exp_v)/500;
		  // a exp_v/exp_k pre-factor.
		 if(exp_k>exp_v*4) lose=0;
		 // if less then 1/4 dx, then no damage.
               } else {
                 lose=(4000+exp_v)/50;  // about 2% lose for victim.
               }
               if(lose<0) lose=0;
               if(lose>exp_v) lose=exp_v;
             }
	     
	     // this is the maximum lose.
	     lose1=(int)victim->query("daoxing") / 40;
	     if(lose>lose1) lose=lose1;
	     
	     return lose;
}

string chinese_daoxing(int gain)
{            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"��";
             if(day) str=str+chinese_number(day)+"��";
             if(hour) str=str+chinese_number(hour)+"ʱ��";

             return str;
}

int check_family(string fam)
{
    if(fam && !undefinedp(family[fam]))
      return family[fam];
    else
      return 0;
}


//the following functions are for performs...weiqi
//copy and modified from spelld.c

int attacking_perform_success(object attacker, object target, int skill_level, int success_adj)
{
        int ap, dp, success;
 
        ap = ( skill_level * skill_level * skill_level / 10 ); //this is from skill.
        //at high exp, the skill level can not follow, so need adjustment here.
        ap = ap*(1+attacker->query("combat_exp")/500000);
        ap = ap+attacker->query("combat_exp");
        dp = target->query("combat_exp");

        success = 0;

        if ( success_adj < 20 ) success_adj = 20;
        else if( success_adj > 500 ) success_adj = 500;

        ap = ap*success_adj/100;

        if( random(100)>dp*100/(ap+dp) ) success = 1;

        return success;
}

int attacking_perform_damage(object attacker, object target, int damage_adj)
{
        int a_neili, d_neili, damage;

        if( damage_adj < 50 ) damage_adj = 50;
        else if( damage_adj > 200 ) damage_adj = 200;

        //will use current neili...but do not allow it exceeds 2 time of the max.
        a_neili = attacker->query("force");
        if( a_neili > 2*attacker->query("max_force") ) a_neili = 2*attacker->query("max_force");
        d_neili = target->query("force");
        if( d_neili > 2*target->query("max_force") ) d_neili = 2*target->query("max_force");


        //neili and qi. weaker than cast here...
        damage = (a_neili - d_neili)/30 + 
                random(attacker->query("eff_kee") / 30)-random(target->query("eff_kee") / 30);

        //mana_factor, here the attacker has some advantage.
        //the damage_adj higher, the better for attacker.
        damage += (3*damage_adj/200) //weaker than cast here...
                *( attacker->query("force_factor") - random(target->query("force_factor")) );

        //for backfire, we need let it be serious...
        if( damage < 0 ) damage = damage - target->query("force_factor"); 
        //here increase the damage, since previously it's included in random()

        damage = damage*damage_adj/100; //last damage scaled again.

        //finally, we need let the force level useful...
        //the setting is, at enabled level 200, the damage will double.
        if( damage > 0 )
        {
                damage += (damage*(int)attacker->query_skill("force"))/200;
        }
        else if ( damage < 0 )
        {
                damage += (damage*(int)target->query_skill("force"))/200;
        }
	
	
        return damage;
}

/*
weiqi 981206
attacking-cast...called from spells function.
modified for perform...
a typical call would be:

        COMBAT_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
		skill_level, 
			//level of skill used
                success_adj, 
                        //success adjustment
                damage_adj, 
                        //damage adjustment
                "both", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$N����ָͷѸ������ͻȻ����һ�磡��Ȼ��������������һ����$n��ȥ��\n" NOR,
                        //initial message
                HIC "���$n���յý�ͷ�ö\n" NOR, 
                        //success message
                HIC "����$n����һ���Ͷ��˿�����\n" NOR, 
                        //fail message
                HIC "���ǻ��汻$n�Է���һ�ƣ�����$N�ؾ��ȥ��\n" NOR, 
                        //backfire initial message
                HIC "���̫������ɣ�$n���յý�ͷ�ö\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );
*/
void attacking_perform(
        object attacker, 
        object target, 
	int skill_level,//the level of skill used to attack.
        int success_adj, 
        int damage_adj, //default value is 100 for this 2 parameters.
        string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
        string msg_init, 
        string msg_success, 
        string msg_fail, 
        string msg_backfire_init,
        string msg_backfire_success)
{
        int damage;

        //first, show the initial message...
        message_vision( msg_init, attacker, target );

        //calculate if the casting can happen...
        if( attacking_perform_success(attacker, target, skill_level, success_adj) == 0 )
        {
                message_vision( msg_fail, attacker, target );
                //let the target kill attacker.
                target->kill_ob(attacker);
                return;
        }

        damage = attacking_perform_damage(attacker, target, damage_adj);

        if( damage > 0 ) //attacker hit target
                SPELL_D->apply_damage(attacker, target, damage, damage_type, msg_success);

        else if( damage < 0 ) //backfire
        {
                message_vision(msg_backfire_init, attacker, target);
                SPELL_D->apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
        }

        else //damge=0
		message_vision(HIB "������ñ�$N��������ס��˭Ҳû�гԿ���\n" NOR, target);

        //let the target kill attacker.
        target->kill_ob(attacker);

        return;
}


