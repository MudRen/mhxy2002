//by tianlin 2001.7.30
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":
"$N����΢�֣�����һ��ʹ��һ��"BLINK+HIY"�������ˡ�"NOR"��һֻ�Ұ׵���צ̽��$n��$l",
                "dodge":                15,
                "parry":                15,
                "force":                120,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$Nٿ��һ��ת��˫��������һ��������һ��"BLINK+HIC"���������"NOR"��ѹ��$n����������",
                "dodge":                -35,
                "parry":                -35,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����΢б���漴���һ�������ֺ��ƺ�צʹ��"BLINK+HIR"�������Ʒ���"NOR"������$n��$l",
                "dodge":                5,
                "parry":                5,
                "force":                80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"BLINK+HIG"���������ˡ�"NOR"��˫�ֻ����쳣��׼$n��$l��ȥ",
                "dodge":                -5,
                "parry":                -10,
                "force":                80,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N������Σ�����ƮƮ�����ĳʱ��̣�һ��"BLINK+HIW"��ƮȻ������"NOR"����$n$l",
                "dodge":                15,
                "parry":                15,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��"BLINK+YEL"������·��"NOR"�����Ծ���䲻�������ǰ��׼$n$l�ɳ�һ��",
                "dodge":                -5,
                "parry":                -5,
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$n$l���������һ��"BLINK+HIY"��˫�������"NOR"��צ����ͬһ��λץ��",
	    "dodge":                15,
                "parry":                15,
                "force":                70,
                "damage_type":  "ץ��"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("�������Ʒ�������֡�\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������̫�����޷��������Ʒ���\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        return action[random(sizeof(action))];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 40)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 40);
	me->add("force", -10);

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 4 );
                switch(random(3)) {
                        case 0: return HIB"��������������һ�����죬�����ǹ����������\n"NOR;
                        case 1: return HIB"$N����һ�£�$n��$l������������һ�����죡\n"NOR;
                        case 2: return HIB"ֻ����$n��$l��������һ�� ...\n"NOR;
                }
        }
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/tianpeng-zhang/" + func;
}
