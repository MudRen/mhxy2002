// LLY@FYSY 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( HIC "����" + MAG "��˫" NOR, ({ "deitysword" ,"sword"}) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����������ģ���Ȼ�ѳ¾ɣ�ȴ�Ա���ú��������ӻ�ɫ�Ľ���ɫ���������ˣ���ʽ���ŵĽ���ȴ���ڷ��Ź⡣\n");
		set("value", 1);set("no_get",1);
		set("no_drop",1);
		set("material", "steel");
	}
	init_sword(80);
	set("wield_msg", "$N��ȫ���Ȼ����һ����˵Ľ��������������۳�һ��$n��\n");
	set("unwield_msg", "$n��Ϊһ�Ž�����ʧ��$N���С�\n");
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam ,pro;
        pro = (int)victim->query("force");
	dam = (int) me->query("force");
	if(dam > random(pro) )
	{
	victim->start_busy(1);
	return HIC "������˫ɢ�������˽�����ʹ��$nΪ֮���ϣ��������ã�\n" NOR;
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
 