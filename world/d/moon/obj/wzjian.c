// by mhsj@gslxz 2001/3/12

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(BLINK+HIC "����֮���贈����������" NOR, ({"wangzhe sword", "sword", "jian",
   "jueqing"}));
        set_weight(10000);
                set("unit", "��");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��������ħ�ı�����\n");
set("value", 220000);
		set("wield_msg",
""HIW"$N"HIC"��ৡ�"NOR"��һ���ӽ����аγ�$n,"HIW"$N"NOR"������ȴ͸¶���˸е����顣\n");
		set("unwield_msg",
""HIW"$N"NOR"�����е�$n�������䣬������������ˣ�\n");
                set("weapon_prop/courage", 10);
        }
    init_sword(3000);
        setup();
}
