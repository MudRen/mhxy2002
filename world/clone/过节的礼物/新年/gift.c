#include <ansi.h> 
inherit ITEM;    
int do_open(string arg);
void create()
{
  set_name(HIG "����" NOR,({"liwu"}));
  set("long","����һ�������������Ŵ�("+HIR+"pick"+NOR+")��������"); 
  set("unit","��"); 
  set("value", 50000000); 
setup();
}
void init()
{
if(!wizardp(this_player())){
    set("no_get","��������ò�������\n"); 
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_sell","�ⶫ����������\n");
}
    if(this_player()==environment())
      add_action("do_open", "pick"); 
}
int do_open(string arg)
{
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("��Ҫ��ʲô?\n"); 
  if (me->query("newyear_liwu")) return notify_fail("���Ѿ��ù������ˣ���ô����Ҫ��\n"); 
  message_vision(HIR"$N�����������Ĵ򿪣���ϲ������ϲ��������\n" NOR,me); 
  me->add("potential",100000); 
  me->add("combat_exp",100000); 
  me->add("daoxing",100000); 
  me->add("rsg_eaten",5);  
  tell_object(me,HIW"�㱻�����ˣ�\n" +
  chinese_number(100000) + "����ѧ��\n"+        
  chinese_number(200000) + "��Ǳ�ܡ�\n"+
  chinese_number(100)    + "����С�\n"+ 
  "����˲ι���\n" NOR); 
  me->set("newyear_liwu",1);
  destruct(this_object());
  return 1; 
}