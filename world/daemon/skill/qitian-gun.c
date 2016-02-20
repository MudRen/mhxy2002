// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "[31mֻ��$N����һ�ᣬһ��[m",
        "[32m$Nһ��������һ��[m",
        "[33m$Nһ������ʹ��һ��[m",
        "[34m$Nһ���Ϻȣ�һʽ[m",
        "[35m$Nʹ��[m",
        "[36m$N�������������һ����ʹ��[m",
});

string* skill_tail =({
        "[31m������$w��$n��$l������[m",
        "[32m������һ����$n��ͷ����[m",
        "[33m��ֻ��$w��$n���ٷ�ȥ��[m",
        "[34m������$w����������$n�����������̲�����ɱ����[m",
        "[35m������$w����ʵ�أ��汼$w��[m",
        "[36m������$w��â���ǣ�ֱ��$n��[m",
});

mapping *action = ({
        ([      "name":                 "һ����Ǭ��",
                "action":
"ֻ��$N����һ�ᣬ���е�$wֱ��$n�����ţ�$n���һ��.",
                "dodge":                5,
               "parry":   -10,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�������",
                "action":
"$Nһ��������һ��[1;32m��������ۡ�[m��$w��$nȫ��Ҫ��������",
                "dodge":                0,
     "parry":     0,
                "damage":               55,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ɨ�칬",
                "action":
"$Nվ�����ͣ�����$w����һָ��һ����Բֱ��$n����",
                "dodge":                10,
     "parry":   -20,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "name":                 "������һ��",
                "action":
"$Nһ���޺ȣ���һ��"+HIW"��������һ����"NOR+"��\n����$nһ�֮�䣬$N����$w���Ǻ�Х������ɨ��$n��$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               55,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����ʤ����",
                "action":
"$Nһ��[1;33m������ʤ������[m����������$n�����������̲�����ɱ����",
                "dodge":                -5,
     "parry":     -5,
                "damage":               40,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "���Ǹ���",
                "action":
     "$Nһ������ʹ��һ��[1;37m�����Ǹ��¡�[mֻ��$w��$n���ٷ�ȥ��",
                "dodge":                5,
     "parry":   -10,
                "damage":               35,
                "damage_type":  "����"
        ]),   
   ([   "name":        "ʥ��һ��",
     "action": 
    "$Nʹ�������ľ���[1;35m��ʥ��һ����[m��$n��ûŪ����ô���£�$N���е�$w�Ѿ������Լ���ͷ�ϣ�",
     "parry":   -40,
     "dodge":   -100,
     "damage":   250,
     "damage_type":  "����"
   ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취���������������Щ���������ɡ�\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�����������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_qitian-gun");
     if(me->query("skill_qitian-gun")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ���������\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        write("�㰴����ѧ����һ�����������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
return CLASS_D("houyao") + "/qitian-gun/" + action;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("qitian-gun",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"������������������ˣ���������������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬��������������һ���µ��÷���\n"NOR);
     tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_qitian-gun");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="���������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"��"+arg+"��"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qitian-gun",m_actions);
}
