#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIG "С¥һҹ������" NOR, ({ "springrain blade", "blade" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "��С¥һҹ�����꣢������С¥���꣢�����������������������֮һ��\n"
                        "�˵���а�����������ࡣ\n");
                set("value", 1);
                set("material", "sapphire");
		set("rigidity", 500000);
		set("no_get",1);
		set("no_drop",1);
                set("wield_msg", "$N��ˢ����һ�����һ�����������$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
                set("weapon_prop/agility", 5);
        }

        init_blade(95);
        setup();
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
	me->add("bellicosity",10+random(30));
        return HIR "$N������ӳ�ţ�С¥һҹ�����꣢�����Ĺ����⣮����\n" NOR;
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

