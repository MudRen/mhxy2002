// five by greenwc
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int damage,qq;
          object obj;


              if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����о�����\n");

        if((int)me->query("force") < 300 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("wuxing-quan", 1) <100)
		return notify_fail("������е��˽⻹������\n");

if((int)me->query_skill("yange-blade", 1) <50)
		return notify_fail("��Խ�����˽⻹������\n");
if((int)me->query_skill("fumo-zhang", 1) <50)
		return notify_fail("���ľ����˽⻹������\n");
if((int)me->query_skill("sanqing-jian", 1) <50)
		return notify_fail("���ˮ����˽⻹������\n");
if((int)me->query_skill("taiyi", 1) <50)
		return notify_fail("��Ի�����˽⻹������\n");
if((int)me->query_skill("kaishan-chui", 1) <50)
		return notify_fail("���������˽⻹������\n");

        me->add("force", -200);
        me->receive_damage("kee", 50);

        obj = target->query_temp("weapon");
        if( random(me->query("max_force")) < 50 ) {
                write("��⣬�������в�˳��\n");
                return 1;
}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
qq=random(5);
message_vision(HIY"\n$N��ȭΪ�ƣ��Կ����˼��£�˫�Ʒ��������Ľ�â��\n"NOR,me,target);
message_vision(HIY"ֻ��һ����������$N˫����$nֱɨ�������õ����ǡ���ϡ�һ����\n"NOR,me,target);
if (random((int)me->query_skill("blade")+ (int)me->query_skill("yange-blade", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("blade")+ (int)me->query_skill("yange-blade", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$nʶ�����������б��˿�����\n"NOR,me,target);

message_vision(HIG"\n$N����һ�����ȣ�˫�ֻ��ţ������������������������ľ\n"NOR,me,target);
message_vision(HIG"˫�����Σ�һʽ��ľ���������ٰ㽫$n���ڵ��У�\n"NOR,me,target);
if (random((int)me->query_skill("staff")+ (int)me->query_skill("fumo-zhang", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("staff")+ (int)me->query_skill("fumo-zhang", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n���鲻�󣬷�ʵ���У����ɻ�����������ơ�\n"NOR,me,target);

message_vision(HIC"\n$N˫�ƺ��İ�������࣬˫�����಻���������У�������ʽ��ˮ�����Ի�ס$n\n"NOR,me,target);
if (random((int)me->query_skill("sword")+ (int)me->query_skill("sanqing-jian", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("sword")+ (int)me->query_skill("sanqing-jian", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$nҲ����$Nȭ���縡Ƽ��Ʈ�ڣ������ıܿ�����һ����\n"NOR,me,target);

message_vision(HIR"\n$N��������һ��һ�������͡�ֱ��$n\n"NOR,me,target);
if (random((int)me->query_skill("spells")+ (int)me->query_skill("taiyi", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("spells")+ (int)me->query_skill("taiyi", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n����һЦ�������ڻ��֮�У����޾�ɫ��\n"NOR,me,target);

message_vision(YEL"\n$N�������һ��ŭȭ�ɰ������\n"NOR,me,target);
message_vision(YEL"�⡰���ڡ������ƣ�ֱ��$n���˵����Կ��ܣ�\n"NOR,me,target);
if (random((int)me->query_skill("hammer")+ (int)me->query_skill("kaishan-chui", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("hammer")+ (int)me->query_skill("kaishan-chui", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n��Ϣ���������࿹�����²��������ҵð�㡣\n"NOR,me,target);

if ((int)me->query_skill("baguazhen",1)>random((int)target->query_skill("literate",1))*2)
{
message_vision(HIW"$nû�������������̣������ڵ��У�\n"NOR,me,target);
target->start_busy(5);
}

me->start_busy(2+random(3));
return 1;
}
