inherit ITEM;

void create()
{
  set_name("Կ��", ({ "key" }));
  set_weight(1000);
set("long", "����һ��������˿�����ҵ�һ��Կ�ף���˵ֻҪ�ܵõ�
 ���Կ�׾��ܼ�����˿����ʦ��\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

