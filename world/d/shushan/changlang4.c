//changlang4.c by yuahu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short",HIR "��" HIY "����" HIR "��" NOR);
	set ("long", @LONG

���Ǵ�������һ�����ȣ����������䳡��С������ľ���̵أ�
��ɨ�ļ�Ϊ�ɾ����������淢��֨֨�����������������ľ����
����һЩɽˮ���
LONG);

	set("exits", 
	([ //sizeof() == 2
		"north" : __DIR__"wshilu",
		"south" : __DIR__"westlianwu1",
	]));

	setup();
}
