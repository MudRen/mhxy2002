// rake.c

#include <ansi.h>;
#include <weapon.h>

inherit RAKE;

void create()
{
        set_name(HIW"�ųݱ���"NOR, ({ "bing pa", "pa","rake" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "iron");
                set("long", HIW"һ�������ľųݱ��ҡ�\n"NOR);
                set("wield_msg", "$N����һ��$n����ͷ�ϻ�����һȦ��\n");
        }
        init_rake(90);
        setup();
}

