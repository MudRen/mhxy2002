// pao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(MAG "��˿������" NOR, ({"ice cloth","cloth"}));
        set_weight(1000);
        set("long", "�������ҽ��еı�˿����֯��ս�ۣ����֮����\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 100000);
                set("armor_prop/armor", 100);
        }
        setup();
}

