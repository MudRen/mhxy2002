// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
����һ����ʯ�̳ɵ�С·���ߵ����̧����ȥ����ɽ��ˮ��
���ܶ������صĴ������ӣ������߲�Զ������ˮ���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"croad1",
  "east" : __DIR__"cunkou",
  "south" : __DIR__"chouse",
  "north" : __DIR__"chouse1",
]));
        set("objects", ([
        __DIR__"npc/xiaotong": 2,
        __DIR__"npc/farmer": 1,
                        ]) );
        set("coor/x",-1025);

	set("coor/y",15);

	set("coor/z",0);
	setup();
    }
