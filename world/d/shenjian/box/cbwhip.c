// TIE@FY3

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "�ȱ���", ({ "whip" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);  
                set("material", "skin");
        }
        init_whip(120);

        set("wield_msg", "$N������ţ�����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

        setup();
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