#include <weapon.h>
#include <ansi.h>

inherit SPEAR;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"��������ǹ"NOR,({ "yitian qiang", "yitian", "qiang", "spear" }) );
        set_weight(20000);
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
                set("wield_msg", HIY"$N��ৡ���һ�������������ǹ���˸�ǹ����������â���£������Ƿɡ�\n$N���ɵô��ĵ�����һ�����ƺ�����\n"NOR);
                set("long", "����һ����������ǹ��ǹ���Ͻ�˿���š����졯����׭�ġ�\n����ǹ����������һ����������δ���ʣ��ѿɼ��䲻����\n");                
                set("unwield_msg", HIY "��������ǹ����һ���׹⣬��ৡ��ط������䡣\n" NOR);                
}
        init_spear(120);
        setup();
}
