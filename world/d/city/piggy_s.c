inherit __DIR__"piggy.c";
#include <ansi.h>

void create()
{
    ::create();

    set ("short","�����Ϸ�");
    set("exits", ([
        "north": __DIR__"club3",
    ]) );
}
