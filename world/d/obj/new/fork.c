// gangcha.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit FORK;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"����"NOR+HIC"��"NOR, ({ "long cha", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("is_monitored", 1);
                set("material", "iron");
                set("long", "һ���ֲ档\n");
                set("wield_msg", HIY"$N��������һ��$n"NOR+HIY"����⻹������⡣\n"NOR);
                set("unwield_msg", HIY "$N�ð�$n" NOR+HIY"�����ֱ����˱���\n");
            }        
init_fork(120);
        setup();
}

