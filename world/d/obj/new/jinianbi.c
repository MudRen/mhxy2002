//jinianbi
#include <armor.h>
#include <ansi.h>
#include <dbase.h>

//inherit F_UNIQUE;
inherit NECK;

void create()
{
        set_name(HIY "�����" NOR, ({"jinian bi","bi"}));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
		set("long", HIW "���λþ���վ����ң�\n" NOR);
                set("material", "steel");
                set("value", 0);
                set("armor_prop/intelligence", 8);
        }
        setup();
}


