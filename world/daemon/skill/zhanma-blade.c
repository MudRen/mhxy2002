// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N���е�$wӭ��һ�Σ���������ѽ���������������ڰ�ؿ���$n��$l",
                "dodge":                -20,
                "damage":               25,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���е�$wӭ����裬�󱩷��еĹ�ɳ������$n��$l",
                "dodge":               -20,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N���е�$w�����е����ƣ����ۺ�ɢ�ؿ���$n��$l",
                "dodge":                -15,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�ζ����е�$w������������֣�������е���Ҷ��һ����һ����ɢ��$n��$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����ȫ��Ĺ��������е�$w��̹Ǻ�������$n",
                "dodge":                -15,
                "damage":               25,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("zanglong-force", 1) < 10 )
                return
                notify_fail("����ڹ��ķ�����㣬�޷���ն����\n");
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
        return 0;
}
int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return CLASS_D("yujian") + "/zhanma-blade/" + action;
}