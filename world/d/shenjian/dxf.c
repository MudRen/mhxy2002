// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���᷿");
        set("long", @LONG
���������������õı���ס�޵ĵط���������һ����Ⱦ���Ҿ�
�ڷŵĴ������ȣ�����һ�ֱ������ĸо���
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dxf1",
  "west" : __DIR__"rqhuayuan",
]));
set("objects", ([
		__DIR__"npc/swordman" : 2,
          	]));
        set("coor/x",-1290);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
