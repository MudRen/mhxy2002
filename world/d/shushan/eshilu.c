// eshilu.c ʯ��· by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIG "ʯ��·" HIR "��" NOR);
	set("long", @LONG
������һ��ʯ��·�ϣ���������������Ʒ�����㿴���в�����
��������׶�ѧ���򣬴��Ǳ߹�������������ɽ�ɴ�����
LONG
	);
       set("exits", ([
		"westup" : __DIR__"dating",
		 "east" : __DIR__"wupinfang",
		]));
        setup();
	replace_program(ROOM);
}

