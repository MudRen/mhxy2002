// baihu_pifeng.c

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;
void create()
{
        set_name(HIC "����������" NOR, ({"moon pao","pao"}));
        set_weight(1000);
        set("long", "������磬����ûʲô��ֵģ���ϸһ������Ȼ���ŵ���ɫ�Ĺ�ã��\n");

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value",100000);
                set("armor_prop/armor", 60);

        }
        setup();
}

