#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"ʥ���"NOR);
        set("long", @LONG
����ͷ��,����˵���������������ϸ��������û��
ʲô�ر�֮����ֻ����һλ����һ����Ŀ���������
�������
LONG
        );
        set("exits", ([
                "down" : __DIR__"shengdian9",
        ]) );
        set("objects", ([
"/d/lingjie/obj/baiyu.c":1,
    __DIR__"npc/baye":1,
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}




