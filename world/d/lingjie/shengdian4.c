#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ʥ���Ĳ�"NOR);
        set("long", @LONG
�ط�ͻȻ��������,��û�뵽���ﻹ���������ĵط�,ÿ
һ��ط���������ϸ�Ĵ�ɨ����,��������ȥ,ȴ�����ɵ�,
ʲôҲ�����塣���ǽ�ȥ�ɣ������ߣ�����ʥ��ĸ߲��ˣ�
��㲻������������������ô��ġ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian5",
                "down" : __DIR__"shengdian3",
                "enter" : __DIR__"zoulang",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}
