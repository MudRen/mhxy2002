// shoe.c
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("����", ({ "xianlv shoes", "shoes" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("value", 40000);
//                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 10);
        }
        setup();
}

