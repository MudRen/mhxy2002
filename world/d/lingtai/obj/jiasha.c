// By tianlin 2001.5.8
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"ˮ��"CYN"ս��"NOR, ({"shuijing pao", "pao", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long"," һ��ˮ������ս��,��˵��������õġ�\n");
                set("material", "cloth");
                set("unit", "��");
                set("value", 10000);
                set("armor_prop/spells", 20);
                set("armor_prop/dodge", 20);
                set("armor_prop/armor", 100);
     set("armor_prop/personality", 2);
        }
        setup();
}
