//18slash.c ʮ����ն
//created by foc,04-7-01
//�ص�˵����˲���ʮ������������
//�������û��busy����ô��ͬ���������������С�

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    object weapon;
    int myexp, urexp, mysk, ursk, damage, n;
    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
    return notify_fail("��Ҫ��˭ʹ�á�ʮ����ն����\n");
    if(!me->is_fighting(target))
    return notify_fail("ֻ����ս����ʹ�á�ʮ����ն����\n");
    if((int)me->query_skill("sword",1)<120 || (int)me->query_skill("evilsword",1)<60)
    return notify_fail("������ʹ��ʮ����ն�����������������\n");
    if((int)me->query("max_force")<1000 || (int)me->query("force")<700)
    return notify_fail("�������Ŀǰ������ʹ�����С�\n");
    if((int)me->query("combat_exp")<1000000 || (int)me->query("daoxing")<300000)
    return notify_fail("�����Ϊ�в�����ʹ�����С�\n");
    if((int)me->query_skill("evileye",1)<120)
    return notify_fail("���а�����в����Կ���������ʹ�á�\n");
    if( me->query_skill_mapped("force")!="evileye" )
    return notify_fail("�����ʹ��а����������������\n");
    if(me->query_temp("16slash_busy"))
    return notify_fail("���������δ�ظ���û�취�����С�\n");
    else
{
    weapon = me->query_temp("weapon");
    myexp=(int)me->query("combat_exp");
    urexp=(int)target->query("combat_exp");
    mysk=(int)me->query_skill("evileye",1)+(int)me->query_skill("evilsword",1);
    ursk=(int)target->query_skill("dodge",1)+(int)target->query_skill("parry",1);
    damage=mysk+random((int)me->query("kar"));
    n=0;
    me->add("force",-700);
    message_vision(HIC "$Nͷ�ϵ�а��ͻȻ��â��ʢ������ȫ��ȼ���ɫ�Ļ��档\n" NOR,me,target);
    message_vision(HIR "$N����ȫ��Ļ��棬���ְ���"+weapon->query("name")+HIR"���棬����$n���˹�ȥ��\n����ʹ�����������ı�ɱ������ʮ����ն��\n" NOR,me,target);
    message_vision(MAG "$N˫���ս�������$nӭ������һ����\n" NOR,me,target);
{//1
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "$n���������Ľ�����ס���������ã���$N�����ˡ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$n��ס����һ����û�����ˡ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N����һ�䣬��������$n��\n" NOR,me,target);
{//2
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n������������������һ����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n���˹�ȥ��\n" NOR,me,target);
}
}
    message_vision(MAG "$N����һ����ն��$n���䣡\n" NOR,me,target);
{//3
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n������������������һ����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n���˹�ȥ��\n" NOR,me,target);
}
}
    message_vision(MAG "$N����"+weapon->query("name")+MAG"��ȫ������$n��\n" NOR,me,target);
{//4
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n����������������һ����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n���˹�ȥ��\n" NOR,me,target);
}
}
    message_vision(MAG "$N���һ�����Ĵ�Ϊ���������$nն�����Σ�\n" NOR,me,target);
{//5
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n��������������������һ����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n���˹�ȥ��\n" NOR,me,target);
}
}
    message_vision(MAG "$N������һ�࣬�˽�������$n��ͷ����\n" NOR,me,target);
{//6
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n�����������Դ�������Ѫ���ɣ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n��ס�ˡ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N�ٿ�Ծ��ȫ������$n�ļ��\n" NOR,me,target);
{//7
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n������������类����һ������ǵ��˿ڣ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$n����һ�࣬���˿�ȥ��\n" NOR,me,target);
}
}
    message_vision(MAG "$N����һ������������"+weapon->query("name")+MAG"���������Ľ������ְ����$n��\n" NOR,me,target);
{//8
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n�������������ر�����һ������С�����˿ڣ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n��ס�ˡ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N��غ�һ������˫���ս�ն��$n��˫�ţ�\n" NOR,me,target);
{//9
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n����������˫���ƺ��������ˣ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$nһ��С������������С�\n" NOR,me,target);
}
}
    message_vision(MAG "$N�ô˻��ᣬ˫�ֽ���"+weapon->query("name")+MAG"��һ�����ὣ���ų�һ������������Ϯ��$n��\n" NOR,me,target);
{//10
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n�ڿ��в�֪���룬�����������һ��������˿ڣ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$n�ڿ���һ���������˿�ȥ��\n" NOR,me,target);
}
}
    message_vision(MAG "$N��$n��δ��أ�����������һ�壬һ���������̳���$n��\n" NOR,me,target);
{//11
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n������������������ײ���������ﴫ��һ��������ѵ�������\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$n�ҽ���������������һ�㣬�����㿪�ˡ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N���Ÿղ��ͷ������ķ������������峯��$n�����ȥ���˽�һ����\n" NOR,me,target);
{//12
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$nʵ�ڶ���������С������һ����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$n��ס�ˡ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N����һ������ͷ��һ��������һ����Բ����$n��\n" NOR,me,target);
{//13
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n�����޴룬�ز�������һ����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "������$nȫ����ס�ˡ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N��������������һ�У�\n" NOR,me,target);
{//14
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n���ؿڱ�����һ��ʮ�֣���Ѫ���䣡\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$nһ������������������������ݣ�\n" NOR,me,target);
}
}
    message_vision(MAG "$N���һ����˫���ٿ�һ�㣬ȫ������������ڽ��ϣ�\n�����ޱȵ�ɱ�����$n����ͷ��һ����\n" NOR,me,target);
{//15
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n�����������Դ�������Ѫ���ɣ�\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$n����һ�࣬��ס����һ����\n" NOR,me,target);
}
}
    message_vision(MAG "$N��$n���������˲�䣬����һ����ն��$n�ĺ󾱣�\n" NOR,me,target);
{//16
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "���$n����������һ����Ѫ��ʱ�����˳�����\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "����$n���˸��ڹ���ͷ�������Ƕ����һ����\n" NOR,me,target);
}
}
    if(n>0)
{
    message_vision(HIW "$nȫ��һ������"+chinese_number(n)+HIW"������Ѫ��ͣ����������\n" NOR,me,target);
    me->start_busy(n);
}
    if(n=0)
{
    message_vision(HIW "$n����һ�����Ĺ����о�Ȼ��������\n" NOR,me,target);
    me->start_busy(3);
}
    me->set_temp("16slash_busy",1);
    call_out("remove_effect",n+120,me);
}

    return 1;
}

int remove_effect(object me)
{
    me->delete_temp("16slash_busy");
    tell_object (me, "��ͻȻ�е��Լ��������ظ��ˣ��ֿ���ʹ���ؼ��ˡ�\n");
}
