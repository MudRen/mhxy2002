#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
 set_name(HIW "Ǳ�ܵ�" NOR, ({"qianneng dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
   set("long", "��������Ǳ�������浤ҩ��\n");
    set("no_sell", 1);
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
    
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

    message_vision(HIW"$N����һ��Ǳ�ܵ�����ʱ����������Ѫ���ڡ�\n"NOR, me);  
  
 me->add("potential", me->query("potential")/100+1000);

  destruct(this_object());
  return 1;
}
