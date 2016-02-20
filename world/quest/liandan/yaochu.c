//yaochu.c ҩ��
//����II���������䣩
//����lywin 2000/6/15

#include <ansi.h>
inherit ITEM;

string *she1=({"/quest/npc/dushe","/quest/npc/jinshe","/quest/npc/qingshe"});
string *she2=({"/quest/npc/fushe"});
string *yao1=({"/quest/liandan/yaocao1","quest/liandan/yaocao2"});

void init()
{
	add_action("do_wayao", "wayao");
}

void create()
{
	set_name("ҩ��", ({"yao chu", "chu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("long", "����һ����ҩ�����������������ҩ��wayao����\n");
		set("value", 0);
	}
	setup();
}

int do_wayao()
{
        object me=this_player();

        if ((me->query("sen") < 20))
        {  
          tell_object(me,"��ľ������ܼ��У���������ҩ��\n");
          return 1;
        }
        else
        if ((me->query("kee") < 30 ))
        {
          tell_object(me,"�������״̬̫�������ҩ��\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("wayao1") >= 1)
        {
        message_vision(HIC"$N�Ӷ�ҩ����ʼ�ڵ�������������\n"NOR,me);
        me->add("sen",-10);
        me->add("kee",-20);
        me->start_busy(3);   
       	call_out("wayao1",3,me);
       	me->stop_busy();
       	return 1;
      	}
      	else
	if (environment(me)->query_temp("wayao2") >= 1)
        {
        message_vision(HIC"$N�Ӷ�ҩ����ʼ�ڵ�������������\n"NOR,me);
        me->add("sen",-20);
        me->add("kee",-30);
        me->start_busy(4);   
       	call_out("wayao2",4,me);
       	me->stop_busy();
       	return 1;
      	}
        return notify_fail("�����ҩ�����ѱ����ڹ��ˡ�\n");
}

int wayao1(object me)
{
      object ob;
      object ob1;        

      if(random(7)<2) 
      {         
        tell_room(environment(me),HIY"�ݴ���һ��ζ���ͻȻ���һ���ߡ�\n"NOR );
        ob=new(she1[random(3)]);
        ob->move(environment(me));
      }
      else
      if (random(7)<3)
      {
          message_vision(CYN"һ�������󣬲ݴ����ƺ�û��$NҪ�ҵĶ�����$Nʧ����̾�˿�����\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N���˰��죬���ڷ�������һ������������Ĳ����в�ͬ��С������ؾ��˳�����\n"NOR,me); 
        message_vision(HIG"ҩ�ݵ����ڵ��ˣ���ϧҩ��ȴ��С�����ˡ�\n"NOR,me); 
        ob1 = new( __DIR__ "yaocao1");
        ob1->move(me);
        environment(me)->add_temp("wayao1",-1);
        destruct(this_object());
      }
      return 1;
}

int wayao2(object me)
{
      object ob;
      object ob1;        

      if(random(7)<2) 
      {         
        tell_room(environment(me),HIY"�ݴ���һ��ζ���ͻȻ���һ���ߡ�\n"NOR );
        ob=new(she2[random(1)]);
        ob->move(environment(me));
      }
      else
      if (random(7)<3)
      {
          message_vision(CYN"һ�������󣬲ݴ����ƺ�û��$NҪ�ҵĶ�����$Nʧ����̾�˿�����\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N���˰��죬���ڷ�������һ������������Ĳ����в�ͬ��С������ؾ��˳�����\n"NOR,me); 
        message_vision(HIG"ҩ�ݵ����ڵ��ˣ���ϧҩ��ȴ��С�����ˡ�\n"NOR,me); 
        ob1 = new(yao1[random(2)]);
        ob1->move(me);
        environment(me)->add_temp("wayao2",-1);
        destruct(this_object());
      }
      return 1;
}
