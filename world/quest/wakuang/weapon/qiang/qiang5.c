#include <weapon.h>
#include <ansi.h>

inherit SPEAR;
inherit F_UNIQUE;

void create()
{
        set_name("����ǹ",({ "huoyun qiang", "huoyun", "spear", "qiang" }) );
        set_weight(20000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("rigidity", 9);
                set("sharpness", 9); 
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5); 
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N��ৡ���һ�����һ�ѻ���ǹ��\n"NOR);
                set("long", "����һ������ǹ��\n");                
                set("unwield_msg", HIY "����ǹ����һ���׹⣬��ৡ��ط������䡣\n" NOR);                
}
        init_spear(80);
        setup();
}
