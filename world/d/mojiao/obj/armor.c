#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(HIY "�������ӻƽ��" NOR, ({"golden armor", "jia"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("value", 100000);
                set("armor_prop/armor", 85);
        }
        setup();
}
