//evileye.c а����
//create by foc,9-6-01
//�ص㣺����������������ʱ������������

inherit FORCE;

#include <ansi.h>

int valid_enable(string usage)
{ 
    return usage=="force";
}

int valid_learn(object me) 
{ 
    if( (int)me->query("combat_exp",1) < 200000 )
    return notify_fail("����Ц����������ѧ����һ����Ʋ���а����ô�죿\n��ϧ�����ɣ�������һ���޳ɵġ�\n");
    if( (int)me->query("daoxing",1) < 250000 )
    return notify_fail("���У�������в����Կ���а�ۡ�\n");
    if( (int)me->query_skill("force", 1) < 60 )
    return notify_fail("���������ΪҪѧа�����������ģ�\n");
    if( (int)me->query_skill("evileye", 1) > 290 )
    return notify_fail("���а�����Ѿ�����һ��ǰ��δ�еľ��磬�޷�������\n������ˡ�\n");
    
    return 1;
}

int practice_skill(object me)
{
    if( (int)me->query_skill("force", 1) < 80 )
    return notify_fail("���������ΪҪ��а�����������ģ�\n");
    if( (int)me->query_skill("evileye",1) < 80 )
    return notify_fail("��������ϰа����������û���κν�����\n");
    if( (int)me->query_skill("force",1) < (int)me->query_skill("evileye", 1)+3  && (int)me->query_skill("force", 1) > 70 && (int)me->query_skill("evileye", 1) > 70 )
    me->receive_damage("kee", 500 - (int)me->query_skill("force",1)/2 );
    message_vision(HIR"$Nͷ�ϵ�а��ͻȻ�ų�����Ĺ�â��$N���ɵøе�һ���ʹ��\n�ƺ�������ʼ��$N��ȥ��\n"NOR,me);
    return notify_fail("ͻȻһ����Ѫ�����˫�������˳�����\n");
    if( (int)me->query("kee") < 200 )
    return notify_fail("�������������\n");
    if( (int)me->query("shen") < 200 )
    return notify_fail("û�㹻�ľ�����ô����а�ۣ�\n");
    if( (int)me->query("force") < 50 )
    return notify_fail("������������ˡ�");
    me->receive_damage("kee", 60);
    me->receive_damage("sen", 60);
    me->add("force",-20);

    return 1;
}

string exert_function_file(string func)
{
      return CLASS_D("mojie") + "/evileye/" + func;
}   

//���µ������Ǹ�����evileye����ҵĽ�����

void skill_improved(object me)
{
    tell_object (me, "�ۣ��������ѽ��˧ѽ��\n");
}
