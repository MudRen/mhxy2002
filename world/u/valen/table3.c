//created by vikee
//2000.11

#include <ansi.h>
inherit ITEM;
int get_liwu(string arg);
void create()
{
  set_name(HIY"����̨" NOR ,({"gift table","table"}));
  set("long","���ǹŻ�����ʦΪ�˽���������������̨����ҿ�����������(na)����(liwu)��");
  set("unit", "��");
  set("value", 1000000000000);
}
void init()
{
  if (!wizardp(this_player())) 
   set("no_get","��������ò�������\n");
  add_action("get_liwu","na");
}
int get_liwu(string arg)
{
  object me = this_player();
  object lw;

 if (arg!="liwu")      return 0;
  if (me->query("newbie_liwu")) return notify_fail("���Ѿ��ù�������,��̫̰��Ӵ��\n");
  message_vision("$N������̨������һ�����\n" NOR, me);
  lw=new("/u/tianlin/liwu.c");
  lw=new("/wiz/bi.c");
  lw->move(me);
  me->set("newbie_liwu",1);
  return 1;
}

