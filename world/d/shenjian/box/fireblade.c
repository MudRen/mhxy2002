#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIR "���泤��" NOR, ({ "fireblade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�ѷǽ��ľ��ͨ�尵��ĳ���\n"
);
                set("value", 1);set("no_get",1);
		set("no_drop",1);
		set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }

        init_blade(25);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
	victim->receive_wound("kee",5);
	return HIR "���泤�����һ���ɺ�Ļ��棬�ǿ���$n��ȫ��\n" NOR;
	}
}
void init()
{
	add_action("do_make","remake");
}
int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=new(__DIR__"box");
	obj->move(me);
	if(query("equipped")) unequip();
	tell_object(me,"�㽫���е�"+query("name")+"�ֲ𿪣���ɸ����ӡ�\n");
        destruct(this_object());
	return 1;
}          
 
