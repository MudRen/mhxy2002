// mhsj@iiiii  2000.12.15
// jinjia.c ���
#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(HBRED+HIY " �� �� װ �� " NOR, ({"golden armor","hejin", "jia", "armor"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ��������͵ı��ף�\n");
                set("material", "steel");
                set("value", 50000);
                set("armor_prop/armor", 500);
set("armor_prop/dodge", 20);
set("armor_prop/spells", 20);
set("armor_prop/force", 20);

        }
        setup();
}



