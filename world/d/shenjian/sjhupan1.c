// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
��ǰ��Ҷ���裬վ��������Կ���Զ����ɽ�壬����г�
����Ǭ��ľҶ�����㣬��һ�ִ�Զɽ�����ķҷ���
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"sroad",
]));
set("objects",([
			__DIR__"npc/xws" : 1,
       	]) );
         set("coor/x",-1310);

	set("coor/y",165);

	set("coor/z",0);
set("no_magic",1);
	setup();
}
