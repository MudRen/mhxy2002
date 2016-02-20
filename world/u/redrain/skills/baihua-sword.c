// baihua-sword

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С�������Ʈ����$w����ػ�������Բ����\n�ó����컨����Ľ�â����$n��$l��ȥ",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 35,
        "damage_type" : "����"
]),
([      "action" : "$Nһ����������һʽ��С԰�վա���\n����$wѸ����$n��������������",
        "dodge" : -15,
        "parry" : -20,
        "damage" : 50,
        "damage_type" : "����"
]),
([      "action" : "$N���ֽ���һ�죬����$wһ����\n����·����$n��$l������һ�С�˫���Իء�",
        "dodge" : -40,
        "parry" : -20,
        "damage" : 45,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������չȡ���$w���������һ�ӣ�\n����ȴ��$n����˼��ĽǶȹ���",
        "dodge" : -20,
        "parry" : -15,
        "damage" : 35,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����軨��·�������μ��Ρ�\nһʱ����о���$w��Ӱ�ӣ���$n��֪��εֵ�",
        "dodge" : -15,
        "parry" : -15,
        "damage" : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ĵ�����᡹��$w�Ƴ�������Ȧ��ƽƽ����$n��$l��ȥ",
        "dodge" : -15,
        "parry" : -25,
        "damage" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N��������棬������ǰһ�ˣ�һ�С���ҩ���项��$w��$n��$l��ȥ",
       "dodge" : -15,
        "parry" : -10,
        "damage" : 35,
        "damage_type" : "����"
]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return
               notify_fail("�������������û�а취ѧ�ٻ���о������\n");

        if( me->query("family/family_name") != "��ԯ��" )
        return notify_fail("ֻ�б������˲���ѧ�˽�����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return
notify_fail("���������һ�ѽ�����ѧ�ٻ���о��������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ���������������\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("����������������׽�������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("xuanyuan") + "/baihua-sword/" + func;
}
