#include <ansi.h>
inherit ITEM;
int get_liwu(string arg);
void create()
{
set_name(HIW"С������̨" NOR ,({"gift table","table"}));
set("long","������ʦΪ����ҹ�С����������̨����ҿ�����������(pick)����(gift)��");
  set("unit", "��");
  set("value", 1000000000000);
}

void init()
{
  if (!wizardp(this_player())) 
    set("no_get","��������ò�������\n");
  add_action("get_gift","pick");
}

int get_gift(string arg)
{
  object me = this_player();
  object lw;
  if (arg!="gift")      return 0;
if (me->query("xiaonian_gift")) return notify_fail("���Ѿ��ù�������,��̫̰��Ӵ��\n");
  message_vision("$N������̨������һ�����\n" NOR, me);
  lw=new("/clone/���ڵ�����/С��/gift");;
  lw->move(me);
   me->set("xiaonian_gift",1);
  return 1;
}

