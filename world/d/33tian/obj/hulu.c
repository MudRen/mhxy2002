// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hulu.c 

inherit ITEM;
void create()
{
   set_name("�����«", ({"hulu", "hu"}));
   set_weight(700);
   set_max_encumbrance(100000000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "̫���Ͼ�����ʢ�ŵ�ҩ�ĺ�«,�ɲ��Լ���֮���������Ƴ�.\n");
     set("unit", "��");
     set("value", 100);
     set("no_sell", 1);
     set("no_give", 1);
     set("no_drop", 1);
     set("no_put", 1);
   }
    setup();
}
  int is_container()
{ 
  return 1;
}
  void init()
{
  object me = this_object();
  object dan = new("/d/obj/drug/lihen");
  dan->move(me);
}
