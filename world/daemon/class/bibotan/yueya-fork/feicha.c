
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void feijian_ok(object);
void postfeijian(object,object,object,int);

int perform(object me, object target)
{
    mapping feijian= ([
       "damage": 100,
       "dodge" : -10,
       "parry" : -10,
       "damage_type" : "����",
       "action" :  HIY"\n$w"+HIY"�ڿ���һ�������߰���$n��$l��ȥ\n",
       "post_action" : (: postfeijian :)
    ]);

      object weapon=me->query_temp("weapon");
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if (!target->is_fighting(me))
             return notify_fail("����û���ڴ�ܣ�\n");
      if (me->query_temp("no_feijian") )
          return notify_fail("������״̬���ѣ�����ʹ�÷ɲ档\n");      
      if (me->query_skill("zhuanlong-force",1)<100)
          return notify_fail("����ڹ�̫���ɳ�ȥ�϶��ɲ�������\n");
      if (me->query_skill("yueya-fork",1)<100) 
          return notify_fail("��Ĳ淨��ô�ã����İѲ��Լ����ϡ�\n");
      if (me->query("force")<100)
           return notify_fail("���������̣����Լ����ɲ档\n");
     
      me->add("force", -100);
      me->set("actions",feijian);
    message_vision(HIC"\n$NͻȻ��Хһ��������"+weapon->query("name")+HIW"���ֶ�����ֱ��$n��ȥ��\n"NOR,me,target);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      me->set_temp("no_feijian",1);
      call_out("feijian_ok",2+random(2),me);
      me->reset_action();
      return 1;
}

void feijian_ok(object me) {
      if (!me) return;
      me->delete_temp("no_feijian");
}         

void postfeijian(object me,object victim,object weapon, int damage) {
      if (damage>0 || damage==RESULT_DODGE)
         message_vision(HIC"$N�þ�һ����"+weapon->query("name")+HIW"�ڿ��д��˸�ת���ֻص����С�\n"NOR,me);
}
