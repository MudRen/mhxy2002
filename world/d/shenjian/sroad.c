// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
Ϧ��������ʧ��ɽ���ϵķ�Ҷȴ���������ģ��е��ķ�����
����һ��СС��ʯ����
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sroad1",
  "southdown" : __DIR__"hsp",
]));
         set("coor/x",-1310);

	set("coor/y",175);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
