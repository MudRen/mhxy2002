//by lovezhe@mhxy for 2001.12.22
//Cracked by Roath

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "��ȸ����",
                "action":
"$N����$wһ����һ��"+RED"����ȸ������"NOR"$N�߸�Ծ������չ���ڷɵ���ȸѹ��$n��$N����$wֱ��$n��$l��ȥ",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸ����",
                "action":               "$N����һת������һ��������$wͻȻ���������ͬ��ȸ����Ľ�����������$n��$l,��һ��"+RED"����ȸ���衹"NOR"",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸ����",
                "action":
"$N�趯$w��ͻȻһ�����壬һ��"+RED"����ȸ���衹"NOR",$wЮ�������Ϳ��������$n��$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸѪ��",
                "action":
"$N����$wһ�����ó������⣬����һ��㱼䣬����"+RED"����ȸѪ�衹"NOR"$w��бб�ص�����$n��$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸ����",
                "action":
"$N���������񹦵���ȸ������������ע�����е�$w��һ��"+RED"����ȸ���衹"NOR",�ּ��ֿ����$n$l��ȥ",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸ����",
                "action":
"$N��Ȼ������һչ������$wͻ�����߽�â��৵ش�����$n��$l,��һ��"+RED"����ȸ����"NOR"",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸ�ڿ�",
                "action":               
"$N���һ��������$w������˷��ڰ�գ�����"+RED"����ȸ�ڿա�"NOR"�����š�\n$nֻ����ȫ�����$w����֮��",
                "dodge":                -10,
                "parry":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ȸ˦β",
                "action":
"$N��һ���񺿣��Ѿ������е�$w��Ϊһ�壬����һ�еس���$n��������$n��������֮ʱͻȻһ��ת��\n����$wȴ������Ϣ�ش���$n��$l����������"+RED"����ȸ˦β��"NOR"",
                "dodge":                -10,
                "parry":                -10,
                "damage":               90,
                "damage_type":  "����"
        ]),


});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취����ȸ����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
	string name;
	mapping actions;

        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        actions=action[random(6)];
        }else {
        actions=action[i];
        }

	name=actions["name"];
	me->set_temp("kill_msg","special_msg");
	me->set_temp("special_msg",name);

	return actions;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ��ȸ����\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����ȸ����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zhuque-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/zhuque-sword/" + func;
}


