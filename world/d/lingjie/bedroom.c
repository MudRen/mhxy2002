inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"���˯��"NOR);
        set("long", @LONG

����һ��˯��������ɸɾ�����һ�Ŵ󴲣�����������Ϣ˯����
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "out" : __DIR__"shengdian2",
        ]));

        setup();
}
