#include <ansi.h> 

inherit SSERVER;

int perform(object me, object target)
{
object weapon;
int dqi,ap,dp,dd1,dd2,dd3,dd4,dd5,dd6;
int dforce,dmana,dsen,damage,aa,a,dam;
      string str;
if( !target ) target = offensive_target(me);

if( !target
|| !target->is_character()
|| target->is_corpse() || target==me)
return notify_fail("��Ҫ��˭ʩչ��һ��"HIR"��"HIC"����Ѱ��"HIR"��"NOR"��\n"); 

if(!me->is_fighting())
return notify_fail("������Ѱ����ֻ����ս����ʹ�ã�\n");
                if(me->query("family/family_name")!="��˿��")
return notify_fail("��������벻���Σ�\n");

if(environment(target)!= environment(me))
return notify_fail("�㹥�����˲������\n");
 if((int)me->query("force") < 600 )
return notify_fail("�������������\n");
if((int)me->query("mana") < 1000 )
return notify_fail("��ķ���������\n");
if((int)me->query("kee") < 600 )
return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
if((int)me->query("sen") < 600 )
return notify_fail("��ľ��񲻼ѣ�û����ʩ���⹦��\n");
if((int)me->query_skill("pansi-dafa", 1) < 150)
return notify_fail("�����˿�󷨼��𻹲�����ʹ����һ�л������ѣ�\n");
if((int)me->query_skill("lanhua-shou", 1) < 60)
return notify_fail("��������ּ��𻹲�����ʹ����һ�л������ѣ�\n");
if((int)me->query_skill("chixin-jian", 1) < 60)
return notify_fail("��ĳ����鳤�����𻹲�����ʹ����һ�л������ѣ�\n");
if((int)me->query_skill("yueying-wubu", 1) < 80)
return notify_fail("�����Ӱ�貽���𻹲�����ʹ����һ�л������ѣ�\n");
if((int)me->query_skill("qingxia-jian", 1) < 150)
return notify_fail("�����ϼ�����𻹲�����ʹ����һ�л������ѣ�\n");
if((int)me->query_skill("jiuyin-xinjing", 1) < 130)
return notify_fail("��ľ����ľ����𻹲�����ʹ����һ�л������ѣ�\n");
a=random(5)+1;
weapon=me->query_temp("weapon");
me->delete("env/brief_message");
message_vision(BLU"\n$N˼���������ˣ����������ҵľ��磬�������������硣\n"NOR+
WHT"$N�������У�����ȴ˿��δ��������һ��������ա���\n "NOR, me);

dd1=me->query_skill("chixin-jian", 1);
dd2=me->query_skill("jiuyin-xinjing", 1);
dd3=me->query_skill("qingxia-jian", 1);
dd4=me->query_skill("lanhua-shou", 1);
dd5=me->query_skill("yueying-wubu", 1);
dd6=me->query_skill("pansi-dafa", 1);
ap = me->query("combat_exp");
dp = target->query("combat_exp");
dqi= me->query("kee");
dsen= me->query("sen");
dmana= me->query("mana");
a=7;
// a=random(a)+1;
// aa=0;
if(random(ap+dp) > dp )
{
if ( dd1 > 5 ) {
message_vision(HIG"\n���еı��������ķ���ҫ�۵�����\n"+
HIC"�������ֶ���������������ˮ��ȴ����ɱ����ǧ��\n"NOR,target,me);
(int)damage=random(dd1*4)+random(dd6/2*8)+random(me->query("kee")/20);
if(damage<1) damage=dd2+random(dd2);
//target->receive_damage("sen", damage, me);
//COMBAT_D->report_sen_status(target);
target->receive_wound("kee", damage, me);
COMBAT_D->report_status(target);
} a = a +1;}else { aa = 5;} if ( a > 6 ) {
message_vision(HIM"\n$N���봭Ϣһ�£�������ǰ����һ��\n"+
HIR"$Nֻ����һ���ʹ���ؿ��ٴ��н���\n"NOR,target,me);
(int)damage=random(dd3*4)+random(dd6/2*8)+random(me->query("kee")/20);
if(damage<1) damage=dd2+random(dd2);
     me->add("force",-400);
     me->add("mana",-400);
//target->receive_damage("sen", damage, me);
//COMBAT_D->report_sen_status(target);
target->receive_wound("kee", damage, me);
COMBAT_D->report_status(target);
    if (target->query("kee")<0 || (!living(target) && target->query("kee")<0))
{str=target->name()+"��"+me->name()+"����˿ɱ����"HIC"������Ѱ����"NOR+HIM"�̴����࣬һ���غ��ˣ�";
 message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
                       }
                }
                me->start_busy(1+random(2));
        return 1;
}
