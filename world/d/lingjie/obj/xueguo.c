#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"Ѫ��"NOR, ({ "xue guo","guo"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "on");
                set("unit", "��");
                set("long", "һ��Ѫ��ɫ�϶�����óԵĹ��ӡ�\n");
                set("value", 1);
		set("water_remaining", 1);
		set("water_supply", 100);
        }
}  
