#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"����������"NOR,({ "yitian cha", "yitian", "fork", "cha" }) );
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("rigidity", 9);
                set("sharpness", 9);
                set("unique", 1);
                set("no_give", "���������Ѫ����ô������������?\n");
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N������������һ��������������棬������â���£������Ƿɡ�\n$N���ɵô��ĵ�����һ�����ƺ�����\n"NOR);
                set("long", "����һ�����߸ֲ棬�����Ͻ�˿���š����졯����׭�ġ�\n����������������һ��������\n");                
                set("unwield_msg", HIY "�������������һ��Ѫ�⣬�������ط������䡣\n" NOR);                
}
         init_fork(120);
        setup();
}
