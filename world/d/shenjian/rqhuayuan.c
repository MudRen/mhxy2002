// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�һ�԰");
        set("long", @LONG
�����ǻ�԰���ұߣ������ݣ��Ĵ��ַ���һЩʯ�ʣ�ʯ������
�м�����ͤ����һ���˼�ʤ�ء�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
   "south" : __DIR__"rwuc",
  "east" : __DIR__"dxf",
  "west" : __DIR__"qhuayuan",
]));
 set("objects", ([
		__DIR__"npc/guard" : 2,
	]));
        set("coor/x",-1300);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
