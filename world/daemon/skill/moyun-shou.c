//Ħ����

//by tianlin 2001.7.3�޸�
#include <ansi.h>
inherit SKILL;

mapping *action = ({
   ([   "action":   HIM"$Nһ��"BLINK YEL"����벶��ʽ��"NOR HIM"������ץ��$n�ĵ������$n�����Է���һ˲�䣬����ȴ��������$n��$l"NOR,
     "dodge":     10,
     "parry":     10,
     "force":     160,
     "damage_type":   "����",
                        "weapon":     "����ʳָ",
   ]),
   ([   "action": HIC"$N˫��һ������"BLINK MAG"��÷����䡻"NOR HIC"��˫���紩������һ�����·��ɡ�\n"CYN"$n�������ۣ�ɲ�Ǽ�$N����������ǰ"NOR,
     "dodge":     5,
     "parry":     -15,
     "force":     180,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
   ([   "action":     HIY"ֻ��$Nһת��һָ��в�´���������$n��$l������$n�����Է���һ˲��,ȭ������,���Ƕ�����ɱ��"NOR,
     "dodge":     5,
     "parry":     10,
     "force":     100,
     "damage_type":   "����",
                        "weapon":     "����ʳָ",
   ]),
   ([   "action":     HIY"$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ��"BLINK HIR"������ʽ��"NOR HIY"ʹ$n��������"NOR,
     "dodge":     20,
     "parry":     20,
     "force":     140,
     "damage_type":   "����",
                        "weapon":     "����", 
   ]),
([   "action":     YEL"$Nһ��"BLINK RED"������������"NOR YEL"�������ڿ����黮�˸��뻡������$n��$l"NOR,
     "dodge":     30,
     "parry":     10,
     "force":     70,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
([   "action":     HIC"����$Nһ��ŭ�����ָ߸߾���һʽ"NOR+BLINK+HIY"��������ɽ��"NOR+HIC"������$n��$l"NOR,
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
([   "action": "$N�������գ�����������ɽ��һ�С�����ʽ�����͵ػ���$n��$l",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
([   "action": "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ�С�׷��ʽ����������$n��ȫ��",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "��צ",
   ]),
([   "action": "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�����ʽ��ʹ$n��������",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
([   "action": "$Nһ����ָ$n�Ľ�����һ�С��ὣʽ����һ������ץ��$n���еĳ���",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
([   "action": "$N����б��$n����֮�䣬һ�С�����ʽ��������ȡĿ�����ַ���$n���ɲ�",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "����",
   ]),
([   "action": "$N������ǰ������Ҹ�º��գ���ָ�繳��һ�С���ȱʽ������$n�Ķ���",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "��ָ",
   ]),
([   "action": "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С�����ʽ����������$n��$l",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "����",
                        "weapon":     "��ָ",
   ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��Ħ���ֱ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("moyunshou_per");
        if( !me->query_temp("moyunshou_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰĦ���֡�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ��Ħ���֡�\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/moyun-shou/" + func;
}

