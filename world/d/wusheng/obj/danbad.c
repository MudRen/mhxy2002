//by tianlin@mhxy 2001.7.4

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "[1;30mһ�Ż��˵�������[2;37;0m" , ({"wuming guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ų�ù��������������ȫ����ë��\n");
    set("value", 0);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="wuming guo" && arg!="guo") 
    return 0;
  
  tell_object(me, "��ҩ���ܳ���\n");
  return 1;
}

