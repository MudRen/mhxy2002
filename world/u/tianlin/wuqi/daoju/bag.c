#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"�ٱ���"NOR, ({ "bag" }) );
        set_weight(0);
        set_max_encumbrance(100000000);
		set_max_items(100000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",BLINK HIC"���Ǳ�վ��ʦΪ�����Ƶ�������ߡ�\n"NOR);
                set("value", 50000);
        }
}

int is_container() { return 1; }


