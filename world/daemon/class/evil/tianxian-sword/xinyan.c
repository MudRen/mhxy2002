//modify by ken 2001-7-12
inherit SSERVER;
#include <ansi.h>
int perform(object me)
{
   int howlong;
   
   if((int)me->query_skill("tianxian-sword") < 120)
     return notify_fail("��Ľ�����û����,�ã����ۣ����˲����ϵ���\n");

   if( (int)me->query("force") < 2*(int)me->query_skill("force"))
     return notify_fail("������������������ۣ�\n");
   if (me->query("family/family_name")!="ħ��")
        return notify_fail("����û�õ���ħ���״����������ã�\n");
   if( (int)me->query("kee") < 50 )
     return notify_fail("�����Ѫ���㣡\n");
   if (me->query_temp("stop_perform")) return notify_fail("���Ѿ����������ˣ�\n");
   if( random(me->query("max_force")) < 200 ) {
     me->add("force",-(int)me->query_skill("sword"));
     me->receive_damage("kee",10);
     message("vision", "����ʲôҲû������\n", environment(me));
     return 5+random(5);
   }
   me->add("force", -2*(int)me->query_skill("sword"));
   me->receive_damage("kee", 20);
   howlong = 15 + random((me->query_skill("sword") -100));
   if (!me->query_temp("no_perform"))
     call_out("free", howlong, me, howlong);
   me->set_temp("xinyantime", howlong+(int)me->query_temp("xinyantime"));
   me->add_temp("stop_perform",1);
   message_vision(HIY"\n$N�������ۣ����˵�һ��һ��ȫ���Ӳ���$N���۾���\n\n"NOR, me);   
   return 5+random(5);
}
void free(object user, int howlong)
{
        if(!user) return;
   if (!user->query_temp("no_perform")) return;
   if (user->query_temp("xinyantime") - howlong) {
     user->set_temp("xinyantime", 
        user->query_temp("xinyantime") - howlong);
     call_out("free", user->query_temp("xinyantime"), 
        user, user->query_temp("xinyantime"));
     return;
     }
   user->delete_temp("xinyantime");
   user->delete_temp("stop_perform");      
   user->save();   
   message_vision(HIY"\n$N�������̣����ò����������ۡ�\n\n"NOR, user);
   return;
}
