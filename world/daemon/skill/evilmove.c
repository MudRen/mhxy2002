//аӰ������ evilmove.c
//created by foc,22-06-01
inherit SKILL;

#include <ansi.h>

string *dodge_msg = ({
     "$n����Ӱһɢ����Ϊ�߰˸�"+BLINK""+HIY"Ӱ��"NOR"�������ܿ���$N��֪���ĸ�\n�����ĸ��Ǽ٣��޴�׷�ϡ�\n",
     "$n���˷�����ֱ�嵽$N��ǰ��$N��һ������ȴ������ֻ�Ǹ�"+BLINK""+HIB"Ӱ��"NOR"��\n��$n���Ѿ�����$N�����\n",
     ""+BLINK""+HIC"$nͷ��а�۷ų���ֵĹ�"NOR"��һɲ�Ǽ�$N˫��ʧ�����޷�����������\n",
     ""+BLINK""+HIR"$n��ȫ��ͻȻȼ���ɫ�Ļ���"NOR"���û���ǧ�ٸ���Ӱ��$N�Ĺ���ʧ���ˡ�\n",
     "$n����ͻȻһ�ͣ�$N��æ����������ȴ���ִ��е�ֻ��$n��"+BLINK""+HIG"�·�"NOR"��\n",
     ""+BLINK""+HIW"$n������ͻȻ��ʧ��"NOR"��$N��ʱ��֪���ԡ�ԭ��$n������$N��Ӱ���\n",
});

int valid_enable(string usage)
{ 
    return usage=="dodge"||usage=="move";
}

int valid_learn(object me)
{
        if( (int)me->query_skill("evilmove", 1) > 280 )
        return notify_fail("���������Ѿ��������ˣ���ѧ�ˣ���ϧ�����ɣ�\n");
        if( (int)me->query_skill("evileye", 1) < 1 )
        return notify_fail("���޷�ѧ�������书�������ǻ���������\n");
        if( (string)me->query_skill_mapped("force")!= "evileye")
        return notify_fail("����ôѧҲѧ�������ֹ����ѵ��ǻ�������ʲô���⣿\n");
	if( (int)me->query_skill("evileye", 1) < 30 )
	return notify_fail("���а��������������ôѧϰ�����书��\n");
        if( (int)me->query_skill("spiritforce", 1) > 0 )
        return notify_fail("��ȫ�����������Ҫ����ϵ���书���²��С�\n");
        if( (int)me->query("combat_exp") < 100000 )
        return notify_fail("��ս�����鲻�㣬������Ц���ˡ�\n");
        if( (int)me->query("daoxing") < 100000 )
        return notify_fail("����Ϊ�������������ﵷ���ˡ�\n");
        if( (int)me->query_skill("evileye", 1) < (int)me->query_skill("evilmove", 1) )
{
        me->receive_damage("kee", -300);
        me->receive_damage("sen", -300);
        message_vision(HIR"ͻȻ��һ��������$N��������ը�ѿ����� $N�����ҽ���һ����\n"NOR,me);
        return notify_fail("���������а������Ϊ������\n");
}
        if( (int)me->query_skill("evilmove", 1) > 290 )
{
        me->receive_damage("kee", -3000 );
        me->receive_damage("sen", -3000 );
        message_vision(HIC"$Nͷ�ϵ�а��ͻȻ�ų�һ����ֵĹ⣬���ž�ʧȥ�˹�ʡ�\n$N������ʹ���ϼӾ磬�������˹�ȥ��\n"NOR,me);
        return notify_fail("��Ȼ�����������ù�ͷ�ˡ�\n");
}
        if( (int)me->query_skill("evilmove", 1) < (int)me->query("spi") * 8 || (int)me->query_skill("evilmove", 1) < (int)me->query("int") * 8 )
        return notify_fail("���аӰ�������������ƺ����˼��ޡ��ٴ������ɣ�\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (string)me->query_skill_mapped("force")!= "evileye")
        return notify_fail("�����ϰû���κν�����������������ʹ�����в���֮����\n");
	if( (int)me->query("sen") < 200 )
	return notify_fail("��ľ���̫���ˣ����������ˡ�\n");
        if( (int)me->query("kee") < 200 )
	return notify_fail("������������ˣ����������ˡ�\n");
	if( (int)me->query_skill("evilmove", 1) < 30 )
        return notify_fail("�Թԣ�����ô����Ϊ�����Լ���ʼ��ϰ������Ҫ�ֳ��������ġ�\n");
        if( (int)me->query_skill("evileye", 1) < (int)me->query_skill("evilmove", 1) )
{
        me->receive_damage("kee", -300);
        me->receive_damage("sen", -300);
        message_vision(HIR"ͻȻ��һ��������$N��������ը�ѿ����� $N�����ҽ���һ����\n"NOR,me);
        return notify_fail("���������а������Ϊ������\n");
}
        if( (int)me->query_skill("evilmove", 1) > 280 )
        return notify_fail("���������Ѿ��������ˣ������ˣ���ϧ�����ɣ�\n");
        if( (int)me->query_skill("evilmove", 1) > 290 )
{
        me->receive_damage("kee", -3000 );
        me->receive_damage("sen", -3000 );
        message_vision(HIC"$Nͷ�ϵ�а��ͻȻ�ų�һ����ֵĹ⣬���ž�ʧȥ�˹�ʡ�\n$N������ʹ���ϼӾ磬�������˹�ȥ��\n"NOR,me);
        return notify_fail("��Ȼ�����������ù�ͷ�ˡ�\n");
}
        if( (int)me->query_skill("evilmove", 1) < (int)me->query("spi") * 8 || (int)me->query_skill("evilmove", 1) < (int)me->query("int") * 8 )
        return notify_fail("���аӰ�������������ƺ����˼��ޡ��ٴ������ɣ�\n");
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);
        me->receive_damage("force", 1);

	return 1;
}

void skill_improved(object me)
{
    tell_object (me, "�ۣ��������ѽ��˧ѽ��\n");
}

       
