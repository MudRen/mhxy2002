// huagu-mianzhang ��������
inherit SKILL;

mapping *action = ({
([  "action" : "$N����΢�Σ�һ�С���������ǡ���ʮָ��ꪣ�����$n��˫������",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl"   : 0,
    "skill_name" : "���������" ,
]),
([  "action" : "$N������磬ʮָ΢΢������һ�С������Ѻ��ѡ�ץ��$n��ǰ��",  
    "force" : 220,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 20,
    "skill_name" : "�����Ѻ���" ,
]),
([  "action" : "$N˫�ֺ������֣�һ�С����紵�䳾�������Ȱ��ץ��$n�ļ�ͷ",  
    "force" : 250,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 40,
    "skill_name" : "���紵�䳾" ,
]),
([  "action" : "$N���ֵ��ػ��������ּ�����һ�С�����ӳ��ɳ�����͵�ץ��$n�Ķ�
ͷ",
    "force" : 290,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl"   : 60,
    "skill_name" : "����ӳ��ɳ" ,
]),
([  "action" : "$Nʹһ�С�ɭȻ���ķ�������������ľ��磬ײ��$n",
    "force" : 340,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl"   : 80,
    "skill_name" : "ɭȻ���ķ�" ,
]),
([  "action" : "$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ���������ֹǺ�����ʮָ    
���������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ",
    "force" : 460,
    "parry" : 5,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 100,
    "skill_name" : "�����ֹǺ�" ,
]),
([  "action" : "$Nʹ������ɳƮ���꡹����Ȼ������ϣ�����$n��ת��Ȧ��$n����  
�����Ҽ䣬$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�",  
    "force" : 430,
    "parry" : 20,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 120,
    "skill_name" : "��ɳƮ����" ,
]),
([  "action" : "$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫��    
�ջ���ǰ������һ�С��׹����޺�������ָ�繳��ֱץ��$n������",
    "force" : 400,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl"   : 140,
    "skill_name" : "�׹����޺�" ,
]),
});

int valid_learn(object me)
{
        
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("���������Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}
mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("moyunshou_per");
        if( !me->query_temp("moyunshou_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ�������ơ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ�黯�����ơ�\n");
        return 1;

}
string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/bibotan/huagu-mianzhang/" + func;
}