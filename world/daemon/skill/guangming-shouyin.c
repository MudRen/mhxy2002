//��������ӡ
//create by focus 2001.2.10


inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "name":    "���ճɾͷ����ӡ",
                "action":               HIC"$N˫���м���ָ�ཻ�廥����ס��ķָ��Сָ���ಢ����, ����һ���޿�\n"+"ƥ�еľ������������ֱ��$nײȥ"NOR,
                "dodge":                10,
                "parry":                10,
                "force":                120,
                "damage_type":  "����",
                "weapon":      "��ָ"
        ]),
        ([      "name":     "��ս����ӡ",
                "action": HIC"$NķָСָ��������ָ���������м���ָ������������ָ֮��ƽ�٣������Ƴ�,\n"+
                          "һ��Ѷ�͵ľ���ֱ��$n��ͷ����"NOR,
                "dodge":                5,
                "parry":                -15,
                "force":                180,
                "damage_type":  "����",
        ]),
        ([      "name":      "����ȭӡ",
                "action":    HIY"ֻ��$N������ָ���������ƣ�ķֱָ��������������ָ��ס����ķָ��ʳָ��ķָ�۳�һԲ����\n"+"�������һ�ɾ���������$n��$l"NOR,
                "dodge":                5,
                "parry":                10,
                "force":                130,
                "damage_type":  "����",
        ]),
        ([      "name":      "��ʤ��ӡ",
                "action":    HIW"$N�������ֵ�ķָ��ʳָ���Գ�һԲ���ಢ���ٸ��Խ������ֺ���ָ������ơ�����$n��$l"NOR,
                "dodge":                20,
                "parry":                20,
                "force":                140,
                "damage_type":  "����",
        ]),
            ([  "name":      "��ݱ����Ħӡ",
                "action":    HIB"$N���������󽻲档���������ڣ����������⡣���������Ƹ���ķָ��Сָָ���һ����\n"+"�м���ָ����΢��,����$n��$l"NOR,
                "dodge":                30,
                "parry":                10,
                "force":                160,
//              "damage_type":  "����",
        ]),
            ([  "name":      "����������۲�������ӡ",
                "action":    HIY"$N˫��ƽ������ǰ�������ָ���Ĵָ��ʳָ��һ�ۻ�,��������ָ���໥���壬ƽ���ڸ�ǰ��������Ѩ֮�䣬\n"+
                "������ָ���ٵ�������������ֱ��$n��$l��ȥ"NOR,
                "dodge":                10,
                "parry":                -10,
                "force":                220,
//              "damage_type":  "����",
        ]),
        ([      "name":      "����������ӡ",
                "action":    HIR"$N��ü�Ŀ��������ָ��ʳָ���죻������Ĵָ������ָ��Сָ��ס��ͬʱ��������ָ��ʳָ����������ɵĴ���ӡ��\n"+"ȫ���������ƶ�����һ������ӡӰ�񣬺����������$n"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                520,
                "damage_type":  "����",
         ]),
});

int valid_learn(object me)
{
        
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����������ӡ������֡�\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="unarmed"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
 /*       int i;
        i=me->query_temp("pfm_shouyin");
        if( !me->query_temp("pfm_shouyin") ) 
        {
              return action[random(6)];
        }   
    else 
        {
              return action[i];
        }*/ 
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 20 )
                return notify_fail("�����������Ѫ������û�а취��ϰ��������ӡ��\n");
        me->receive_damage("kee", 30);
        me->add("force", -15);
        write("�㰴����ѧ����һ���������ӡ��\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("lingjie") + "/guangming-shouyin/" + func;
}
