// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ׯ������ׯ������Ϣ��ӵĵط����Ĵ��ڷ���һЩ���׺ͽ��ߡ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rwuc",
]));
set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard" : 2,
	]));
        set("coor/x",-1290);

	set("coor/y",240);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
