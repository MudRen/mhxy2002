//By waiwai@mszj 2000/10/26

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIR"�ɹŴ��"NOR, ({ "menggu doctor","doctor"}));
	set("title", HIB"���"NOR);
	set("nickname", BLINK+HIG"ȫ��һ�ѵ�"NOR);
	set("shen_type", 1);

	set("str", 50);
	set("gender", "����");
	set("age", 35);
	set("long",HIC
		"�����򳤰�����Ψһ��һλ�������������ˣ��ƹ���ҵ���Ů�Ա��Ȩ��\n"NOR);
	set("combat_exp", 9500000);
	set("attitude", "friendly");
	
	setup();
	
}
