// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������ֻ����һ������������һƥƥ����˨�����
�ɴ˿ɼ�ׯ��ÿ�����ı�����Ŀ�ˡ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lwuc",
  "east" : __DIR__"rroad",
]));
 set("objects", ([
		__DIR__"npc/mafu" : 2,
             	]));
        set("coor/x",-1320);

	set("coor/y",230);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
