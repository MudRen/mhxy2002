#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"���佣"NOR, ({"zhenwu jian", "sword", "zhenwu"}));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѻ������۵ĹŽ�,��������Ļ������ƺ�������Щ����,�����Ͼ�Ȼ���м���ȱ�ڡ�\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 5);
                set("no_give", "���������Ѫ����ô������������?\n");
                set("sharpness", 3);
                set("material", "blacksteel");
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 3);
                set("treasure",1);       
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);        
                set("skill", ([
                        "name": "sword",
                        "exp_required": 500000,
                        "difficulty": 25,
                        "min_skill": 100,
                        "max_skill": 150,                       
                ]) );
                set("wield_msg",HIW"$N[��]��һ�����һ�����佣,�����ж�ʱ�������ޱߵ�ɱ����\n"NOR);
                set("unwield_msg",HIW"$N�����еı������뽣�ʡ����ܵ�ɱ��Ҳ������ʧ�ˡ�\n"NOR);
}
        init_sword(100);
        setup();
}