#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object *inv, obj;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
return notify_fail("��Ҫ��˭ʩչ��һ�С������ء���\n");

        if(!me->is_fighting())
 return notify_fail("�������ء�ֻ����ս����ʹ�ã�\n");

	      if((string)me->query("family/family_name") != "������" )
 return notify_fail("������ɳ�������ܾ�����֮��أ�\n");
 if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

     if((int)me->query("force") < 350 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 150 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
if((int)me->query_skill("jinglei-mace", 1) < 50)
 return notify_fail("��ľ��ױ޼��𻹲�����ʹ����һ�л������ѣ�\n");

message_vision(HIW"\n����к�Ȼ���˵�������ֱ��$n��ȥ��\n"NOR, me, target);
me->start_busy(2+random(2));

        mystr=(int)me->query("str");
        tastr=(int)target->query("str");
myexp=(int)me->query("combat_exp")/20;
        taexp=(int)target->query("combat_exp")/30;
        mylvl=(int)me->query_skill("spear")*(int)me->query_skill("bawang-qiang");
        talvl=(int)target->query_skill("parry")*(int)target->query_skill("dodge");
        
        mypot=mystr*mylvl+myexp;
        tapot=tastr*talvl+taexp;
        
        y=random(3);
      
      if( random(mypot) >random(tapot)) {

message_vision(HIY"$N�������������������ţ�\n"NOR, target);
   target->receive_damage("kee", 50 + random((int)me->query("max_force")/40+(int)me->query("force_factor")));
        COMBAT_D->report_status(target);
if (random(2)) {
SPELL_D->attacking_cast(
me,
target,
100,
80,
"kee",
HIR "���׼д��Ż�⣬��$n��Х��ֹ��\n" NOR,
HIR "$n���׻���У�һ���ڣ�\n" NOR, 
HIG "$n���·��ѱ�ȼ�ţ�������ȴ����\n" NOR, 
HIB "$n����һ�ӣ����׻�����أ�\n" NOR, 
RED "$n���׻𷴻����Լ����˸���ü������\n" NOR
);
if( userp(target) ) target->fight_ob(me);
 else if( !target->is_killing(me) ) target->kill_ob(me);
}
}
else{
 me->add("force", -200);
  me->receive_damage("sen", 100);
 message_vision(HIC"ȴ��$N�㿪�ˣ�\n"NOR, target);
 me->start_busy(2+random(2));
return 1+random(5);
}
}
