// wshilu.c ʯ��· by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIG "ʯ��·" HIR "��" NOR);
	set("long", @LONG
������һ��ʯ��·�ϣ������������Ƿ������㿴���в�����
Χ�������ߡ������߾���ͨ����ɽ��·��
LONG
	);
       set("exits", ([
		"south" : __DIR__"changlang4",
		 "east" : __DIR__"wshilu1",
               "west" : __DIR__"fanting",
            "northup" :  __DIR__"houshan",
		]));
             set("objects", 
        ([ //sizeof() == 1
               "d/shushan/npc/mingyue" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "northup" ) {
        if (objectp(present("ming yue", environment(me))))
        return notify_fail("�����������е���潣��˵��:ʦ������,�����������Ϻ�ɽ!\n");
        }   
        return ::valid_leave(me, dir);
}


