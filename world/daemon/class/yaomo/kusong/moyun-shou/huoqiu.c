//by tianlin 2001.7.5�޸�
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
#include "/u/tianlin/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
      object ob, tar;
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail(""HIR"������"NOR"����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query("family/family_name") != "���ƶ�" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����򡹣�\n"); 

message_vision(HIR"\n$N������ȣ�������ʢ��������ͻȻ����һ�������"RED"����"HIR"���ڿ��й�µµ��Ѹ��ת����\n\n"NOR,me);
me->start_busy(1);
me->set_temp("pfm_chousui", 1);
if(random(me->query_kar()) > 15)
      check_pfm(me, target, ob);
else call_out("check_pfm", 6, me, target, ob);
       return 1;
}
int check_armor(object target)
{
object *inv;
int i, j;
inv = all_inventory(target);
j=0;
for(i=0; i<sizeof(inv); i++)
if( (string)inv[i]->query("equipped")=="worn" ) j++;
return j;
}

int check_pfm(object me, object target, object ob)
{
string msg, *limbs;
int i, force, ap, dp, damage, p;
object *inv;
if(!me) return 0;
i = (int)me->query_skill("moyun-shou", 1);
force = (int)me->query("force");
damage = (i+me->query("force_factor"))*2;
me->delete_temp("pfm_chousui");
me->start_busy(1);

        if(!living(me) || me->is_ghost()) return 1;
        if( me->query_skill("moyun-shou", 1) < 150 ){
                tell_object(me, "�㷢���Լ����ַ���������죬�޷�ʹ�á����򡹽��й�����\n");
                return 1;
                }
        if (me->query_skill_mapped("unarmed") != "moyun-shou"
                          ){
                tell_object(me,"�������Ħ���ֲ���ʹ�á����򡹽��й�����\n");
                return 1;
                }
        if( (int)me->query("max_force") < 1800) {
                tell_object(me,"�㷢���Լ�����ʵ��̫�����޷���������ǽ�����й�����\n");
                return 1;
                }
        if(me->query("force") < 1000){
                tell_object(me,"�㷢���Լ���������ʵ��̫�����ٲ��𡸻�ǽ�����й�����\n");       
                return 1;
                }
        if(!living(target) || !target || environment(me)->query("no_fight")
           ){
           message_vision(HIY"$N�����ٷ�����̧���"HIR"����"HIY"ѹ�ػ���֮�С�\n"NOR,me);
                return 1;
                }
        me->add("force", -1000);
ap = me->query("combat_exp")/1000 * i * me->query_str();
dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) /20* target->query_con();
if (ap < 1) ap = 1;
if (dp < 1) dp = 1;

message_vision(HIW"\n��ʱ$N�������ް��Ѫɫ��һ�ڿ���Ѫ��ס��"RED"����"WHT"����ȥ !!\n"NOR,me);
msg = HIR"\n����һʢ�������������죬��������𻨣�"HIW"����"HIR"��Ȼ�����$n���������\n"NOR;

if(ap > random(dp/5)){
inv = all_inventory(target);
               if(check_armor(target) >= 1){     
               if(me->query("force") > target->query("force")*2){ 
               if(me->query_str() > random(target->query_str())){
me->start_busy(3);
target->start_busy(2);
msg += HIY"���Ҽ�����¶�������𻨱��䣬ը����$p�Ļ��ߣ�\n" NOR;
for(i=0; i<sizeof(inv); i++)
if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
inv[i]->unequip();
inv[i]->move(environment(target));
inv[i]->set("name", "�����" + inv[i]->query("name"));
inv[i]->delete("value");
inv[i]->set("armor_prop", 0);
}
target->reset_action();
damage = damage * 3;
if (damage > 4000) damage = 4000;
damage = damage - target->query_temp("apply/armor");
target->receive_damage("kee", damage, me);   
target->receive_wound("kee", damage/4, me);  
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "����");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                             else {
me->start_busy(3);
target->start_busy(3);
msg += HIY"ֻ��������Ȼ���£����Ľ�������ֱ͸$p�Ļ��ߣ�\n" NOR;
for(i=0; i<sizeof(inv); i++)
if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
inv[i]->set("name", "���ѵ�" + inv[i]->query("name"));
inv[i]->set("value", 49);
if(inv[i]->query("armor_prop/armor"))
inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
}
target->reset_action();
damage = damage * 3;
if (damage > 3500) damage = 3500;
damage = damage - target->query_temp("apply/armor");
target->receive_damage("kee", damage, me); 
target->receive_wound("kee", damage/4, me);  
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "����");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                             }
                             else {
me->start_busy(3);
target->start_busy(3);
msg += HIY"�����ٹ���������Ľ��������������ײ��$p���\n" NOR;                  
damage = damage * 2;
if (damage > 2500) damage = 2500;
target->receive_damage("kee", damage, me);
target->receive_wound("kee", damage/6, me);   
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "����");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                           }
                             else {
//target has no armor, so, hehe...
damage = damage*2 + random(damage);
if (damage > 3000) damage = 3000;
if(force > target->query("force")*2) damage = damage*2;
target->receive_damage("kee", damage, me);   
target->receive_wound("kee", damage/2, me);  
p = (int)target->query("kee")*100/(int)target->query("max_kee");
msg += damage_msg(damage, "����");
msg += "( $n"+eff_status_msg(p)+" )\n";
me->start_busy(2);
target->start_busy(1);    
                             }
                           }
                             else {
me->start_busy(2);
msg += HIY"\n$p�ۿ���Ҫ�����У�ð��һ���������š���ȫ����ϥ�Ǵ����ȥ�������ܹ�$w"HIY"��\n" NOR;
                             }
message_vision(msg, me, target);
limbs = target->query("limbs");
msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
msg = replace_string(msg, "$w", RED"����"NOR);    
if(!target->is_killing(me->query("id"))) target->kill_ob(me);
        if (target->query_temp("weapon")) {
        msg = CYN "\n\n$N����$n��ʽ������������һ������ߡ�\n"NOR;
                message_vision(msg, me, target);
                target->query_temp("weapon")->move(environment(target));}
return 1;
}

