// liejiuquan.c,���������ȭ��
// created by foc,26-08-01 
//˵������˵�е������ļ����书��Ŀǰֻ����ˮ���ɡ�ֻ�������ѧϰ��
//���иߣ��˺������ϣ�pfm������

inherit SKILL;
#include <ansi.h> 

mapping *action = ({
  ([
    "action":
"$NͻȻ����һ����������$n�ı���$N�����ҽţ����ϴ�����ת\n"
"��"+BLINK""+HIM"�Ϻ�ɫ"NOR+"����������$n��$l���߹�ȥ��\n",
    "force":            120,
    "dodge":            -20,
    "parry":            -10,
    "damage_type":      "����",
  ]),
  ([
    "action":
"$N��Цһ�������Ծ����ŵ�����$n��$n��Ҫ�мܣ�$Nȴһ����\n"
"���ҽ����϶�������$n����һ�����ż�ǿ������������ʵ��С\n",
    "force":            150,
    "dodge":            -25,
    "parry":             -5,
    "damage_type":      "����",
  ]),
  ([
    "action":
"$N��$n��ǰһԾ��ͬʱ�������$n��ͷ�������Ź���һ�䣬�����\n"
"Ϊ���ģ�һ�������ҽ���˲����$n�����˶�ʮ����\n",
    "force":            190,
    "dodge":            -30,
    "parry":              0,
    "damage_type":      "����",
  ]),
  ([
    "action":
"$N�����ҽ�ɨ��$n�����������Ÿ�ɨΪ���߻���$n��ͷ��,$n��û��\n"
"Ӧ������$N�Ѿ�С������ͬʱ���������������¶�������$n��\n"
"�°ͣ��ż�������"+BLINK""+HIM"�Ϻ�ɫ"NOR+"���������ø�������\n",
    "force":            110,
    "dodge":             -5,
    "parry":             -5,
    "damage_type":      "����",
  ]),
  ([
    "action":
"$N����һ̧��һ��"+BLINK""+HIM"�Ϻ�ɫ������"NOR+"�����γɣ�\n"
"��������һ�ӣ�������������$n�ɹ�ȥ���������������ȺͽǶ�\n"
"�����˵㡣$n������֣�$N����ӰͻȻ����������ǰ���֣��ҽŴ�\n"
"���������֮���������ϣ������������ǰ�س�$N�������\n",
    "force":            200,
    "dodge":            -10,
    "parry":            -30,
    "damage_type":      "����",
  ]),
  ([
    "action":
"$N˫��һչ������"+BLINK""+HIM"�Ϻ�ɫ������"NOR+"�����γɣ�\n"
"����˫��һ�ӣ�������������$n�ɹ�ȥ��һǰһ���ٶȷǳ��졣\n"
"$N����ӰͻȻ�ں����������ǰ���֣��ҽŴ����������֮������\n"
"���ϣ�����һ����������Ը�������ɨ��ǰ����������ϡ�����\n"
"��������ֱ�߹���$n��$l����ǰ���������ȴ��ת��������Ϯ��$n\n"
"�ĺ�",
    "force":            350,
    "dodge":            -20,
    "parry":            -20,
    "damage_type":      "����",
  ]),
  ([
    "action":
"$Nȫ��ų�"+BLINK""+HIM"�Ϻ�ɫ"NOR+"��������ǿ�������������\n"
"$n���ߡ�ͻȻ��$N������һ�䣬��Ϊ��"+BLINK""+HIY"���ɫ������"NOR+"�����ܵĿ�������\n"
"�����˹�ȥһ��������$N��������һ���ҹ�ȭ��һ���޴�������������\n"
"�ɣ�����$nϯ���ȥ���޴�������ڵ��ϻ�����һ��������ѹ�\n",
    "force":            250,
    "dodge":             -5,
    "parry":            -30,
    "damage_type":      "��������",
  ]),
});

int valid_learn(object me)
{
    if(me->query("race")=="ħ��")
    return notify_fail("�����书ֻ�����������̳С�\n");
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
    return notify_fail("��ϰ�������ȭ������֡�\n");
    if( (int)me->query_skill("liejiuquan", 1 ) < 30 )
{ 
    if( (int)me->query_skill("cuixin-zhang",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");    
    if( (int)me->query_skill("changquan",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("puti-zhi",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("yinfeng-zhua",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("jinghun-zhang",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("dragonfight",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("moyun-shou",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("wuxing-quan",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("jienan-zhi",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("fumozhang",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
}
    
       if( (int)me->query_skill("spiritforce", 1) < 60 && (int)me->query_skill("segokee",1)<0)
       return notify_fail("���������Ϊ������������ѧϰ�������ȭ��\n");
       if( (int)me->query_skill("liejiuquan", 1) > 302 )
       return notify_fail("���ȭ����Ϊ�Ѿ��������˵���������磬û�취����ˡ�\n");
       if( (int)me->query_skill("liejiuquan", 1) > (int)me->query_skill("spiritforce", 1 ) && (int)me->query_skill("segokee",1)<1)
{
        me->add("kee", -4000 );
        me->add("sen", -4000 );
        message_vision(HIR"$N����ѧϰ�������ȭ�������������ͻȻ����������$N�ҽ���һ���� \n"NOR,me);
}
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
            if( (int)me->query_skill("liejiuquan", 1 ) < 60 )
{ 
    if( (int)me->query_skill("cuixin-zhang",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");    
    if( (int)me->query_skill("changquan",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("puti-zhi",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("yinfeng-zhua",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("jinghun-zhang",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("dragonfight",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("moyun-shou",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("wuxing-quan",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("jienan-zhi",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
    if( (int)me->query_skill("fumozhang",1) < 100 )
    return notify_fail("�������ȭ����������ȭ����������û�е����Ҫ����Ϊ֮ǰ��\n�����ܾ���ôѧϰ�ġ�\n");
}
        if( (int)me->query_skill("liejiuquan", 1) > 302 )
        return notify_fail("���ȭ����Ϊ�Ѿ��������˵���������磬û�취����ˡ�\n");
        if( (int)me->query_skill("spiritforce", 1) < 100 && (int)me->query_skill("segokee",1)<1)
        return notify_fail("��������ϰ����ȭ����������Ȼ�������������\n");       
        if((int)me->query_skill("spiritforce", 1) < (int)me->query_skill("liejiuquan", 1 ) && (int)me->query_skill("segokee",1)<1)
{
        me->add("kee", -4000 );
        me->add("sen", -4000 );
        message_vision(HIR"$N������ϰ�������ȭ�������������ͻȻ����������$N�ҽ���һ���� \n"NOR,me);
}
        if( (int)me->query("sen") < 200)
        return notify_fail("��ľ����޷��������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("kee") < 200 )
        return notify_fail("�����ڻ�����ʹ���̣���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 350 )
        return notify_fail("������������ˡ�\n");

        me->receive_damage("kee", 70);
        me->add("force", -30);

        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("mojie") + "/liejiuquan/" + func;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("liejiuquan", 1)==100 )
{
        me->add("kar", -2 );
        me->add("spi", 1 );
        message_vision(HIY"$N��ȫ��ͻȻ�ų�ǿ�������������$N����Ϊ����һ���µĽ׶Ρ�\n
����$N��������һ���ʹ���ƺ���ʲô������������һ����\n"NOR,me);
}
        if( (int)me->query_skill("liejiuquan", 1)==200 )
{
        me->add("kar", -5 );
        me->add("spi", 2 );
        me->add("str", 1 );
        me->add("max_force", 300 );
        me->add("combat_exp", 500000 );
        me->add("daoxing", 500000 );
        message_vision(HIY"$N��ȭ����Ϊ����һ���µľ��磬�������ʹ���̣��ƺ���ʲô������������һ����\n��$N��ȷ�е��Լ��������ˡ�\n"NOR,me);
}
        if( (int)me->query_skill("liejiuquan", 1)==300 )
{
        me->add("kar", -10 );
        me->add("combat_exp", 1000000 );
        me->add("daoxing", 500000 );
        me->add("spi", 2 );
        me->add("str", 1 );
        me->add("cps", 1 );
        me->add("con", 1 );
        me->add("cor", 1 );        
        message_vision(HIY"�޴��ʹ���$N�������ﱬ��������$N���˷�һ�����Χ�Ķ���ȭ����ߡ�\n���ҵ���������Ű�����������ѳ������롣\n"NOR,me);
        me->start_busy(10);
        me->set("live_forever", 0 );
        me->set("live_forever_announced", 0 );
        write ("��е��Լ��������ˣ���������ĳЩ�����������ˡ�\n");
        message("channel:rumor", HIY + "�����δ��¡��������棺��˵"+
     me->query("name")+"���������ȭ��Ϊ�Ѿ�����һ���൱�ľ��硣�ۣ����������ҵ�λ�ðɣ�\n"NOR,users());
}

}