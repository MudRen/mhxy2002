//������ 
//created by foc,9-6-01

inherit SKILL;

#include <ansi.h>

mapping *action = ({
        ([      "name":          "ӭ��һ��",
                "action":
"$N�ҽ��ڵ���һ�㣬���γ���$n�����ȥ��ͬʱ���ְν�����$nһ�ӡ�\n��һն����������ɱ����$n���ɵ�һ��������"+BLINK""+HIR"��ӭ��һ�ϡ�"NOR+"��Ȼ������",
                "dodge":   -25,
                "parry":   -5,
                "damage":   225,
                "damage_type":  "ն��"
        ]),
        ([      "name":          "Ӱɱ", 
                "action":
"$N���Ž�����$n��ȥ��ʹ����������"+BLINK""+HIG"��Ӱɱ��"NOR+"��Ӱ���̱����������\nһ��������$n�ı�����һ��������$n����ǰ��\n$n������֣�������Ӱ�Ѿ�ͬʱ�ӽ���$n��$lն�£�",

                "dodge":     -25,
                "parry":     -30,
                "damage":     190,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�桤�����",
                "action":
"$N˫�ż��٣��ɿ�س���$n��ȥ������$n���������˲�䣬$NͻȻ\n�ν�һ�ӣ�һ��������"+BLINK""+HIC"����"NOR+"����Ϯ��$n�����䣡��������\n�����е�"+BLINK""+HIY"���桤����ϡ�"NOR+"��",
                "dodge":   -30,
                "parry":   -10,
                "damage":   230,
                "damage_type":  "ն��"
        ]),
        ([      "name":                 "����ն",
                "action":
"$Nһ����Ц�����첻���嵽$n����ǰ��$n��Ҫ����������ǰ��$N��\n��������$Nȴ�Ѿ�վ����$n�ļ���ϣ�����������$n��ͷ�����£�ԭ��$Nʹ\n����"+BLINK""+HIB"������ն��"NOR+"��",
                "dodge":   -10,
                "parry":    15,
                "damage":   200,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ʮ��Ӱ��",
                "action":
"$N��ȫ��ͻȻ�ų�ǿ�ҵ�����������Ծ��$n��б�Ϸ������һ����\n������ʮ����Ӱ�ӣ�ÿ��Ӱ�Ӷ���$n�ӳ�һ����ֻ��"+BLINK""+HIC"��ʮ��������"NOR+"\n��$nȫ�����µ�Ҫ�������ȥ������"+BLINK""+HIW"����ʮ��Ӱ�ϡ�"NOR+"��$n����·ȫ��ס�ˡ�",
                "dodge":     -35,
                "parry":     -25,
                "damage":     185,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "а��ڤ��ɱ",
                "action":
"$Nʹ��"+BLINK""+HIM"��а��ڤ��ɱ��"NOR+"��˫Ŀһ�գ���ͷ�ϳ�����һֻ"+BLINK""+HIC"�۾�"NOR+"��\n$n������֣���"+BLINK""+HIC"�۾�"NOR+"һ�ţ�һ�ɹ�����������������\n$n�е��Լ����ж�ͻȻһ�������ͬʱ��$N���е�$w�Զ�����$n�����ȥ��",
                "dodge":   -25,
                "parry":   -5,
                "damage":    220,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "���塤ڤ����ɱ��",
                "action":
"$Nͷ�ϵ�а���ſ�������ȼ��"+BLINK""+HIC"��ɫ�Ļ���"NOR+"��\nͬʱ����$wҲȼ��ͬ����"+BLINK""+HIC"����"NOR+"��$N���һ��������һ�ף�\n���γ���$n���������$N����������$n��������\nȭ����������һ�٣��պýӵ�$w��$N˫���ս�������������\n������һն����һն���������Ļ��棬Ҫ�Ǳ�ն�У��ɾ����ˡ�������\n��˵�����������������"+BLINK""+HIR"�����塤ڤ����ɱ����"NOR+"��",
                "dodge":   -40,
                "parry":   -40,
                "damage":   450,
                "force":    300,
                "damage_type":  "������"
        ]),
   ([   "name":        "ʵս����",
     "action":   "$N������$n�����ӽ���������"+BLINK""+HIC"����"NOR+"���������Ľ�����һ�Ŵ���һ������$nȫ��Ҫ����",
     "parry":   -15,
     "dodge":   -20,
     "damage":   180,
     "damage_type":  "����"
   ]),
});


int valid_learn(object me)
{
     object ob;
     if((int)me->query_skill("evileye", 1) < (int)me->query_skill("evilsword",1)/2)
     return notify_fail("���а������Ϊ�����ˣ�����������������ĵȼ��ˡ�\n"); 
     if( (string)me->query_skill_mapped("force")!= "evileye")
     return notify_fail("�������������а������������\n");
     if( (int)me->query("max_force") < 450 )
     return notify_fail("�������������û�а취����������������Լ���������˵�ɡ�\n");

     if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )       
     return notify_fail("���������һ�ѽ����������ֽ�����\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="sword";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string action_name, int skill)
{
          return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 200
        ||      (int)me->query("force") < 100 )
                return notify_fail("�������������������û�а취��ϰ��������\n");
        me->receive_damage("kee", 60);
        me->add("force", -20);
        write("�㰴����ѧ����һ����������\n");
        return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("mojie") + "/evilsword/" + func;
}
