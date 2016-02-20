// by mhsj@gslxz 2001/3/12
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long=HIC"һ�ѵ���ɫ��ϸ����������͸�������洦���ŵ�㺮�⣬\n�������ƺ��и�������װ"+HIR" (install)"+HIC" Щ������ȥ��\n"NOR;

void create()
{
        set_name(HIM"ѩ�·ɻ�"+HIY"�����"NOR, ({"fenghuang sword", "sword"}));
	set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "��");
   set("value", 200000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��Цһ�����ӱ���γ���$n��\n");
                set("unwield_msg", "$N�����е�$n������У���Ƕ���һ˿Ц�⡣\n");
                set("anqi/allow", 1);
                set("anqi/max", 60);
                set("anqi/now", 0);
        }
        init_sword(80);
        setup();
}

void init()
{                                             
        add_action("do_install", "install");
        add_action("do_uninstall", "uninstall");
}


int do_install(string arg)
  {
   object me=this_object();
   object who=this_player();
   object aq;
   int remain;

   if( !arg)  return notify_fail("����װʲô��\n");

   aq=present(arg, who);
   if (! present(arg, who)) 
        return notify_fail("������û���ⶫ����\n");
   else if( aq->query("name") == me->query("name") ) return notify_fail("װ�Լ���\n");
   else if (aq->query("name") != "����" && aq->query("name") != "������") 
        return notify_fail("������̫���ˣ�װ����ȥ��\n");
   else if (me->query("anqi/now") == me->query("anqi/max"))
        return notify_fail(me->query("name")+"�Ѿ�װ�������ˡ�\n");
   else if (me->query("anqi/now") >0 && 
            me->query("anqi/type") != aq->query("name") )
        return notify_fail(me->query("name")+"����װ��ͬ�İ�����\n");
   else  
     {
     message_vision( "$N��"+me->query("name")+"�Ļ��أ���һ"+aq->query("unit")+aq->query("name")+"װ�˽�ȥ��\n",who);
     who->start_busy(1);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));
     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
         {
         remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
         me->set("anqi/now",me->query("anqi/max"));
         me->set("long",me->query("orilong")+"�����Ѿ�װ��" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"��������uninstall��\n");
         aq->set_amount(remain);
         }
     else 
         {
         me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
         me->set("long",me->query("orilong")+"�����Ѿ�װ��"
           +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"��������uninstall��\n");
         destruct(aq);
         }
     return 1;
     }
  }

int do_uninstall(string arg)
  {
   object ob,where;
   object me=this_object();
   object who=this_player();
	where = environment(who);

   if (who->is_busy() || who->query_temp("doing_xiudao"))
		return notify_fail("��������æ���ء�\n");

   if(where->query("no_kill"))
	     return notify_fail("�����ֹ�氵����\n");

   if(where->query("no_bian"))
	     return notify_fail("�����ֹ�氵����\n");

  if( who->is_fighting() )
		return notify_fail("ս���н�ֹ���룡����\n");

   if( !this_object()->id(arg) ) return notify_fail("�����ʲô��\n");
   else if (me->query("anqi/now") ==0) return notify_fail(me->query("name")+"����ʲôҲû�С�\n");
   else 
     {
      if (me->query("anqi/type") =="����") ob=new("/d/obj/weapon/throwing/yinzhen");
      else if (me->query("anqi/type") =="������") ob=new("/d/obj/weapon/throwing/handuzhen");
      else ob=new("/d/obj/weapon/throwing/kongqueling");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long",ori_long);
      me->set("anqi/now", 0);
      message_vision("$N��"+me->query("name")+"������һ"+ob->query("unit")+ob->query("name")+"��\n", who);
      who->start_busy(2);
      return 1;               
     }
  }

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
	victim->receive_wound("sen",10);
	return HIM"ѩ�·ɻ�"+HIB"�����"+HIY"�����ĺ�Х���ŵ�"+NOR"$n"+HIR"��������\n" NOR;
	}
}
