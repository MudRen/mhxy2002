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
  "southeast" : __DIR__"cyf1",
  "northup" : __DIR__"cyf2",
]));
       set("coor/x",-1025);

	set("coor/y",45);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
