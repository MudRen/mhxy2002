#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "���ɽ�" NOR, ({ "xianxian jian", "jian", "sword", "xianxian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ɽ�\n");
                set("value", 0);
                set("material", "purplegold");
                set("sheenness", 50);
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
        int damm;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damm = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("kee",damm);
        return HIR "���ɽ�һ����\n" NOR;
        }
}

