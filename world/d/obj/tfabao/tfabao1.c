// �����硤���μǡ��汾���������ͣ�
/* <SecCrypt CPL V3R05> */
// by night
//�������ⷨ�������ļ�
#include <ansi.h>
#include <weapon.h>

inherit ITEM;

int ji();
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
object offensive_target(object me);
/************************************************************/

void create()
{
    set_name(YEL "�����෨��" NOR,({"fabao object", "fabao", "object"}));
    set_weight(10000);
    if(clonep())
        set_default_object(__FILE__);
    else {
        set("value", 1);
        set("no_get", 1);       
        set("no_give", 1);      
        set("no_sell", 1);      
        set("no_drop", 1);      
        set("no_put", 1);
        set("material","jade");

        set("long","һֻ�������ܵķ�����\n");
        }
    setup();
}

// This function selects a random target for offensive spells/functions.
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

int ji()
{
    object victim;
    int sp;
    object me=this_player();
    int mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name(), unit=this_object()->query("unit");

    string *ACTIONS=({HIW"�ͳ�һ"+unit+objname+HIW"����������𣬿��������дʣ�\n"NOR,
                      HIY"��һ�ӣ�ϼ��������һ"+unit+objname+HIY"�ɵ���գ��������裬\n"NOR,
                      HIR"��һ"+unit+objname+HIR"�̿���"+objname+HIR"һ����ת��һ��Խ��Խ��\n"NOR,
                      HIC"һ�����ڣ���Ȼ���һ����һ"+unit+objname+HIC"�ӿ������콵�£�\n"NOR,
                      HIB"˫��һ�ϣ�ֻ��Ũ�ص�����ƽ��ӿ�������ţ�һ"+unit+objname+HIB"��Ȼ���������\n"NOR,
                      });
    string *RESULTS=({HIW"ֻ��һ��������𣬽�$N���ڵ��С�\n"NOR,
                      HIY"ֻ��һ������������$N���������嶼�����������ˡ�\n"NOR,
                      HIR"ֻ��һ�������䣬$N�����ʧ��"+objname+HIR"�С�\n"NOR,
                      HIC"ֻ��һ�����������$N�����忪ʼ���ٵ���ת��������������ա�\n"NOR,
                      HIB"ֻ��һƬˮ��������$N����Ӱ���������𽥵�ȥ��\n"NOR,
                      });    
    if( me->is_busy())
        return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

    if( (int)me->query("mana") < 100)
        return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 50)
        return notify_fail("��ľ����޷����У�\n");
    if((!environment(me)->query("valid_startroom")
    || !environment(me)->query("sleep_room")
    || !environment(me)->query("no_fight"))
    && (int)me->query("sen") * 100 / (int)me->query("max_sen") > 50 
    && (int)me->query("kee") * 100 / (int)me->query("max_kee") > 50)
        return notify_fail("�������������棬������㣬ֻ���ڰ�ȫ��ʹ��"+objname+NOR+"��\n");
    
    sp = random(5); 
    victim = offensive_target(me);
    msg = ACTIONS[sp];
    msg += RESULTS[sp];
    if(!victim)
    {
      if(!me->is_fighting())
      {	
      switch( sp )   {
	case 0:
       	message_vision(HIW"$N"+msg,me);
       	break;
       	case 1:
       	message_vision(HIY"$N"+msg,me);
	break;
	case 2:
       	message_vision(HIR"$N"+msg,me);
       	break;
	case 3:
       	message_vision(HIC"$N"+msg,me);
       	break;
	case 4:
       	message_vision(HIB"$N"+msg,me);
       	break;
	}
      me->add("mana",-100);
      me->add("sen",-50);
      me->move("/d/city/kezhan");
      message_vision(YEL"$N��Ȼ�����ڴ����ǰ��\n"NOR,me);
      return 1;
      }
    }

    switch( sp )   {
	case 0:
       	message_vision(HIW"��ս�У�$N��Ȼ����սȦ��"+msg,me);
       	break;
       	case 1:
       	message_vision(HIY"��ս�У�$N��Ȼ����սȦ��"+msg,me);
	break;
	case 2:
       	message_vision(HIR"��ս�У�$N��Ȼ����սȦ��"+msg,me);
       	break;
	case 3:
       	message_vision(HIC"��ս�У�$N��Ȼ����սȦ��"+msg,me);
       	break;
	case 4:
       	message_vision(HIB"��ս�У�$N��Ȼ����սȦ��"+msg,me);
       	break;
       	}
    // if condition is 1, then ji is successful.
    // if condition is 0, then ji is unsuccessful but nothing bad happens.
    
    condition=determine_success(me, victim);

    switch(condition)
    {
      case 1:
        message_vision(HIR"$n��ǰһ����$N�Ѿ������ˡ�\n"NOR,me,victim);
        me->move("/d/city/kezhan");
    	message_vision(YEL"$N��Ȼ�����ڴ����ǰ��\n"NOR,me);        
        break;
      case -1:
        message_vision(HIB"��$n���һ����������������һָ��$N�����������Ρ�\n"NOR,me,victim);
    	break;
    }
    me->add("mana", -determine_cost("mana", 100));
    me->add("sen", -determine_cost("sen", 40));
    return 1;
}

/************************************************************/
int determine_success(object me, object victim)
{
    int myspells, myexp, victimspells, victimexp;
    int ap, dp, attackfactor, condition;

    myspells=me->query_skill("spells")/10;
    myexp=me->query("combat_exp")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimexp=victim->query("combat_exp")/1000;

    ap=(myexp+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;

    attackfactor=random(ap+dp);

    if (attackfactor>dp/4) condition=1;
    else condition=-1;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    // nothing complicated here i think.

    cost=me->query(variable)/5;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}
/************************************************************/
