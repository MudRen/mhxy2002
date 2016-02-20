//�����޷���yaohu-whip.c
//created by foc,27-08-01
//�ص�˵�����������ߣ����иߣ�pfmǿ�����������ơ�

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
   ([   "action":
"$N��������������$w����$w����$nһ�ӣ�������������ʱ����$w�ϣ�\n�Ӹ�������Ϯ��$n��������$n�Ѿ��޴������ˣ�\n",
     "dodge":     -5,
     "parry":    -30,
     "damage":    80,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���Ծ������һ�ӣ�"+HIG"����$w��Ȼ�䳤��"NOR"��$N������һ�ˣ�\n��$w�������������Ƶģ�������������$n��\n",
     "dodge":     -15,
     "parry":     -25,
     "damage":     90,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����ų�"+HIR"��ɫ������"NOR"���������е�$w��Ȼ��"+HIG"ֲ��"NOR"һ�������˴�\n��СС��ɫ"+HIM"�����Ļ�"NOR"��$N��һ������Щ"+HIM"��"NOR"������ɢ�����������"+HIM"����"NOR"��\n������������Ϯ��$n��\n",
     "dodge":     -20,
     "parry":      10,
     "damage":     50,
     "damage_type":   "��������"
   ]),
   ([   "action":
"$N���һ����������$w���������������$n������֣�\nͻȻ$N����һ������$w�����ܶ�"+HIG"�����Ĵ�"NOR"������ת�ž���$n��\n",
     "dodge":     -10,
     "parry":      -5,
     "damage":     80,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����ų�"+HIR"��ɫ������"NOR"������ͻȻ����������"+BLINK""+HIM"����"NOR"��Ư����$N����Χ��\n���ţ�$N����ʹ�˸�������$w�Ͼ�Ȼ������ǿ�ҵ�������\n��Ȼ����������֮�£����е�"+BLINK""+HIM"����"NOR"����$n�����ȥ�����ƾ��ˣ�\n",
     "dodge":     -30,
     "parry":      10,
     "damage":     70,
     "damage_type":   "��������"
   ]),
   ([   "action":
"$N������$wһ�ף���"+HIG"$wȴ���������Ƶģ�Χ����$N������ת"NOR"��\n���ţ�$N������ϣ�����$nײȥ���˻�δ����$n������\n�Ѿ������������������˺ü����˺ۡ�\n",
     "dodge":    -30,
     "parry":    -30,
     "damage":   150,
     "damage_type":   "��������"
   ]),
   ([   "action":
"$N������ͻȻ���˱仯��"+HIG"����$wͻȻ��ñ�ֱ�ޱ�"NOR"������$N��\n����$w����$nͶ����ȥ��ͬʱ��ָһ����һ��"+BLINK""+HIR"Ǿޱ"NOR"���������$n��\n",
     "dodge":     10,
     "parry":    -10,
     "damage":    90,
     "damage_type":   "���˼Ӹ���"
   ]),
});

int valid_learn(object me)
{
   object ob;
   
   if((int)me->query_skill("yaohu-whip",1)>=282)
     return notify_fail("�������ֱ޷��ϵ������Ѿ������ܼ�����˭ѧ����\n");
   if( (int)me->query("combat_exp")<500000)
     return notify_fail("���ս��������̫�٣�������������Լ������������﹥����Ч����\n");
   if((int)me->query("daoxing")<200000)
     return notify_fail("���������Ϊ�����ھ���ѧ�����Σ�\n");
   if((int)me->query_skill("throwing",1)<100)
     return notify_fail("���ֱ޷���Ҫ�õ������������㻹û�ﵽ��׼��\n");
   if((int)me->query_skill("yaoli",1)<100) 
     return notify_fail("������������Կ�ʼѧϰ���ֱ޷���\n");
   if((int)me->query_skill("whip",1)<100)
     return notify_fail("�Ȱѻ�������������ɣ�\n"); 
   if( (int)me->query("max_force") < 500 )
     return notify_fail("�������������û�а취ѧϰ�����޷���\n");
   if((int)me->query_skill("unarmed",1)<100)
     return notify_fail("��ı������������ٶ������ɣ�\n");
   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("���������һ�ѱ��Ӳ������޷���\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}

int practice_skill(object me)
{
   if((int)me->query_skill("yaohu-whip",1)>=282)
     return notify_fail("�������ֱ޷��ϵ������Ѿ������ܼ�������ô��Ҳ�����н����ˡ�\n");
   if( (int)me->query("kee") < 100
   ||   (int)me->query("force") < 100 )
     return notify_fail("�����������Ѫ������û�а취��ϰ�����޷���\n");
   if( (int)me->query("combat_exp")<600000)
     return notify_fail("���ս��������̫�٣���ô������\n");
   if((int)me->query("daoxing")<300000)
     return notify_fail("���������Ϊ�����ھ����������Σ�\n");
   if((int)me->query_skill("throwing",1)<100)
     return notify_fail("���ֱ޷���Ҫ�õ������������㻹û�ﵽ��׼��\n");
   if((int)me->query_skill("whip",1)<100)
     return notify_fail("�Ȱѻ�������������ɣ�\n"); 
   if( (int)me->query("max_force") < 500 )
     return notify_fail("�������������û�а취��ϰ�����޷���\n");
   if((int)me->query_skill("unarmed",1)<100)
     return notify_fail("��ı������������ٶ������ɣ�\n");
   me->receive_damage("kee", 50);
   me->add("force", -10);
   write("�㰴����ѧ����һ�������޷���\n");
   return 1;
}
void skill_improved(object me)
{
   if((int)me->query_skill("yaohu-whip",1)==60)
{
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   tell_object (me, "�㾭����ϰ��ͻȻ�������򣬱޷��͵ؽ����ˣ�\n");
}
   if((int)me->query_skill("yaohu-whip",1)==120)
{
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   me->improve_skill("yaohu-whip",60000);
   tell_object (me, "�㾭����ϰ��ͻȻ�������򣬱޷��͵ؽ����ˣ�\n");
}
   if((int)me->query_skill("yaohu-whip",1)==180)
{
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   me->improve_skill("throwing",60000);
   tell_object (me, "����ϰ�У���ͻȻ����һЩ����ʹ�õķ��š�\n");
}
   if((int)me->query_skill("yaohu-whip",1)==240)
{
   me->add("str",2);
   me->add("spi",2);
   me->add("int",5);
   me->add("per",2);
   me->add("combat_exp",200000);
   me->add("daoxing",100000);
   tell_object (me, "�������������׶ε���ϰʱ��ͻȻ�����Լ��������е㲻һ���ˡ�\n");
}
   if((int)me->query_skill("yaohu-whip",1)==280)
{
   me->improve_skill("yaohu-aoyi",10000);
   tell_object (me, "��ͻȻ������һЩ������\n");
   message("channel:rumor", HIM + "��ҥ�ԡ�ĳ�ˣ���˵"+
     me->query("name")+"�Ѿ������˱޷����ռ��������磡\n"NOR,users());
   message_vision(HIG "$N����һ�棬���еı��ӻ���һ�������Ļ��ߣ�\n���ܵĶ�����û���������������������Ļ��ˡ�\n" NOR,me);
   tell_object (me, "����������������޷��ͽ��������յľ��磬\n�Ժ�Ľ���ֻ�ܿ���������ˡ�\n");
}
   return;
}

string perform_action_file(string func)
{
        return CLASS_D("mojie") + "/yaohu-whip/" + func;
}