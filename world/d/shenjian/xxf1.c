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
  "south" : __DIR__"xxf",
]));
set("objects", ([
		__DIR__"npc/swordman" : 2,
          	]));
	setup();
}
