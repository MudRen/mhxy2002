// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ǰ��԰");
        set("long", @LONG
������ɽׯǰԺ�Ļ�԰���룬�ʷ�ջ�ʢ����ʱ�ڣ����صľջ�
���涷�ޣ����࿪�ţ����Ҳ��ϵ�����Ů����ȥȥ��
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dt",
  "south" : __DIR__"wuc",
   "east" : __DIR__"rqhuayuan",
    "west" : __DIR__"lqhuayuan",
]));
      set("objects", ([
		__DIR__"npc/shinu" : 2,
	]));
              set("coor/x",-1310);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
