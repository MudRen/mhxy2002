//�����
//creat by focus
inherit SKILL;
#include <ansi.h>


mapping *action = ({
   ([  "action": HIW"$N���ϵ���������ָ��Ĵָ��ס��ʳָһ�㣬����$n��$l��ȥ"NOR,
     "dodge":     5,
     "damage":     35,
     "damage_type":   "����"
   ]),
([ "action":HIM"ֻ��$N����һ�������ϵ���˿ȫ��ɢ�����ɣ�һƬ��˿�У����Ѿ�����$n��$l"NOR,
     "dodge":     -5,
     "damage":     40,
     "damage_type":   "����"
   ]),
   (["action":HIW"�׺���ɢ�����������������У���������Ĵ���$n��$l"NOR,
     "dodge":     -5,
     "damage": 60,
     "damage_type":   "����"
   ]),
   ([ "action":HIM"�׺���ɴ����ʫ�����Ρ���....���˵�����, �������磬����$n��$l"NOR,
     "dodge":     10,
     "damage": 45,
     "damage_type":   "����"
   ]),
  ([  "action": HIW"$Ņ�֣�������������֮�Ʊ��������ɢ��ɢ��Ũ����������$n��$l"NOR,
     "dodge":     0,
     "damage": 60,
     "damage_type":   "����"
   ]),
  ([ "action": HIM"$N���а׺������Ĳ�������ͬ�������µ���������ô��η�����飬�¶���$n���ˣ������ǲ���˼�ǵ�����...����ѻ���$n��$l"NOR,
     "dodge":     -5,
     "damage":     60,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("�����������,û�а취�������.\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "yumao" )
     return notify_fail("�����һ���Ű׺���������ϰ�����\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="yumao" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_libieyu");
     if(me->query("skill_libieyu")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 10 )
    return notify_fail("���������������,û�а취��ϰ�����.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
  write(HIB"���Ѽ�į��С�꣬������������\n"NOR, me);
   return 1;
}

string perform_action_file(string func)
{
  return CLASS_D("lingjie") + "/libieyu/" + func;
}
