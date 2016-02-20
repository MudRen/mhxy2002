//firehit.c а����ɱ������
//created by foc,20-06-01
//�ص�˵���������Թ���pfm����ɱ����fear�Լ����԰ɣ�
//��ȼ���������Խ��Խ������

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
     int damage, time, myto, yourto, ft;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("��Ҫ��˭ʹ�á�а����ɱ����������\n");
     if(!me->is_fighting(target))
     return notify_fail("ֻ����ս����ʹ�á�а����ɱ����������\n");
     if(me->query_temp("firehit_busy"))
     return notify_fail("�������У�����ȴ��һ���ʹ����������ʹ��������\n");
     if( (int)me->query_skill("evilfight",1) < 60 )
     return notify_fail("�������ڵ���ɱȭ��Ϊ��Ҫ���ǲ�̫���ܵġ�\n");
     if( (int)me->query_skill("unarmed",1) < 60 )
     return notify_fail("��Ļ�����û��ã��������\n");
     if( (int)me->query("max_force") < 700 )
     return notify_fail("����Ц���������ڵ�����Ҫ�����У�ֻ�����������ε�ʱ��\n");
     if( (int)me->query("force") < 300 )
     return notify_fail("�������ƺ�������������㡣\n");
     if( me->query_skill_mapped("force")!="evileye" )
     return notify_fail("�����ʹ��а����������������\n");
     if((int)me->query_skill("evileye",1) < 60)
     return notify_fail("���а������Ϊ���������ܺܺõؿ���������ʹ�á�\n");
     if((int)me->query("combat_exp") < 200000 )
     return notify_fail("����ս�����������̫�٣�ʹ�����л������ѡ�\n");
     if((int)me->query("daoxing") < 100000 )
     return notify_fail("�����Ϊ�����ߣ������ó���������Ҳ�����\n");
     if((int)me->query("combat_exp")+(int)me->query("daoxing") > (int)target->query("combat_exp")*3+(int)target->query("daoxing")*3+(int)target->query("kar")*100 )
     return notify_fail("��������������ô�������۸�С�����\n");
     if((int)me->query_skill("evileye",1) > 60) ft=1;
     if((int)me->query_skill("evileye",1) > 120) ft=2;
     if((int)me->query_skill("evileye",1) > 180) ft=3;
     if((int)me->query_skill("evileye",1) > 240) ft=4;
     time =4-(int)me->query_skill("evileye",1)/60;
     if(time < 0) time=1;
damage=(int)me->query_skill("evilfight",1)+(int)me->query_skill("evileye", 1)+random((int)me->query("kar"))*3;
     myto=(int)me->query("combat_exp")/5+(int)me->query("daoxing");
     yourto=(int)target->query("combat_exp")/5+(int)target->query("daoxing");
     message_vision(HIC "$Nͷ�ϵ�а���ſ�����ʱ��â��ʢ��ǿ�������������$N�������ϼ��С�\n" NOR,me,target);
     message_vision(HIR "ͻȻ��������һ�䣬һ������ȼ�յĻ�������ˣ�\n" NOR,me,target);
     message_vision(HIG "$N���һ���������У�а����ɱ����������Ȼ��߶����淢���˹�����\n" NOR,me,target);
     message_vision(HIY "ֻ��$N��ȭ����������ǿ�����������Ż��棬���ž޴�ĳ������$n���˹�ȥ��\n" NOR,me,target);
{    
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "���$n�ҽ�һ�����ؿ��Ѿ����˺ü�ȭ������ֱð�������ⱻ�ս��ˡ�\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/2);
     target->receive_wound("kee",damage*ft/2);
     target->receive_wound("sen",damage*ft/2);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "����$n����˫�֣���$N�⼸ȭȫ������������\n" NOR,me,target);
     tell_object (target, "���������ȴ�ܵ���Щ��̶ȵ����ˡ�\n");
     target->receive_damage("kee",100);
     target->receive_damage("sen",100);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
}
     message_vision(HIM "$NԾ�����У�һ�������ҽŴ������ȵĻ�����$n����������\n" NOR,me,target);
{
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "$n��ܲ�������$N�ߵ��˲��ӣ�ֻ�������ꡱ��һ���졣$n��ʱ����������ת��\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/2);
     target->receive_wound("kee",damage*ft/2);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "$n���Ų�æ���������ұ۵�ס����һ����\n" NOR,me,target);
     me->add("force",-100);
}
}
     message_vision(HIW "$N��δ��أ���һ������˫ȭ�ϵĻ������̱�ø������ˣ�\n����$N����ȭ�����������ƻ��Ե�ȭ�����Ż��棬���籩��������$n��\n" NOR,me,target);
{
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "$n����������ȫ������һ�����˼�ʮȭ���ҽв��ϡ�\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("kee",damage*ft/2);
     target->receive_wound("kee",damage*ft/2);
     target->receive_wound("sen",damage*ft/2);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "$n�ۼ�$N�Ĺ������ڣ�����Ӳƴ��һ��������¿������˿�ȥ���Ǳ�֮����\n" NOR,me,target);
     me->add("force",-100);
}
}
     if((int)me->query_skill("evileye",1) >= 120 && target->is_living())
{
     message_vision(HIB "$N������ϣ�ȴ��һҧ����ͷ�ϵ�а�۷����һ����\n�ȵĻ��档��һ��ʵ���ǹ��죬$n���Ҳ�������ˣ�\n" NOR,me,target);
     me->add("force",-200);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/2);
     target->receive_wound("kee",damage*ft/8);
     target->receive_wound("sen",damage*ft/8);
     COMBAT_D->report_status(target, 0);
     time +=1;
}
     if((int)me->query_skill("evileye",1) >= 180 && target->is_living())
{
     message_vision(HIR "$N��һ��أ�$n���л��ᣬ������ǰ������˭֪$Nһ����Ц�������ٶȷų�������\n�ֳ��˺�ɫ�����ƣ��������ְ���������֮�ϡ�$n��ʱ�о������Ȼ��$N��\n��һ�������ֻ�����ǰһ�ƣ�һ�ź�ɫ�������̻���һ����������$n��\n" NOR,me,target);
     time +=1;
     if(target->is_busy() || random(myto) >= random(myto+yourto))
{
     message_vision(GRN "$n�������������ǻ������ض��������˲��ᡣ\n" NOR,me,target);
     target->receive_damage("kee",damage*ft/2);
     target->receive_damage("sen",damage*ft/4);
     target->receive_wound("kee",damage*ft/10);
     target->receive_wound("sen",damage*ft/10);
     COMBAT_D->report_status(target, 0);
     me->reveive_wound("kee",20);
     me->receive_wound("sen",20);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "$n�����������߾�ȫ����ס��$N�Ĺ���������ȴ���˵����ˡ�\n" NOR,me,target);
     me->reveive_wound("kee",10);
     me->receive_wound("sen",10);
     me->add("force",-100);
     target->receive_damage("kee",100);
     target->receive_damage("sen",100);
     COMBAT_D->report_status(target, 0);
}
}
     if(present("sword", this_player()) && (int)me->query_skill("evilsword",1) > 120 && target->is_living())
{
     message_vision(MAG "$Nץס���ᣬ�첽����$n���γ��������Ϻ�ɫ����ն��$n��\n" NOR,me,target);
     time +=1;
     if(target->is_busy() || random(myto) > random(myto+yourto))
{
     message_vision(GRN "���$n���ؿڱ�ն�У���Ѫ���ؾ����˳�����\n" NOR,me,target);
     target->receive_damage("kee",(int)me->query_skill("evilsword",1));
     target->receive_damage("sen",(int)me->query_skill("evilsword",1));
     target->receive_wound("kee",(int)me->query_skill("evilsword",1)/12);
     target->receive_wound("sen",(int)me->query_skill("evilsword",1)/12);
     COMBAT_D->report_status(target, 0);
     me->add("force",-100);
}
     else
{
     message_vision(GRN "����$nʹ�˸������ţ��պö�����������Ĺ�����\n" NOR,me,target);
     me->add("force",-100);
}
}
     if((int)me->query_skill("evilfight",1) > 240 && target->is_living())
{
     message_vision(GRN "$n����������������֣����㻹��ʲô�У������꣬����������������\n$N��������֮��������Щ͸֧���ƺ�ֻ�ܰ����ˣ�\n" NOR,me,target);
     message_vision(RED "����$Nƴ��ȫ����������������������ܷ��������\n" NOR,me,target);
     time +=1;
     if(target->is_busy() || random(myto) > random(myto+yourto))
{
     message_vision(GRN "���$n�������һ�գ������������������������ƺ���û���ܵ����ص��˺���\n" NOR,me,target);
     target->start_busy(4);
     time=0;
}
     else
{
     message_vision(GRN "����$n����ض������һ����û���ܵ��κ��˺���\n" NOR,me,target);
}
     tell_object (me, "һ����Ѫ�����а�������˳���������һ�أ�\n");
     me->receive_wound("kee",(int)me->query_skill("evileye",1));
     me->receive_wound("sen",(int)me->query_skill("evileye",1));
     COMBAT_D->report_status(me, 0);

}
     message_vision(HIG "$Nֹͣ�˹�������ʼ�����ظ�������\n" NOR,me,target);
     if(time > 7) time=7;
     me->start_busy(time);
     if((int)target->query("kee") > 0)
     tell_object (target, "�û��ᣬ�����ڸϿ췢��������\n");     
     me->set_temp("firehit_busy",1);
     call_out("remove_effect",120+random(5),me);

     return 1;
}

void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("firehit_busy");
  message_vision(HIW "$N���������ָ��ˣ����ֿ�ʼ�ų�ǿ���������\n" NOR,me);
}
