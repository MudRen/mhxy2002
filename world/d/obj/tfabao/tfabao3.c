// �����硤���μǡ��汾���������ͣ�
/* <SecCrypt CPL V3R05> */
// by night
//�������ⷨ�������ļ�
#include <ansi.h>
#include <weapon.h>

inherit ITEM;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);

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
	set("long","һֻ�������˵ķ�����\n");
	}
    setup();
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar()/2, dingtime, condition;
    string msg, fabaoname=this_object()->name();

    if (this_object()->query("in_use"))
   	return notify_fail("����������ʹ��"+fabaoname+"��\n");
    
    if (!target)
	return notify_fail("�����ö�˭��"+fabaoname+"��\n");

    if (!objectp(victim=present(target, environment(me))))
	return notify_fail("����û�� "+target+"��\n");

    if (me->is_busy())
    {
    	tell_object (me, "���޷�æ��͵�м�"+fabaoname+"��\n");
        return notify_fail("����æ���ء�\n");
    }
  
    if(!living(victim))
	return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!me->is_fighting(victim))
	return notify_fail("ֻ��ս���в��ܼ�"+fabaoname+"��\n");  
    if(victim->query("no_move"))
   	return notify_fail("�Է��Ѿ���Ͼ�Թ��ˣ��б�Ҫ��"+fabaoname+"ô��\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("��ľ����޷����У�\n");

    msg=HIC"$N�ӱ�����һ"+this_object()->query("unit")+fabaoname+HIC"��������𣬿��������дʣ�\n"NOR;
    if (this_object()->query("interactive_usage") > (me->query_kar()/3))
    {
    message_vision ("ֻ��"+fabaoname+"�����ϻ�ΪһƬ�������紵ɢ�ˡ�\n",me);
    destruct (this_object());
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
    }
    switch( random(3))   {
    case 0:	
    msg+=RED"���һ����"+fabaoname+RED"�зɳ�һ����������$n"RED"��ȥ��\n"NOR;
    break;
    case 1:
    msg+=CYN"ֻ��"+fabaoname+CYN"�ڿ���һ��ת�ۣ��·������԰㣬��$n"CYN"���ƶ�ȥ��\n"NOR;
    break;
    case 2:
    msg+=YEL"���ҫĿ��ֻ��"+fabaoname+YEL"��ΪһƬ���ƣ���$n"YEL"��ͷ���¡�\n"NOR;
    break;
    }
    
    // if condition is 1, then ji is successful.
    // if condition is 0, then ji is unsuccessful but nothing bad happens.
    // if condition is -1, then ji fails AND is bounced back.

    condition=determine_success(me, victim);
    switch(condition)
    {
    case 1:
    msg+=HIR"$n"HIR"�����θ�ס��һʱ����æ���ң���֪���롣\n" NOR;
    msg+=CYN"$n"CYN"��"+fabaoname+CYN"�ķ�����ס�ˣ�\n"NOR;
    victim->set_temp("no_move", 1);
    dingtime=random(mykar);
    if (dingtime < 1) dingtime=1; 
    if (wizardp(me) && me->query("env/combat")=="verbose")
       tell_object(me, GRN ""+victim->name()+"����ס��"+chinese_number(dingtime)+"�롣\n" NOR);
    this_object()->set("in_use", 1);
    call_out("remove_ding", dingtime, me, victim);
    break;
    case 0:
    msg+=HIB"$n"HIB"����һָ�����һ�����䣡��ֻ�����������"+fabaoname+HIB"�����$N"HIB"���С�\n"NOR;
    break;
    case -1:
    msg+=HIB"$n"HIB"����һָ�����һ�����أ�����ֻ��"+fabaoname+HIB"�ڿ���һ������������$N"HIB"��ס�ˣ�\n"NOR;
    dingtime=random(victim->query_kar()/2);
    if (dingtime<1) dingtime=1;
    me->set_temp("no_move",1);
    this_object()->set("in_use",1);
    call_out("remove_ding", dingtime, victim, me);
    break;
    case -2:
    msg+=HIB"$n"HIB"����һָ�����һ�����գ���ֻ��"+fabaoname+HIB"�ӿ�����������£�����$n"HIB"���С�\n"NOR;
    this_object()->move(victim);
    break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    this_object()->add("interactive_usage",1);    
    me->start_busy(random(3)+1);    
    return 1;
}        

void remove_ding(object me, object victim)
{
    string msg=CYN"ֻ��"+query("name")+CYN"�ڿն��𣬻ص���$N"CYN"���С�\n"NOR;
    this_object()->delete("in_use");
    
    if(!victim) return;

    if (living(victim))
    msg += CYN"$n"CYN"�ָֻ������ɡ�\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}

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

    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    cost=me->query(variable)/4;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

