// long_kui.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIG "�����̶���" NOR, ({"long kui","kui"}));
        set_weight(1000);
        set("long", "��˵�ⶥ�������ž����������۵ķ�����\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
                set("value", 100000);
                set("armor_prop/armor", 30);
        }
        setup();
}

