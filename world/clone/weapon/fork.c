
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("[1;32;44m����������[m", ({ "fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_drop",1);
                set("no_put",1);
//                set("no_give",1);
                               set("unit", "��");
                set("value", 1000);
                set("material", "iron");
                set("long", "һ�������ĸֲ档\n");
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
        }
        init_fork(190);
        setup();

}
