// gold_armor.c

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIY "�ƽ����Ӽ�" NOR, ({"gold armor","armor"}));
        set_weight(3000);
        set("long", "һ���ƽ������ı��ף�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
                set("value", 100000);
                set("armor_prop/armor", 195);
                set("armor_prop/dodge", -5);
        }
        setup();
}
