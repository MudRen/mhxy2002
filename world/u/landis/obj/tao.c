// mihoutao.c �ش��⨺���
//by tianlin 2001.5.1����ҳ�����10��force��mana�Ҿ�������ͦ�õ�,��ǰ���Ǹ��ҳ��˲�һ��,ûʲô����.(xixi)
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIY"����"+NOR+YEL"⨺���"NOR, ({"mihou tao","mihoutao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "[1;33m�Ƴȳȵ�һ��⨺��ң�����˴������Ρ�[2;37;0m\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(100);
  me->add_maximum_mana(100);
  message_vision(HIG "$Nһ�ھͳ���������ֺ��ң���һ�������������ȷ�Ǻóԣ� \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
