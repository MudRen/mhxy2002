// segokee.c  ʥ����
//created by foc,29-6-01
//�ص�˵������ǿ�Ķ�����������������������ߵģ�Ҳ���������ġ�

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
    if((int)me->query_skill("force",1) < 250)
    return notify_fail("����������ʥ����������û���κν������ƺ��ǻ���������\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("���У�����������Կ�ʼ����ʥ������\n");
    if(me->query_skill("moonforce",1)     
                || me->query_skill("ningxie-force",1)
                || me->query_skill("lengquan-force",1)
                || me->query_skill("zhenyuan-force",1)
                || me->query_skill("huntian-qigong",1)
                || me->query_skill("tonsillit",1)
                || me->query_skill("dragonforce",1)
                || me->query_skill("huomoforce",1)
                || me->query_skill("wuxiangforce",1)
                || me->query_skill("lotusforce",1)
                || me->query_skill("zixia-shengong",1)    
                || me->query_skill("evileye",1))
    return notify_fail("�����ϵ�����������������ʥ������\n");
    if((int)me->query("combat_exp")<2300000)
    return notify_fail("���ս�����鲻�㣬���²��ܺܺõؿ�������������\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("�����Ϊ���㣬���²��ܺܺõؿ�������������\n");
    if((int)me->query_skill("segokee",1)>151)
    return notify_fail("���ʥ�����Ѿ��������ܹ������ļ��ޣ��Ժ�Ľ���ֻ�ܿ���������ˡ�\n");
    if((int)me->query("kee")<200)
    return notify_fail("�������������㣬��ϧ�����ɣ�\n");
    if((int)me->query("sen")<200)
    return notify_fail("���Ѿ�̫���ˣ���ϧ�����ɣ�\n");
    if((int)me->query("force")<200)
    return notify_fail("��տ�ʼ����ʥ������ȴ�����Լ����������ˣ�ֻ��ͣ��������\n");
    me->receive_damage("kee",100);
    me->receive_damage("sen",100);
    me->add("force",-10);
    return 1;
}
/*
int valid_learn(object me) 
{
        return notify_fail("����ʥ�������˱��ͺ��٣����ϸ��˵���������ͬ��û�취ͨ��ѧϰ��������\n");
}
*/
string exert_function_file(string func)
{
        return CLASS_D("mojie") + "/segokee/" + func;
}

void skill_improved(object me)
{
    if((int)me->query_skill("segokee",1)==10)
{
    message_vision(HIY "$N���ŷų��Լ���ʥ���������շų�һ�㣬���շ��˵���\n��������$N��ʥ��������һ���µľ��硣\n" NOR,me);
    message("channel:rumor", HIM + "�����α����顿ŷ��ɣA���ۣ�����������������\n"NOR,users());
    message("channel:rumor", HIM + "�����α����顿ŷ��ɣB����˵�����������"+me->query("name")+"������ʥ������ʱ�򡭡�\n"NOR,users());
    me->add("str",1);
    me->add("spi",1);
    me->add("con",1);
    me->add("cor",1);
    me->add("per",1);
    me->add("cps",1);
    me->add("int",1);
    me->add("kar",-5);
}
}