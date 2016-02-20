// link 2001.2.16
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$Nʹ����ᦾ����е�����ʽ������������������е�$w����һ���âն��$n��$l",
		"force":		500,
		"damage_type":	"����"
	]),
	([	"action":		"$N��һ����һ�С��������������е�$w�ó�һƬɡ����ɢ��$n��$l",
		"force":		400,
		"damage_type":	"����"
	]),
	([	"action":		"$Nɡ����ת�����е�$wһ�С�Թ���������������������$n��$l",
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$N��Ӱ�ζ���ɡ�������ң�һ�С������������������е�$w������·ͻȻ����$n��$l",
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$N��˫�ŵ�أ�ɡ������һ�С�������������ȫ��ת��һ��ɡ�����$n",
		"force":		300,
		"damage_type":	"����"
	]),
	([	"action":		"$Nɡ�����ϣ�һ�С�����������������һ��$n���벻���ĽǶ�����$n��$l",
		"force":		200,
		"damage_type":	"����"
	]),
	([	"action":		"$N�����е�$w���ҺỮ��һ�С��������������������ػصؿ�ɨ��$n��$l",
		"force":		300,
		"damage_type":	"����"
	]),
        ([      "action":               "$Nʹ����ᦾ����е�����ʽ������������������е�$wѸ���ޱȵؿ���$n��$l",
                "force":                600,
                "damage_type":  "����"
        ]),
});

mapping query_action(object me)
{
    if (random(me->query_skill("umbrella",1)) > 50 &&
        me->query_skill("force",1) > 200 &&
        me->query("force") > 200 ) {
             me->add("force", -200);
             return ([
                  "action": "$Nҧ����⣬������Ѫ������ɡ�ϣ��ۼ�ȫ�����������$n",
                  "force": 1000,
                  "damage_type": "����"]);
    }
    return action[random(sizeof(action))];
}


int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 200 )
                return
                notify_fail("����ڹ��ķ�����㣬�޷�����ᦾ�����\n");
        if( (int)me->query_skill("guangming-force", 1) < 200 )
                return
		notify_fail("��Ĺ����ķ�����㣬�޷�����ᦾ�����\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="umbrella") || (usage=="parry");
}


int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "umbrella" )
		return notify_fail("���������һ��ɡ��������ɡ����\n");

	if( (int)me->query("kee") < 80 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 80);
	return 1;
}
int effective_level() { return 50;}

string *parry_msg = ({
	"$nʹ����ᦾ����е����С�Թ�޽ٶ����������ѡ������е�$v���ɾ���ɡĻ��סȫ��\n",
});

string *unarmed_parry_msg = ({
        "$nʹ����ᦾ����е����С�Թ�޽ٶ����������ѡ������е�$v���ɾ���ɡĻ��סȫ��\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return umbrella_parry_msg[random(sizeof(umbrella_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("lingjie") + "/lingfan-san/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    int i=random(10);
    if( damage_bonus < 100 ) return 0;
    if (me->query("force")<=200) return 0;
    if(random(me->query_skill("lingfan-san", 1)) > 40
       &&i>7&&me->query_skill("lingfan-san", 1) > victim->query_skill("lingfan-san", 1)
       && (me->query("force") + me->query("con")*30) > victim->query("force")){
       if(victim->query_skill("force")/2 < me->query_skill("force")){
          victim->apply_condition("yun_poison", 2+victim->query_condition("yun_poison"));
	me->add("force",-200);
	message_vision(YEL"$N��ת���ˣ�\n"NOR,victim);}
       else {me->apply_condition("yun_poison", 1+victim->query_condition("yun_poison"));
	me->add("force",-200);
	message_vision(YEL"$N���˲��ɣ������Լ���ת���ˣ�\n"NOR,me);}
        }
}