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
  "south" : __DIR__"dxf",
]));
set("objects", ([
		__DIR__"npc/swordman" : 1,
          	]));
        set("coor/x",-1290);

	set("coor/y",255);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
