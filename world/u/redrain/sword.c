#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

inherit SWORD;

int do_wield(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIC "�����ƻʽ�" NOR, ({"wolf sword" ,"jian", "sword"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("value",90000);
                set("no_sell", "��������˭��������޼�֮����\n");
                set("no_get", "��С�������ǵı��������ĳ�����\n");
                set("long","���ǹ�����һ������ʱżȻ�õ���һ�ѱ�����������ϡ����Ӱ������\n");
                set("spells/fire", 100);
                set("spells/thunder",100);
                set("spells/water",100);
                set("spells/wind",100);
                set("spells/earth",100);
        }
        init_sword(5000);
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
        add_action("do_wield","wield");
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

int do_wield (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "wolf sword" )
    return notify_fail("��Ҫ��ʲô��\n");
  msg = HIY"$N��������һ��������һ����Х�������Ѷ��һ��"HIW"�����ƻʽ�"HIY"��\n"NOR; 
  zhu->set("wield_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
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
        msg = "\n"HIW"�����ƻʽ�"HIY"ϼ��"HIB"����"HIC"��"CYN"��Ӱ"HIM"Ⱥ��"HIC"......\n"NOR;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp/2 )
                 {
                        damage = 600+random(1000);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIW "\n��"HIY"��"HIR"��"HIC"��"HIW"......\n"NOR; 
msg += "\n( $n"HIR"��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ"NOR" )\n"NOR;
                                target->receive_damage("kee", damage/2);
                                target->receive_wound("kee", damage/5);
                                target->start_busy(2+random(2));
                        } 
            else
                msg += HIC "\n$n��Ϊ֮������\n" NOR;   
                }
                else
                        msg += HIC "\n$n��Ϊ֮������\n" NOR;  

                message_vision(msg, who, target); 
        }
call_out("shengzhuconditions",7,who,ob);
}

