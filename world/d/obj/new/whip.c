// whip.c 
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit WHIP;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"�һ�" NOR+HIC "��" NOR, ({"liehuo bian", "bian", "whip"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "�����ϲ����ŵ�����Ļ��档\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIR "ֻ�����䡹��һ���������е��һ�Ϊһ���������$N���\n" NOR);
                set("unwield_msg",HIR "$N�����е�$n"+HIR "�����һ�壬��޶�ʱ��Ϊһ���һ���ʧ�ˡ�\n"NOR);
                             set("weapon_prop/cor", 1);
}
        init_whip(120);
        setup();
}
