// �����硤���μǡ��汾��������
// By tianlin 2001.5.1
/* <SecCrypt CPL V3R05> */

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
   ([   "action":
"$N����$w��$n��$lֱ��������",
     "dodge":     -5,
                "parry":                -10,
     "damage":     50,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w��$n��$lб��������",
     "dodge":     -35,
                "parry":                -5,
     "damage":     50,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����һ�����ǣ���$n��$l���˹�ȥ��",
     "dodge":     -10,
                "parry":                -15,
     "damage":     65,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w���˸���Բ����$n��$l���˹�ȥ��",
     "dodge":     -30,
                "parry":                -5,
     "damage":     70,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����$n��$l���˹�ȥ��",
     "dodge":     -20,
                "parry":                -20,
     "damage":     120,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{

   object ob;

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ�������������\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_westsword");
     if(me->query("skill_westsword")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
        {
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("�����������������û�а취��ϰ���󽣷���\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write("�㰴����ѧ����һ�����󽣷���\n");
   return 1;
}


string perform_action_file(string func)
{
return CLASS_D("moon") + "/snowsword/" + func;
}

