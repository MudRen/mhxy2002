// LLY@FYSY 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIW "����ʮ��������Ľ�" NOR, ({ "jewelsword" ,}) );
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����Ƥ�ʣ��ƽ��̿ڣ�����׺��ʮ���Ŷ�������ĳ����������в��ϵ���������˲����ࡣ\n");
		set("value", 1300000);
		set("material", "steel");
	}
	init_sword(80);
	set("wield_msg", "û�����ܿ��ü�$N�ν��Ķ�����$N��$n��Ȼ����Ѿ������γ�����\n");
	set("unwield_msg", "$N��$n�ջؽ����\n");
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("gin",dam/13);
        victim->receive_damage("sen",dam/13);
        victim->receive_damage("kee",dam/13);
        return HIW "����ʮ��������Ľ��ϵ����鷴���ҫ�۵Ĺ�â�ŵ�$n˫�۴�ʹ��\n" NOR;
}
