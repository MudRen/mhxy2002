#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name("��������",({ "jinggang chanzhang", "chanzhang", "zhang", "staff" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("treasure",1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("unique", 1);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 1);        
                set("material", "steel");
                set("long", "���ǰ����ȣ��������ҫ�ۡ�\n");
                set("wield_msg", HIC "ֻ�������ˡ���һ�����������֣�$N���µ�$n���ñ�ֱ��\n" NOR);
                set("unwield_msg", HIC "�������е�$n��\n" NOR);
                set("unequip_msg", HIC "�������е�$n��\n" NOR);
}
        init_staff(60);
        setup();
}
