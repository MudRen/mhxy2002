//lmd@wenxin
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIC "����������" NOR, ({ "long-blade" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ������˿˿���ı������Ǵ�˵���������֮һ\n"
);
                set("value", 1);
                set("for_bandit",1);
                set("material", "steel");
		set("no_get",1);
		set("no_drop",1);
                set("wield_msg", "$Nһ����Х��һ������ĵ��ʣ�һ������������ж���һ��$n��\n");
                set("unwield_msg", "$N�����н������һ�ף�$n����һ����磬�ص����С�\n");
        }

        init_blade(100);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/5);
        return HIC "������������Ȼ����������������$n����Ӱ����$n���þ������������\n" NOR;
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
