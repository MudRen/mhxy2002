#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"�ն���������"NOR,({ "puduzhongsheng chanzhang", "chanzhang", "staff", "zhang" }) );
        set_weight(50000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("rigidity", 9);
                set("no_give", "���������Ѫ����ô������������?\n");
                set("sharpness", 9); 
                set("unique", 1);
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"\n$N���ĳ��һ���ն��������ȣ����ܷ�����������Χ���˽���ס����Ĥ�ݡ�\n\n"NOR);
                set("long", "����������������������İݣ��ն�������\n");                
                set("unwield_msg", HIY "$N���ն��������ȷ��£�������ͣ�����ָܻ���������\n" NOR);                
}
        init_staff(160);
        setup();
}
