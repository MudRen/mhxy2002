// LLY@FYSY 
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name("����", ({ "letter" }));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("for_sjwoman",1);
		set("long",
			"һ��л�������ɽׯ�ļ��飬�����漰��һЩ�Ƽ�����ׯ�����顣\n");
	set("value", 0);
		


	}
	setup();
}


