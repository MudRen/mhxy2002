// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ·");
        set("long", @LONG
ɽ�ּе����ߵ����ֻʣһ��������С·��ǿ���������ˡ�վ
��������Կ���л�Ҵ���ڽ��£���Զ�ĵʹ�����ˮ�İ�����
����ͣ�Ĵ�������
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"cyf",
  "northwest" : __DIR__"cyf3",
]));
     set("coor/x",-1015);

	set("coor/y",35);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
