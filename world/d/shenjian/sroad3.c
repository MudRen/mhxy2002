// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ׯ��С·");
        set("long", @LONG
�߳��˷��֣�����ǰ������ɽׯ�ˣ���ɽׯ��ɽ��ˮ����
�����϶����
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sjsz",
  "south" : __DIR__"sroad2",
]));
          set("coor/x",-1310);

	set("coor/y",210);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
