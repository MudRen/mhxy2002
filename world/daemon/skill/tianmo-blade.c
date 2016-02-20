// updated by ken 2001.3.9
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N����ħ�У�ʹ����ħ��ʽ�е�����ʽ����ħ���ѡ������е�$w����һ���âն��$n��$l",
                "parry":                 5,
                "dodge":                -10,
//              "force":                 500,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��һ������ʱħ���ʢ����$n�ۻ�����֮�ʣ����е�$w�ó�һƬ������ɢ��$n��$l",
                "parry":                 10,
                "dodge":                 10,
//              "force":                 500,
                "damage":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��Ӱ�ζ������������ң����е�$w������·ͻȻ����$n��$l����һʽ����ħ���𡹣�",
                "parry":                -20,
                "dodge":                -20,
//              "force":                 500,
                "damage":                15,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�����ת�����е�$wһʽ��ħ��է�֡������������$n��$l",
                "parry":                -20,
                "dodge":                -20,
//              "force":                 500,
                "damage":                15,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��˫�ŵ�أ���������ȫ��ת��һ�ŵ������$n����һʽ��������ħ��",
                "dodge":                -20,
                "parry":                -20,
//              "force":                 500,
                "damage":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������ϣ�һ�С���ħ���졹����һ��$n���벻���ĽǶ�����$n��$l",
                "dodge":                -10,
                "parry":                -10,
//              "force":                 500,
                "damage":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���е�$w���ҺỮ��һ�С���ħ���֡��������ػصؿ�ɨ��$n��$l",
                "dodge":                -10,
                "parry":                -10,
//              "force":                 700,
                "damage":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nħ����ʢ��ʹ����ħ������ʽ�е�����ʽ����ħ���ڡ������е�$wѸ���ޱȵؿ���$n��$l",
                "dodge":                -10,
                "parry":                -10,
//              "force":                 1000,
                "damage":                40,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 200 )
                return notify_fail("����������㣬�޷�����ħ������ʽ��\n");
        if( (int)me->query_skill("force", 1) < 20 )
                return notify_fail("����ڹ��ķ�����㣬�޷�����ħ������ʽ��\n");
        if( (int)me->query_skill("evil-force", 1) < 20 )
                return notify_fail("���ħ������㣬�޷�����ħ������ʽ��\n");
        if(me->query("family/family_name") != "ħ��")
                return notify_fail("��ħ��ʽ��ħ�̲���֮�ܣ�\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
                return notify_fail("��ħ������ʽ�����ħ���ſɷ���������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

//      if(me->query("family/master_id") != "master feng")
//           return notify_fail("�㻹��֪����ô��ϰħ����\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
              return notify_fail("�������ħ���ſ�����ϰ������\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ���������������\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
        me->add("force", -10);
        write("�㰴����ѧ����һ����ħ��ʽ��\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("evil") + "/tianmo-blade/" + action;
}
