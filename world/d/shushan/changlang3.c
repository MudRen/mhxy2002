//changlang3.c by yuahu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short",HIR "��" HIY "����" HIR "��" NOR);
	set ("long", @LONG

���Ǹ����ȣ���������ɽ���ڵ���Ʒ����Ҫ����ɽ�������µ��˶���ȥ
��Ʒ���칤�ߣ��ϱ��Ƕ����䳡��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"xiuxishi",
		"south" : __DIR__"wupinfang",
	]));

	setup();
}
