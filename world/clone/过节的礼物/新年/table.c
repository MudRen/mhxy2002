#include <ansi.h> 
inherit ITEM;
int get_liwu(string arg);
void create()
{
  set_name(HIW"��������̨" NOR ,({"gift table","table"}));
  set("long","�������˸÷������ˣ���ҿ�����������(pick)����(gift)��");
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
  object me = this_player(); // �趨me��ָ����Ʒ
  object lw; //�趨��Ʒ�򵥳ƺ�                          
  if (arg!="gift")      return 0;
  if (me->query("newyear_gift")) return notify_fail("���Ѿ��ù�������,��̫̰��Ӵ��\n"); //"���"����
  if (me->query("combat_exp") <= 10000) return notify_fail("�����ѧ�ǲ����е㡣������\n"); //��ѧ����
  message_vision("$N������̨������һ�����\n" NOR, me); //��������ʱ�Ķ�������
  lw=new("clone/���ڵ�����/����/gift"); //����·��    
  lw->move(me); //���������Ķ���ǰ���me��ָ��
  me->set("newyear_gift",1); //�����
  return 1;
}