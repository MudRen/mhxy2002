//By tianlin@mhxy for 2001.12.31

#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
                    set_name( HIY "�λ����δ󲹵�" NOR , ({"da bu dan","dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
  set("unit", "��");
       set("long", "������ʦ�ǾžŰ�ʮһ�쾫�����ƵĴ󲹵�(dan)����˵��(eat)������Ч��\n");
      set("value", 100);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

 int do_eat(string arg)
{
  object me = this_player();
       if (arg!="dan") return 0;
  if (me->query("newbie_liwu")) return notify_fail("���Ѿ��ù������ˣ���ô����Ҫ��\n");

seteuid(getuid());
  switch (random(5))
{
case 0:
{
     me->add("combat_exp",30000);
                   message_vision(HIM "$N����һ���λ����δ󲹵���С������س��˽�ȥ��
         �ÿᰡ��$N����ѧ����������30000�㣡\n" NOR, me);
break;
}
case 1:
{
       me->add("daoxing",20000);
       me->add("kill/nkgain",20000);
                     message_vision(HIG "$N����һ���λ����δ󲹵���С������س��˽�ȥ��
           �ÿᰡ��$N�ĵ���������20�꣡\n" NOR, me);
break;
}
case 2:
{
        me->add("potential",50000);
                      message_vision(HIR "$N����һ���λ����δ󲹵���С������س��˽�ȥ��
            �ÿᰡ��$N��Ǳ��������50000�㣡\n" NOR, me);
break;
}
case 3:
{
        me->add("force",300);
        me->add("maximum_force",300);
        me->add("max_force",300);
                        message_vision(HIB "$N����һ���λ����δ󲹵���С������س��˽�ȥ��
             �ÿᰡ��$N������������300�㣡\n" NOR, me);
break;
}
case 4:
{
        me->add("mana",300);
        me->add("max_mana",300);
        me->add("maximum_mana",300);
                        message_vision(HIW "$N����һ���λ����δ󲹵���С������س��˽�ȥ��
             �ÿᰡ��$N�ķ���������300�㣡\n" NOR, me);
break;
}
}
  me->set("newbie_liwu",1);
  destruct(this_object());
  return 1;
}
