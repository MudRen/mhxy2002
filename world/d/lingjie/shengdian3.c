#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ʥ������"NOR);
        set("long", @LONG
���������������,���һ���Щ�����Ľ���,��ʵ
Ҳûʲô��˵���ˡ��������߾���ʥ��ĸ��߲㡣
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian4",
                "down" : __DIR__"shengdian2",
                "enter" : __DIR__"guanli",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}
