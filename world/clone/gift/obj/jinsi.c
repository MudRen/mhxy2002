// jinjia.c ���
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("��˿����", ({"jinsi baojia","baojia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����������˿������ÿ��ϰ��֮�����ǵķ��ߣ�\n");
                set("material", "steel");
                set("value", 0); 

                set("no_give",1);
                set("armor_prop/armor", 60);
        }
        setup();
}


