#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name("������",({ "dragon fork", "fork", "cha" }) );
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("rigidity", 9);
                set("sharpness", 9); 
                set("no_get", 1);
                set("no_give", "���������Ѫ����ô������������?\n");
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5); 
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N�����������ĳ��һ�������档\n"NOR);
                set("long", "����һ����ɫ����ĸֲ档\n");                
                set("unwield_msg", HIW "���������һ���׹⣬��ৡ��ط������䡣\n" NOR);                
}
        init_fork(80);
        setup();
}
