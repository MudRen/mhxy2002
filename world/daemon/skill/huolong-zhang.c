// created by ken
inherit SKILL;

mapping *action = ({
([      "action": "$N˫��ƽ�����һ���һ�����ǵص�ɨ����$n",
        "dodge": -30,
        "parry": 10,
        "force": 200,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "����"
]),
([      "action": "$N����һ����һ�С��������ա���Ѹ���ޱȵ�����$n��$l",
        "dodge": -10,
        "parry": -10,
        "force": 120,
        "damage_type": "����"
]),
([      "action": "$N˫��ʩ��һ�С�ŭ�����������������ŷ���֮������$n��$l",
        "dodge": -15,
        "parry": -10,
        "force": 100,
        "damage_type": "����"
]),
([      "action": "$N���ƾ۳�һ���һ𣬳�$nһ��͵�����$n",
        "dodge": -10,
        "parry": 10,
        "force": 100,
        "damage_type": "����"
]),
([      "action": "$Nʩ��һ�С��һ������������ƾ���һ�Ż���������$n",
        "dodge": -10,
        "parry": 20,
        "force": 150,
        "damage_type": "����"
]),
([      "action": "$Nʹ�����һ������������ƴ���һ�����ȵĻ����Ӳ����ܵĽǶ�ɨ����$n",
        "dodge": 0,
        "parry": 10,
        "force": 100,
        "damage_type": "����"
]),
([      "action": "$N���һ����˫��ʹ����������ء����ĳ������һ𲻹�һ�а����$n",
        "dodge": -15,
        "parry": -10,
        "force": 200,
        "damage_type": "����"
]),
([      "action": "$N�ٿ�Խ����Хһ������$n����������",
        "dodge": -10,
        "parry": -10,
        "force": 120,
        "damage_type": "����"
]),

});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if(me->query("family/master_id") != "master hate")
            return notify_fail("����û���˽�����ô��ϰѽ��\n");
        if (me->query("betray/count"))
             return notify_fail("����ѧ֮�Ĳ�ר����Եѧ�û����ơ�\n");
        if(me->query("family/family_name") != "ħ��")
             return notify_fail("���������޺޲���֮�ܣ�\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
             return notify_fail("�����������ħ���ſɷ���������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("evil-force", 1) < 20)
                return notify_fail("���ħ����򲻹����޷��������ơ�\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������̫�����޷��������ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if(me->query("family/master_id") != "master hate")
                return notify_fail("�㻹û�õ������״�����֪�����ϰ���С�\n");
        if (me->query("betray/count"))
                return notify_fail("����ʦ���棬��Եѧ�û����ơ�\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
                return notify_fail("�����������ħ��������ϰ��\n");       
        if( (int)me->query_skill("evil-force",1) < (int)me->query_skill("huolong-zhang",1)/2)
                return notify_fail("���ħ�������������ϰ�����ƣ�\n");
        if ((int)me->query("kee") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 10)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("evil") + "/huolong-zhang/" + func;
}
