// xiaohunjian.c 
//create by lixin
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"����" NOR+HIC "��" NOR, ({"xiaohun sword", "sword", "jian"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���꽣�������ꡣ\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", MAG "$N��ৡ���һ�����һ��$n"+MAG "�������У��۳�����˱��˵ĺ��⣬����������������֮�С�\n" NOR);
                set("unwield_msg",MAG "$N�����е�$n"+MAG "��ؽ��ʣ����֮���ɱ���Ž�����ʧ��\n");
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_sword(120);
        setup();
}
