//yueya-fork by redrain

inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":               
"$N���˵��һ�����ȣ����ƽ���һ�㣬���$n��֪���롣\n"
"����һ�С������ķ�����$n��$l��ȥ", 
     "dodge":     10,
     "parry":     -10,
     "damage":     45,
     "damage_type":   "����"
        ]),
        ([      "action":               
"$Nһ�����е�$w�����е�$w��$n��$l������ش���,\n"
"$nһ�֮�䣬$w�ѵ�$n��$l����һ�С���׳ɽ�ӡ�!",
     "dodge":     0,
     "parry":     -20,
     "damage":     50,
     "damage_type":   "����"
        ]),
        ([      "action":               
"$N����һ�����ڿշ�����̩ɽѹ��֮ʽ��$nֱ�˶��£�\n"
"���е�$w���ź��������һ�С�ǧ��һ��������$n��$l", 
     "dodge":   10,
     "parry":   -20,
     "damage":   45,
     "damage_type":   "����",
        ]),
        ([      "action":               
"$N���е�$wһת��һ����ȣ�һʽ����籩�꡹������˷�����$n,\n"
"������ֻ������˷�����Ӱ���ƺ��Ѱ�$n������·",
     "dodge":   0,
     "parry":   -25,
     "damage":   50,
     "damage_type":   "����",
        ]),
        ([      "action":
"$Nһ�����е�$w������һ��ԲȦ������һƬ���ˣ�\n"
"һ�С����տ������ó�һƬ��Ӱ������ʵʵ�Ĵ���$n��$l", 
     "dodge":   10,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "����",       
 ]),
        ([      "name":   "һ",
    "action" : WHT"$N�����һ�㣬˫�ֳ�$w������һ��ֱ��$nͷ����ȥ��"NOR,
    "dodge" : -15,
    "damage" : 70,
    "force"  : 65,
    "parry"  :-65,
    "damage_type" : "����"
	]),
	([      "name":   "��",
    "action" : WHT"$N�����ڿն�������$w"WHT"�ó���㺮�ǣ���$nȫ���������ڣ�"NOR,
    "dodge" : -15,
    "damage" : 75,
    "parry"  :-70,
    "force"  : 70,
    "damage_type" : "����"
	]),
	([      "name":   "��",
    "action" : WHT"$N���θ�һ��أ��͵�һ�����������棬���в���$n��˫�ţ�"NOR,
    "dodge" : -10,
    "damage" : 80,
    "parry"  :-75,
    "force"  : 75,
    "damage_type" : "����"
]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return
notify_fail("�������������û�а취ѧϰ������������������ɡ�\n");

        if( (int)me->query("str") < 25 )
return notify_fail("������̫�ͣ�ʹ������������\n");
 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "fork" )
                return
notify_fail("���������һ�����Ӳ���ѧ��������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="fork")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
     int i;
	i=me->query("juesha");
	if( !me->query("juesha") ) {
     mapping* m_actions;
     m_actions=me->query("skill_yueya-fork");
     if(me->query("skill_yueya-fork")==0 )
     return action[random(5)];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    	
        return action[random(6)];
	}else {
	return action[i];
	}
     
     
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("force") < 5 )
                return
notify_fail("�����������������û�а취��ϰ��\n");
        me->receive_damage("kee", 25);
        me->add("force", -10);
        write("�㰴����ѧ����һ������������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bibotan") + "/yueya-fork/" + func;
}