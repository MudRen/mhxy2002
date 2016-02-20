//����Ⲩ��ȭ��lingguang-quan.c
//create by foc,26-08-01
inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":
"$N����һ�Σ�ͻȻת��$n�ı���һ�Ÿ��ܶ������ۼ���$N�������ϣ������ػ���$n��$l",     
        "dodge":    -5,
        "parry":   -10,
        "force":   150,
        "damage" :  10,
        "damage_type":  "��������",
        "weapon" :              "����",
]),
        ([      "action":
"$N���һ����ͬʱ�����������ۼ�������ʳָ֮�ϣ�\n"
"��Χ�Ŀ������̺������˹�ȥһ����$n�е��е�\n"
"�����æ�������˼�����������ͬʱ��$N���һ������"+BLINK""+HIW"�顪����������"NOR"��һ������ľ޴�����\n"
"����$n��$l�������˹�ȥ\n",
        "dodge":    -5,
        "parry":   -30,
        "force":   300,
        "damage" :  50,
        "damage_type":          "����",
        "weapon":               "�鵯",
]),
        ([      "action":
"ֻ��$N���Ծ��˫��ͬʱ���д�������������ҫ�۵Ĺ�â��\n"
"�������е�����ͻȻת��Ϊ�������С"+BLINK""+HIW"������"NOR"��$N\n"
"˫��һ��������С"+BLINK""+HIW"������"NOR"���컨������$n��ȫ��Ϯȥ\n",                "dodge":   -20,
        "parry":    -5,
        "force":    80,
        "damage" :   5,
        "damage_type":          "����",
        "weapon":               "������",
]),
        ([      "action":
"$N��Цһ����ͻȻ�������ƶ���$n����ǰ���͵�һͷ��$nײ��ȥ��\n"
"��һ�����ž޴������������$n��ʵ����һ��",
        "dodge":    10,
        "parry":   -20,
        "force":   130,
        "damage" :   2,
        "damage_type":          "ײ��",
        "weapon":               "ͷ",
]),
        ([      "action":
"ֻ��$NͻȻ�����ƣ�$n���һ������ô��������鵯����\n"
"�첽׷��ȥ��������������$Nȴ�����ַ������������ϣ�\n"
"ͬʱ���������Ҳ࣬ȫ��ų���ǿ����������������̨��\n"
"һ��ؼ�����$N������ȭͷ�ϡ�$n������֣�ͻȻ�䣬\n"
"$N����Ϊ����������ϣ�����$nֱ���������ȭһ����\n"
"���������޴��"+BLINK"+"HIW"������"NOR"��������������$n\n"
"��������·�������ˣ�$n�ۿ�����һ�У���֪������ô��ź�\n",
        "dodge":  -30,
        "parry":  -30,
        "force":  300,
        "damage_type":          "����",
        "damage" : 70,
        "weapon":               "��������",
]),
        ([      "action":
"$N����$n���ȥ��˫ȭ����������ÿһȭ�����ž޴�������������\n"
"$n������֮�£�ֻ����Σ������\n",
        "dodge":    0,
        "parry":    5,
        "force":   90,
        "damage_type":          "ȭ��",
        "damage" : 10,
        "weapon":               "ȭͷ",
]),
});

int valid_learn(object me)
{
        if(me->query("race")!="����")
        return notify_fail("����ȭ��ֻ��������̳С�\n");
        if( (int)me->query_skill("spiritforce",1) < (int)me->query_skill("lingguan-quan",1)/2 && (int)me->query_skill("segokee",1)<0)         return notify_fail("���������̫���ˣ��޷����������Ⲩ��ȭ����Ϊ�ˡ�\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("����Ⲩ��ȭ������֡�\n");
        if((int)me->query_skill("unarmed",1)<60 || (int)me->query_skill("force",1)<60)
        return notify_fail("��Ļ�������û���Ŷ��\n");
        return 1;
}

int valid_enable(string usage)
{
     return usage=="unarmed"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{
     if( (int)me->query_skill("spiritforce",1) < (int)me->query_skill("lingguang-quan",1)/2 && (int)me->query_skill("segokee",1)<1)
     return notify_fail("���������������Ӧ���ߵȼ���ȭ��������\n");
     if( (int)me->query("kee") < 50)
     return notify_fail("������������ˣ������ɾ�Ҫ�������ˡ�\n");
     if( (int)me->query("sen") < 50 )
     return notify_fail("�����ڵľ��������Կ����Լ���������������Ϣһ�������ɡ�\n");
     if( (int)me->query("force") < 20 )
     return notify_fail("������������ˡ�\n");
     me->receive_damage("kee", 40);
     me->add("force", -10);
     return 1;
}

string perform_action_file(string func)
{
     return CLASS_D("mojie") + "/lingguang-quan/" + func;
}
