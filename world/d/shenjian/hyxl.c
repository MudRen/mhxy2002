// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ԺС¥");
        set("long", @LONG
С���ϵƻ�������һ��¥��ɿ���һ��˥�϶��㲵ĸ��ˣ�Ĭ
Ĭ�����ڹµ��ϡ��ݷ��ڵȴ������ȵ���ʲ���ˣ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"hy",
]));
set("objects",([
 __DIR__"npc/oldwoman" : 1,
 __DIR__"npc/master" : 1,
       	]) );
        set("coor/x",-1310);

	set("coor/y",410);

	set("coor/z",20);
	setup();
}
