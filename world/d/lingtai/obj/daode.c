// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

#include <ansi.h>

int do_read(string arg);
void create()
{
  set_name("���¾�", ({"daode jing","dade","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100);
    set("no_sell", 1);
    set("long", " ����һ�����ӵ��¾������� read �Ķ���\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me = this_player();
  string content;
  
  content=read_file("/d/lingtai/npc/laozi.txt");
  me->start_more(content);
  return 1;
}

