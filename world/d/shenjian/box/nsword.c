// ken 1999.12.11

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"���̽�" NOR, ({ "ningsword" ,"sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",                        
"�����ǻ�ɽ���ŵ��������̽���\n");
                set("value", 1);
		set("for_bandit",1);
		set("no_get",1);
		set("no_drop",1);
                set("material", "steel");
                set("wield_msg", "$N�ӹ��ӵĽ����г��һ���������˵�$n��\n");
                set("unwield_msg", "$N�����н�$n������У�$n����һ���̹����뽣��֮�С�\n");
             }

        init_sword(100);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("force");
        victim->receive_damage("gin",dam/7);
        victim->receive_damage("kee",dam/5);  
	victim->receive_damage("sen",dam/7);
	return HIG "һƬ��ɫ��â��$n�����޾��Ļ����У������е�$n�Եþ����㱣�����\n" NOR;
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