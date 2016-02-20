//By tianlin@mhxy for 2001.12.15

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "name":                 "",
                "action":
"$Nб���������ϣ�����$wӭ��һ�Σ����������$n�ĺ���",
                "dodge":                0,
		"parry":		-20,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N����һ��������$w������ߣ�������Ϣ������$n��˫��",
                "dodge":                -10,
		"parry":		0,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N˫��һ��$wͻ��Ѫ�⣬��\t"HIY"��\t"HIB+BLINK"ħ\t"NOR+HIR"��"NOR"\t��һ��������$n��ȥ",
                "dodge":                5,
		"parry":		-15,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "name":                 "",
                "action":
"$N����ͻȻ��������������$wЮ��һ��Ѫ������$n��$l",
                "dodge":                5,
		"parry":	-5,
                "damage":               40,
                "damage_type":  "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if(  !(ob = me->query_temp("weapon"))
        ||     (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�����ѧ�񼫵�����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="blade";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{

        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("�����������������û�а취��ϰ�񼫵�����\n");

        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���񼫵�����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("shenjian") + "/shenji-blade/" + func;
}


