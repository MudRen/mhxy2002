#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(YEL"��"NOR, ({ "jia" }) );
        set_weight(20000);
        set("unit", "��");
        set("material", "steel");
        set("no_give", "���������Ѫ����ô������������?\n");
        set("value", 2500);
        set("armor_prop/armor", 10);
        set("unique", 1);
        setup();
}
