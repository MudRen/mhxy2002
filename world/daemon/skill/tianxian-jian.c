// created by ken,pnt 2001.3.9 tianxian-sword
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":                 "�Ż�����",
                "action":               "$N�������������Ծ��һ�С��Ż����ա�������$w����������$n��$l��û����֪��������������Ҳ���޷��ֵ�",
                "dodge":                -20,
                "parry" :               -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�޿ײ���",
                "action":               "$N���е�$wͻת���޿ײ���Ĵ���$n��$l",
                "dodge":                -10,
                "parry" :               -10,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���Ǵ���",
                "action":               "$N�趯$w��һ�С����Ǵ��ޡ�����������������磬�˽���һ������$n��$l",
                "dodge":                -10,
                "parry" :               -10,
                "damage":                35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "���ھ���",
                "action":               "$Nһ������$w��ʹ�������ھ��졹�����ɵú���׳־������Ԧ������$n��$l�̳�һ��",
                "dodge":                -10,
                "parry" :               -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ӵ�к",
                "action":               "$N����$w������ɢ����������������$n��$l�����˲�֪�����Ժη�",
                "dodge":                -15,
                "parry" :               -15,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������",
                "action":               "$N�����������������������������$wֱָ$n$l��һ�С��������Ρ����̳��˾��춯�ص�һ��",
                "dodge":                -10,
                "parry":                -20,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":"$Nһʽ��������ɡ���$wͻȻ���������һƬ���Χ��$nȫ��",
                 "dodge" :               -25,
                 "parry" :               -25,
                 "damage":                40,
                 "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$NЦ�����ϣ�ȫ������һ�޽䱸����$nһ�֮������$wһ�С��������ǡ���$n��$1��б����",
                "damage":               40,
                "dodge":                -20,
                "parry":                -15,
                "damage_type":      "����",
        ]),
   ([   "action":
HIY"$N����ͻת�������طɣ�"NOR,
     "dodge":     -70,
     "parry":     -70,
     "damage":     15,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
        object ob;

   if(me->query("family/master_id") != "master hate")
            return notify_fail("��������ɽ�������֪�����ϰ��\n");
   if (me->query("betray/count"))
             return notify_fail("����ѧ֮�Ĳ�ר����Եѧ�����ɽ�����\n");
   if(me->query("family/family_name") != "ħ��")
             return notify_fail("���ɽ������޺޲�����ѧ��\n");
   if( (string)me->query_skill_mapped("force")!= "evil-force")
             return notify_fail("���ɽ��������Ѫħ�񹦲ſɷ���������\n");
        if( (int)me->query("max_force") < 150 )
                return notify_fail("��������������޷�ѧϰ������\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("������Ұѽ���������������\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;

        i=me->query_temp("TXJ_perform");
        if(!me->query_temp("TXJ_perform")) {
                return action[random(8)];
        }else {
                return action[i];
        }
   }
int practice_skill(object me)
{
        object weapon;
        
        if(me->query("family/master_id") != "master hate")
                return notify_fail("��������ɽ�������֪�����ϰ���С�\n");
        if (me->query("betray/count"))
                return notify_fail("����ʦ���棬��Եѧ�����ɽ�����\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
                return notify_fail("���ɽ��������Ѫħ�񹦲�����ϰ��\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("�����޽��������ϰ������\n");

        if( (int)me->query("kee") < 50 
        ||    (int)me->query("force") < 30)
                return notify_fail("���������������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 50);
        me->add("force", -10);
        write("����ǰ�ó�������Ӱ��������������\n");
        return 1;
}


string perform_action_file(string action)
{
        return CLASS_D("evil") + "/tianxian-sword/" + action;
}
