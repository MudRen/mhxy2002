//��Ӧ���������yinglong-stick
//update by swagger

inherit SKILL;
#include <ansi.h>
int ratio;
mapping *action = ({
([ 
      "action":"$N����$w���ᣬ����л�������$n��$l",    
               "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               50,
                "damage_type":  "����"
]),
([ 
     "action":"$N���ƻ��أ��ұ�Ю���͵�ɨ��$n������",

                "dodge":                0,
                        "parry":   -40,
                        "force":   40,
                "damage":               50,
                "damage_type":  "����"
]),
([   
     "action":"$N����$w��ָ���أ���$n��$l��ȥ",
               "dodge":                -10,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
    "damage_type":"����"
]),
([  
     "action":"$N����$w�����˻��˸���Ȧ������$n��$l",
                "dodge":                0,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
                "damage_type":  "����"
]),
([  
     "action":"$N���й������ţ�����������$n",  
                "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
                "damage_type":  "����"
]),
([   
     "action":"$N����֧�أ�һ��һ���������$n��$l",
                "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
    "damage_type":"����"
]),
([ 
     "action":"$NŤ������$w�ӿ�����������$n���ؿ�",
                "dodge":                0,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
    "damage_type":"����"
]),
([  
      "action":"$N�ڿն�����ɽ��Ӱ������ѹ��$n",
                "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
                "damage_type":  "����"
]),
        ([      "action":               
"$Nʹһ�С�������Ԩ��������$nһ�֮�䣬$N����$w���Ժ���ǰ��Х������ɨ��$n��$l",
                "dodge":                -15,
                "parry":                -10,
                "damage" :              35,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��Ӧ���еġ�����Ⱥ�衹������$w�ζ������һ����ͻȻ�Թ�Ӱ��һ��ɨ��$n��$l",
                "dodge":                -10,
                "parry":                0,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������β������ǰ�͵�һ�ܣ�����$w����һ����ֱ��$n��$l",
                "dodge":                10,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһʽ�������пա�������$w�Ҷ�������ǵ�ɱ�������в���$n��$l",
                "damage":                35,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��㣬��ؽ�������һ�С������ĺ�����$n���벻���ĵط�����$n��$l",
                "dodge":                -15,
                "parry":                -10,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�ݣ�������°���ת��һ�С�˫��Ϸ�项���ֽ���������׼$n$l��ȥ",
                "dodge":                0,
                "parry":                -10,
                "damage":               40,
                "damage_type":  "����"
]),
});
string *liudao=({
                HIC"\n$N��̤"HIY""BLINK"��"NOR""HIC"λ��һʽ"HIY"  ���ɺͣ�����Ȱ��������!"NOR,
                HIC"\n$Nת̤"HIG""BLINK"��"NOR""HIC"λ��һʽ"HIG"  ���ɹã������������ɲ�!"NOR,
                HIC"\n$N��̤"HIM""BLINK"��"NOR""HIC"λ��һʽ"HIM"  �ܹ��ˣ�ǧ����������!"NOR,
                HIC"\n$N��̤"HIR""BLINK"��"NOR""HIC"λ��һʽ"HIR"  �����ӣ��������������!"NOR,
                HIC"\n$N��̤"HIB""BLINK"��"NOR""HIC"λ��һʽ"HIB"  �����룬��������������!"NOR,
                HIC"\n$N��̤"YEL""BLINK"��"NOR""HIC"λ��һʽ"YEL"  ������ߵ���ɽ�����!"NOR,
                HIC"\n$N��̤"HIC""BLINK"��"NOR""HIC"λ��һʽ"HIC"  �Ź��ϣ�����ױ�����¿!"NOR,
                HIC"\n$N��̤"HIW""BLINK"Ǭ"NOR""HIC"λ��һʽ"HIW"  �����������������ǧ��!"NOR,
                });
              
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취����Ӧ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ�����������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i,j;
	    mapping* m_actions;
		string strs;
		m_actions=me->query("skill_yinglong-stick");

        if( !me->query_temp("zuizj") ) {
           if(me->query("skill_yinglong-stick")==0) 
		    	return action[8+random(6)];
           if(random(0))
		    	return action[8+random(6)];
          return m_actions[random(sizeof(m_actions))];
		}
       else 
		   j=me->query_temp("zui")%8;
           message_vision(liudao[j],me);
           me->add_temp("zui",1);
        return action[j];
}
                

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰӦ��������\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("�㰴����ѧ����һ��Ӧ��������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("wusheng") + "/yinglong-stick/" + func;
}

mixed fail_hit(object me, object victim)
{    if (me->query_temp("zuizj"))
      {
      switch (me->query_temp("zui")%8)
                    {
                        case 1: return HIC"$nԶ��"HIY"����λ��"HIC"����ָ�����λ��ȥ��\n"NOR;
                        case 2: return HIC"$n����"HIG"����λ��"HIC"���첽�뿪��\n"NOR;
                        case 3: return HIC"$n��"HIM"����λ��"HIC"��мһ�ˣ���֮߮�С�\n"NOR;
                        case 4: return HIC"$n�Ը�"HIR"����λ��"HIC"�������࣬�ܿ��ɱ��һ��Ѫ·��\n"NOR;
                        case 5: return HIC"$n����"HIB"����λ��"HIC"һ�־�ԶԶ�Ķ��˿�ȥ��\n"NOR;
                        case 6: return HIC"$n��̤"YEL"����λ��"HIC"��һ���������ˡ�\n"NOR;
                        case 7: return HIC"$nһ��СԾ����������"HIC"����λ��"HIC"��\n"NOR;
                        case 0: return HIC"$n���ɵ�һ�����ܿ���"HIW"��Ǭλ��"HIC"��\n"NOR;
                        //default: return 1;
                    }
       }   
}      
mixed hit_ob_msg(object me,object victim)
{   string strs;
        if (me->query_temp("zuizj"))
      {//me->add_temp("zui",1);
      switch (me->query_temp("zui")%8)
              {
                        case 1: return HIY"$n�����ڡ���λ���ж���֪����\n"NOR;
                        case 2: return HIG"$n���롺��λ����������·��\n"NOR;
                        case 3: return HIM"$n������λ����Χ���ŵû���ֱð�亹��\n"NOR;
                        case 4: return HIR"$n���롺��λ�����Ѿ���ƣ���ߡ�\n"NOR;
                        case 5: return HIB"$n��������λ���������Լ������˽�ȥ��\n"NOR;
                        case 6: return YEL"$nһ����ȴ�������롺��λ����\n"NOR;
                        case 7: return HIC"$n���ŵ����롺��λ����ȴ��ôҲ�߲�������\n"NOR;
                        case 0: return HIW"$n�ۿ��Լ����롺Ǭλ����ȴ��֪����Ǻá�\n"NOR;
               }
       }
}        
