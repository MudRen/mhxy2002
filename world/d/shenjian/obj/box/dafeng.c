#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIG "��絶" NOR, ({ "windblade" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�������񣬵���һ����ֻ��ı���������ʮ�����������֮һ\n"
);
                set("value", 1);
		set("for_bandit",1);
                set("material", "steel");
		set("no_get",1);
		set("no_drop",1);  
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }

        init_blade(75);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
	victim->receive_damage("sen",dam/5);
	return HIG "��絶�����ĺ�Х���ŵ�$n��������\n" NOR;
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