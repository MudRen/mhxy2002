#include <weapon.h>
#include <ansi.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name("ɱ����",({ "shawei gun", "shawei", "stick", "bang" }) );
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value", 0);
        set("rigidity", 9);
        set("no_give", "���������Ѫ����ô������������?\n");
        set("sharpness", 9); 
        set("no_get", 1);
        set("material", "steel");
        set("weapon_prop/dodge", -5);
        set("weapon_prop/parry", 5); 
        set("wield_neili", 300);
        set("wield_maxneili", 700);
        set("wield_str", 22);
        set("wield_msg", HIY"$N��ৡ���һ�����һ��ɱ������\n"NOR);
        set("long", "����һ����ɫ����Ĵ����\n");                
        set("unwield_msg", HIY "ɱ��������һ���׹⣬��ৡ��ط������䡣\n" NOR);                
}
        init_stick(80);
        setup();
}
