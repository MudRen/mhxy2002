#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����", ({"changpao"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɫ���ۣ�������ѧ�ʵ��˴��ģ�\n");
                set("unit", "��");
                set("value", 200);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}
