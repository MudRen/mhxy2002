// by qingchun(�����) 6/30/2001
// pidai.c ����Ƥ��

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(YEL "����ţƤ��" NOR, ({"pidai", "pi", "dai"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ������������������Ƥ���������������Ƶ�ԭ�������ģ����ԣ�eat
����һ�ԡ�\n");
    set("drug_type", "��Ʒ");
    set("value",0);
  }

  setup();
}

void init()
{
  if (!wizardp(this_player()))
 {
    set("no_get","�ٺ٣���Ҫ���������� \n");
    set("no_give","���ڲ��ǳ���ʱ�ڣ���Ҫ���������ˣ� \n");
    set("no_drop","��ô����ļ���Ʒ�����˶Բ�ס������ \n");
    set("no_sell","�����Լ����Űɡ�\n");
  }            
  add_action("do_eat", "eat");}


int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
if (me->query("changzheng_liwu")) return notify_fail("���Ѿ�������˳���������.\n");


  me->set("food", (int)me->max_food_capacity());
  switch (random(3))
  {
    case 0:
    {
      message_vision(HIG "$N������üͷ��������������Ƥ������������ǧ����࣡
                          $N�õ���10000��Ǳ�ܣ�10000��ѧ����ϲ�ˣ�\n" NOR, me);
      me->add("potential", 10000);
      me->add("combat_exp", 10000);
      break;
    }
    case 1:
    {
      message_vision(HIW "$N������ԥ�ĳ���������Ƥ������ʾ��һ�ִ���η�ľ���
                           $N�õ���5000��Ǳ�ܣ�10����У���ϲ�ˣ� \n" NOR, me);
      me->add("potential", 5000);
      me->add("daoxing", 10000);
      break;
    }
    case 2:
    {
      message_vision(RED "$N�����Ľ�����Ƥ�����꣬���г����˶Ժ��սʿ�ľ��أ�
                           $N�õ���5000����ѧ��10����У���ϲ�ˣ�\n" NOR, me);
     me->add("combat_exp", 5000);
      me->add("daoxing", 10000);

      
      break;
    }
  }
  me->set("changzheng_liwu",1);
  destruct(this_object());
  return 1;
}

