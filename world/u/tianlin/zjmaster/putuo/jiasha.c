//By tianlin@mhxy for 2002.1.23

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"��������"NOR, ({ "mianpao jiasha","jia sha", "jiasha" }) );
        set("long", "����������������,���������Ŀ�����ǿ�Լ��ķ�����\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/spells", 100);
                set("armor_prop/dodge", 50);
                set("value", 50000);
        }
        setup();
}


