#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIG "������" NOR, ({ "qinglong sitck", "bang", "qinglong", "stick" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","���Ǹ��ִ���ֱ��������������Լ���������Ļ��ơ�\n");
        set("value", 0);
        set("unique", 1);
        set("rigidity", 1);
        set("sharpness", 1);
        set("material", "blacksteel");
        set("treasure",1);
        set("wield_msg", "ֻ������������һ���������֣�$N��������µ�$n���ñ�ֱ��\n");
        set("unequip_msg", "$N�����е�$n�������䡣\n");
}
        init_stick(40);
        setup();
}
