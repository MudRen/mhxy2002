//By tianlin@mhxy for 2002.1.10
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽׯǰԺ");
        set("long", @LONG
һ��ׯ���������Ұ��Ȼ���ʣ��ղŵ�ѹ��һɨ���⡣�˴�������
�����⣬������һ�����������Ƶĵ�·�����ҽ��Ƿ������������İ�
��ЪϢ�Ĵ����������˹���������һ�Է�ȥ����߲�Զ��������˻����
��������������ˣ��ұ���һ���ʷ�����ʱ���˽�����
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wuc",
  "south" : __DIR__"sjsz",
  "east" : __DIR__"zf",
  "west" : __DIR__"ml",
]));
set("objects", ([
		__DIR__"npc/guard3" : 2,
                __DIR__"npc/guard" : 1,
          	]));
  set("outdoors", __DIR__);
             set("coor/x",-1310);

	set("coor/y",230);

	set("coor/z",10);
	setup();
}
