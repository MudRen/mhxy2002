#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "���ɽ�" NOR, ({ "juexian jian", "jian", "sword", "juexian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���ɽ�\n"
);
                set("value", 0);
                set("sheenness", 25);
                set("material", "silver");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

       init_sword(100);
setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int damage;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damage = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("sen",damage*2);
        victim->receive_damage("kee",damage*2);
        victim->start_busy(3);
        return HIW "���ɽ��Ϻ��һ����\n" NOR;
        }
}

