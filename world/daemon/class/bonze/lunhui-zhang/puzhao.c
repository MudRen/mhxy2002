//������� by yushu 2001.2
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object *inv, obj;
        object weapon;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������ա���\n");


        if(!me->is_fighting())
                return notify_fail("��������ա�ֻ����ս����ʹ�ã�\n");

        if((string)me->query("family/family_name") != "�Ϻ�����ɽ" )
                return notify_fail("�㻹û���Ĵ�Կա������������ܷ�����գ�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

       if((int)me->query_skill("lunhui-zhang", 1) < 150)
                return notify_fail("����ֻ��ȼ��𻹲�����ʹ����һ�л������ѣ�\n");

message_vision(HIY"\n$N���������վ�����\n"NOR,me,target);
message_vision(HIY"\n������ȼ������������������ģ��ռ�һ�С�\n"NOR,me,target);
message_vision(HIY"\nԸ���������������࣬�����������Ͼ����֡�\n"NOR,me,target);
message_vision(HIW"\n�߾����е�"+weapon->query("name")+HIW"����$n��\n"NOR,me,target);
         me->start_busy(2);
         mystr=(int)me->query("str");
         tastr=(int)target->query("str");
         myexp=(int)me->query("combat_exp")/20;
         taexp=(int)target->query("combat_exp")/30;
         mylvl=(int)me->query_skill("staff")*(int)me->query_skill("lunhui-zhang");
         talvl=(int)target->query_skill("parry")*(int)target->query_skill("dodge");
         mypot=mystr*mylvl+myexp;
         tapot=tastr*talvl+taexp;
         y=random(3);
         if( random(mypot) >random(tapot)) {
          message_vision(HIR"$N������������������ţ�\n"NOR, target);
          target->receive_damage("kee", 60 + random((int)me->query("max_force")/40+(int)me->query("force_factor")));
          target->receive_damage("sen", 60 + random((int)me->query("max_mana")/40+(int)me->query("mana_factor")));
          COMBAT_D->report_status(target);
          COMBAT_D->report_sen_status(target);
          if (y=1) {
                if (target->query_temp("weapon")) {
                obj=target->query_temp("weapon");
                obj->unequip();
                obj->set("value", 0);
                message_vision(HIW "ֻ������ž����һ����$N���е�" + obj->name()+HIW"�ѱ�һ�л��ķ��飡\n" NOR, target);
                obj->set("name", "���ѵ�" + obj->query("name"));
                obj->set("weapon_prop", 0);
                obj->set("armor_prop", 0);
                obj->move(environment(target));
                call_out("remove_broken_cloth",random(300)+60,obj);}
                }
     return 1+random(5);
     }
     else {
     message_vision(HIC"ȴ��$N�㿪�ˣ�\n"NOR, target);
     me->add("force", -200);
     me->receive_damage("sen", 100);
     target->kill_ob(me);
     me->start_busy(2+random(2));
     return 1+random(5);
}
}

void remove_broken_cloth(object obj)
{
  if(obj && environment(obj)) {
    tell_object(environment(obj),
      "һ��΢�紵����"+obj->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(obj);
  }
}
