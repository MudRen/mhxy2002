// dwuchang1.c by yushu-2000.10

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIG "���䳡" HIR "��" NOR);
	set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ���
LONG
	);
        set("outdoors", 2);
        set("exits", ([
	    "south" : __DIR__"westlianwu",
           "north" : __DIR__"changlang4",
	]));

            setup();
}

