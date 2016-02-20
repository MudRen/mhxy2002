// �����硤���μǡ��汾���������ͣ�
/* <SecCrypt CPL V3R05> */
// by night
//��ȡ���ⷨ�������ļ�
#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;

int ji (string target);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
 
void create()
{
  set_name("��ȡ�෨��",({"fabao object", "fabao", "object"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("value", 1);
    set("no_get", 1);	
    set("no_give", 1);	
    set("no_sell", 1);	
    set("no_drop", 1);	
    set("no_put", 1);
    set_max_encumbrance(50000);
    set("material","jade");
    set("long","һֻ�յ��˱������׵ķ�����\n");
  }
  setup();
} 

int ji_ob (object victim)
{
  object fabao = this_object ();
  object me = environment(fabao);
  string fabaoname = fabao->query("name");
  object ob;
  int mykar=me->query("kar"), victimkar;
  int condition;

  if (me->is_busy())
  {
    tell_object (me, "���޷�æ��͵�м�"+fabaoname+"��\n");
    return notify_fail("����æ���ء�\n");
  }

  if (sizeof(all_inventory(fabao))>0)
  {
    tell_object (me, fabaoname+"����������޷��ټ�"+fabaoname+"��\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  if (!victim)
  {
    tell_object (me, "��������˲������\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"�Ѿ����޵ֿ������ˡ�\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+fabaoname+"��\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  if ((int)me->query("mana") < 300)
  {
    tell_object (me, "��ķ������㣬������"+fabaoname+"��\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  ob = victim->query_temp("weapon"); 
  if(!ob)
  {
    tell_object (me, "�Է�û��ʹ��������\n");
    return notify_fail("���"+fabaoname+"ʧ�ܡ�\n");
  }

  message_vision ("\n$N��������"+fabaoname+"�����������дʡ�\n",me,victim);
  
  message_vision ("ɲ�Ǽ�"+fabaoname+"�ڿ���һ�Σ�����һ�ɰ���\n",me,victim);
  
  condition=determine_success(me, victim);

  switch(condition)
  {
      case 1:
             message_vision ("$n���е�"+ob->name()+"�ѳֲ�����\n",me,victim);
             message_vision ("˵ʱ����ʱ�죬"+ob->name()+"�ѱ�"+fabaoname+"��ȥ��\n",me,victim);
             ob->unequip();
             if (ob->query_weight()>fabao->query_max_encumbrance())
             {
             	message_vision (ob->name()+"��"+fabaoname+"�ﻯ��һ����ɢ�ˣ�\n",me,victim);
                destruct(ob);
             }
             else ob->move(fabao);
	     
	break;
      case -1:
             message_vision ("$nһ�����ƿ��˿��е�"+fabaoname+"��\n",me,victim);
  }
  me->add("mana", -determine_cost("mana", 250));
  me->add("sen", -determine_cost("sen", 50));
  me->start_busy(random(3)+1);
  victim->kill_ob(me);
  if (interactive(me))
    fabao->add("interactive_usage",1);
  return 1;
}

int ji (string target)
{
  object fabao = this_object ();
  object me = this_player();
  string fabaoname = fabao->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+fabaoname+"��\n");

  victim=present(target,environment(me));
  fabao->ji_ob(victim);
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

    if (attackfactor>dp/2) condition=1;
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
