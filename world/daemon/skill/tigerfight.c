inherit SKILL;
mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С��컢��ʽ�������ƴ�������$n��$l",
                "dodge":                -30,
                "parry":                10,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��컢��ʽ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                -10,
                "parry":                -30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������С��컢ɨʽ�������ͻ�������$n��ǰ��һ������$n��$l",
                "dodge":                -30,
                "parry":                10,
                "force":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�����컢��ʽ������׼$n��$l�����ĳ�����",
                "dodge":                10,
                "parry":                -30,
                "force":                130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��컢�ʽ������$n$l",
                "dodge":                10,
                "parry":                5,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����컢��ʽ��������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                "dodge":                10,
                "parry":                10,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������һ�С������컢��˫�Ʋ����Ƴ�",
                "parry":                10,
                "dodge":                10,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;
   if (me->query("betray/count"))
     return notify_fail("������ʦ�ţ���Եѧ���컢�ơ�\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
   return notify_fail("�컢���������Ѫħ�񹦲ſɷ���������\n");
        if( (int)me->query("max_force") < 200 )
                return notify_fail("��������������޷�ѧϰ�컢���ơ�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����Ʊ�����֡�\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);

   if (me->query("betray/count"))
     return notify_fail("����ѧ֮�Ĳ�ר����Եѧ�컢���ơ�\n");
   if( (string)me->query_skill_mapped("force")!= "evil-force")
     return notify_fail("�컢���������ħ����������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("evil") + "/tigerfight/" + action;
}
