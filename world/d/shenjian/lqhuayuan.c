// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
����һ������㣬һ����ɽ��������ǰ,��ɽ����һ����Ȫ���£�
�������˵������������Ŀ�������
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lwuc",
    "east" : __DIR__"qhuayuan",
  "west" : __DIR__"xxf",
]));
         set("objects", ([
		__DIR__"npc/shinu" : 1,
                __DIR__"npc/guard" : 2,
	]));
        set("coor/x",-1320);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
