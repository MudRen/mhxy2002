// renshen-guo.c �˲ι�
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
      if(this_player()==environment())
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW "�˲ι�" NOR, ({"renshen guo", "renshenguo", "guo"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", "�װ����ֵ�һö�˲ι�������û����ȫ��͸������ֵ��ǣ�����ɢ���ų�ζ��\n");
                set("value", 500);
                set("drug_type", "��Ʒ");
        }
        set("no_drop",1);
        set("no_put",1);
        set("is_monitored",1);
        setup();
  set("is_monitored",1);
}

int do_eat(string arg)
{
        int howmany;

        object me = this_player();
  
        if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        howmany = (int)me->query("rsg_eaten");
  
        me->set("food", (int)me->max_food_capacity());

                if( howmany <= 10 ) me->add_maximum_force(5);
               if( howmany <= 10 ) me->add_maximum_mana(5);

        me->set("rsg_eaten", howmany+1);

            message_vision(HIW "$N���˲ι�������һ�����̲�ס���һ�����˲ι����˲ι����������˲ι��� \n˵���˷ܵö������˹�ȥ��\n\n"NOR,me);
message_vision(HIR"��������ϸ��һ�������ɵô�У���ԭ���Ǽٵİ����ĸ�������ôȱ��Ӵ?? \n"NOR, me); 

write(HIG"\nһ�����������������...............\n"NOR);
write(BLU"��ϲ����˲ι��������ּ���һ.�������ܹ�����"+chinese_number(howmany+1)+"���˲ι���\n"NOR);
        destruct(this_object());

        return 1;

}
