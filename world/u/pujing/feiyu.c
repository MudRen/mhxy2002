//By tianlin@mhxy for 2002.1.2.
#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIR"����"HIY"��"NOR, ({ "huoyan ling","ling" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",HIR"���ǻ������ϵ���ë������ȼ���Ż��档\n"NOR);
                set("unit", "Щ");
                set("base_unit", "֦");
                set("base_weight", 40);
                set("value", 20000);
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("base_value", 50);
        }
        set_amount(30);
        init_throwing(100+random(100));
        setup();
}


