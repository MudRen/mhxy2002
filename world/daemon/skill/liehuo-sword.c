// by tianlin 2001.5.1
// �һ𽣷�
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$Nһ��",
        "ֻ��$N��������Ծ��,һ��",
        "$Nʹ��",
        "$NƮȻ������һʽ",
        "$N��������Ծ��,�������ּ�ת��һ��",
        "$N����������һ��",
});

string* skill_tail =({
        "������$w��������,�ó�һ���׹�ֱ��$n��$l",
        "��$w����һ������,������������,ֱȡ$n��$l",
        "���������ּ�ת,�ε�$nͷ��Ŀѣ",
        "������$w��ò����س�����$n��Χ.",
        "��������ˮ������$nȫ��",
});

mapping *action = ({
   ([  "action": "$Nһ��"HIY"��"NOR+HBBLU+HIR"�һ�����"NOR+HIY"��"NOR",����$w��������,�ó�һ���׹�ֱ��$n��$l",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "����"
   ]),
([ "action":"ֻ��$N��������Ծ��,һ��"HIR"�������һ�"NOR",������ˮ,һйǧ��,����$nȫ��",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":
"$NƮȻ����,����$w΢΢���,ɲ�Ǽ������Ž�,�ִ�$wȫ��Ÿ���λ,����һ��"HIY"��"BLINK+HIW"����"HIR"�һ�"NOR+HIY"��"NOR".\n",
     "dodge":     0,
     "damage": 35,
     "damage_type":   "����"
   ]),
   ([ "action":
"$N��ָ�ᵯ����,$w����һ������,������������,ֱȡ$n��$l,ȴ��һ��"HIY"��"BLINK+WHT+HBRED"����ķ�"NOR+HIY"��"NOR".\n",
     "dodge":     0,
     "damage": 45,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("�����������,û�а취���һ𽣷�.\n");

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
     m_actions=me->query("skill_birds-sword");
     if(me->query("skill_birds-sword")==0 )
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
    return notify_fail("���������������,û�а취��ϰ�һ𽣷�.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
  write("�㰴����ѧ����һ���һ𽣷�.\n");
   return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("yaomo/kusong") + "/liehuo-sword/" + action;
}

