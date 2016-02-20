#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ARMOR;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIY ""BLINK"���ǽ����" NOR, ({"swagger armor" ,"armor", "yi"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("value",90000);
                set("no_sell", "��������˭��������޼�֮����\n");
                set("no_get", "��С�������ǵı��������ĳ�����\n");
                set("long","���ǹ�����ˮ���ͽ��˿��ʱ������ҹ֯�ɵ�һ�����ף���������������ˡ�\n");
               set("armor_prop/armor", 20000);
                set("armor_prop/dodge", 100);
                set("armor_prop/personality", 15);

                set("spells/fire", 100);
                set("spells/thunder",100);
                set("spells/water",100);
                set("spells/wind",100);
                set("spells/earth",100);
        }
        setup();
}

int init()
{
        object who = this_player();
        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 100000 )
        this_object()->move("/obj/empty"); 
         }
        add_action("do_wear","wear");
        add_action("do_remove", "remove");

}

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "swagger armor" )
    return notify_fail("��Ҫʲô��\n");
  msg = HIW"$N����һ�����������"+name+""HIW"����ʱ��ɳ��ʯ��ɽ�����ѣ���Χ�����޲���ɫ��\n"NOR; 
  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "swagger armor")
    return notify_fail("��Ҫ�ѵ�ʲô��\n");

  msg = HIW"$N��"+name+""HIW"�����������������Χ���˶����˿�����һ�ж��ָ���ƽ������\n"NOR; 
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIW"$N�૵����˼������ͻȻ˫��һ�٣������ĺ��������ϵ����񰡣����������Թ��ǵ����������������ҳ��У���\n
"HIY"ֻ������һ�����������������ɽ�������Ϻ��������������㣡��ɽ��ʥ���������ᣡѩɽ������......\n
"HIY"                          �ݿ����󣡻��Ʒɻ������ܵزأ��¹��϶���ׯ��Ԫ�������׷���......\n"NOR;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp/2 )
                 {
                        damage = 600+random(1000);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "����һ��ʩ�����£����$n"HIC"��ܲ�����������������һ��̧�Ÿ�������ħ�����˸����ţ��ֱ���Ԫ����ζ����յ�Ƥ������......\n
��ѩɽ�����ĳ��Ǿ����ȥ������������ĵ�ĸ���Ƥ��Ѫ����������ʥ���򽣴���͸�������ֱ������������������......\n"NOR; 
msg +=GRN "(  $n"RED"�Ѿ���������״̬����ʱ������ˤ����ȥ��"GRN"  )\n"NOR;
msg +=GRN "(  $n"RED"�����Ѿ���ȫ��ʧ����ʱ���п��ܱ�����ȥ��"GRN"  )\n"NOR;

                                target->receive_damage("sen", damage*8/5);
                                target->receive_wound("sen", damage*2/3);
                                target->receive_damage("kee", damage*8/5);
                                target->receive_wound("kee", damage/2);
                                target->start_busy(10);
                        } 
            else
                msg += HIC "\n$nһ����¿������Ǳ������Ķ��˹�ȥ��\n" NOR;   
                }
                else
                        msg += HIC "\n$nһ����¿������Ǳ������Ķ��˹�ȥ��\n" NOR;  

                message_vision(msg, who, target); 
        }
call_out("shengzhuconditions",7,who,ob);
}

