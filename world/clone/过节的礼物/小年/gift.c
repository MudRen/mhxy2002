#include <ansi.h>
inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "С������" NOR,({"gift"}));
  set("long","����һ�������������Ŵ�("+HIR+"open"+NOR+")��������");
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
  add_action("do_open", "open");
}

int do_open(string arg)
{
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("��Ҫ��ʲô?\n");
  if (me->query("xiaonian_liwu")) return notify_fail("���Ѿ��ù������ˣ���ô����Ҫ��\n");
  message_vision(HIG"$N�����������Ĵ򿪣�һ����â���������$N�������ۣ�������Ŷ����\n" NOR,me);
  me->add("potential",100000);
  tell_object(me,HIR"�㱻�����ˣ�\n" +
  chinese_number(100000)    + "��Ǳ��\n" NOR);
  me->set("xiaonian_liwu",1);
  destruct(this_object());
  return 1;

}
