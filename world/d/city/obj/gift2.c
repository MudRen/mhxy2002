//by yushu 2001.1
#include <ansi.h> 
inherit ITEM;    
inherit F_FOOD;
int do_eat(string arg); 
void create()
{
  set_name(YEL "����" NOR,({"zongzi"})); 
  set("long","������ʦ�͸���ҵĶ���ڵ����"); 
  set("unit","��"); 
  set("value", 0); 
  setup(); 
}
void init()
{
   if (!wizardp(this_player())) {
    set("no_get","��������ò�������\n"); 
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_sell","�ⶫ����������\n");
   }
    if(this_player()==environment())
      add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me=this_player();
  if (!arg && arg!="zongzi") return notify_fail("��Ҫ��ʲô?\n"); 
  if (me->query("duanwu01_liwu")) return notify_fail("���Ѿ��Թ������ˣ��Զ���Ҫ�����ӵġ�\n");
  message_vision("$N�������ڽ���������,$N�õ�"HIR+BLINK"һ����ѧ��һ��Ǳ�ܣ�һ���˲ι�"NOR"�Ľ�������"HIW+BLINK"save"NOR"��"HIW+BLINK"quit"NOR"�����߽��롣\n" NOR,me); 
  me->add("potential",10000);
  me->add("combat_exp",10000);
  me->add("rsg_eaten",1); 
  me->set("duanwu01_liwu",1);
  destruct(this_object());
  return 1; 

}
