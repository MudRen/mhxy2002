// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���Ʒ���");
        set("long", @LONG
������ï�ܵ����֣�ǰ����һ����᫵�ɽ·��˳��ɽ·��ȥ����Ŀ��䣬
һ����ɽ������̲ݺ������ķҷ����������
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"cyf1",
  "south" : __DIR__"cunkou",
]));
        set("coor/x",-1015);

	set("coor/y",25);

	set("coor/z",0);
set("no_magic",1);
	setup();
}
