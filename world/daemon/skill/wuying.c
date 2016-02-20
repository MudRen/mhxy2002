// wuying-sword ����Ӱ����

/*
��Ӱ��    dodge  -10    parry  -10    damage  65
�˽���Ϊ��ħ�����������ʱ��������ħ����ʱ�Ѿ������޽�ʤ�н��ľ��磬
����������������������������������ƶ���������Ϊ����Ӱ����������
���У��ֱ�Ϊ�硢�ס��硢�ơ�
*/

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$Nһ��",
        "ֻ��$N��������Ծ��,һ��",
        "$Nʹ��",
        "$NƮȻ������һʽ",
        "$N��������Ծ��,�������ּ�ת��һ��",
        "$N����������һ��",
});


string* skill_tail =({
        "������$w��ͣ�ز�����",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "������$wȥ��Ʈ��������ֻ����$n�ۻ�����",
        "������$w�����㺮�⣬ָ��$nǰ��Ѩ��",
});
mapping *action = ({
	([	"name":			"��",
		"action":
"$Nһ�����е�$w��˲��̳���ʮ����������"+BLINK""+HIW"���ơ�"NOR+"Ū��$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-10,
                "parry":                -10,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһ������$n��$n��æ���Ա�һ����\n"
"����$Nһ�˾��������е�$wͻȻ���˹���������"+BLINK""+HIC"���硹"NOR+"��Ȼǧ���򻯣�ת������$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		45,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N����$w�������������⻷������"+BLINK""+MAG"���ס�"NOR+"����Ѹ��һ����������$n��ǰ̤��һ����$N���ֽ�ָ�Ѵ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		55,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһת������$n��һʽ"+BLINK""+HIY"���硹"NOR+"����$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		65,
		"damage_type":		"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����Ӱ����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
		mapping* m_actions;
		m_actions=me->query("skill_wuying");
        i=me->query_temp("WX_perform");
        if( !me->query_temp("WX_perform")) {
           if(me->query("skill_wuying")==0) return action[random(4)];
           if(random(2))return action[random(4)];
           m_actions=me->query("skill_wuying");
           return m_actions[random(sizeof(m_actions))];
        }
		else 
		{
         return action[i];
		}
		return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ��Ӱ����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ����Ӱ����\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
	return CLASS_D("wusheng") + "/wuying/"+func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("wuying",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"�����Ӱ������������ˣ������Ӱ��������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬����Ӱ���������һ���µ��÷���\n"NOR);
     tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}
void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_wuying");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="��Ӱ����ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_wuying",m_actions);
}