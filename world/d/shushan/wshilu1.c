// wshilu.c ʯ��· by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIG "ʯ��·" HIR "��" NOR);
	set("long", @LONG
������һ��ʯ��·�ϣ������������Ƿ������㿴���в�����
Χ�������ߡ����Ǳ߹�������������ɽ�ɴ�����
LONG
	);
       set("exits", ([
		"west" : __DIR__"wshilu",
	        "eastup" : __DIR__"dating",
         ]));
        setup();
	replace_program(ROOM);
}

