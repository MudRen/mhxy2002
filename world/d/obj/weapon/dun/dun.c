#include <armor.h>

inherit SHIELD;

void create()
{
        set_name( "�����ٶ�" , ({"qingluo dun","shield", "dun", "qingluo"}) );
		set("long", "��������õĶ�֮һ��\n");
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("value", 1000);
                set("armor_prop/armor", 100);
        }
        setup();
}


   