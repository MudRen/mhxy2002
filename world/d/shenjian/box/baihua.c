
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "��" + HIG "˫" + HIC "�ٻ���" NOR, ({ "baihua sword", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�����������â�ķ����������Ǵ�˵�����������֮һ��\n"
);
                set("value", 18000);
                set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N��������ɫ��ʯ����佣���г��һ���������˵�$n��\n");
                set("unwield_msg", "$N�����н�$n������У�$n����ƬƬ�ɻ�������佣���С�\n");
        }
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/10);
        victim->receive_damage("sen",dam/10);
        victim->receive_damage("kee",dam/10);
        return HIG "���εĽ�������ƬƬ�ɻ���$n�����޾��Ļ����У������е�$n�Եþ����㱣�����\n" NOR;
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
