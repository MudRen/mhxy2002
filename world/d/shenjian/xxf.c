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
  "north" : __DIR__"xxf1",
  "east" : __DIR__"lqhuayuan",
]));
set("objects", ([
		__DIR__"npc/swordman" : 1,
          	]));
	setup();
}
