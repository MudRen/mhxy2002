//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIW"�Źǿ�ɽ��"NOR, ({"jiugu chui","jiugu","chui","kaishan chui","hammer"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ǧ����ص�������\n");
                set("value", 300000);
                set("material", "iron");
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("wield_msg", HIB"$N˫���黮��$n"HIB"����˫�֣���Ȼ��ס��\n"NOR);
                set("unwield_msg", HIB"$N��$n"HIB"�ջر���\n"NOR);
        }
        init_hammer(100+random(100));
        setup();
}
