//yitianjian.c
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("[1;36m���౦��[2;37;0m", ({ "ziqing baojian", "baojian","jian","sword" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 50000);
//        	set("no_drop", "1");
              set("no_sell", "1");
        	set("material", "iron");
        	set("long", "�������µ�һ�������С����첻����˭�����桱֮˵��\n");
        	set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
        	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
	}
        init_sword(90);
	setup();
}
