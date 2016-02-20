// link 2001.2.16
#include <ansi.h>
inherit SKILL;
string* skill_head =({
        "$N$Nʹ����ᦾ����е�����ʽһ��",
        "$N��һ����һ��",
        "$N$Nɡ����ת�����е�$wһ��",
        "$N��Ӱ�ζ���ɡ�������ң�һ��",
        "$N��˫�ŵ�أ�ɡ������һ��",
        "$Nɡ�����ϣ�һ��",
        "$N���е�$w���ҺỮ��һ��",
        "$Nʹ����ᦾ����е�����ʽ",
});
string* skill_tail =({
        "�����е�$w����һ���âն��$n��$l��",
        "�����е�$w�ó�һƬɡ����ɢ��$n��$l��",
        "������$w���������$n��$l��",
        "�����е�$w������·ͻȻ����$n��$l��",
        "��ȫ��ת��һ��ɡ�����$n��",
        "����һ��$n���벻���ĽǶ�����$n��$l��",
        "�����е�$w���ҺỮ�����ػصؿ�ɨ��$n��$l��",
        ", ���е�$wѸ���ޱȵؿ���$n��$l��",
});

mapping *action = ({
        ([      "action":               "$Nʹ����ᦾ����е�����ʽһ��"+BLINK""+MAG"�������������"NOR"�����е�$w����һ���âն��$n��$l",
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��һ����һ��"+BLINK""+CYN"������������"NOR"���е�$w�ó�һƬɡ����ɢ��$n��$l",
                "force":                55,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nɡ����ת�����е�$wһ��"+BLINK""+HIR"��Թ����������"NOR"�����������$n��$l",
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��Ӱ�ζ���ɡ�������ң�һ��"+BLINK""+HIY"��������������"NOR"�����е�$w������·ͻȻ����$n��$l",
                "force":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��˫�ŵ�أ�ɡ������һ��"+BLINK""+HIB"��������������"NOR"ȫ��ת��һ��ɡ�����$n",
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nɡ�����ϣ�һ��"+BLINK""+HIG"��������������"NOR"����һ��$n���벻���ĽǶ�����$n��$l",
                "force":                55,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���е�$w���ҺỮ��һ��"+BLINK""+HIC"��������������"NOR"�������ػصؿ�ɨ��$n��$l",
                "force":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʹ����ᦾ����е�����ʽ"+BLINK""+HIW"�������������"NOR"�����е�$wѸ���ޱȵؿ���$n��$l",
                "force":                120,
                "damage_type":  "����"
        ]),
});


mapping query_action(object me)
{
    if (random(me->query_skill("umbrella",1)) > 20 &&
        me->query_skill("force",1) > 20 &&
        me->query("force") > 200 ) {
             me->add("force", -20);
             return ([
                  "action": "$N"+BLINK""+RED"��ҧ����⣬������Ѫ������ɡ�ϡ�"NOR"��"+BLINK""+WHT"���ۼ�ȫ���������"NOR"����$n",
                  "force": 300,
                  "damage_type": "����"]);
    }
    return action[random(sizeof(action))];
}


int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 20 )
                return
                notify_fail("����ڹ��ķ�����㣬�޷����������ɡ ��\n");
        if( (int)me->query_skill("guangming-force", 1) < 20 )
                return
                notify_fail("��Ĺ����ķ�����㣬�޷����������ɡ ��\n");
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
        ||      (string)weapon->query("skill_type") != "umbrella" )
                return notify_fail("���������һ��ɡ��������ɡ����\n");

        if( (int)me->query("kee") < 10 )
                return notify_fail("�����������������ɡ������������Ϣ��Ϣ�ɡ�\n");
me->receive_damage("kee", 10);
        write("�㰴����ѧ����һ���������ɡ��\n");;
        return 1;
}
int effective_level() { return 50;}

string *parry_msg = ({
        "$nʹ����ᦾ����е�����"+BLINK""+HIG"��Թ�޽ٶ����������ѡ�"NOR"�����е�$w���ɾ���ɡĻ��סȫ��\n",
});

string *unarmed_parry_msg = ({
        "$nʹ����ᦾ����е�����"+BLINK""+HIG"��Թ�޽ٶ����������ѡ�"NOR"�����е�$w���ɾ���ɡĻ��סȫ��\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
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
        message_vision(RED"$N���˲��ɣ������Լ���ת���ˣ�\n"NOR,me);}
        }
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("lingfan-san",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"�����ᦾ���ɡ����������ˣ������ᦾ���ɡ������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬����ᦾ���ɡ�������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_lingfan-san");
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

   if(!arg||arg==" ")arg="��ᦾ�����ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_lingfan-san",m_actions);
}
