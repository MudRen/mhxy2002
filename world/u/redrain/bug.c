//����
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"�ٱ���"NOR, ({"bug gift","gift"}));
    set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
        set("long",
              HIR+"                ������������������������������������������������
                ��               "HIW""BLINK"�ٱ������й�"NOR"         "HIR"        �� 
                ������������������������������������������������"NOR"
��å��ʦ�������Ľ��������(chai)��������ʲô��
"NOR
);
    set("value", 2000);
    set("no_sell",1);
    set("no_get",1);
    set("no_put",1);
    set("no_drop",1);
  }
    setup();
}
void init()
{
    add_action("do_chai", "chai");
}
int do_chai(string arg)
{
    string *skills ,str;
    mapping all_skills;
    object me = this_player();
    int i;
  if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");

 {

 {
{
 str="��˵"+me->name()+"�ٱ�bug�й����õ��˺���Ľ�����"NOR;
 message("channel:rumor",HIM"�����澫�顿ĳ�ˣ�"+str+"\n"NOR,users());
}      me->add("max_force", 100);
       me->add("max_mana",100);
       me->add("maximum_force", 100);
       me->add("maximum_mana",100);
       me->add("potential",50000);
       me->add("combat_exp",20000) ;
       me->add("daoxing",20000);
     } 
 tell_object(me,HIC "��������100��������100�㷨����5��Ǳ�ܣ�2����ѧ��20����С�\n" NOR);
  }  destruct(this_object());
     return 1;
}
void owner_is_killed() { destruct(this_object()); }


