// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ���������ӻ�¯�ϵĴ�������Ʈ���������ﵽ�����Ÿ�ʽ�����Ĳ��ȡ�
��ɽׯ�˶��ڶ࣬ÿ��Ҫ�ԵĶ������Ǵ������ȥ�ġ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lpt",
]));
set("objects", ([
		__DIR__"npc/cook" : 2,
          	]));
                set("coor/x",-1330);

	set("coor/y",260);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
