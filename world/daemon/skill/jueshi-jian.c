//BY tianlin@mhxy for 2001.10.7
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N�������ˣ�ʹ��һ��",
        "$N���쳤Ц����Ҳ������һ��",
        "$N����һԾ��ʹ�˸�",
        "$N��̬���У�һ��",
        "$N����ת����ͣ��ͻȻһ��",
        "$N����̤�˸����ֲ���һ��",
});

string* skill_tail =({
        "������$w����������$n����һն",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "�����ֶ�׼$n$lһ����ȥ",
        "����$nת��֮�ʣ��ӳ�һ��",
});



mapping *action = ({
   ([   "action":     "$Nʹ��һ��"+HIR"��"NOR+BLINK+WHT"����ʽ"NOR+HIR"��"NOR+"��������˸�������������޵ش���$n$l",
     "dodge":     0,
     "parry":     15,
     "damage":     35,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����ת����ͣ��ͻȻһ��"+HIR"��"NOR+BLINK+YEL"ɽ����ҡ"NOR+HIR"��"NOR+"ʹ��������$w����һ������������$n$l",
     "dodge":     -10,
     "parry":     15,
     "damage":     45,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����̤�˸����ֲ���һ��"+HIR"��"NOR+BLINK+CYN"��ȥ��Ӱ"NOR+HIR"��"NOR+"����$w����������$n����һն",
     "dodge":     -5,
     "parry":     15,
     "damage":     40,
     "damage_type":   "����"
   ]),
   ([   "action":     "����$N���˼�������Ȼ������Ծ������$wһʽ"+HIR"��"NOR+BLINK+HIG"ƽ��ʽ"NOR+HIR"��"NOR+"��׼$n��$l���һն",
     "dodge":     -15,
     "parry":     5,
     "damage":     50,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
     return notify_fail(CYN"�������������û�а취������������\n"NOR);

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail(RED"���������һ�ѽ�������������\n"NOR);

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_jueshi-jian");
     if(me->query("skill_jueshi-jian")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("�����������������û�а취��ϰ����������\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write(YEL"�㰴����ѧ����һ��"NOR+HIC"��������"NOR+YEL"��\n"NOR);
   return 1;
}
string perform_action_file( string action)
{
return CLASS_D("shenjian") + "/jueshi-jian/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("jueshi-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��Ծ���������������ˣ���ľ�����������һ���µľ��磡\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�Ծ������������һ���µ��÷���\n"NOR);
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

   m_actions=me->query("skill_jueshi-jian");
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

   if(!arg||arg==" ")arg="����������ɱ��"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HBRED+WHT"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_jueshi-jian",m_actions);
}
 
